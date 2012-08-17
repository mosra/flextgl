import time, os
import urllib.request
import os.path
from glob import glob
import re
from optparse import OptionParser

from wheezy.template.engine import Engine
from wheezy.template.ext.core import CoreExtension
from wheezy.template.loader import FileLoader

script_dir = os.path.dirname(__file__)

if script_dir == '':
    script_dir = '.'

script_dir += '/'
spec_dir = script_dir + 'spec/'
default_template_root = script_dir + 'templates/'

enumext_file = '%s/enumext.spec' % spec_dir
spec_file    = '%s/gl.spec' % spec_dir
tm_file      = '%s/gl.tm' % spec_dir


def file_age(filename):
    return time.time() - os.path.getmtime(filename) / 3600.0;
    

def parse_args():
    parser = OptionParser(usage='Usage: %prog [options] filename')
    parser.add_option('-d', '--download',
                      action='store_true', dest='download', default=False,
                      help='Force (re-)downloading the spec files before parsing')
    parser.add_option('-D', '--outdir', dest='outdir', default='generated',
                      help='Output directory for generated source files')
    parser.add_option('-T', '--template', dest='template', default='compatible',
                      help='The template set to use for file generation')
    parser.add_option('-t', '--template-dir', dest='template_dir', default=None,
                      help='The directory to look for template files in. (overrides --template)')
    options, args = parser.parse_args()

    if len(args) < 1:
        parser.print_help()
        exit(0)
    elif len(args) > 1:
        parser.print_help()
        exit(1)

    if options.template_dir == None:
        options.template_dir = default_template_root + options.template

    return options, args[0]


def download_spec(always_download = False):

    if not os.path.exists(spec_dir):
        os.makedirs(spec_dir)

    if (24 * 3 < max([file_age(tm_file),
                          file_age(spec_file), 
                          file_age(enumext_file)])):
        always_download = True

    if ( not always_download and
         os.path.exists(spec_file) and 
         os.path.exists(tm_file) and 
         os.path.exists(enumext_file) ):
        return


    print ('Downloading gl.tm')
    urllib.request.urlretrieve('http://www.opengl.org/registry/api/gl.tm', tm_file)
    print ('Downloading gl.spec')
    urllib.request.urlretrieve('http://www.opengl.org/registry/api/gl.spec', spec_file)
    print ('Downloading enumext.spec')
    urllib.request.urlretrieve('http://www.opengl.org/registry/api/enumext.spec', enumext_file)


class Version():
    def __init__(self, major, minor, core):
        self.major = int(major)
        self.minor = int(minor)
        self.core = core

    def __str__(self):

        return 'OpenGL %d.%d %s' % (self.major, self.minor, 'core' if self.core else 'compatibility')

    def int_value(self):
        return 10 * self.major + self.minor;


def parse_profile(filename):
    comment_pattern = re.compile('#.*$|\s+$')
    version_pattern = re.compile('version\s+(\d)\.(\d)\s*(core|compatibility|)\s*$')
    extension_pattern = re.compile('extension\s+(\w+)\s+(required|optional)\s*$')

    version = None
    extensions = []
    extension_set = set()

    with open(filename, 'r') as file:
        for line_no,line in enumerate(file, start=1):

            match = version_pattern.match(line)
            if match:
                if version != None:
                    print ('Error (%s:%d): Duplicate version statement' % (filename,line_no))
                    exit(1)
                version = Version(match.group(1), match.group(2), match.group(3) == 'core')
                continue

            match = extension_pattern.match(line)
            if match:            
                if match.group(1) in extension_set:
                    print ('Error (%s:%d): Duplicate extension statement' % (filename, line_no))
                    exit(1)
                
                extension_set.add(match.group(1))
                extensions.append((match.group(1), match.group(2) == 'required'))
                continue

            match = comment_pattern.match(line)
            if not match:
                print ('Syntax Error (%s:%d): %s' % (filename, line_no, line))
                exit(1)
    
    return version, extensions


def parse_typemap():
    typemap_pattern = re.compile('(\w+),\*,\*,\s*([A-Za-z0-9 \*_]+),*,*')

    typemap = {}

    with open(tm_file, 'r') as tmfile:
        for line in tmfile:
            match = typemap_pattern.match(line)

            if match:
                typemap[match.group(1)] = match.group(2)

    typemap['void'] = typemap['Void']

    return typemap


def build_entry_dependencies(dependencies = {}):
    opengl_pattern      = re.compile('# OpenGL (\d).(\d) commands\s*$')
    opengl_deprecated_pattern = re.compile('# OpenGL (\d).(\d) deprecated commands\s*$')
    category_pattern = re.compile('\s*category\s+(\w+)')
    newcategory_pattern = re.compile('newcategory: (\w+)')
    extension_pattern   = re.compile('passthru: \/\* (\w+) \*\/')
    reuse_1_pattern     = re.compile('passthru: \/\* (\w+) reuses entry points from (\w+) \*\/')
    reuse_2_pattern     = re.compile('passthru: \/\* (\w+) also reuses entry points from (\w+) and (\w+) \*\/')
    require_pattern     = re.compile('#@ (\w+) also requires (\w+)')
    shared_pattern      = re.compile('passthru: \/\* .* entry points are shared with (\w+). \*\/')
    

    current_deps = set()
    current_cat  = None
    passthru     = []

    with open(spec_file, 'r') as specfile:
        for line in specfile:

            match = opengl_pattern.match(line)
            if match:
                line = 'newcategory: VERSION_%s_%s' % (match.group(1), match.group(2))

            match = opengl_deprecated_pattern.match(line)
            if match:
                line = 'newcategory: VERSION_%s_%s_DEPRECATED' % (match.group(1), match.group(2))

            match = category_pattern.match(line)
            if match:
                line = 'newcategory: %s' % match.group(1)

            match = newcategory_pattern.match(line)
            if match:
                if current_cat:
                    dependencies[current_cat] = current_deps
                    
                current_cat  = match.group(1)
                current_deps = dependencies[current_cat] if current_cat in dependencies else set()
                continue

            match = extension_pattern.match(line)
            if match:
                current_deps.add(match.group(1))
                continue

            match = reuse_1_pattern.match(line)
            if match:
                current_deps.add(match.group(2))
                continue

            match = reuse_2_pattern.match(line)
            if match:
                current_deps.add(match.group(2))
                current_deps.add(match.group(3))
                continue

            match = require_pattern.match(line)
            if match:
                current_deps.add(match.group(2))
                continue

            match = shared_pattern.match(line)
            if match:
                current_deps.add(match.group(1))
                continue


    if current_cat:
        dependencies[current_cat] = current_deps  

    return dependencies
    
    

def parse_enums():
    category_pattern = re.compile('(\w+) enum:')
    passthru_pattern = re.compile('passthru: (.*)')
    enum_pattern     = re.compile('\s*(\w+)\s*=\s*(-?\w+)')
    use_pattern      = re.compile('\s*use\s+(\w+)\s+(\w+)')
    category = None
    enums = []
    lines = []
    enum_dict = {}

    with open(enumext_file, 'r') as enumfile:
        for line in enumfile:
            
            match = category_pattern.match(line)
            if match:
                category = match.group(1)

                lines.append('\n/* GL_%s */' % category)
                continue

            match = passthru_pattern.match(line)
            if match:
                #lines.append(match.group(1))
                continue

            match = enum_pattern.match(line)
            if match:
                value = match.group(2)
                value = value[3:] if value[:3] == 'GL_' else value
                value = enum_dict[value] if value in enum_dict else value
                enum_dict[match.group(1)] = value
                lines.append('#define GL_%s %s' % (match.group(1).ljust(45), value))
                continue

            match = use_pattern.match(line)
            if match:
                #lines.append('/* reuse GL_%s */' % match.group(2))
                continue
            

    return '\n'.join(lines)

class Function():
    def __init__(self, name):
        self.name = name
        self.params = []
        self.returntype = None
        self.minor_version = 1
        self.major_version = 0
        self.deprecated = False
        self.category = None

    def is_incomplete(self):
        if self.returntype == None:
            return True

        if self.category == None:
            return True

        return False

    def param_list_string(self):
        return 'void' if len(self.params) == 0 else ', '.join(['%s %s' % (t, p) for p,t in self.params])

    def param_type_list_string(self):
        return 'void' if len(self.params) == 0 else ', '.join(['%s' % t for p,t in self.params])

    def __str__(self):
        return '%s gl%s(%s)' % (self.returntype, self.name, self.param_list_string())

def parse_functions(categories, typemap):

    function_pattern         = re.compile('(\w+)\(.*\)\s*$')
    return_pattern           = re.compile('\s*return\s+(\w+)')
    category_pattern         = re.compile('\s*category\s+(\w+)')
    param_pattern            = re.compile('\s*param\s+(\w+)\s+(\w+) (in|out) (value|array|reference)')
    passthru_pattern         = re.compile('passthru: (.+)')
    passthru_comment_pattern = re.compile('passthru: \/\*(.+)\*\/')
    

    functions_by_category = {}
    current_function = None
    passthru = []

    with open(spec_file, 'r') as specfile:
        for line in specfile:
            
            match = function_pattern.match(line)
            if match:
                if current_function and current_function.category in categories:
                    if current_function.category not in functions_by_category:
                        functions_by_category[current_function.category] = []
                    functions_by_category[current_function.category].append(current_function)

                current_function = Function(match.group(1))
                continue

            match = return_pattern.match(line)
            if match:
                current_function.returntype = typemap[match.group(1)]
                continue

            match = category_pattern.match(line)
            if match:
                current_function.category = match.group(1)
                continue

            match = param_pattern.match(line)
            if match:
                
                param = match.group(1)
                isPointer = match.group(4) == 'array' or match.group(4) == 'reference'
                typename = match.group(2)
                direction = match.group(3)
                
                typename = ('const ' if direction == 'in' else '') + typemap[typename] + ('*' if isPointer else '')
                current_function.params.append((param, typename))
                continue
            
            if passthru_comment_pattern.match(line):
                continue

            match = passthru_pattern.match(line)
            if match:
                passthru.append(match.group(1)+'\n')


    if current_function and current_function.category in categories:
        if current_function.category not in functions_by_category:
            functions_by_category[current_function.category] = []
        functions_by_category[current_function.category].append(current_function)

    return functions_by_category, ''.join(passthru)
                
    
def find_categories(version, extensions, use_all=False):
    dependencies = build_entry_dependencies()
    
    all_categories = set(dependencies.keys())

    if use_all:
        return all_categories

    categories = set([extension for extension,_ in extensions])
    
    for v in range(10,version.major*10+version.minor+1):
        major = v / 10
        minor = v % 10

        categories.add('VERSION_%d_%d' % (major,minor))

        if not version.core:
            categories.add('VERSION_%d_%d_DEPRECATED' % (major,minor))

    categories = categories.intersection(all_categories)

    while True:
        old_categories = categories

        for cat in old_categories:
            if cat in dependencies:
                categories = categories.union(dependencies[cat])

        if old_categories == categories:
            break

    return categories

                
def generate_source(options, version, enums, functions_by_category, passthru, extensions):
    generated_warning = '/* WARNING: This file was automatically generated */\n/* Do not edit. */\n'
    template_pattern = re.compile("(.*).template")
    
    template_namespace = {'passthru'  : passthru,
                          'functions' : sorted(functions_by_category.items()),
                          'enums'     : enums,
                          'options'   : options,
                          'version'   : version,
                          'extensions': extensions}
    if not os.path.isdir(options.template_dir):
        print ('%s is not a directory' % options.template_dir)
        exit(1)
    
    if os.path.exists(options.outdir) and not os.path.isdir(options.outdir):
        print ('%s is not a directory' % options.outdir)
        exit(1)

    if not os.path.exists(options.outdir):
        os.mkdir(options.outdir)
        
        
    engine = Engine(loader=FileLoader([options.template_dir]), extensions=[CoreExtension()])
    
    for template_path in glob('%s/*.template' % os.path.abspath(options.template_dir)):
        
        infile = os.path.basename(template_path)
        outfile = '%s/%s' % (options.outdir, template_pattern.match(infile).group(1))
                
        template = engine.get_template(infile)
        
        with open(outfile, 'w') as out:
            out.write(generated_warning)
            out.write(template.render(template_namespace))

        
        

        
        

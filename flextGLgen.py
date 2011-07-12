import urllib
import re
from optparse import OptionParser
import os.path
from glob import glob
import numbers

from Cheetah.Template import Template

script_dir = os.path.dirname(__file__)

if script_dir == "":
    script_dir = "."

script_dir += os.sep
spec_dir = script_dir + "spec" + os.sep

if not os.path.exists(spec_dir):
    os.makedirs(spec_dir)

def download_spec():
    print ('Downloading gl.tm')
    urllib.urlretrieve("http://www.opengl.org/registry/api/gl.tm", spec_dir+"gl.tm")
    print ('Downloading gl.spec')
    urllib.urlretrieve("http://www.opengl.org/registry/api/gl.spec", spec_dir+"gl.spec")
    print ('Downloading enumext.spec')
    urllib.urlretrieve("http://www.opengl.org/registry/api/enumext.spec", spec_dir+"enumext.spec")


commentpattern = re.compile("#.*")
statementpattern = re.compile("([A-Za-z0-9_]+),\*,\*,\s*([A-Za-z0-9 \*_]+),*,*")

def parse_typemap():
    tmfile = open(spec_dir+'gl.tm', 'r')
    tm = {}

    line = ""

    while True:
        line = tmfile.readline()
        if (line == ""): return tm
        
        match = statementpattern.match(line)
        if match != None:
            tm[match.group(1)] = match.group(2)
        elif not commentpattern.match(line):
            print ( "Error: %s" % line)


class Version():
    def __init__(self, major, minor, profile):
        self.major = int(major)
        self.minor = int(minor)
        
        if profile == 'core':
            self.core = True
        else:
            self.core = False
        

def parse_input_file(filename):
    commentpattern = re.compile("#.*$|\s+$")
    versionpattern = re.compile("version\s+([0-9])\.([0-9])\s*(core|compatibility|)\s*$")
    extensionpattern = re.compile("extension\s+([a-zA-Z0-9_]+)\s(required|optional)\s*$")

    file = open(filename, 'r')
    version = None
    extensions = {}

    line_no = 0

    while True:
        line = file.readline()
        line_no = line_no + 1
        if (line == ""): return version, extensions

        if versionpattern.match(line):
            if version != None:
                print ("Error (%s:%d): Duplicate version statement" % (filename,line_no))
                exit(1)
            match = versionpattern.match(line)
            version = Version(match.group(1), match.group(2), 
                              match.group(3))
        elif extensionpattern.match(line):
            match = extensionpattern.match(line)
            
            if extensions.has_key(match.group(1)):
                print ("Error (%s:%d): Duplicate extension statement" % (filename, line_no))
                exit(1)

            if match.group(2) == "required":
                extensions[match.group(1)] = True
            else:
                extensions[match.group(1)] = False
        elif not commentpattern.match(line):
            print ("Syntax Error (%s:%d): %s" % (filename, line_no, line))
            exit(1)

        

def parse_args():
    parser = OptionParser(usage='Usage: %prog [options] filename')
    parser.add_option("-d", "--download",
                      action="store_true", dest="download", default=False,
                      help="Force (re-)downloading the spec files before parsing")
    parser.add_option("-D", "--outdir", dest="outdir", default='generated',
                      help="Output directory for generated source files")
    parser.add_option("-T", "--template", dest="template", default="compatible",
                      help="The template set to use for file generation")
    options, args = parser.parse_args()

    if len(args) < 1:
        parser.print_help()
        exit(0)
    elif len(args) > 1:
        parser.print_help()
        exit(1)

    return options, args[0]


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
    def print_definition(self):

        print ('%s gl%s(' % (self.returntype, self.name))

        first = True
        for p,t in self.params.iteritems():
            print ('%s%s %s' % (('' if first else ', '), t, p))
            first = False
        
        print (')')

def parse_glspec(typemap, categories):
    commentpattern = re.compile("#.*$|\s+$")
    passthrupattern = re.compile("passthru: (.*$)")
    functionpattern = re.compile('(\w+)\((\w+(, \w+)*)?\)\s*$')
    returnpattern = re.compile('\s*return\s+(\w+)')
    parampattern = re.compile('\s*param\s+(\w+)\s+(\w+) (in|out) (value|array|reference)')
    versionpattern = re.compile('\s*version\s+(\d)\.(\d)')
    categorypattern = re.compile('\s*category\s+(\w+)')
    deprecatedpattern = re.compile('\s*deprecated\s+(\d)\.(\d)')

    file = open(spec_dir+'gl.spec', 'r')
    passthru = []
    functions = {}

    current_function = None

    lineno = 0

    while True:
        line = file.readline()
        lineno = lineno+1
        if line == '': return passthru, functions

        if passthrupattern.match(line):
            match = passthrupattern.match(line)

            passthru.append(match.group(1) + '\n')
        elif functionpattern.match(line):
            if current_function != None:
                if current_function.is_incomplete():
                    print ("Error(%s:%d): Incomplete information for function %s" % ("gl.spec", lineno, current_function.name))
                    exit(1)

                function_category = current_function.category

                if not functions.has_key(function_category):
                    functions[function_category] = []
                functions[function_category].append(current_function)

            match = functionpattern.match(line)

            functionname = match.group(1)
            # params = [s.strip() for s in match.group(2).split(',')]
        
            current_function = Function(functionname)
        elif deprecatedpattern.match(line):
            current_function.deprecated = True
        elif versionpattern.match(line):
            match = versionpattern.match(line)
            
            current_function.minor_version = int(match.group(1))
            current_function.major_version = int(match.group(2))

        elif categorypattern.match(line):
            match = categorypattern.match(line)

            current_function.category = match.group(1)            
        elif returnpattern.match(line):
            match = returnpattern.match(line)

            typename = match.group(1)

            if not typemap.has_key(typename):
                print ("Error(gl.spec:%d): Unknown typename %s" % typename)
                exit(1)

            current_function.returntype = typemap[typename]
        elif parampattern.match(line):
            match = parampattern.match(line)

            param = match.group(1)
            isPointer = match.group(4) == 'array' or match.group(4) == 'reference'
            typename = match.group(2)
            direction = match.group(3)
            
            if not typemap.has_key(typename):
                print ("Error(gl.spec:%d): Unknown typename %s" % typename)
                exit(1)
            else:
                typename = ('const ' if direction == 'in' else '') + typemap[typename] + ('*' if isPointer else '')
                current_function.params.append((param, typename))
                
def parse_enums(categories):
    categorypattern = re.compile("(\w+)\s+enum:")
    enumpattern = re.compile("\s*(\w+)\s+=\s+((0x)?[\da-fA-F]+)")
    refenumpattern = re.compile("\s*(\w+)\s+=\s+GL_(\w+)")
    hexpattern = re.compile('0x([\da-fA-F]+)')
    usepattern = re.compile('\s*use (\w+)\s*(\w+)')

    file = open(spec_dir+'enumext.spec', 'r')
    lineno = 0
    enums = {}
    current_category = None
    current_enums = {}
    
    while True:        
        line = file.readline()
        lineno = lineno+1
        if line == '': break

        if categorypattern.match(line):
            if current_category != None:
                if enums.has_key(current_category):
                    enums[current_category].update(current_enums)
                else:
                    enums[current_category] = current_enums

            match = categorypattern.match(line)
            current_category = match.group(1)
            current_enums = {}

        elif enumpattern.match(line):
            match = enumpattern.match(line)

            enumname = match.group(1)

            # There are sometimes 0xffffffffffff... enums defined
            # To handle those, we truncate enum values to 32 bit.
            enumvalue = long(long(match.group(2), 0) & 0x7fffffffffffffff)

            current_enums[enumname] = enumvalue
        elif refenumpattern.match(line):
            match = refenumpattern.match(line)

            enumname = match.group(1)
            reference = match.group(2)
            
            current_enums[enumname] = reference
        elif usepattern.match(line):
            match = usepattern.match(line)

            enumname = match.group(2)
            enumsource = match.group(1)

            current_enums[enumname] = enumsource

    for category in enums.itervalues():
        for name, value in category.iteritems():
            
            if isinstance(value, str):
                realvalue = None
                if value in enums and name in enums[value]:
                    realvalue = enums[value][name]
                elif value+'_DEPRECATED' in enums and name in enums[value+'_DEPRECATED']:
                    realvalue = enums[value+'_DEPRECATED'][name]
                elif value in category:
                    realvalue = category[value]
            
                
                
                if not isinstance(realvalue, numbers.Integral):
                    # let's try brute force
                    for category2 in enums.itervalues():
                        for name2, value2 in category2.iteritems():
                            if name2 == name and isinstance(value2, numbers.Integral):
                                realvalue = value2
                            if name2 == value and isinstance(value2, numbers.Integral):
                                realvalue = value2

                if not isinstance(realvalue, numbers.Integral):
                    print("Could not resolve reference for enum %s = %s (%s)" % (name,value,realvalue))
                    exit(1)

                category[name] = realvalue

    return enums

            

def get_categories(extensions, version):

    categories = []

    for maj in range(1,version.major):
        for min in range(10):
            categories.append('VERSION_%d_%d' % (maj, min))
            if not version.core:
                categories.append('VERSION_%d_%d_DEPRECATED' % (maj, min))

    for min in range(version.minor+1):
        categories.append('VERSION_%d_%d' % (version.major, min))
        if not version.core:
            categories.append('VERSION_%d_%d_DEPRECATED' % (version.major, min))

    categories = categories + [e for e in extensions.keys()]
    
    if not version.core:
        categories = categories + [e+'_DEPRECATED' for e in extensions.keys()]

    return categories


def find_longest_enum(enums):
    longest = 0

    for categories in enums.itervalues():
        for name in categories.iterkeys():
            if len(name) > longest:
                longest = len(name)
    return longest

def resolve_promotions(version, categories, functions, enums, passthru):
    versionpattern = re.compile("/\* OpenGL (\d).(\d) also reuses entry points from these extensions: \*/")
    extensionpattern = re.compile("/\* (\w+)")

    target_version = (version.major, version.minor)
    active_version = None
    active_category = ''

    for line in passthru:
        if versionpattern.match(line):
            match = versionpattern.match(line)
            active_version = (int(match.group(1)), int(match.group(2)))
            active_category = 'VERSION_%d_%d' % active_version
        elif extensionpattern.match(line):
            match = extensionpattern.match(line)
            extension = match.group(1)

            if active_version <= target_version and extension not in categories:
                if extension in functions:
                    if active_category in functions:
                        functions[active_category].extend(functions[extension])
                    else:
                        functions[active_category] = list(functions[extension])
                if extension in enums:
                    if active_category in enums:
                        enums[active_category].update(enums[extension])
                    else:
                        enums[active_category] = list(enums[extension])

    enums['VERSION_2_0'].update(enums['ARB_imaging'])
                
            

options, file = parse_args()

version, extensions = parse_input_file(file)

categories = get_categories(extensions, version)

if ((not os.path.exists(spec_dir+"gl.spec")) or 
    (not os.path.exists(spec_dir+"gl.tm")) or
    (not os.path.exists(spec_dir+"enumext.spec"))):
    options.download = True

if options.download:
    download_spec()

typemap = parse_typemap()
typemap['void'] = 'void'
passthru, functions = parse_glspec(typemap, categories)
all_enums = parse_enums(categories)

resolve_promotions(version, categories, functions, all_enums, passthru)

enums = {}

for category in categories:
    if category in all_enums:
        enums.update(all_enums[category])

enums = enums.items()
enums.sort()

template_namespace = {'passthru' : ''.join(passthru),
                      'categories' : categories,
                      'functions' : functions,
                      'enums' : enums,
                      'longest_enum' : find_longest_enum(all_enums),
                      'options' : options,
                      'version' : version,
                      'extensions' : extensions
                      }

if not os.path.exists(options.outdir):
    os.makedirs(options.outdir)

for template_path in glob('%stemplates/%s/*.template' % (script_dir,options.template)):
    template_file = os.path.split(template_path)[1]
    pattern = re.compile("(.*).template")
    outfile = "%s/%s" % (options.outdir, pattern.match(template_file).group(1))
    
    template = Template(open(template_path, 'r').read(), template_namespace)
    f = open(outfile, 'w')
    f.write(str(template))
    f.close()

import time, os
import urllib.request
import os.path
import re

from glob     import glob

import xml.etree.ElementTree as etree

from wheezy.template.engine   import Engine
from wheezy.template.ext.core import CoreExtension
from wheezy.template.loader   import FileLoader


################################################################################
# Find the local directory for this file
################################################################################

script_dir = os.path.dirname(__file__)

if script_dir == '':
    script_dir = '.'

script_dir += '/'
spec_dir = script_dir + 'spec/'
default_template_root = script_dir + 'templates/'


################################################################################
# Name and location for spec file(s)
################################################################################

specFileList = ['gl.xml']
specURL = 'http://www.opengl.org/registry/api/'
gl_xml_file = '%s/gl.xml' % spec_dir

GL_API_NAME = 'gl'


################################################################################
# Spec file download
################################################################################

def file_age(filename):
    return (time.time() - os.path.getmtime(filename)) / 3600.0

def download_spec(always_download = False):
    if not os.path.exists(spec_dir):
        os.makedirs(spec_dir)

    for fileName in specFileList:
        filePath = '%s%s' % (spec_dir, fileName)
        if (always_download or not os.path.exists(filePath) or file_age(filePath) > 3 * 24):
            fileURL  = '%s%s' % (specURL, fileName)
            print ('Downloading %s' % fileURL)
            urllib.request.urlretrieve(fileURL, filePath)


################################################################################
# Profile file parsing
################################################################################

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


################################################################################
# XML spec file parsing
################################################################################

class Function:
    def __init__(self, rettype, name, params):
        self.name          = name
        self.params        = params
        self.returntype    = rettype

    def param_list_string(self):
        return 'void' if len(self.params) == 0 else ', '.join(['%s %s' % (t, p) for p,t in self.params])

    def param_type_list_string(self):
        return 'void' if len(self.params) == 0 else ', '.join(['%s' % t for p,t in self.params])

class APISubset:
    def __init__(self, name, types, enums, commands):
        self.name     = name
        self.types    = types
        self.enums    = enums
        self.commands = commands
       
class Type:
    def __init__(self, name, definition, dependent):
        self.name       = name
        self.definition = definition
        self.dependent  = dependent
        
class Enum:
    def __init__(self, name, value):
        self.name  = name
        self.value = value
        
class Command:
    def __init__(self, rettype, name, params, requiredTypes):
        self.name          = name
        self.params        = params
        self.returntype    = rettype
        self.requiredTypes = requiredTypes
        
def safe_text(text):
    return '' if (text is None) else text

def xml_extract_all_text(node, substitutes):
    fragments = [safe_text(node.text)]
    for item in list(node):
        fragments.append(substitutes[item.tag] if item.tag in substitutes else safe_text(item.text))
        fragments.append(safe_text(item.tail))
    return ''.join(fragments)

def xml_parse_type_name_pair(node):
    name = node.find('name').text.strip()
    type = xml_extract_all_text(node, {'name':''}).strip()
    ptype = node.find('ptype')
    return (name, type, ptype.text.strip() if ptype != None else None)

def extract_names(feature, selector):
    return [element.attrib['name'] for element in feature.findall('./%s[@name]' % selector)]

def parse_int_version(version_str):
    version_pattern = re.compile('(\d)\.(\d)')
    match = version_pattern.match(version_str)
    return int(match.group(1)) * 10 + int(match.group(2))

def parse_xml_enums(root):
    enums = {}

    for enum in root.findall("./enums/enum"):
        if ('api' in enum.attrib and enum.attrib['api'] != GL_API_NAME): continue
        name  = enum.attrib['name']
        value = "%s%s" % (enum.attrib['value'], enum.attrib['type']) if 'type' in enum.attrib else enum.attrib['value']
        enums[name] = value

    return enums

def parse_xml_types(root):
    types = []

    for type in root.findall("./types/type"):
        if ('api' in type.attrib and type.attrib['api'] != GL_API_NAME): continue

        name = type.attrib['name'] if 'name'in type.attrib else type.find('./name').text
        definition = xml_extract_all_text(type, {'apientry' : 'APIENTRY'})

        types.append(Type(name, definition, type.attrib['requires'] if 'requires' in type.attrib else None))

    return types

def parse_xml_commands(root):
    commands = {}

    for cmd in root.findall("./commands/command"):
        requiredTypes = set()
        name, rettype, requiredType = xml_parse_type_name_pair(cmd.find('./proto'))
        if requiredType!=None:
            requiredTypes.add(requiredType)


        params = []
        for item in cmd.findall("./param"):
            pname, ptype, requiredType = xml_parse_type_name_pair(item)
            params.append((pname, ptype))

            if requiredType!=None:
                requiredTypes.add(requiredType)

        commands[name] = Command(rettype, name, params, requiredTypes)

    return commands

def parse_xml_features(root, int_version, core):
    subsets = []
    profileStr = 'core' if core else 'compatibility'

    for feature in root.findall("./feature[@api='%s'][@name][@number]" % GL_API_NAME):
        if (parse_int_version(feature.attrib['number'])>int_version):
            continue

        featureName = feature.attrib['name']

        typeList    = []
        enumList    = []
        commandList = []

        for actionSet in list(feature):
            if 'profile' in actionSet.attrib and actionSet.attrib['profile'] != profileStr:
                continue

            if actionSet.tag == 'require':
                typeList.extend(extract_names(actionSet, './type'))
                enumList.extend(extract_names(actionSet, './enum'))
                commandList.extend(extract_names(actionSet, './command'))

            if actionSet.tag == 'remove':
                for subset in subsets:
                    subset.types    = [entry for entry in subset.types    if entry not in set(extract_names(actionSet, './type'))]
                    subset.enums    = [entry for entry in subset.enums    if entry not in set(extract_names(actionSet, './enum'))]
                    subset.commands = [entry for entry in subset.commands if entry not in set(extract_names(actionSet, './command'))]

        subsets.append(APISubset(featureName[3:], typeList, enumList, commandList))

    return subsets

def parse_xml_extensions(root, extensions):
    removedEnums    = set()
    removedTypes    = set()
    removedCommands = set()

    subsets = []

    for name, _ in extensions:
        extension = root.find("./extensions/extension[@name='GL_%s']" % name)
        if (extension==None):
            print ('%s is not an extension' % name)
            continue
        subsets.append(APISubset(name, extract_names(extension, 'require/type'), extract_names(extension, 'require/enum'), extract_names(extension, 'require/command')))

    return subsets

def generate_passthru(dependencies, types):
    passthru = ''
    for type in types:
        if (type.name in dependencies):
            if passthru: passthru += '\n'
            passthru += type.definition

    return passthru

def generate_enums(subsets, enums):
    enumsDecl = ''
    for subset in subsets:
        if subset.enums != []:
            if enumsDecl: enumsDecl += '\n\n'
            enumsDecl += '/* GL_%s */\n' % subset.name
            for enumName in subset.enums:
                enumsDecl += '\n#define %s %s' % (enumName, enums[enumName])

    return enumsDecl

def generate_functions(subsets, commands):
    functions = []
    function_set = set()
    
    for subset in subsets:
        #remove 'gl' suffixes and strip away commands that are already required by a preceding feature or extension
        subset_functions = [Function(commands[name].returntype, commands[name].name[2:], commands[name].params) for name in subset.commands if name not in function_set]
        function_set = function_set.union(subset.commands)
            
        functions.append((subset.name, subset_functions))

    return functions

def resolve_type_dependencies(subsets, types, commands):
    requiredTypes = set()

    for subset in subsets:
        requiredTypes |= set(subset.types)
        for cmd in subset.commands:
            requiredTypes |= commands[cmd].requiredTypes

    for type in types:
        if type.name in requiredTypes and type.dependent:
            requiredTypes.add(type.dependent)

    return requiredTypes

def parse_xml(version, extensions):
    tree = etree.parse(gl_xml_file)
    root = tree.getroot()

    types    = parse_xml_types(root)
    enums    = parse_xml_enums(root)
    commands = parse_xml_commands(root)

    subsetsGL  = parse_xml_features  (root, version.int_value(), version.core)
    subsetsEXT = parse_xml_extensions(root, extensions)

    subsets  = subsetsGL
    subsets += subsetsEXT

    requiredTypes = resolve_type_dependencies(subsets, types, commands)

    passthru     = generate_passthru(requiredTypes, types)
    enums        = generate_enums(subsets, enums)
    functions    = generate_functions(subsets, commands)

    return passthru, enums, functions


################################################################################
# Source generation
################################################################################

def generate_source(options, version, enums, functions_by_category, passthru, extensions):
    generated_warning = '/* WARNING: This file was automatically generated */\n/* Do not edit. */\n'
    template_pattern = re.compile("(.*).template")

    template_namespace = {'passthru'  : passthru,
                          'functions' : functions_by_category,
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
    
    generatedFiles = 0
    allFiles       = 0;

    for template_path in glob('%s/*.template' % os.path.abspath(options.template_dir)):

        infile = os.path.basename(template_path)
        outfile = '%s/%s' % (options.outdir, template_pattern.match(infile).group(1))

        template = engine.get_template(infile)

        allFiles += 1

        with open(outfile, 'w') as out:
            out.write(generated_warning)
            out.write(template.render(template_namespace))
            print("Successfully generated %s" % outfile)
            generatedFiles += 1;

    print("Generated %d of %d files" % (generatedFiles, allFiles))

    

import os
import re
import shutil
import subprocess
import sys
import unittest

from types import SimpleNamespace as Empty

import flextGLgen

# https://stackoverflow.com/a/12867228
_camelcase_to_snakecase = re.compile('((?<=[a-z0-9])[A-Z]|(?!^)[A-Z](?=[a-z]))')

# The test files are automatically detected from derived class name and
# filesystem location. For a `test_generate.VkRelease` class, it will look
# for the `generate_vk_release` directory. If the class name is equivalent to
# the filename (e.g. `test_generate.Generate`), then it will be looking for
# just `page` instead of `page_page`. If needed, the directory name can be
# overriden by passing it via dir to __init__().
class BaseTestCase(unittest.TestCase):
    def __init__(self, *args, dir=None, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs)

        # Get the test filename from the derived class module file. If path is
        # not supplied, get it from derived class name converted to snake_case
        path = sys.modules[self.__class__.__module__].__file__
        if not dir: dir = _camelcase_to_snakecase.sub('_\\1', self.__class__.__name__).lower()

        # Full directory name (for test_something.py the directory is
        # something_{dir}
        dir_prefix = os.path.splitext(os.path.basename(path))[0][5:]
        if dir and dir_prefix != dir:
            dirname = dir_prefix + '_' + dir
        else:
            dirname = dir_prefix
        # Absolute path to this directory
        self.path = os.path.join(os.path.dirname(os.path.realpath(path)), dirname)
        self.cwd = os.path.dirname(self.path)
        self.root = os.path.dirname(self.cwd)

        if not os.path.exists(self.path):
            raise AssertionError("autodetected path {} doesn't exist".format(self.path))

        # Display ALL THE DIFFS
        self.maxDiff = None

    def setUp(self):
        if os.path.exists(os.path.join(self.path, 'generated')):
            shutil.rmtree(os.path.join(self.path, 'generated'))

    def run_flextglgen(self, template_dir=None):
        args = Empty()
        args.download = False
        args.outdir = os.path.join(self.path, 'generated')
        args.template_dir = template_dir if template_dir else self.path
        flextGLgen.main('-D generated -t somepath profile.txt', args, os.path.join(self.path, 'profile.txt'))

    def actual_expected_contents(self, actual, expected=None, replace=None):
        if not expected: expected = actual

        with open(os.path.join(self.path, expected)) as f:
            expected_contents = f.read().strip()
        with open(os.path.join(self.path, 'generated', actual)) as f:
            actual_contents = f.read().strip()

        # Not replacing expected_contents, there it should be done already.
        # That also prevents accidents of replacing something unwanted.
        if replace: actual_contents = re.sub(replace[0], replace[1], actual_contents)

        return actual_contents, expected_contents

class Generate(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Es(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Vk(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h',
            replace=('#define VK_HEADER_VERSION \d+', '#define VK_HEADER_VERSION 00')))

class VkRelease(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen(template_dir=os.path.join(self.cwd, 'generate_vk'))
        self.assertTrue(os.path.exists(os.path.join(self.root, "spec/vk.v1.1.73.xml")))
        self.assertEqual(*self.actual_expected_contents('flextVk.h'))

class VkDuplicateExtensionInteraction(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h'))

class VkExtendEmptyFlagBits(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h'))

class VkExtensionInteractionReorder(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h'))

class VkPromotedEnum(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h',
            replace=('#define VK_HEADER_VERSION \d+', '#define VK_HEADER_VERSION 00')))

class VkDuplicateEnum(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h',
            replace=('#define VK_HEADER_VERSION \d+', '#define VK_HEADER_VERSION 00')))

class VkEnumAliasWithDependency(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h'))

class VkEnumAliasWithoutDependency(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextVk.h'))

class NotADirectory(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, dir='generate', **kwargs)

    def test_template(self):
        with self.assertRaises(SystemExit):
            args = Empty()
            args.download = False
            args.outdir = os.path.join(self.path, 'generated')
            args.template_dir = os.path.join(self.cwd, 'nonexistent')
            flextGLgen.main('', args, os.path.join(self.cwd, 'profile.txt'))

    def test_out(self):
        with self.assertRaises(SystemExit):
            args = Empty()
            args.download = False
            args.outdir = os.path.join(self.cwd, 'profile.txt')
            args.template_dir = os.path.join(self.root, 'templates')
            flextGLgen.main('', args, os.path.join(self.cwd, 'profile.txt'))

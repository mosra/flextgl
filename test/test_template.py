import os
import re
import shutil
import subprocess
import sys
import unittest

from types import SimpleNamespace as Empty

import flextGLgen

class BaseTestCase(unittest.TestCase):
    def __init__(self, path, template, *args, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs)

        self.template = template

        # Ground truth files in the template_{template}/ subdirectory
        self.cwd = os.path.dirname(os.path.realpath(path))
        self.root = os.path.dirname(self.cwd)
        self.path = os.path.join(self.cwd, ('template' + ('_' + template if template else '')))

        # Display ALL THE DIFFS
        self.maxDiff = None

    def setUp(self):
        if os.path.exists(os.path.join(self.path, 'generated')):
            shutil.rmtree(os.path.join(self.path, 'generated'))

    def run_flextglgen(self, profile):
        args = Empty()
        args.download = False
        args.outdir = os.path.join(self.path, 'generated')
        args.template_dir = os.path.join(self.root, 'templates', self.template) if self.template else self.path
        flextGLgen.main(args, os.path.join(self.cwd, profile))

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

class Compatible(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'compatible', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile.txt')
        self.assertEqual(*self.actual_expected_contents('flextGL.c'))
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Glfw(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'glfw', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile.txt')
        self.assertEqual(*self.actual_expected_contents('flextGL.c'))
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Glfw3(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'glfw3', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile.txt')
        self.assertEqual(*self.actual_expected_contents('flextGL.c'))
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Glfw3Es(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'glfw3-es', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile-es.txt')
        self.assertEqual(*self.actual_expected_contents('flextGL.c'))
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Lite(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'lite', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile.txt')
        self.assertEqual(*self.actual_expected_contents('flextGL.c'))
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Sdl(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'sdl', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile.txt')
        self.assertEqual(*self.actual_expected_contents('flextGL.c'))
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Vulkan(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'vulkan', *args, **kwargs)

    def test(self):
        self.run_flextglgen('profile-vk.txt')
        self.assertEqual(*self.actual_expected_contents('flextVk.cpp'))
        self.assertEqual(*self.actual_expected_contents('flextVk.h',
            replace=('#define VK_HEADER_VERSION \d+', '#define VK_HEADER_VERSION 00')))

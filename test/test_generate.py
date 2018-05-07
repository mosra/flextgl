import os
import shutil
import subprocess
import sys
import unittest

from types import SimpleNamespace as Empty

import flextGLgen

class BaseTestCase(unittest.TestCase):
    def __init__(self, path, dir, *args, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs)

        # Ground truth files in the template_{template}/ subdirectory
        self.cwd = os.path.dirname(os.path.realpath(path))
        self.root = os.path.dirname(self.cwd)
        self.path = os.path.join(self.cwd, ('generate' + ('_' + dir if dir else '')))

        # Display ALL THE DIFFS
        self.maxDiff = None

    def setUp(self):
        if os.path.exists(os.path.join(self.path, 'generated')):
            shutil.rmtree(os.path.join(self.path, 'generated'))

    def run_flextglgen(self):
        args = Empty()
        args.download = False
        args.outdir = os.path.join(self.path, 'generated')
        args.template_dir = self.path
        flextGLgen.main(args, os.path.join(self.path, 'profile.txt'))

    def actual_expected_contents(self, actual, expected = None):
        if not expected: expected = actual

        with open(os.path.join(self.path, expected)) as f:
            expected_contents = f.read().strip()
        with open(os.path.join(self.path, 'generated', actual)) as f:
            actual_contents = f.read().strip()
        return actual_contents, expected_contents

class Core(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, '', *args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class Es(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, 'es', *args, **kwargs)

    def test(self):
        self.run_flextglgen()
        self.assertEqual(*self.actual_expected_contents('flextGL.h'))

class NotADirectory(BaseTestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(__file__, '', *args, **kwargs)

    def test_template(self):
        with self.assertRaises(SystemExit):
            args = Empty()
            args.download = False
            args.outdir = os.path.join(self.path, 'generated')
            args.template_dir = os.path.join(self.cwd, 'nonexistent')
            flextGLgen.main(args, os.path.join(self.cwd, 'profile.txt'))

    def test_out(self):
        with self.assertRaises(SystemExit):
            args = Empty()
            args.download = False
            args.outdir = os.path.join(self.cwd, 'profile.txt')
            args.template_dir = os.path.join(self.root, 'templates')
            flextGLgen.main(args, os.path.join(self.cwd, 'profile.txt'))

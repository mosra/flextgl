import os
import shutil
import subprocess
import sys
import unittest

from types import SimpleNamespace as Empty

import flextGLgen

class ParseErrors(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs)

        # Ground truth files in the template_{template}/ subdirectory
        self.cwd = os.path.dirname(os.path.realpath(__file__))
        self.root = os.path.dirname(self.cwd)

    def run_flextglgen(self, profile):
        args = Empty()
        args.download = False
        args.outdir = os.path.join(self.cwd, 'generated')
        args.template = 'glfw'
        flextGLgen.main(args, os.path.join(self.cwd, profile))

    def test_duplicate_version(self):
        with self.assertRaises(SystemExit):
            self.run_flextglgen('profile/duplicate-version.txt')

    def test_mismatched_begin_end(self):
        with self.assertRaises(SystemExit):
            self.run_flextglgen('profile/mismatched-begin-end.txt')

    def test_duplicate_extension(self):
        with self.assertRaises(SystemExit):
            self.run_flextglgen('profile/duplicate-extension.txt')

    def test_invalid_function(self):
        with self.assertRaises(SystemExit):
            self.run_flextglgen('profile/invalid-function.txt')

    def test_unknown_command(self):
        with self.assertRaises(SystemExit):
            self.run_flextglgen('profile/unknown-command.txt')

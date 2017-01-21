#!/usr/bin/env python

import os
import shutil
from subprocess import call

def main():
    path = "build"
    shutil.rmtree(path, ignore_errors=True)
    os.makedirs(path)
    os.chdir(path)
    call(["cmake ../"], shell=True)
    call(["make "], shell=True)

if __name__ == '__main__':
    main()


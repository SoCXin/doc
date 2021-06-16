 

from os import chdir, getcwd, readlink, remove, symlink, walk
from os.path import exists, islink, join, relpath
from sys import exit as sys_exit


def fix_symlink(root, fname, brokenlink):
    print(root, fname, brokenlink)
    prevcwd = getcwd()

    chdir(root)
    remove(fname)
    symlink(relpath(brokenlink, root), fname)
    chdir(prevcwd)


def main():
    for root, dirnames, filenames in walk("."):
        for f in filenames:
            path = join(root, f)
            if not islink(path) or exists(path):
                continue
            fix_symlink(root, f, readlink(path))


if __name__ == "__main__":
    sys_exit(main())

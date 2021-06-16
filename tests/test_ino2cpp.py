 

from os import listdir
from os.path import dirname, isdir, join, normpath

from platformio.commands.ci import cli as cmd_ci

INOTEST_DIR = normpath(join(dirname(__file__), "ino2cpp"))


def pytest_generate_tests(metafunc):
    if "piotest_dir" not in metafunc.fixturenames:
        return
    test_dirs = []
    for name in listdir(INOTEST_DIR):
        if isdir(join(INOTEST_DIR, name)):
            test_dirs.append(join(INOTEST_DIR, name))
    test_dirs.sort()
    metafunc.parametrize("piotest_dir", test_dirs)


def test_example(clirunner, validate_cliresult, piotest_dir):
    result = clirunner.invoke(cmd_ci, [piotest_dir, "-b", "uno"])
    validate_cliresult(result)


def test_warning_line(clirunner, validate_cliresult):
    result = clirunner.invoke(cmd_ci, [join(INOTEST_DIR, "basic"), "-b", "uno"])
    validate_cliresult(result)
    assert 'basic.ino:16:14: warning: #warning "Line number is 16"' in result.output
    assert 'basic.ino:46:2: warning: #warning "Line number is 46"' in result.output
    result = clirunner.invoke(cmd_ci, [join(INOTEST_DIR, "strmultilines"), "-b", "uno"])
    validate_cliresult(result)
    assert 'main.ino:75:2: warning: #warning "Line 75"' in result.output

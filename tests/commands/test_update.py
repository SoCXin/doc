 

# pylint: disable=unused-argument

from platformio.commands.update import cli as cmd_update


def test_update(clirunner, validate_cliresult, isolated_pio_core):
    matches = ("Platform Manager", "Library Manager")
    result = clirunner.invoke(cmd_update, ["--only-check"])
    validate_cliresult(result)
    assert all(m in result.output for m in matches)
    result = clirunner.invoke(cmd_update)
    validate_cliresult(result)
    assert all(m in result.output for m in matches)

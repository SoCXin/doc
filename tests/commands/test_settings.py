 

from platformio import app
from platformio.commands.settings import cli


def test_settings_check(clirunner, validate_cliresult):
    result = clirunner.invoke(cli, ["get"])
    validate_cliresult(result)
    assert result.output
    for item in app.DEFAULT_SETTINGS.items():
        assert item[0] in result.output

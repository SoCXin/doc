 

import json

from platformio.commands.boards import cli as cmd_boards
from platformio.commands.platform import platform_search as cmd_platform_search


def test_board_json_output(clirunner, validate_cliresult):
    result = clirunner.invoke(cmd_boards, ["mbed", "--json-output"])
    validate_cliresult(result)
    boards = json.loads(result.output)
    assert isinstance(boards, list)
    assert any("mbed" in b["frameworks"] for b in boards)


def test_board_raw_output(clirunner, validate_cliresult):
    result = clirunner.invoke(cmd_boards, ["espidf"])
    validate_cliresult(result)
    assert "espressif32" in result.output


def test_board_options(clirunner, validate_cliresult):
    required_opts = set(["fcpu", "frameworks", "id", "mcu", "name", "platform"])

    # fetch available platforms
    result = clirunner.invoke(cmd_platform_search, ["--json-output"])
    validate_cliresult(result)
    search_result = json.loads(result.output)
    assert isinstance(search_result, list)
    assert search_result
    platforms = [item["name"] for item in search_result]

    result = clirunner.invoke(cmd_boards, ["mbed", "--json-output"])
    validate_cliresult(result)
    boards = json.loads(result.output)

    for board in boards:
        assert required_opts.issubset(set(board))
        assert board["platform"] in platforms

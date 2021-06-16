 

import json
import subprocess
import sys

import click


@click.command()
@click.option("--desktop", is_flag=True, default=False)
@click.option(
    "--ignore",
    envvar="PIO_INSTALL_DEVPLATFORMS_IGNORE",
    help="Ignore names split by comma",
)
@click.option(
    "--ownernames",
    envvar="PIO_INSTALL_DEVPLATFORMS_OWNERNAMES",
    help="Filter dev-platforms by ownernames (split by comma)",
)
def main(desktop, ignore, ownernames):
    platforms = json.loads(
        subprocess.check_output(
            ["platformio", "platform", "search", "--json-output"]
        ).decode()
    )
    ignore = [n.strip() for n in (ignore or "").split(",") if n.strip()]
    ownernames = [n.strip() for n in (ownernames or "").split(",") if n.strip()]
    for platform in platforms:
        skip = [
            not desktop and platform["forDesktop"],
            platform["name"] in ignore,
            ownernames and platform["ownername"] not in ownernames,
        ]
        if any(skip):
            continue
        subprocess.check_call(["platformio", "platform", "install", platform["name"]])


if __name__ == "__main__":
    sys.exit(main())

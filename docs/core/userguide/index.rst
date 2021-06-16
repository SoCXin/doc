 
.. _piocore_userguide:

CLI Guide
=========

.. contents::

Usage
-----

.. code-block:: bash

    pio [OPTIONS] COMMAND
    # alias of "pio"
    platformio [OPTIONS] COMMAND


Options
-------

.. program:: pio

.. option::
    --no-ansi

Do not print ANSI control characters.

See also :envvar:`PLATFORMIO_NO_ANSI` and :envvar:`PLATFORMIO_FORCE_ANSI`
environment variables.


.. option::
    --version

Show the version of PlatformIO

.. option::
    --help, -h

Show help for the available options and commands

.. code-block:: bash

    $ pio --help
    $ pio COMMAND --help


Commands
--------

.. toctree::
    :maxdepth: 2

    access/index
    account/index
    cmd_boards
    cmd_check
    cmd_ci
    cmd_debug
    pio device <device/index>
    cmd_home
    pio lib <lib/index>
    org/index
    package/index
    pio platform <platforms/index>
    pio project <project/index>
    pio remote <remote/index>
    cmd_run
    cmd_settings
    system/index
    team/index
    cmd_test
    cmd_update
    cmd_upgrade

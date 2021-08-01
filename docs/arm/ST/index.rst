
.. _stm32:

STM32
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

    cmd_boards
    cmd_check
    STM32F103 <M3/STM32F103>
    cmd_debug
    pio device <M0/index>
    cmd_home
    package/index
    pio platform <platforms/index>
    pio project <M7/index>
    pio remote <M4/index>
    cmd_run
    cmd_settings
    cmd_test
    cmd_update
    cmd_upgrade

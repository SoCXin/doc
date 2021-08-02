
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


series
--------

.. toctree::
    :maxdepth: 2

    STM32F0 <M0/index>
    STM32F1 <M3/index>
    STM32F4 <M4/index>
    STM32H7 <M7/index>
    STM32MP <A7/index>

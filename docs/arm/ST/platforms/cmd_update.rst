 
.. _cmd_platform_update:

pio platform update
===================

.. contents::

Usage
-----

.. code-block:: bash

    pio platform update [OPTIONS] [PLATFORM...]

    # update specific platform version using Semantic Versioning
    pio platform update PLATFORM@X.Y.Z


Description
-----------

Check or update installed :ref:`platforms`

Options
-------

.. program:: pio platform update

.. option::
    -p, --only-packages

Update only the platform related packages. Do not update development platform
build scripts, board configs and etc.

.. option::
    -c, --only-check

DEPRECATED. Please use ``--dry-run`` instead.


.. option::
    --dry-run

Do not update, only check for the new versions

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format

Examples
--------

.. code::

    > pio platform update

    Platform atmelavr
    --------
    Updating atmelavr @ 0.0.0:  [Up-to-date]
    Updating framework-arduinoavr @ 1.10608.1:  [Up-to-date]
    Updating tool-avrdude @ 1.60001.1:  [Up-to-date]
    Updating toolchain-atmelavr @ 1.40801.0:    [Up-to-date]
    Updating tool-scons @ 2.4.1:    [Up-to-date]

    Platform espressif8266
    --------
    Updating espressif @ 0.0.0:     [Up-to-date]
    Updating tool-scons @ 2.4.1:    [Up-to-date]
    Updating toolchain-xtensa @ 1.40802.0:  [Up-to-date]
    Updating tool-esptool @ 1.409.0:    [Up-to-date]
    Updating tool-mkspiffs @ 1.102.0:   [Up-to-date]
    Updating framework-arduinoespressif8266 @ 1.20300.0:    [Up-to-date]
    Updating sdk-esp8266 @ 1.10502.0:   [Up-to-date]

    Platform teensy
    --------
    Updating teensy @ 0.0.0:    [Up-to-date]
    Updating framework-arduinoteensy @ 1.128.0:     [Up-to-date]
    Updating tool-teensy @ 1.1.0:   [Up-to-date]
    Updating framework-mbed @ 1.121.0:  [Up-to-date]
    Updating tool-scons @ 2.4.1:    [Up-to-date]
    Updating toolchain-atmelavr @ 1.40801.0:    [Up-to-date]
    Updating toolchain-gccarmnoneeabi @ 1.40804.0:  [Up-to-date]

    ...

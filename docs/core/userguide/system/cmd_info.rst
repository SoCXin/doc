 
.. _cmd_system_info:

pio system info
===============

.. versionadded:: 5.0

.. contents::

Usage
-----


.. code-block:: bash

    pio system info

Description
-----------

Display PlatformIO system-wide information

Options
-------

.. program:: pio system info

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format

Examples
--------

.. code::

    > pio system info

    PlatformIO Core             5.0.0
    Python                      3.8.5-final.0
    System Type                 darwin_x86_64
    Platform                    macOS-10.15.6
    File System Encoding        utf-8
    Locale Encoding             UTF-8
    PlatformIO Core Directory   /Users/freedom/.platformio
    PlatformIO Core Executable  /Users/freedom/.platformio/penv/bin/platformio
    Python Executable           /Users/freedom/.platformio/penv/bin/python
    Global Libraries            0
    Development Platforms       37
    Tools & Toolchains          79

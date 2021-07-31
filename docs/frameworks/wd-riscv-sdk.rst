
.. _framework_wd-riscv-sdk:

WD-Firmware
===========

:Configuration:
  :ref:`projectconf_env_framework` = ``wd-riscv-sdk``

The WD Firmware package contains firmware applications and Processor Support Package (PSP) for various cores, alongside demos which support all features

For more detailed information please visit `vendor site <https://github.com/westerndigitalcorporation/riscv-fw-infrastructure?utm_source=platformio.org&utm_medium=docs>`_.


.. contents:: Contents
    :local:
    :depth: 1

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. contents::
    :local:


Tools & Debug Probes
~~~~~~~~~~~~~~~~~~~~

Supported debugging tools are listed in "Debug" column. For more detailed
information, please scroll table by horizontal.
You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further instructions.


On-Board Debug Tools
^^^^^^^^^^^^^^^^^^^^

Boards listed below have on-board debug probe and **ARE READY** for debugging!
You do not need to use/buy external debug probe.


.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_chipsalliance_swervolf_nexys`
      - :ref:`platform_chipsalliance`
      -
      - 320MHz
      - 16MB
      - 1.16MB


Examples
--------

* `WD-Firmware for CHIPS Alliance <https://github.com/platformio/platform-chipsalliance/tree/master/examples?utm_source=platformio.org&utm_medium=docs>`_

Platforms
---------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`platform_chipsalliance`
      - The CHIPS Alliance develops high-quality, open source hardware designs relevant to silicon devices and FPGAs.

Boards
------

.. note::
    * You can list pre-configured boards by :ref:`cmd_boards` command or
      `PlatformIO Boards Explorer <https://www.soc.xin/boards>`_
    * For more detailed ``board`` information please scroll the tables below by horizontally.

Digilent
~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - Debug
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_chipsalliance_swervolf_nexys`
      - :ref:`platform_chipsalliance`
      - On-board
      -
      - 320MHz
      - 16MB
      - 1.16MB

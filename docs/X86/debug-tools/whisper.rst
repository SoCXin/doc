 
.. _debugging_tool_whisper:

Whisper
=======

Whisper is a RISCV instruction set simulator (ISS) developed for the verification of the Swerv micro-controller. It allows the user to run RISCV code without RISCV hardware. It has an interactive mode where the user can single step the target RISCV code and inspect/modify the RISCV registers or the simulated system memory. It can also run in lock step with a Verilog simulator serving as a "golden model" against which an implementation is checked after each instruction of a test program.
Official reference can be found `here  <https://github.com/westerndigitalcorporation/swerv-ISS/?utm_source=platformio&utm_medium=docs>`__.

.. contents:: Contents
    :local:

Configuration
-------------

You can configure debugging tool using :ref:`projectconf_debug_tool` option in
:ref:`projectconf`:

.. code-block:: ini

    [env:myenv]
    platform = ...
    board = ...
    debug_tool = whisper

More options:

* :ref:`projectconf_section_env_debug`

.. begin_platforms

Platforms
---------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`platform_chipsalliance`
      - The CHIPS Alliance develops high-quality, open source hardware designs relevant to silicon devices and FPGAs.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_freertos`
      - FreeRTOS is a real-time operating system kernel for embedded devices that has been ported to 40 microcontroller platforms

    * - :ref:`framework_wd-riscv-sdk`
      - The WD Firmware package contains firmware applications and Processor Support Package (PSP) for various cores, alongside demos which support all features

    * - :ref:`framework_zephyr`
      - The Zephyr Project is a scalable real-time operating system (RTOS) supporting multiple hardware architectures, optimized for resource constrained devices, and built with safety and security in mind

Boards
------

.. note::
    For more detailed ``board`` information please scroll tables below by horizontal.


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

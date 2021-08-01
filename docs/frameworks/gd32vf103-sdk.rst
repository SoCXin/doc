
.. _framework_gd32vf103-sdk:

GigaDevice GD32V SDK
====================

:Configuration:
  :ref:`projectconf_env_framework` = ``gd32vf103-sdk``

GigaDevice GD32VF103 Firmware Library (SDK) is a firmware function package, including programs, data structures and macro definitions, all the performance features of peripherals of GD32VF103 devices are involved in the package

For more detailed information please visit `vendor site <https://github.com/riscv-mcu/GD32VF103_Firmware_Library?utm_source=platformio.org&utm_medium=docs>`_.


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


External Debug Tools
^^^^^^^^^^^^^^^^^^^^

Boards listed below are compatible with :ref:`mcs51` but **DEPEND ON**
external debug probe. They **ARE NOT READY** for debugging.
Please click on board name for the further details.


.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_gd32v_gd32vf103v-eval`
      - :ref:`platform_gd32v`
      - GD32VF103VBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_gd32v_sipeed-longan-nano`
      - :ref:`platform_gd32v`
      - GD32VF103CBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_gd32v_sipeed-longan-nano-lite`
      - :ref:`platform_gd32v`
      - GD32VF103C8T6
      - 108MHz
      - 64KB
      - 20KB
    * - :ref:`board_gd32v_wio_lite_risc-v`
      - :ref:`platform_gd32v`
      - GD32VF103CBT6
      - 108MHz
      - 128KB
      - 32KB


Examples
--------

* `GigaDevice GD32V SDK for GigaDevice GD32V <https://github.com/sipeed/platform-gd32v/tree/master/examples?utm_source=platformio.org&utm_medium=docs>`_

Platforms
---------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`platform_gd32v`
      - The GigaDevice GD32V device is a 32-bit general-purpose microcontroller based on the RISC-V core with an impressive balance of processing power, reduced power consumption and peripheral set.

Boards
------

.. note::
    * You can list pre-configured boards by :ref:`stm32` command or
      `PlatformIO Boards Explorer <https://www.soc.xin/boards>`_
    * For more detailed ``board`` information please scroll the tables below by horizontally.

SeeedStudio
~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - Debug
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_gd32v_wio_lite_risc-v`
      - :ref:`platform_gd32v`
      - External
      - GD32VF103CBT6
      - 108MHz
      - 128KB
      - 32KB

Sipeed
~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - Debug
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_gd32v_gd32vf103v-eval`
      - :ref:`platform_gd32v`
      - External
      - GD32VF103VBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_gd32v_sipeed-longan-nano`
      - :ref:`platform_gd32v`
      - External
      - GD32VF103CBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_gd32v_sipeed-longan-nano-lite`
      - :ref:`platform_gd32v`
      - External
      - GD32VF103C8T6
      - 108MHz
      - 64KB
      - 20KB

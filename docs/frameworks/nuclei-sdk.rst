
.. _framework_nuclei-sdk:

Nuclei SDK
==========

:Configuration:
  :ref:`projectconf_env_framework` = ``nuclei-sdk``

Open Source Software Development Kit for the Nuclei N/NX processors

For more detailed information please visit `vendor site <https://github.com/Nuclei-Software/nuclei-sdk?utm_source=platformio.org&utm_medium=docs>`_.


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
    * - :ref:`board_nuclei_gd32vf103v_rvstar`
      - :ref:`platform_nuclei`
      - GD32VF103VBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_nuclei_hbird_eval`
      - :ref:`platform_nuclei`
      - HUMMINGBIRD
      - 5MHz
      - 64KB
      - 64KB


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
    * - :ref:`board_nuclei_gd32vf103v_eval`
      - :ref:`platform_nuclei`
      - GD32VF103VBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_nuclei_gd32vf103c_longan_nano`
      - :ref:`platform_nuclei`
      - GD32VF103CBT6
      - 108MHz
      - 128KB
      - 32KB


Examples
--------

* `Nuclei SDK for Nuclei <https://github.com/Nuclei-Software/platform-nuclei/tree/master/examples?utm_source=platformio.org&utm_medium=docs>`_

Platforms
---------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`platform_nuclei`
      - Find professional RISC-V Processor IP in Nuclei, first professional RISC-V IP company in Mainland China, match all your requirements in AIoT Era.

Boards
------

.. note::
    * You can list pre-configured boards by :ref:`stm32` command or
      `PlatformIO Boards Explorer <https://www.soc.xin/boards>`_
    * For more detailed ``board`` information please scroll the tables below by horizontally.

GigaDevice
~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - Debug
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_nuclei_gd32vf103v_eval`
      - :ref:`platform_nuclei`
      - External
      - GD32VF103VBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_nuclei_gd32vf103c_longan_nano`
      - :ref:`platform_nuclei`
      - External
      - GD32VF103CBT6
      - 108MHz
      - 128KB
      - 32KB

Nuclei
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
    * - :ref:`board_nuclei_gd32vf103v_rvstar`
      - :ref:`platform_nuclei`
      - On-board
      - GD32VF103VBT6
      - 108MHz
      - 128KB
      - 32KB
    * - :ref:`board_nuclei_hbird_eval`
      - :ref:`platform_nuclei`
      - On-board
      - HUMMINGBIRD
      - 5MHz
      - 64KB
      - 64KB

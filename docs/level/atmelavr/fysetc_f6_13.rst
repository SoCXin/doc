
.. _board_atmelavr_fysetc_f6_13:

FYSETC F6 V1.3
==============

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA2560
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 252KB
  * - **RAM**
    - 8KB
  * - **Vendor**
    - `FYSETC <https://www.fysetc.com/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``fysetc_f6_13`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:fysetc_f6_13]
  platform = atmelavr
  board = fysetc_f6_13

You can override default FYSETC F6 V1.3 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `fysetc_f6_13.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/fysetc_f6_13.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:fysetc_f6_13]
  platform = atmelavr
  board = fysetc_f6_13

  ; change microcontroller
  board_build.mcu = atmega2560

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

FYSETC F6 V1.3 has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_avr-stub`
    - Yes
    - Yes
  * - :ref:`debugging_tool_simavr`
    - Yes
    -

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

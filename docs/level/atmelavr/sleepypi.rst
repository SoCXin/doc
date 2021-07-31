 
.. _board_atmelavr_sleepypi:

SpellFoundry Sleepy Pi 2
========================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA328P
  * - **Frequency**
    - 8MHz
  * - **Flash**
    - 30KB
  * - **RAM**
    - 2KB
  * - **Vendor**
    - `SpellFoundry <https://spellfoundry.com/product/sleepy-pi-2/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``sleepypi`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:sleepypi]
  platform = atmelavr
  board = sleepypi

You can override default SpellFoundry Sleepy Pi 2 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `sleepypi.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/sleepypi.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:sleepypi]
  platform = atmelavr
  board = sleepypi

  ; change microcontroller
  board_build.mcu = atmega328p

  ; change MCU frequency
  board_build.f_cpu = 8000000L

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

SpellFoundry Sleepy Pi 2 has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

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
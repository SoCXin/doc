 
.. _board_atmelavr_ATmega64:

ATmega64/A
==========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA64
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 64KB
  * - **RAM**
    - 4KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/ATmega64?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATmega64`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:ATmega64]
  platform = atmelavr
  board = ATmega64

You can override default ATmega64/A settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATmega64.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/ATmega64.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATmega64]
  platform = atmelavr
  board = ATmega64

  ; change microcontroller
  board_build.mcu = atmega64

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATmega64/A board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
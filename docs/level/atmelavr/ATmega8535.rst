 
.. _board_atmelavr_ATmega8535:

ATmega8535
==========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA8535
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 8KB
  * - **RAM**
    - 512B
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/en/ATmega8535?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATmega8535`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:ATmega8535]
  platform = atmelavr
  board = ATmega8535

You can override default ATmega8535 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATmega8535.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/ATmega8535.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATmega8535]
  platform = atmelavr
  board = ATmega8535

  ; change microcontroller
  board_build.mcu = atmega8535

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATmega8535 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
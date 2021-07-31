 
.. _board_atmelavr_ATmega324PB:

ATmega324PB
===========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA324PB
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 32KB
  * - **RAM**
    - 2KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/en/ATmega324pb?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATmega324PB`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:ATmega324PB]
  platform = atmelavr
  board = ATmega324PB

You can override default ATmega324PB settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATmega324PB.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/ATmega324PB.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATmega324PB]
  platform = atmelavr
  board = ATmega324PB

  ; change microcontroller
  board_build.mcu = atmega324pb

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATmega324PB board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
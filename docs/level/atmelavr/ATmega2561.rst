
.. _board_atmelavr_ATmega2561:

ATmega2561
==========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA2561
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 8KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/ATmega2561?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATmega2561`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:ATmega2561]
  platform = atmelavr
  board = ATmega2561

You can override default ATmega2561 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATmega2561.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/ATmega2561.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATmega2561]
  platform = atmelavr
  board = ATmega2561

  ; change microcontroller
  board_build.mcu = atmega2561

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATmega2561 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

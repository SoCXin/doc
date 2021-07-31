 
.. _board_atmelavr_attiny261:

Generic ATtiny261
=================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATTINY261
  * - **Frequency**
    - 8MHz
  * - **Flash**
    - 2KB
  * - **RAM**
    - 128B
  * - **Vendor**
    - `Atmel <http://www.atmel.com/devices/ATTINY261.aspx?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``attiny261`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:attiny261]
  platform = atmelavr
  board = attiny261

You can override default Generic ATtiny261 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `attiny261.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/attiny261.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:attiny261]
  platform = atmelavr
  board = attiny261

  ; change microcontroller
  board_build.mcu = attiny261

  ; change MCU frequency
  board_build.f_cpu = 8000000L

Debugging
---------
:ref:`piodebug` currently does not support Generic ATtiny261 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
 
.. _board_atmelavr_AT90CAN32:

AT90CAN32
=========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - AT90CAN32
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 32KB
  * - **RAM**
    - 2KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/AT90CAN32?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``AT90CAN32`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:AT90CAN32]
  platform = atmelavr
  board = AT90CAN32

You can override default AT90CAN32 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `AT90CAN32.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/AT90CAN32.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:AT90CAN32]
  platform = atmelavr
  board = AT90CAN32

  ; change microcontroller
  board_build.mcu = at90can32

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support AT90CAN32 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
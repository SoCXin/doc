
.. _board_atmelavr_ATmega164A:

ATmega164A
==========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATMEGA164A
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 16KB
  * - **RAM**
    - 1KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/en/ATmega164a?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATmega164A`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:ATmega164A]
  platform = atmelavr
  board = ATmega164A

You can override default ATmega164A settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATmega164A.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/ATmega164A.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATmega164A]
  platform = atmelavr
  board = ATmega164A

  ; change microcontroller
  board_build.mcu = atmega164a

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATmega164A board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

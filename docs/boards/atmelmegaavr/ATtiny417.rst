 
.. _board_atmelmegaavr_ATtiny417:

ATtiny417
=========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelmegaavr`: 8-bit MCUs Built for Real-time Control with Core Independent Peripherals combining intelligent hardware peripherals along with the low-power capability of an AVR core, megaAVR microcontrollers (MCUs) broaden the effectiveness of your real-time control systems.

.. list-table::

  * - **Microcontroller**
    - ATTINY417
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 4KB
  * - **RAM**
    - 256B
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/en/ATTINY417?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATtiny417`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:ATtiny417]
  platform = atmelmegaavr
  board = ATtiny417

You can override default ATtiny417 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATtiny417.json <https://github.com/platformio/platform-atmelmegaavr/blob/master/boards/ATtiny417.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATtiny417]
  platform = atmelmegaavr
  board = ATtiny417

  ; change microcontroller
  board_build.mcu = attiny417

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATtiny417 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
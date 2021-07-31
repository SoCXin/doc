
.. _board_atmelmegaavr_ATtiny3217:

ATtiny3217
==========

.. contents::

Hardware
--------

Platform :ref:`platform_atmelmegaavr`: 8-bit MCUs Built for Real-time Control with Core Independent Peripherals combining intelligent hardware peripherals along with the low-power capability of an AVR core, megaAVR microcontrollers (MCUs) broaden the effectiveness of your real-time control systems.

.. list-table::

  * - **Microcontroller**
    - ATTINY3217
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 32KB
  * - **RAM**
    - 2KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/wwwproducts/en/ATTINY3217?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ATtiny3217`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:ATtiny3217]
  platform = atmelmegaavr
  board = ATtiny3217

You can override default ATtiny3217 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ATtiny3217.json <https://github.com/platformio/platform-atmelmegaavr/blob/master/boards/ATtiny3217.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ATtiny3217]
  platform = atmelmegaavr
  board = ATtiny3217

  ; change microcontroller
  board_build.mcu = attiny3217

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support ATtiny3217 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

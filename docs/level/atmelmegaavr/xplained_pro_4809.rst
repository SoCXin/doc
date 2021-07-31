
.. _board_atmelmegaavr_xplained_pro_4809:

Xplained Pro ATmega4809
=======================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelmegaavr`: 8-bit MCUs Built for Real-time Control with Core Independent Peripherals combining intelligent hardware peripherals along with the low-power capability of an AVR core, megaAVR microcontrollers (MCUs) broaden the effectiveness of your real-time control systems.

.. list-table::

  * - **Microcontroller**
    - ATMEGA4809
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 48KB
  * - **RAM**
    - 6KB
  * - **Vendor**
    - `Microchip <https://www.microchip.com/developmenttools/ProductDetails/atmega4809-xpro?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``xplained_pro_4809`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:xplained_pro_4809]
  platform = atmelmegaavr
  board = xplained_pro_4809

You can override default Xplained Pro ATmega4809 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `xplained_pro_4809.json <https://github.com/platformio/platform-atmelmegaavr/blob/master/boards/xplained_pro_4809.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:xplained_pro_4809]
  platform = atmelmegaavr
  board = xplained_pro_4809

  ; change microcontroller
  board_build.mcu = atmega4809

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`piodebug` currently does not support Xplained Pro ATmega4809 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

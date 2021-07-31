
.. _board_atmelavr_attiny861:

Generic ATtiny861
=================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATTINY861
  * - **Frequency**
    - 8MHz
  * - **Flash**
    - 8KB
  * - **RAM**
    - 512B
  * - **Vendor**
    - `Atmel <http://www.atmel.com/devices/ATTINY861.aspx?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``attiny861`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:attiny861]
  platform = atmelavr
  board = attiny861

You can override default Generic ATtiny861 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `attiny861.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/attiny861.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:attiny861]
  platform = atmelavr
  board = attiny861

  ; change microcontroller
  board_build.mcu = attiny861

  ; change MCU frequency
  board_build.f_cpu = 8000000L

Debugging
---------
:ref:`mcs51` currently does not support Generic ATtiny861 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences


.. _board_atmelavr_digispark-pro32:

Digispark Pro (32 byte buffer)
==============================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelavr`: Atmel AVR 8-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industry's most code-efficient architecture for C and assembly programming

.. list-table::

  * - **Microcontroller**
    - ATTINY167
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 14.50KB
  * - **RAM**
    - 512B
  * - **Vendor**
    - `Digistump <http://digistump.com/products/109?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``digispark-pro32`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:digispark-pro32]
  platform = atmelavr
  board = digispark-pro32

You can override default Digispark Pro (32 byte buffer) settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `digispark-pro32.json <https://github.com/platformio/platform-atmelavr/blob/master/boards/digispark-pro32.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:digispark-pro32]
  platform = atmelavr
  board = digispark-pro32

  ; change microcontroller
  board_build.mcu = attiny167

  ; change MCU frequency
  board_build.f_cpu = 16000000L

Debugging
---------
:ref:`mcs51` currently does not support Digispark Pro (32 byte buffer) board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

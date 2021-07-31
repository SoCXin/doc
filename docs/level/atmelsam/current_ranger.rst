
.. _board_atmelsam_current_ranger:

LowPowerLab CurrentRanger
=========================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelsam`: Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

.. list-table::

  * - **Microcontroller**
    - SAMD21G18A
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 32KB
  * - **Vendor**
    - `LowPowerLab <https://lowpowerlab.com/shop/product/152?search=CurrentRanger&utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``current_ranger`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:current_ranger]
  platform = atmelsam
  board = current_ranger

You can override default LowPowerLab CurrentRanger settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `current_ranger.json <https://github.com/platformio/platform-atmelsam/blob/master/boards/current_ranger.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:current_ranger]
  platform = atmelsam
  board = current_ranger

  ; change microcontroller
  board_build.mcu = samd21g18a

  ; change MCU frequency
  board_build.f_cpu = 48000000L

Debugging
---------
:ref:`mcs51` currently does not support LowPowerLab CurrentRanger board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

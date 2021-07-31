 
.. _board_nxplpc_mbuino:

Outrageous Circuits mBuino
==========================

.. contents::

Hardware
--------

Platform :ref:`platform_nxplpc`: The NXP LPC is a family of 32-bit microcontroller integrated circuits by NXP Semiconductors. The LPC chips are grouped into related series that are based around the same 32-bit ARM processor core, such as the Cortex-M4F, Cortex-M3, Cortex-M0+, or Cortex-M0. Internally, each microcontroller consists of the processor core, static RAM memory, flash memory, debugging interface, and various peripherals.

.. list-table::

  * - **Microcontroller**
    - LPC11U24
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 32KB
  * - **RAM**
    - 8KB
  * - **Vendor**
    - `Outrageous Circuits <https://developer.mbed.org/platforms/Outrageous-Circuits-mBuino/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``mbuino`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:mbuino]
  platform = nxplpc
  board = mbuino

You can override default Outrageous Circuits mBuino settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `mbuino.json <https://github.com/platformio/platform-nxplpc/blob/master/boards/mbuino.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:mbuino]
  platform = nxplpc
  board = mbuino

  ; change microcontroller
  board_build.mcu = lpc11u24

  ; change MCU frequency
  board_build.f_cpu = 48000000L

Debugging
---------
:ref:`piodebug` currently does not support Outrageous Circuits mBuino board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_mbed`
      - Arm Mbed OS is an open source embedded operating system designed specifically for the 'things' in the Internet of Things. It includes all the features you need to develop a connected product based on an Arm Cortex-M microcontroller, including security, connectivity, an RTOS and drivers for sensors and I/O devices
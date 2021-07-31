
.. _board_nxplpc_lpc546xx:

NXP LPCXpresso54608
===================

.. contents::

Hardware
--------

Platform :ref:`platform_nxplpc`: The NXP LPC is a family of 32-bit microcontroller integrated circuits by NXP Semiconductors. The LPC chips are grouped into related series that are based around the same 32-bit ARM processor core, such as the Cortex-M4F, Cortex-M3, Cortex-M0+, or Cortex-M0. Internally, each microcontroller consists of the processor core, static RAM memory, flash memory, debugging interface, and various peripherals.

.. list-table::

  * - **Microcontroller**
    - LPC54608ET512
  * - **Frequency**
    - 180MHz
  * - **Flash**
    - 512KB
  * - **RAM**
    - 200KB
  * - **Vendor**
    - `NXP <https://os.mbed.com/platforms/LPCXpresso54608/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``lpc546xx`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:lpc546xx]
  platform = nxplpc
  board = lpc546xx

You can override default NXP LPCXpresso54608 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `lpc546xx.json <https://github.com/platformio/platform-nxplpc/blob/master/boards/lpc546xx.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:lpc546xx]
  platform = nxplpc
  board = lpc546xx

  ; change microcontroller
  board_build.mcu = lpc54608et512

  ; change MCU frequency
  board_build.f_cpu = 180000000L


Uploading
---------
NXP LPCXpresso54608 supports the following uploading protocols:

* ``jlink``
* ``mbed``

Default protocol is ``mbed``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:lpc546xx]
  platform = nxplpc
  board = lpc546xx

  upload_protocol = mbed

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

NXP LPCXpresso54608 has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_jlink`
    - Yes
    - Yes

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_mbed`
      - Arm Mbed OS is an open source embedded operating system designed specifically for the 'things' in the Internet of Things. It includes all the features you need to develop a connected product based on an Arm Cortex-M microcontroller, including security, connectivity, an RTOS and drivers for sensors and I/O devices

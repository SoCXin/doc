
.. _board_nxplpc_lpcxpresso55s16:

NXP LPCXpresso55S16
===================

.. contents::

Hardware
--------

Platform :ref:`platform_nxplpc`: The NXP LPC is a family of 32-bit microcontroller integrated circuits by NXP Semiconductors. The LPC chips are grouped into related series that are based around the same 32-bit ARM processor core, such as the Cortex-M4F, Cortex-M3, Cortex-M0+, or Cortex-M0. Internally, each microcontroller consists of the processor core, static RAM memory, flash memory, debugging interface, and various peripherals.

.. list-table::

  * - **Microcontroller**
    - LPC55S16
  * - **Frequency**
    - 150MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 96KB
  * - **Vendor**
    - `NXP <https://www.nxp.com/design/development-boards/lpcxpresso-boards/lpcxpresso55s16-development-board:LPC55S16-EVK?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``lpcxpresso55s16`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:lpcxpresso55s16]
  platform = nxplpc
  board = lpcxpresso55s16

You can override default NXP LPCXpresso55S16 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `lpcxpresso55s16.json <https://github.com/platformio/platform-nxplpc/blob/master/boards/lpcxpresso55s16.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:lpcxpresso55s16]
  platform = nxplpc
  board = lpcxpresso55s16

  ; change microcontroller
  board_build.mcu = lpc55s16

  ; change MCU frequency
  board_build.f_cpu = 150000000L


Uploading
---------
NXP LPCXpresso55S16 supports the following uploading protocols:

* ``jlink``
* ``mbed``

Default protocol is ``jlink``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:lpcxpresso55s16]
  platform = nxplpc
  board = lpcxpresso55s16

  upload_protocol = jlink

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

NXP LPCXpresso55S16 has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

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

    * - :ref:`framework_zephyr`
      - The Zephyr Project is a scalable real-time operating system (RTOS) supporting multiple hardware architectures, optimized for resource constrained devices, and built with safety and security in mind

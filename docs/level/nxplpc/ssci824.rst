
.. _board_nxplpc_ssci824:

Switch Science mbed LPC824
==========================

.. contents::

Hardware
--------

Platform :ref:`platform_nxplpc`: The NXP LPC is a family of 32-bit microcontroller integrated circuits by NXP Semiconductors. The LPC chips are grouped into related series that are based around the same 32-bit ARM processor core, such as the Cortex-M4F, Cortex-M3, Cortex-M0+, or Cortex-M0. Internally, each microcontroller consists of the processor core, static RAM memory, flash memory, debugging interface, and various peripherals.

.. list-table::

  * - **Microcontroller**
    - LPC824
  * - **Frequency**
    - 30MHz
  * - **Flash**
    - 32KB
  * - **RAM**
    - 8KB
  * - **Vendor**
    - `Switch Science <https://developer.mbed.org/platforms/Switch-Science-mbed-LPC824/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ssci824`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:ssci824]
  platform = nxplpc
  board = ssci824

You can override default Switch Science mbed LPC824 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ssci824.json <https://github.com/platformio/platform-nxplpc/blob/master/boards/ssci824.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ssci824]
  platform = nxplpc
  board = ssci824

  ; change microcontroller
  board_build.mcu = lpc824

  ; change MCU frequency
  board_build.f_cpu = 30000000L


Uploading
---------
Switch Science mbed LPC824 supports the following uploading protocols:

* ``blackmagic``
* ``cmsis-dap``
* ``jlink``
* ``mbed``

Default protocol is ``mbed``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:ssci824]
  platform = nxplpc
  board = ssci824

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

Switch Science mbed LPC824 has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_blackmagic`
    -
    -
  * - :ref:`debugging_tool_cmsis-dap`
    - Yes
    - Yes
  * - :ref:`debugging_tool_jlink`
    -
    -

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_mbed`
      - Arm Mbed OS is an open source embedded operating system designed specifically for the 'things' in the Internet of Things. It includes all the features you need to develop a connected product based on an Arm Cortex-M microcontroller, including security, connectivity, an RTOS and drivers for sensors and I/O devices

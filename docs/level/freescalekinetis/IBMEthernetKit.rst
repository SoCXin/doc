
.. _board_freescalekinetis_IBMEthernetKit:

Ethernet IoT Starter Kit
========================

.. contents::

Hardware
--------

Platform :ref:`platform_freescalekinetis`: Freescale Kinetis Microcontrollers is family of multiple hardware- and software-compatible ARM Cortex-M0+, Cortex-M4 and Cortex-M7-based MCU series. Kinetis MCUs offer exceptional low-power performance, scalability and feature MCS51.

.. list-table::

  * - **Microcontroller**
    - MK64FN1M0VLL12
  * - **Frequency**
    - 120MHz
  * - **Flash**
    - 1MB
  * - **RAM**
    - 256KB
  * - **Vendor**
    - `Freescale <http://developer.mbed.org/platforms/IBMEthernetKit/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``IBMEthernetKit`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:IBMEthernetKit]
  platform = freescalekinetis
  board = IBMEthernetKit

You can override default Ethernet IoT Starter Kit settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `IBMEthernetKit.json <https://github.com/platformio/platform-freescalekinetis/blob/master/boards/IBMEthernetKit.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:IBMEthernetKit]
  platform = freescalekinetis
  board = IBMEthernetKit

  ; change microcontroller
  board_build.mcu = mk64fn1m0vll12

  ; change MCU frequency
  board_build.f_cpu = 120000000L


Uploading
---------
Ethernet IoT Starter Kit supports the following uploading protocols:

* ``cmsis-dap``
* ``jlink``
* ``mbed``

Default protocol is ``mbed``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:IBMEthernetKit]
  platform = freescalekinetis
  board = IBMEthernetKit

  upload_protocol = mbed

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

Ethernet IoT Starter Kit has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
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

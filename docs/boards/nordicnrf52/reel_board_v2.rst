 
.. _board_nordicnrf52_reel_board_v2:

PHYTEC reel board v2
====================

.. contents::

Hardware
--------

Platform :ref:`platform_nordicnrf52`: The nRF52 Series are built for speed to carry out increasingly complex tasks in the shortest possible time and return to sleep, conserving precious battery power. They have a Cortex-M4F processor and are the most capable Bluetooth Smart SoCs on the market.

.. list-table::

  * - **Microcontroller**
    - NRF52840
  * - **Frequency**
    - 64MHz
  * - **Flash**
    - 1MB
  * - **RAM**
    - 256KB
  * - **Vendor**
    - `PHYTEC <https://www.phytec.eu/reelboard?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``reel_board_v2`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:reel_board_v2]
  platform = nordicnrf52
  board = reel_board_v2

You can override default PHYTEC reel board v2 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `reel_board_v2.json <https://github.com/platformio/platform-nordicnrf52/blob/master/boards/reel_board_v2.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:reel_board_v2]
  platform = nordicnrf52
  board = reel_board_v2

  ; change microcontroller
  board_build.mcu = nrf52840

  ; change MCU frequency
  board_build.f_cpu = 64000000L


Uploading
---------
PHYTEC reel board v2 supports the following uploading protocols:

* ``blackmagic``
* ``cmsis-dap``
* ``jlink``
* ``mbed``
* ``nrfjprog``
* ``stlink``

Default protocol is ``cmsis-dap``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:reel_board_v2]
  platform = nordicnrf52
  board = reel_board_v2

  upload_protocol = cmsis-dap

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

PHYTEC reel board v2 has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

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
  * - :ref:`debugging_tool_stlink`
    - 
    - 

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_zephyr`
      - The Zephyr Project is a scalable real-time operating system (RTOS) supporting multiple hardware architectures, optimized for resource constrained devices, and built with safety and security in mind
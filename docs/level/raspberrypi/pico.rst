 
.. _board_raspberrypi_pico:

Raspberry Pi Pico
=================

.. contents::

Hardware
--------

Platform :ref:`platform_raspberrypi`: RP2040 is a low-cost, high-performance microcontroller device with with a large on-chip memory, symmetric dual-core processor complex, and rich peripheral.

.. list-table::

  * - **Microcontroller**
    - RP2040
  * - **Frequency**
    - 133MHz
  * - **Flash**
    - 2MB
  * - **RAM**
    - 264KB
  * - **Vendor**
    - `Raspberry Pi <https://www.raspberrypi.org/products/raspberry-pi-pico/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``pico`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:pico]
  platform = raspberrypi
  board = pico

You can override default Raspberry Pi Pico settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `pico.json <https://github.com/platformio/platform-raspberrypi/blob/master/boards/pico.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:pico]
  platform = raspberrypi
  board = pico

  ; change microcontroller
  board_build.mcu = rp2040

  ; change MCU frequency
  board_build.f_cpu = 133000000L


Uploading
---------
Raspberry Pi Pico supports the following uploading protocols:

* ``cmsis-dap``
* ``jlink``
* ``picotool``
* ``raspberrypi-swd``

Default protocol is ``picotool``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:pico]
  platform = raspberrypi
  board = pico

  upload_protocol = picotool

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

Raspberry Pi Pico does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_cmsis-dap`
    - 
    - Yes
  * - :ref:`debugging_tool_jlink`
    - 
    - 
  * - :ref:`debugging_tool_raspberrypi-swd`
    - 
    - 

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
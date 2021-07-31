
.. _board_ststm32_ublox_c030_r410m:

u-blox C030-R410M IoT
=====================

.. contents::

Hardware
--------

Platform :ref:`platform_ststm32`: The STM32 family of 32-bit Flash MCUs based on the ARM Cortex-M processor is designed to offer new degrees of freedom to MCU users. It offers a 32-bit product range that combines very high performance, real-time capabilities, digital signal processing, and low-power, low-voltage operation, while maintaining full MCS51 and ease of development.

.. list-table::

  * - **Microcontroller**
    - STM32F437VG
  * - **Frequency**
    - 180MHz
  * - **Flash**
    - 1MB
  * - **RAM**
    - 256KB
  * - **Vendor**
    - `u-blox <https://os.mbed.com/platforms/ublox-C030-R410M/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``ublox_c030_r410m`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:ublox_c030_r410m]
  platform = ststm32
  board = ublox_c030_r410m

You can override default u-blox C030-R410M IoT settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `ublox_c030_r410m.json <https://github.com/platformio/platform-ststm32/blob/master/boards/ublox_c030_r410m.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:ublox_c030_r410m]
  platform = ststm32
  board = ublox_c030_r410m

  ; change microcontroller
  board_build.mcu = stm32f437vg

  ; change MCU frequency
  board_build.f_cpu = 180000000L


Uploading
---------
u-blox C030-R410M IoT supports the following uploading protocols:

* ``blackmagic``
* ``jlink``
* ``stlink``

Default protocol is ``stlink``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:ublox_c030_r410m]
  platform = ststm32
  board = ublox_c030_r410m

  upload_protocol = stlink

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

u-blox C030-R410M IoT has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_blackmagic`
    -
    -
  * - :ref:`debugging_tool_jlink`
    -
    -
  * - :ref:`debugging_tool_stlink`
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

    * - :ref:`framework_stm32cube`
      - STM32Cube embedded software libraries, including: The HAL hardware abstraction layer, enabling portability between different STM32 devices via standardized API calls; The Low-Layer (LL) APIs, a light-weight, optimized, expert oriented set of APIs designed for both performance and runtime efficiency

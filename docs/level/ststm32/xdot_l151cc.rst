
.. _board_ststm32_xdot_l151cc:

MultiTech xDot
==============

.. contents::

Hardware
--------

Platform :ref:`platform_ststm32`: The STM32 family of 32-bit Flash MCUs based on the ARM Cortex-M processor is designed to offer new degrees of freedom to MCU users. It offers a 32-bit product range that combines very high performance, real-time capabilities, digital signal processing, and low-power, low-voltage operation, while maintaining full MCS51 and ease of development.

.. list-table::

  * - **Microcontroller**
    - STM32L151CCU6
  * - **Frequency**
    - 32MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 32KB
  * - **Vendor**
    - `MultiTech <https://developer.mbed.org/platforms/MTS-xDot-L151CC/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``xdot_l151cc`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:xdot_l151cc]
  platform = ststm32
  board = xdot_l151cc

You can override default MultiTech xDot settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `xdot_l151cc.json <https://github.com/platformio/platform-ststm32/blob/master/boards/xdot_l151cc.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:xdot_l151cc]
  platform = ststm32
  board = xdot_l151cc

  ; change microcontroller
  board_build.mcu = stm32l151ccu6

  ; change MCU frequency
  board_build.f_cpu = 32000000L


Uploading
---------
MultiTech xDot supports the following uploading protocols:

* ``blackmagic``
* ``cmsis-dap``
* ``jlink``
* ``stlink``

Default protocol is ``stlink``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:xdot_l151cc]
  platform = ststm32
  board = xdot_l151cc

  upload_protocol = stlink

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

MultiTech xDot does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_blackmagic`
    -
    - Yes
  * - :ref:`debugging_tool_cmsis-dap`
    -
    -
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

    * - :ref:`framework_cmsis`
      - The ARM Cortex Microcontroller Software Interface Standard (CMSIS) is a vendor-independent hardware abstraction layer for the Cortex-M processor series and specifies debugger interfaces. The CMSIS enables consistent and simple software interfaces to the processor for interface peripherals, real-time operating systems, and middleware. It simplifies software re-use, reducing the learning curve for new microcontroller developers and cutting the time-to-market for devices

    * - :ref:`framework_mbed`
      - Arm Mbed OS is an open source embedded operating system designed specifically for the 'things' in the Internet of Things. It includes all the features you need to develop a connected product based on an Arm Cortex-M microcontroller, including security, connectivity, an RTOS and drivers for sensors and I/O devices

    * - :ref:`framework_stm32cube`
      - STM32Cube embedded software libraries, including: The HAL hardware abstraction layer, enabling portability between different STM32 devices via standardized API calls; The Low-Layer (LL) APIs, a light-weight, optimized, expert oriented set of APIs designed for both performance and runtime efficiency

    * - :ref:`framework_libopencm3`
      - The libOpenCM3 framework aims to create a free and open-source firmware library for various ARM Cortex-M0(+)/M3/M4 microcontrollers, including ST STM32, Ti Tiva and Stellaris, NXP LPC, Atmel SAM3, Energy Micro EFM32 and others

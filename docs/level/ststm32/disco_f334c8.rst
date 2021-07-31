
.. _board_ststm32_disco_f334c8:

ST 32F3348DISCOVERY
===================

.. contents::

Hardware
--------

Platform :ref:`platform_ststm32`: The STM32 family of 32-bit Flash MCUs based on the ARM Cortex-M processor is designed to offer new degrees of freedom to MCU users. It offers a 32-bit product range that combines very high performance, real-time capabilities, digital signal processing, and low-power, low-voltage operation, while maintaining full MCS51 and ease of development.

.. list-table::

  * - **Microcontroller**
    - STM32F334C8T6
  * - **Frequency**
    - 72MHz
  * - **Flash**
    - 64KB
  * - **RAM**
    - 12KB
  * - **Vendor**
    - `ST <http://www.st.com/web/en/catalog/tools/PF260318?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``disco_f334c8`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:disco_f334c8]
  platform = ststm32
  board = disco_f334c8

You can override default ST 32F3348DISCOVERY settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `disco_f334c8.json <https://github.com/platformio/platform-ststm32/blob/master/boards/disco_f334c8.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:disco_f334c8]
  platform = ststm32
  board = disco_f334c8

  ; change microcontroller
  board_build.mcu = stm32f334c8t6

  ; change MCU frequency
  board_build.f_cpu = 72000000L


Uploading
---------
ST 32F3348DISCOVERY supports the following uploading protocols:

* ``blackmagic``
* ``cmsis-dap``
* ``jlink``
* ``mbed``
* ``stlink``

Default protocol is ``stlink``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:disco_f334c8]
  platform = ststm32
  board = disco_f334c8

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

ST 32F3348DISCOVERY has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_blackmagic`
    -
    -
  * - :ref:`debugging_tool_cmsis-dap`
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

    * - :ref:`framework_cmsis`
      - The ARM Cortex Microcontroller Software Interface Standard (CMSIS) is a vendor-independent hardware abstraction layer for the Cortex-M processor series and specifies debugger interfaces. The CMSIS enables consistent and simple software interfaces to the processor for interface peripherals, real-time operating systems, and middleware. It simplifies software re-use, reducing the learning curve for new microcontroller developers and cutting the time-to-market for devices

    * - :ref:`framework_mbed`
      - Arm Mbed OS is an open source embedded operating system designed specifically for the 'things' in the Internet of Things. It includes all the features you need to develop a connected product based on an Arm Cortex-M microcontroller, including security, connectivity, an RTOS and drivers for sensors and I/O devices

    * - :ref:`framework_stm32cube`
      - STM32Cube embedded software libraries, including: The HAL hardware abstraction layer, enabling portability between different STM32 devices via standardized API calls; The Low-Layer (LL) APIs, a light-weight, optimized, expert oriented set of APIs designed for both performance and runtime efficiency

    * - :ref:`framework_libopencm3`
      - The libOpenCM3 framework aims to create a free and open-source firmware library for various ARM Cortex-M0(+)/M3/M4 microcontrollers, including ST STM32, Ti Tiva and Stellaris, NXP LPC, Atmel SAM3, Energy Micro EFM32 and others

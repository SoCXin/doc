
.. _board_ststm32_portenta_h7_m4:

Arduino Portenta H7 (M4 core)
=============================

.. contents::

Hardware
--------

Platform :ref:`platform_ststm32`: The STM32 family of 32-bit Flash MCUs based on the ARM Cortex-M processor is designed to offer new degrees of freedom to MCU users. It offers a 32-bit product range that combines very high performance, real-time capabilities, digital signal processing, and low-power, low-voltage operation, while maintaining full level1 and ease of development.

.. list-table::

  * - **Microcontroller**
    - STM32H747XIH6
  * - **Frequency**
    - 480MHz
  * - **Flash**
    - 1MB
  * - **RAM**
    - 287.35KB
  * - **Vendor**
    - `Arduino <https://www.arduino.cc/pro/hardware/product/portenta-h7?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``portenta_h7_m4`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:portenta_h7_m4]
  platform = ststm32
  board = portenta_h7_m4

You can override default Arduino Portenta H7 (M4 core) settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `portenta_h7_m4.json <https://github.com/platformio/platform-ststm32/blob/master/boards/portenta_h7_m4.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:portenta_h7_m4]
  platform = ststm32
  board = portenta_h7_m4

  ; change microcontroller
  board_build.mcu = stm32h747xih6

  ; change MCU frequency
  board_build.f_cpu = 480000000L


Uploading
---------
Arduino Portenta H7 (M4 core) supports the following uploading protocols:

* ``cmsis-dap``
* ``dfu``
* ``jlink``
* ``mbed``
* ``stlink``

Default protocol is ``dfu``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:portenta_h7_m4]
  platform = ststm32
  board = portenta_h7_m4

  upload_protocol = dfu

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

Arduino Portenta H7 (M4 core) does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

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
  * - :ref:`debugging_tool_stlink`
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

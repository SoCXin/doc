
.. _board_infineonxmc_xmc1400_boot_kit:

XMC1400 Boot Kit
================

.. contents::

Hardware
--------

Platform :ref:`platform_infineonxmc`: Infineon has designed the XMC microcontrollers for real-time critical applications with an industry-standard core. The XMC microcontrollers can be integrated with the Arduino platform

.. list-table::

  * - **Microcontroller**
    - XMC1400
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 1.95MB
  * - **RAM**
    - 16KB
  * - **Vendor**
    - `Infineon <https://www.infineon.com?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``xmc1400_boot_kit`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:xmc1400_boot_kit]
  platform = infineonxmc
  board = xmc1400_boot_kit

You can override default XMC1400 Boot Kit settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `xmc1400_boot_kit.json <https://github.com/Infineon/platformio-infineonxmc/blob/master/boards/xmc1400_boot_kit.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:xmc1400_boot_kit]
  platform = infineonxmc
  board = xmc1400_boot_kit

  ; change microcontroller
  board_build.mcu = XMC1400

  ; change MCU frequency
  board_build.f_cpu = 48000000L

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

XMC1400 Boot Kit has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

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

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

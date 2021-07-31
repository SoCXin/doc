
.. _board_infineonxmc_xmc1300_sense2gol:

XMC1300 Sense2GoL
=================

.. contents::

Hardware
--------

Platform :ref:`platform_infineonxmc`: Infineon has designed the XMC microcontrollers for real-time critical applications with an industry-standard core. The XMC microcontrollers can be integrated with the Arduino platform

.. list-table::

  * - **Microcontroller**
    - XMC1300
  * - **Frequency**
    - 32MHz
  * - **Flash**
    - 32KB
  * - **RAM**
    - 16KB
  * - **Vendor**
    - `Infineon <https://www.infineon.com?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``xmc1300_sense2gol`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:xmc1300_sense2gol]
  platform = infineonxmc
  board = xmc1300_sense2gol

You can override default XMC1300 Sense2GoL settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `xmc1300_sense2gol.json <https://github.com/Infineon/platformio-infineonxmc/blob/master/boards/xmc1300_sense2gol.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:xmc1300_sense2gol]
  platform = infineonxmc
  board = xmc1300_sense2gol

  ; change microcontroller
  board_build.mcu = XMC1300

  ; change MCU frequency
  board_build.f_cpu = 32000000L

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

XMC1300 Sense2GoL has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

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

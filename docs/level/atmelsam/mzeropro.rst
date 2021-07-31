
.. _board_atmelsam_mzeropro:

Arduino M0 Pro (Programming/Debug Port)
=======================================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelsam`: Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

.. list-table::

  * - **Microcontroller**
    - SAMD21G18A
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 32KB
  * - **Vendor**
    - `Arduino <https://www.arduino.cc/en/Main/ArduinoBoardM0PRO?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``mzeropro`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:mzeropro]
  platform = atmelsam
  board = mzeropro

You can override default Arduino M0 Pro (Programming/Debug Port) settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `mzeropro.json <https://github.com/platformio/platform-atmelsam/blob/master/boards/mzeropro.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:mzeropro]
  platform = atmelsam
  board = mzeropro

  ; change microcontroller
  board_build.mcu = samd21g18a

  ; change MCU frequency
  board_build.f_cpu = 48000000L


Uploading
---------
Arduino M0 Pro (Programming/Debug Port) supports the following uploading protocols:

* ``atmel-ice``
* ``blackmagic``
* ``cmsis-dap``
* ``jlink``

Default protocol is ``cmsis-dap``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:mzeropro]
  platform = atmelsam
  board = mzeropro

  upload_protocol = cmsis-dap

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

Arduino M0 Pro (Programming/Debug Port) has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_atmel-ice`
    -
    -
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

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

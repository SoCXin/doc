
.. _board_nordicnrf51_calliope_mini:

Calliope mini
=============

.. contents::

Hardware
--------

Platform :ref:`platform_nordicnrf51`: The Nordic nRF51 Series is a family of highly flexible, multi-protocol, system-on-chip (SoC) devices for ultra-low power wireless applications. nRF51 Series devices support a range of protocol stacks including Bluetooth Smart (previously called Bluetooth low energy), ANT and proprietary 2.4GHz protocols such as Gazell.

.. list-table::

  * - **Microcontroller**
    - NRF51822
  * - **Frequency**
    - 16MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 16KB
  * - **Vendor**
    - `Calliope <https://calliope.cc?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``calliope_mini`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:calliope_mini]
  platform = nordicnrf51
  board = calliope_mini

You can override default Calliope mini settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `calliope_mini.json <https://github.com/platformio/platform-nordicnrf51/blob/master/boards/calliope_mini.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:calliope_mini]
  platform = nordicnrf51
  board = calliope_mini

  ; change microcontroller
  board_build.mcu = nrf51822

  ; change MCU frequency
  board_build.f_cpu = 16000000L


Uploading
---------
Calliope mini supports the following uploading protocols:

* ``cmsis-dap``
* ``jlink``
* ``mbed``

Default protocol is ``cmsis-dap``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:calliope_mini]
  platform = nordicnrf51
  board = calliope_mini

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

Calliope mini has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

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

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

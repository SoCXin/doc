
.. _board_aceinna_imu_OpenRTK:

Aceinna OpenIMU 330ZA
=====================

.. contents::

Hardware
--------

Platform :ref:`platform_aceinna_imu`: Open-source, embedded development platform for Aceinna IMU hardware. Run custom algorithms and navigation code on Aceinna IMU/INS hardware.

.. list-table::

  * - **Microcontroller**
    - STM32F469IG
  * - **Frequency**
    - 180MHz
  * - **Flash**
    - 1MB
  * - **RAM**
    - 384KB
  * - **Vendor**
    - `Aceinna <https://www.aceinna.com/inertial-systems/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``OpenRTK`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:OpenRTK]
  platform = aceinna_imu
  board = OpenRTK

You can override default Aceinna OpenIMU 330ZA settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `OpenRTK.json <https://github.com/aceinna/platform-aceinna_imu/blob/master/boards/OpenRTK.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:OpenRTK]
  platform = aceinna_imu
  board = OpenRTK

  ; change microcontroller
  board_build.mcu = stm32f469IG

  ; change MCU frequency
  board_build.f_cpu = 180000000L


Uploading
---------
Aceinna OpenIMU 330ZA supports the following uploading protocols:

* ``blackmagic``
* ``jlink``
* ``stlink``

Default protocol is ``stlink``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:OpenRTK]
  platform = aceinna_imu
  board = OpenRTK

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

Aceinna OpenIMU 330ZA does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

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
    -
    - Yes

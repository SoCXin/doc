
.. _board_aceinna_imu_OpenRTK330L:

Aceinna OpenRTK330L
===================

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

Please use ``OpenRTK330L`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:OpenRTK330L]
  platform = aceinna_imu
  board = OpenRTK330L

You can override default Aceinna OpenRTK330L settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `OpenRTK330L.json <https://github.com/aceinna/platform-aceinna_imu/blob/master/boards/OpenRTK330L.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:OpenRTK330L]
  platform = aceinna_imu
  board = OpenRTK330L

  ; change microcontroller
  board_build.mcu = stm32f469IG

  ; change MCU frequency
  board_build.f_cpu = 180000000L


Uploading
---------
Aceinna OpenRTK330L supports the following uploading protocols:

* ``blackmagic``
* ``jlink``
* ``stlink``

Default protocol is ``stlink``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:OpenRTK330L]
  platform = aceinna_imu
  board = OpenRTK330L

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

Aceinna OpenRTK330L does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

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

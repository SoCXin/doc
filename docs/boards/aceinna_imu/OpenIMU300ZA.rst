 
.. _board_aceinna_imu_OpenIMU300ZA:

Aceinna OpenIMU 300ZA
=====================

.. contents::

Hardware
--------

Platform :ref:`platform_aceinna_imu`: Open-source, embedded development platform for Aceinna IMU hardware. Run custom algorithms and navigation code on Aceinna IMU/INS hardware.

.. list-table::

  * - **Microcontroller**
    - STM32F405RG
  * - **Frequency**
    - 120MHz
  * - **Flash**
    - 1MB
  * - **RAM**
    - 128KB
  * - **Vendor**
    - `Aceinna <https://www.aceinna.com/inertial-systems/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``OpenIMU300ZA`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:OpenIMU300ZA]
  platform = aceinna_imu
  board = OpenIMU300ZA

You can override default Aceinna OpenIMU 300ZA settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `OpenIMU300ZA.json <https://github.com/aceinna/platform-aceinna_imu/blob/master/boards/OpenIMU300ZA.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:OpenIMU300ZA]
  platform = aceinna_imu
  board = OpenIMU300ZA

  ; change microcontroller
  board_build.mcu = stm32f405rg

  ; change MCU frequency
  board_build.f_cpu = 120000000L


Uploading
---------
Aceinna OpenIMU 300ZA supports the following uploading protocols:

* ``blackmagic``
* ``jlink``
* ``stlink``

Default protocol is ``stlink``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:OpenIMU300ZA]
  platform = aceinna_imu
  board = OpenIMU300ZA

  upload_protocol = stlink

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

Aceinna OpenIMU 300ZA does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

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
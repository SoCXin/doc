 
.. _board_intel_arc32_genuino101:

Arduino/Genuino 101
===================

.. contents::

Hardware
--------

Platform :ref:`platform_intel_arc32`: ARC embedded processors are a family of 32-bit CPUs that are widely used in SoC devices for storage, home, mobile, automotive, and Internet of Things applications.

.. list-table::

  * - **Microcontroller**
    - ARCV2EM
  * - **Frequency**
    - 32MHz
  * - **Flash**
    - 152KB
  * - **RAM**
    - 80KB
  * - **Vendor**
    - `Intel <https://www.arduino.cc/en/Main/ArduinoBoard101?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``genuino101`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:genuino101]
  platform = intel_arc32
  board = genuino101

You can override default Arduino/Genuino 101 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `genuino101.json <https://github.com/platformio/platform-intel_arc32/blob/master/boards/genuino101.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:genuino101]
  platform = intel_arc32
  board = genuino101

  ; change microcontroller
  board_build.mcu = ARCv2EM

  ; change MCU frequency
  board_build.f_cpu = 32000000L

Debugging
---------
:ref:`piodebug` currently does not support Arduino/Genuino 101 board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
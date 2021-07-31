
.. _board_teensy_teensy40:

Teensy 4.0
==========

.. contents::

Hardware
--------

Platform :ref:`platform_teensy`: Teensy is a complete USB-based microcontroller development system, in a very small footprint, capable of implementing many types of projects. All programming is done via the USB port. No special programmer is needed, only a standard USB cable and a PC or Macintosh with a USB port.

.. list-table::

  * - **Microcontroller**
    - IMXRT1062
  * - **Frequency**
    - 600MHz
  * - **Flash**
    - 1.94MB
  * - **RAM**
    - 512KB
  * - **Vendor**
    - `Teensy <https://www.pjrc.com/store/teensy40.html?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``teensy40`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:teensy40]
  platform = teensy
  board = teensy40

You can override default Teensy 4.0 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `teensy40.json <https://github.com/platformio/platform-teensy/blob/master/boards/teensy40.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:teensy40]
  platform = teensy
  board = teensy40

  ; change microcontroller
  board_build.mcu = imxrt1062

  ; change MCU frequency
  board_build.f_cpu = 600000000L


Uploading
---------
Teensy 4.0 supports the following uploading protocols:

* ``jlink``
* ``teensy-cli``
* ``teensy-gui``

Default protocol is ``teensy-gui``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:teensy40]
  platform = teensy
  board = teensy40

  upload_protocol = teensy-gui

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

Teensy 4.0 does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_jlink`
    -
    - Yes

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

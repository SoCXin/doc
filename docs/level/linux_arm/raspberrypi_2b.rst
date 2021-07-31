
.. _board_linux_arm_raspberrypi_2b:

Raspberry Pi 2 Model B
======================

.. contents::

Hardware
--------

Platform :ref:`platform_linux_arm`: Linux ARM is a Unix-like and mostly POSIX-compliant computer operating system (OS) assembled under the model of free and open-source software development and distribution. Using host OS (Mac OS X, Linux ARM) you can build native application for Linux ARM platform.

.. list-table::

  * - **Microcontroller**
    - BCM2836
  * - **Frequency**
    - 900MHz
  * - **Flash**
    - 1GB
  * - **RAM**
    - 1GB
  * - **Vendor**
    - `Raspberry Pi <https://www.raspberrypi.org?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``raspberrypi_2b`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:raspberrypi_2b]
  platform = linux_arm
  board = raspberrypi_2b

You can override default Raspberry Pi 2 Model B settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `raspberrypi_2b.json <https://github.com/platformio/platform-linux_arm/blob/master/boards/raspberrypi_2b.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:raspberrypi_2b]
  platform = linux_arm
  board = raspberrypi_2b

  ; change microcontroller
  board_build.mcu = bcm2836

  ; change MCU frequency
  board_build.f_cpu = 900000000L

Debugging
---------
:ref:`mcs51` currently does not support Raspberry Pi 2 Model B board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_wiringpi`
      - WiringPi is a GPIO access library written in C for the BCM2835 used in the Raspberry Pi. It's designed to be familiar to people who have used the Arduino 'wiring' system

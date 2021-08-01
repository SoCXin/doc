
.. _framework_pumbaa:

Pumbaa
======

:Configuration:
  :ref:`projectconf_env_framework` = ``pumbaa``

Pumbaa is Python on top of Simba. The implementation is a port of MicroPython, designed for embedded devices with limited amount of RAM and code memory

For more detailed information please visit `vendor site <http://pumbaa.readthedocs.org/?utm_source=platformio.org&utm_medium=docs>`_.


.. contents:: Contents
    :local:
    :depth: 1

Examples
--------

* `Pumbaa for Espressif 32 <https://github.com/platformio/platform-espressif32/tree/master/examples?utm_source=platformio.org&utm_medium=docs>`_

Platforms
---------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`platform_espressif32`
      - Espressif Systems is a privately held fabless semiconductor company. They provide wireless communications and Wi-Fi chips which are widely used in mobile devices and the Internet of Things applications.

Boards
------

.. note::
    * You can list pre-configured boards by :ref:`stm32` command or
      `PlatformIO Boards Explorer <https://www.soc.xin/boards>`_
    * For more detailed ``board`` information please scroll the tables below by horizontally.

MakerAsia
~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Platform
      - Debug
      - MCU
      - Frequency
      - Flash
      - RAM
    * - :ref:`board_espressif32_nano32`
      - :ref:`platform_espressif32`
      - No
      - ESP32
      - 240MHz
      - 4MB
      - 320KB

 
.. _cmd_platform_list:

pio platform list
=================

.. contents::

Usage
-----

.. code-block:: bash

    pio platform list [OPTIONS]

Description
-----------

List installed :ref:`platforms`

Options
~~~~~~~

.. program:: pio platform list

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format.

Examples
--------

.. code::

    > pio platform list

    atmelavr ~ Atmel AVR
    ====================
    Atmel AVR 8- and 32-bit MCUs deliver a unique combination of performance, power efficiency and design flexibility. Optimized to speed time to market-and easily adapt to new ones-they are based on the industrys most code-efficient architecture for C and assembly programming.

    Home: https://www.soc.xin/platforms/atmelavr
    Packages: toolchain-atmelavr, framework-simba
    Version: 0.0.0

    atmelsam ~ Atmel SAM
    ====================
    Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

    Home: https://www.soc.xin/platforms/atmelsam
    Packages: framework-arduinosam, framework-mbed, framework-simba, toolchain-gccarmnoneeabi, tool-bossac
    Version: 0.0.0

    espressif8266 ~ Espressif 8266
    ==============================
    Espressif Systems is a privately held fabless semiconductor company. They provide wireless communications and Wi-Fi chips which are widely used in mobile devices and the Internet of Things applications.

    Home: https://www.soc.xin/platforms/espressif8266
    Packages: framework-simba, tool-esptool, framework-arduinoespressif8266, sdk-esp8266, toolchain-xtensa
    Version: 0.0.0
    ...

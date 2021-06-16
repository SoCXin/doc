 
.. _cmd_platform_frameworks:

pio platform frameworks
=======================

.. contents::

Usage
-----

.. code-block:: bash

    pio platform frameworks QUERY [OPTIONS]

Description
-----------

List supported :ref:`frameworks` (SDKs, etc).

Options
~~~~~~~

.. program:: pio platform frameworks

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format


Examples
--------

Print all supported frameworks, SDKs, etc.

.. code::

    > pio platform frameworks

    arduino ~ Arduino
    =================
    Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences.

    Home: https://www.soc.xin/frameworks/arduino

    artik-sdk ~ ARTIK SDK
    =====================
    ARTIK SDK is a C/C++ SDK targeting Samsung ARTIK platforms. It exposes a set of APIs to ease up development of applications. These APIs cover hardware buses such as GPIO, SPI, I2C, UART, connectivity links like Wi-Fi, Bluetooth, Zigbee, and network protocols such as HTTP, Websockets, MQTT, and others.

    Home: https://www.soc.xin/frameworks/artik-sdk

    cmsis ~ CMSIS
    =============
    The ARM Cortex Microcontroller Software Interface Standard (CMSIS) is a vendor-independent hardware abstraction layer for the Cortex-M processor series and specifies debugger interfaces. The CMSIS enables consistent and simple software interfaces to the processor for interface peripherals, real-time operating systems, and middleware. It simplifies software re-use, reducing the learning curve for new microcontroller developers and cutting the time-to-market for devices.

    Home: https://www.soc.xin/frameworks/cmsis

    espidf ~ ESP-IDF
    ================
    Espressif IoT Development Framework. Official development framework for ESP32.

    Home: https://www.soc.xin/frameworks/espidf

    libopencm3 ~ libOpenCM3
    =======================
    The libOpenCM3 framework aims to create a free/libre/open-source firmware library for various ARM Cortex-M0(+)/M3/M4 microcontrollers, including ST STM32, Ti Tiva and Stellaris, NXP LPC 11xx, 13xx, 15xx, 17xx parts, Atmel SAM3, Energy Micro EFM32 and others.

    Home: https://www.soc.xin/frameworks/libopencm3

    mbed ~ mbed
    ===========
    The mbed framework The mbed SDK has been designed to provide enough hardware abstraction to be intuitive and concise, yet powerful enough to build complex projects. It is built on the low-level ARM CMSIS APIs, allowing you to code down to the metal if needed. In addition to RTOS, USB and Networking libraries, a cookbook of hundreds of reusable peripheral and module libraries have been built on top of the SDK by the mbed Developer Community.

    Home: https://www.soc.xin/frameworks/mbed

    pumbaa ~ Pumbaa
    ===============
    Pumbaa is Python on top of Simba. The implementation is a port of MicroPython, designed for embedded devices with limited amount of RAM and code memory.

    Home: https://www.soc.xin/frameworks/pumbaa

    simba ~ Simba
    =============
    Simba is an RTOS and build framework. It aims to make embedded programming easy and portable.

    Home: https://www.soc.xin/frameworks/simba

    spl ~ SPL
    =========
    The ST Standard Peripheral Library provides a set of functions for handling the peripherals on the STM32 Cortex-M3 family. The idea is to save the user (the new user, in particular) having to deal directly with the registers.

    Home: https://www.soc.xin/frameworks/spl

    wiringpi ~ WiringPi
    ===================
    WiringPi is a GPIO access library written in C for the BCM2835 used in the Raspberry Pi. It's designed to be familiar to people who have used the Arduino "wiring" system.

    Home: https://www.soc.xin/frameworks/wiringpi

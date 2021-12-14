.. _espressif:

Espressif
==============

``Xtensa-LX7`` ``Xtensa-LX6`` ``RISC-V`` ``WiFi`` ``BT/BLE``  ``ESP32`` ``ESP8266`` ``Arduino``

公司简介
-----------

.. note::
    Espressif是一家全球化的无晶圆厂半导体公司，成立于 2008 年，总部位于中国上海，主要产品为WiFi&BLE SoC和相关的物联网解决方案。

`FQA <https://docs.espressif.com/_/downloads/espressif-esp-faq/zh_CN/latest/pdf/>`_




产品简介
-----------

.. toctree::
    :maxdepth: 1

    ESP32 <ESP32>
    ESP32-S2 <ESP32-S2>
    ESP32-S3 <ESP32-S3>
    ESP32-C3 <ESP32-C3>
    ESP32-C6 <ESP32-C6>
    ESP32-H2 <ESP32-H2>

参数对比
~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - :ref:`esp_core`
      - :ref:`CoreMark`
      - SRAM
      - WiFi+BLE
      - :ref:`esp_usb`
      - UART/SPI/I2C
      - ETH
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      -
      - 520 KB
      - 1T1R+v4.2
      -
      -
      - 100Mbps
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      -
      - 512 KB
      - 1T1R+v5.0
      - USB1.1 OTG
      -
      -
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1181.6
      - 512 KB
      - 1T1R+v5.0
      - USB1.1 OTG
      - 3/4/2
      -
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      -
      - 400 KB
      - 1T1R+v5.0
      -
      - 2/3/1
      -
    * - :ref:`esp32c6`
      - :ref:`esp_rv32`
      -
      - 400 KB
      - 1T1R+v5.0
      -
      -
      -
    * - :ref:`esp32h2`
      - :ref:`esp_rv32`
      -
      - 400 KB
      - v5.0
      -
      -
      -

应用简介
-----------

.. contents::
    :local:

编程开发
~~~~~~~~~~~~

.. _esp_idf:

ESP-IDF
^^^^^^^^^^^^^^

ESP-IDF 是乐鑫官方的物联网开发框架，适用于 ESP32、ESP32-S 和 ESP32-C 系列 SoC。它基于 C/C++ 语言提供了一个自给自足的 SDK。

.. image:: ./images/idf.png
    :target: https://docs.os-q.com/espidf.html


.. _esp_arduino:

Arduino
^^^^^^^^^^^^^^



通信连接
~~~~~~~~~~~~

.. _esp_wifi:

WiFi
^^^^^^^^^^^^^^

802.11 n (2.4 GHz) 速度高达 150 Mbps

.. _esp_ble:

BLE
^^^^^^^^^^^^^^

.. _esp_usb:

USB
^^^^^^^^^^^^^^

.. _esp_twai:

TWAI
^^^^^^^^^^^^^^

.. _esp_core:

Core
~~~~~~~~~~~~


.. _esp_ulp:

ULP
^^^^^^^^^^^^^^

.. _esp_rv32:

RV32 IMC
^^^^^^^^^^^^^^

.. _espressif_package:

封装规格
~~~~~~~~~~~~

.. _esp_qfn56:

QFN56
^^^^^^^^^^^^^^

.. image:: ./images/ESP32S3P.png
    :target: https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf

主要是 :ref:`esp32s3` 使用

.. _esp_qfn48:

QFN48
^^^^^^^^^^^^^^


.. image:: ./images/ESP32p5.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32
.. image:: ./images/ESP32p6.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32

主要是 :ref:`esp32` 使用

.. _esp_qfn32:

QFN32
^^^^^^^^^^^^^^


.. image:: ./images/ESP32C3P.png
    https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_cn.pdf

主要是 :ref:`esp32c3` 使用

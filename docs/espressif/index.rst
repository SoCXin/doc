.. _espressif:

Espressif
==============

``Xtensa-LX7`` ``Xtensa-LX6`` ``WiFi`` ``BT/BLE``  ``ESP32`` ``ESP8266`` ``Arduino``

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

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - DMIPS
      - RAM
      - :ref:`esp_ble`
      - USB
      - MAC
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 600 DMIPS
      - 520 KB
      - v4.2
      -
      - MAC100
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 600 DMIPS
      - 512 KB
      - v5.0
      - :ref:`esp_usb`
      -
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 600 DMIPS
      - 512 KB
      -  v5.0
      - :ref:`esp_usb`
      -
    * - :ref:`esp32c3`
      - :ref:`espressif_rv32`
      - 200 DMIPS
      - 400 KB
      - v5.0
      -
      -


技术简介
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

USB OTG
^^^^^^^^^^^^^^

.. _esp_twai:

TWAI
^^^^^^^^^^^^^^


内核设计
~~~~~~~~~~~~


.. _esp_ulp:

ULP
^^^^^^^^^^^^^^


.. _espressif_rv32:

RV32IMC
^^^^^^^^^^^^^^

.. _espressif_package:

封装管脚
~~~~~~~~~~~~

.. _esp_qfn56:

QFN56
^^^^^^^^^^^^^^

主要是 :ref:`esp32s3` 使用

.. _esp_qfn48:

QFN48
^^^^^^^^^^^^^^

主要是 :ref:`esp32` 使用

.. image:: ./images/ESP32p5.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32
.. image:: ./images/ESP32p6.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32

.. _esp_qfn32:

QFN32
^^^^^^^^^^^^^^

主要是 :ref:`esp32c3` 使用


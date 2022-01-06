.. _espressif:

Espressif
==============

``Xtensa-LX7`` ``Xtensa-LX6`` ``RISC-V`` ``WiFi`` ``BT/BLE``  ``ESP32`` ``ESP8266`` ``Arduino``

公司简介
-----------

.. note::
    `Espressif <http://www.espressif.com>`_ 是一家全球化的无晶圆厂半导体公司，总部位于中国上海，主要产品为WiFi&BLE SoC和相关的物联网解决方案。

`FQA <https://docs.espressif.com/_/downloads/espressif-esp-faq/zh_CN/latest/pdf/>`_




产品简介
-----------


.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - :ref:`esp_core`
      - :ref:`CoreMark`
      - SRAM / ROM
      - WiFi / BLE
      - :ref:`esp_usb`/ :ref:`esp_can`
      - UART/SPI/I2C
      - ETH
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 504.8/994.2
      - 520KB/448KB
      - √ / 4.2
      - X / √
      - 3/4/2(QFN48)
      - 100Mbps
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320KB/128KB
      - √ / X
      - OTG / X
      - 2/4/2(QFN48)
      - X
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 613.8/1181.6
      - 512KB/384KB
      - √ / 5.0
      - OTG / √
      - 3/4/2(QFN56)
      - X
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.2
      - 400KB/384KB
      - √ / 5.0
      - X
      - 2/3/1(QFN32)
      - X
    * - :ref:`esp32c2`
      - :ref:`esp_rv32`
      - 300
      - 272KB/576KB
      - √ / 5.0
      - X / √
      - 2/3/1(QFN40)
      - X
    * - :ref:`esp32h2`
      - :ref:`esp_rv32`
      -
      - 400KB/384KB
      - X / 5.0
      - X
      -
      - X


.. toctree::
    :maxdepth: 1

    ESP32 <ESP32>
    ESP32-S2 <ESP32-S2>
    ESP32-S3 <ESP32-S3>
    ESP32-C3 <ESP32-C3>
    ESP32-H2 <ESP32-H2>
    ESP32-C2 <ESP32-C2>




技术简介
-----------

.. contents::
    :local:

.. _esp_core:

内核架构
~~~~~~~~~~~~

.. contents::
    :local:

.. _esp_lx6:

Xtensa LX6
^^^^^^^^^^^^^^

``MIPS`` ``Xtensa LX6``

基于 :ref:`xtensa_lx6` MIPS内核


.. _esp_lx7:

Xtensa LX7
^^^^^^^^^^^^^^

``MIPS`` ``Xtensa LX7``

基于 :ref:`xtensa_lx7` MIPS内核


.. _esp_rv32:

RISC-V
^^^^^^^^^^^^^^


.. _esp_ulp:

ULP
^^^^^^^^^^^^^^



框架相关
~~~~~~~~~~~~

.. contents::
    :local:

.. _esp_idf:

ESP-IDF
^^^^^^^^^^^^^^

ESP-IDF 是乐鑫官方的物联网开发框架，适用于 ESP32、ESP32-S 和 ESP32-C 系列 SoC。它基于 C/C++ 语言提供了一个自给自足的 SDK。

.. image:: ./images/idf.png
    :target: https://docs.os-q.com/espidf.html

.. _esp_arduino:

Arduino
^^^^^^^^^^^^^^


.. _esp_adf:

ESP-ADF
^^^^^^^^^^^^^^

`ESP-ADF <https://github.com/espressif/esp-adf>`_  用于开发各类音频应用，还提供多种语音平台的连接服务，方便用户直连云平台开发语音产品。

.. _esp_skainet:

ESP-Skainet
^^^^^^^^^^^^^^

``WakeNet``

`ESP-Skainet <https://github.com/espressif/esp-skainet>`_ 是乐鑫针对语音控制设备推出的智能语音助手。
它不依赖云连接，可以完全实现离线运行，在本地乐鑫 SoC 上即可进行唤醒词检测和语音命令词（短语）识别。
ESP-Skainet 集成多种声学算法，如语音活动检测、声学回声消除、降噪和波束成形等，提供了增强的声学性能。




外设相关
~~~~~~~~~~~~


.. contents::
    :local:

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

.. _esp_can:

CAN
^^^^^^^^^^^^^^




.. _esp_package:

封装规格
~~~~~~~~~~~~

.. contents::
    :local:

.. _esp_qfn56:

QFN56
^^^^^^^^^^^^^^

.. image:: ./images/ESP32S3P.png
    :target: https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf


.. _esp_qfn48:

QFN48
^^^^^^^^^^^^^^


.. image:: ./images/ESP32p5.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32
.. image:: ./images/ESP32p6.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32


.. _esp_qfn32:

QFN32
^^^^^^^^^^^^^^

.. image:: ./images/ESP32C3P.png
    :target: https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_cn.pdf


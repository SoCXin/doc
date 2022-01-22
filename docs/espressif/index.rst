.. _espressif:

Espressif
==============

``Xtensa-LX7`` ``Xtensa-LX6`` ``RISC-V`` ``WiFi`` ``BT/BLE``  ``ESP32`` ``ESP8266`` ``Arduino``

公司简介
-----------

`乐鑫科技 <http://www.espressif.com>`_ (股票代码：688018)是一家全球化的无晶圆厂半导体公司，成立于 2008 年，总部位于中国上海，主营 Wi-Fi&BLE AIoT SoC及相关解决方案。


.. note::
    乐鑫伴随物联网崛起，就早期狭义的技术实现而言，物联网≈ESP32/ESP8266，嵌入式工程师入门最经典的莫过于 STM32F103+ESP8266

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
      - 3/4/2
      - 100Mbps
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320KB/128KB
      - √ / X
      - OTG / X
      - 2/4/2
      - X
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 613.8/1181.6
      - 512KB/384KB
      - √ / 5.0
      - OTG / √
      - 3/4/2
      - X
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.2
      - 400KB/384KB
      - √ / 5.0
      - X / √
      - 2/3/1
      - X
    * - :ref:`esp32c2`
      - :ref:`esp_rv32`
      - 300
      - 272KB/576KB
      - √ / 5.0
      - X / X
      - 2/3/1
      - X
    * - :ref:`esp32h2`
      - :ref:`esp_rv32`
      -
      - 400KB/384KB
      - X / 5.0
      - X / X
      - 3/4/2
      - X


.. toctree::
    :maxdepth: 1

    ESP32 <ESP32>
    ESP32-S2 <ESP32-S2>
    ESP32-S3 <ESP32-S3>
    ESP32-C3 <ESP32-C3>
    ESP32-C2 <ESP32-C2>
    ESP32-H2 <ESP32-H2>




技术简介
-----------

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

基于 :ref:`xtensa_lx7` MIPS内核，五级流水线架构，支持高达 240 MHz 的时钟频率

* 16 位/24 位指令集提供高代码密度
* 32 位定制化指令集及 128 位宽数据总线，提供高运算性能
* 支持单精度浮点运算单元 (FPU)
* 支持 32 位乘法器、32 位除法器
* 非缓存 GPIO 指令
* 支持六级 32 个中断
* 支持 windowed ABI，64 个物理通用寄存器
* 支持带 TRAX 压缩模块的 trace 功能，最大 16 KB 的记录存储器 (trace memory)
* 用于调试的 JTAG 接口


.. _esp_rv32:

RISC-V
^^^^^^^^^^^^^^


.. _esp_ulp:

ULP
^^^^^^^^^^^^^^

``RISC-V`` ``8KB SRAM`` ``17.5MHz``




开发框架
~~~~~~~~~~~~

.. contents::
    :local:

.. _esp_arduino:

Arduino
^^^^^^^^^^^^^^


.. _esp_idf:

ESP-IDF
^^^^^^^^^^^^^^

ESP-IDF 是乐鑫官方的物联网开发框架，适用于 ESP32、ESP32-S 和 ESP32-C 系列 SoC。它基于 C/C++ 语言提供了一个自给自足的 SDK。

.. image:: ./images/idf.png
    :target: https://docs.os-q.com/espidf.html

.. image:: ./images/idf-v.png
    :target: https://github.com/espressif/esp-idf


.. _esp_adf:

ESP-ADF
^^^^^^^^^^^^^^

`ESP-ADF <https://github.com/espressif/esp-adf>`_  用于开发各类音频应用，还提供多种语音平台的连接服务，方便用户直连云平台开发语音产品。


.. _esp_now:

ESP-NOW
^^^^^^^^^^^^^^

`ESP-NOW简介 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/api-reference/network/esp_now.html>`_

由乐鑫定义的 Wi-Fi 通信协议，采用 CCMP 方法保护供应商特定动作帧的安全，ESP-NOW 广泛应用于智能照明、远程控制、传感器等领域。

标准相关
~~~~~~~~~~~~

.. _esp_matter:

Matter
^^^^^^^^^^^^^^

Matter 成立于 2019 年，由连接标准联盟（Connectivity Standards Alliance，前称 Zigbee Alliance）发起并领导，旨在提高不同厂商智能家居产品间的兼容性和互操作性。

是一个统一的智能家居互联标准，能够为家庭自动化项目提供安全可靠的无线连接。

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



.. _esp32c2:

ESP32-C2
================

* 关键词：``RISC-V`` ``120MHz`` ``WiFi`` ``BLE5.0`` ``QFN40``
* 资源池：`GitHub <https://github.com/SoCXin/ESP32C2>`_

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/ESP32C2.png
    :target: https://www.espressif.com/zh-hans/news/ESP32-C2

规格参数
~~~~~~~~~~~

ESP32-C2 芯片比 ESP8266 面积更小、性能更强。ESP32-C2 在满足简单物联网应用需求的基础上，进一步优化成本，能够为用户提供一个极具性价比的开发平台。值得一提的是，乐鑫的射频技术实现重要突破，可达到 1024-QAM 技术指标，未来将为客户提供更多高性能的产品选择。


基本参数
^^^^^^^^^^^

* 发布时间：2021-12-23
* 制程工艺：
* 工作温度：-40°C to +105°C
* 处理性能：300 :ref:`CoreMark`
* RAM容量：272 KB
* Flash容量：576 KB
* 封装规格：QFN40 (5x5mm)

特征参数
^^^^^^^^^^^

* 120 MHz :ref:`riscv`
* Wi-Fi IEEE 802.11b/g/n
* BLE 5.0
* 14 x GPIO


电源参数
^^^^^^^^^^^

* 供电电压：2.3 to 3.6 V

安全特性
~~~~~~~~~~~~~~


.. contents::
    :local:

.. note::
    硬件安全单元十分利于物联网产品设计，特别是对加密算法的支持，在嵌入式领域配置如此多的安全外设，也是十分强大的

RSA 模块
^^^^^^^^^^^^^^^

基于 RSA-3072 的标准身份验证方案，确保在设备上运行受信任的应用程序。该功能可阻止设备运行烧录在 flash 中的恶意程序。
安全启动需要快速高效地进行，以满足即时启动设备（如球泡灯）的需求，ESP32-C3 的安全启动方案仅在设备启动过程中增加了不到 100 ms 的时间开销。

AES 模块
^^^^^^^^^^^^^^^

基于 AES-128-XTS 算法的 flash 加密方案，确保应用程序与配置数据在 flash 中保持加密状态。
flash 控制器支持执行加密的应用程序固件，这不仅为存储在 flash 中的敏感数据提供了必要保护，还防止了运行时由于固件更改造成的 TOCTTOU (time-of-check-to-time-of-use) 攻击。




Xin选择
-----------


.. contents::
    :local:


品牌对比
~~~~~~~~~


.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Performance
      - SRAM/ROM
      - Characteristics
      - UART/SPI/SDIO
      - Package
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407 :ref:`CoreMark`
      - 512KB/384KB
      - 1T1R/v5.0
      - 2/3/No
      - :ref:`esp_qfn32`
    * - :ref:`hi3861`
      - :ref:`riscv`
      -
      - 352KB/288KB
      - 72Mbps@HT20
      - 3/2/1
      - QFN32
    * - :ref:`air101`
      - :ref:`riscv`
      -
      - 288KB/1MB
      -
      - 5/2/1
      - QFN32
    * - :ref:`w806`
      - :ref:`xt804`
      - 300 :ref:`DMIPS`
      - 288KB/1MB
      - 1T1R
      - 6/2/1
      - :ref:`w806_qfn56`




型号对比
~~~~~~~~~

.. contents::
    :local:

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - DMIPS
      - RAM
      - WiFi
      - BLE
      - USB
      - MAC
    * - :ref:`esp32`
      - Dual LX6
      - 600 DMIPS
      - 520 KB
      - 802.11 b/g/n
      - BT/BLE v4.2
      - NO
      - 100M
    * - :ref:`esp32s3`
      - Dual LX7
      - 600 DMIPS
      - 512 KB
      - 802.11 b/g/n
      - BLE v5.0
      - USB1.1 OTG
      - NO
    * - :ref:`esp32c3`
      - RV32IMC
      - 200 DMIPS
      - 400 KB
      - 802.11 b/g/n
      - BLE v5.0
      - NO
      - NO



版本对比
~~~~~~~~~


.. image:: ./images/ESP32-C2S.png


Xin应用
-----------

.. contents::
    :local:

开发板
~~~~~~~~~~


编译工具
~~~~~~~~~

开发框架
~~~~~~~~~


ESP-IDF
^^^^^^^^^^^

需要release/v4.3及以上版本 :ref:`esp_idf` ，围绕 ESP32-C3构建固件，需要安装一些必备工具包括 Python、Git、交叉编译器、CMake 和 Ninja等。

Arduino
^^^^^^^^^^^^

`Arduino <https://docs.os-q.com/arduino>`_

应用笔记
~~~~~~~~~







Xin总结
--------------

.. contents::
    :local:

能力构建
~~~~~~~~~~~~~

要点提示
~~~~~~~~~~~~~

问题整理
~~~~~~~~~~~~~


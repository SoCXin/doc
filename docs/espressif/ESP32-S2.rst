
.. _esp32s2:

ESP32S2
================

`标签 <https://github.com/SoCXin/ESP32-S2>`_ : ``Xtensa LX7`` ``240MHz`` ``Wi-Fi`` ``USB1.1 OTG`` ``ULP`` ``DVP`` ``DAC`` ``QFN56``

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/ESP32S2.png
    :target: https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s2/get-started/index.html

规格参数
~~~~~~~~~~~

基本参数
^^^^^^^^^^^

* 发布时间：2019年7月22日
* 参考价格：$1.32
* 制程工艺：40 nm
* 供货周期：至2032年
* 处理性能：613.8 :ref:`CoreMark`
* 运行环境：-40°C to 105°C
* 封装规格：:ref:`esp_qfn56` (7x7mm)
* RAM容量：320 KB
* ROM容量：128 KB
* Flash容量：4 MB (1GB)

特征参数
^^^^^^^^^^^

* 240 MHz :ref:`xtensa_lx7` + :ref:`esp_ulp`
* :ref:`esp32s2_wifi`
* :ref:`esp_usb`
* :ref:`esp32_can`
* 4 Kbit eFuse
* 1× 16bit DVP, 1× 8bit LCD
* 2x 13bit SAR ADC
* 2x 8bit DAC
* 2× UART
* 43× GPIO


.. warning::
    ESP32-S2为单核WiFi SoC，并不支持蓝牙，支持TOF，并且配置有8bit DAC，软件开始增加RainMaker支持

芯片架构
~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`espressif`
      - GPIO
      - UART
      - SPI
      - I2C
      - I2S
      - PWM
      - RMT
      - :ref:`esp_usb`
      - :ref:`esp32s2_wifi`
    * - :ref:`esp32s2`
      - 43
      - 2
      - 4
      - 2
      - 1
      - 8
      - 4
      - 1.1 OTG
      - b/g/n

电源参数
^^^^^^^^^^^

* 电压范围：2.3 to 3.6 V
* 功耗范围：


连接能力
~~~~~~~~~~~~~~

.. _esp32s2_wifi:

WiFi
^^^^^^^^^^^^^^^
``802.11b/g/n`` ``21dBm`` ``150Mbps`` ``HT40``

在 2.4 GHz 频带支持 20 MHz 和 40 MHz 频宽，支持 1T1R 模式，数据速率高达 150 Mbps

* 天线分集
* 802.11 mc FTM
* 支持外部功率放大器

.. _esp_usb:

USB
^^^^^^^^^^^^^^
``USB 1.1 OTG`` ``<12Mbps``


安全特性
~~~~~~~~~~~~~~

内置安全硬件，4096 bit OTP，硬件加密加速器可支持 AES-128/256、Hash、RSA、HMAC，RNG


.. contents::
    :local:

RSA 模块
^^^^^^^^^^^^^^^

基于 RSA-3072 的标准身份验证方案，确保在设备上运行受信任的应用程序。该功能可阻止设备运行烧录在 flash 中的恶意程序。
安全启动需要快速高效地进行，以满足即时启动设备（如球泡灯）的需求，ESP32-C3 的安全启动方案仅在设备启动过程中增加了不到 100 ms 的时间开销。

AES 模块
^^^^^^^^^^^^^^^

基于 AES-128-XTS 算法的 flash 加密方案，确保应用程序与配置数据在 flash 中保持加密状态。
flash 控制器支持执行加密的应用程序固件，这不仅为存储在 flash 中的敏感数据提供了必要保护，还防止了运行时由于固件更改造成的 TOCTTOU (time-of-check-to-time-of-use) 攻击。

TEE 模块
^^^^^^^^^^^^^^^

世界控制器模块提供了两个互不干扰的执行环境。根据配置，世界控制器使用可信执行环境 (TEE) 或权限分离机制。
如果应用程序固件需要处理敏感的安全数据（如 DRM 服务），则可以利用世界控制器模块，在安全区域处理数据。

数字签名
^^^^^^^^^^^^^^^

可以通过固件不可访问的私钥生成数字签名。同样地，其 HMAC 外设也可以生成固件不可访问的加密摘要。
目前，大多数物联网云服务使用基于 X.509 证书的身份验证，数字签名外设保护了定义设备身份的私钥。这样一来，即使出现软件漏洞，它也能为设备身份提供强大的保护



Xin选择
-----------

.. contents::
    :local:

品牌对比
~~~~~~~~~

就计算性能而言 :ref:`esp32s2` 的 613.8 :ref:`CoreMark` 略高于 :ref:`stm32f429` 的 608 :ref:`CoreMark`

型号对比
~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`espressif`
      - :ref:`esp_core`
      - :ref:`CoreMark`
      - SRAM/ROM
      - Wireless
      - ADC/DAC
      - USB/CAN
      - Package
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 994.26
      - 520K/448K
      - WiFi&BLE4.2
      - 2(12bit)/2(8bit)
      - TWAI
      - :ref:`esp_qfn48`
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320K/128K
      - WiFi
      - 2(12bit)/2(8bit)
      - 1.1 OTG
      - :ref:`esp_qfn56`
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1181.6
      - 512K/384K
      - WiFi&BLE5.0
      - 2(12bit)/X
      - 1.1 OTG
      - :ref:`esp_qfn56`
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.22
      - 400K/384K
      - WiFi&BLE5.0
      - 2(12bit)/X
      - TWAI
      - :ref:`esp_qfn32`

`芯片系列对比 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/hw-reference/chip-series-comparison.html>`_


.. hint::
    :ref:`esp32s2` 在 :ref:`esp32` 基础上移除了蓝牙增加了USB OTG， :ref:`xtensa_lx7` 单核相较 :ref:`esp32s3` 有保留DAC

版本对比
~~~~~~~~~

.. image:: ./images/ESP32S2ser.png
    :target: https://www.espressif.com/sites/default/files/documentation/esp32-s2_datasheet_cn.pdf



Xin应用
-----------

.. contents::
    :local:

开发板
~~~~~~~~~~

.. image:: ./images/B_ESP32S2.jpg
    :target: https://item.taobao.com/item.htm?spm=a1z09.2.0.0.4cb32e8dCPqAi3&id=641754177657&_u=vgas3eue654

开发框架
~~~~~~~~~~

Arduino
^^^^^^^^^^^^

:ref:`esp_arduino` 提供低门槛开发环境

PlatformIO
^^^^^^^^^^^^

:ref:`pio` 提供便捷的开发环境

应用方案
~~~~~~~~~~



.. _esp_usb_pd:

USB PD
^^^^^^^^^^^^

:ref:`usb_pd` 提供高效的能源传输方式

内置12位ADC可以监控USB TYEP-C接口的CC线，精确测量CC线上的压差，实现USB连接、拔除、传输方向的检测判断。

DAC可输出控制

`tinyusb <https://github.com/hathach/tinyusb>`_ 被整合在 :ref:`esp_idf` 组件中

.. code-block:: bash

    int main(void)
    {

    }



Xin总结
-------------

.. contents::
    :local:

能力构建
~~~~~~~~~~~~~

问题整理
~~~~~~~~~~~~~

应用总结
~~~~~~~~~~~~~

:ref:`esp32s2` 的市场定位及市场竞争力存在一定的短板，就配置而言作为 :ref:`esp8266` 的继任者性价比不够，而作为高性能产品又显得配置过低，与 :ref:`esp32` 、:ref:`esp32s3` 相比没有足够的吸引力，只能作为一个短暂的过渡产品。

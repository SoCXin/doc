
.. _esp32s2:

ESP32-S2
================

* 关键词：``Xtensa LX7`` ``240MHz`` ``QFN48`` ``Wi-Fi`` ``USB OTG`` ``ULP``
* 资源池：`GitHub <https://github.com/SoCXin/ESP32-S2>`_

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/ESP32S2.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32-S2

.. contents::
    :local:

规格配置
~~~~~~~~~~~

基本参数
^^^^^^^^^^^

* 发布时间：
* 工作温度：-40°C to 105°C
* 处理性能：613.8 :ref:`CoreMark`
* RAM容量：320 KB
* Flash容量：128 KB
* 封装规格：:ref:`esp_qfn48`


特征参数
^^^^^^^^^^^

* 240 MHz :ref:`xtensa_lx7`
* :ref:`esp_ulp`
* :ref:`esp_wifi`
* :ref:`esp_usb`
* :ref:`esp_twai`
* 4 Kbit eFuse
* 1× 16bit DVP, 1× 8bit LCD
* 2x 13bit SAR ADC
* 2x 8bit DAC
* 1 GB external flash
* 2 × UART
* 43 × GPIO


.. warning::
    ESP32-S2为单核 WiFi SoC，注意并没有蓝牙


电源参数
^^^^^^^^^^^

* 供电电压：2.3 to 3.6 V


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

.. hint::
    :ref:`esp32s2` 发布于2019年，在:ref:`esp32` 基础上移除了蓝牙，增加了USB OTG，Xtensa LX7单核

编译工具
~~~~~~~~~

开发框架
~~~~~~~~~

ESP-IDF
^^^^^^^^^^


Arduino
^^^^^^^^^^



Xin应用
--------------

.. contents::
    :local:
.. image:: ./images/B_ESP32S2.jpg
    :target: https://item.taobao.com/item.htm?spm=a1z09.2.0.0.4cb32e8dCPqAi3&id=641754177657&_u=vgas3eue654

tinyUSB
~~~~~~~~~~


.. code-block:: bash

    int main(void)
    {

    }





开源方案
~~~~~~~~~

* `ESP-IDF <https://github.com/espressif/esp-idf>`_
* `arduino-esp32 <https://github.com/espressif/arduino-esp32/>`_

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

esp32s2现在的外部ram无法使用，模块出的psram纯属摆设，现在sdk还没修复，估计这个是硬件bug。

https://www.espressif.com/sites/default/files/documentation/esp32-s2_datasheet_cn.pdf


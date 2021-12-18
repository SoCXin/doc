.. _NO_015:
.. _esp32s3:

ESP32-S3
================

* 关键词：``Xtensa LX7`` ``Dual Core`` ``240MHz`` ``WiFi`` ``BLE5.0`` ``USB FS OTG`` ``TWAI`` ``QFN56``
* 代码库：`GitHub <https://github.com/SoCXin/ESP32S3>`_ , `Gitee <https://gitee.com/socxin/ESP32S3>`_

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/ESP32S3.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32-S3

.. contents::
    :local:

规格配置
~~~~~~~~~~~

.. hint::
    2020年12月发布，预计2021年8月开始供货

基本参数
^^^^^^^^^^^

* 发布时间：2020年12月31日
* 工作温度：-40°C to 105°C
* 处理性能：613.8 :ref:`CoreMark`, 1181.6 :ref:`CoreMark` (Dual)
* RAM容量：512 KB (TCM)
* Flash容量：384 KB
* 封装规格：:ref:`esp_qfn56`



特征参数
^^^^^^^^^^^

* 240 MHz :ref:`xtensa_lx7` Dual Core
* :ref:`esp_ulp`
* :ref:`esp_wifi`
* :ref:`esp_ble` v5
* :ref:`esp_usb`
* :ref:`esp_twai`
* 4 Kbit eFuse
* 1 × 16bit DVP, 1 × 16bit LCD
* 2 × SDIO 主机
* 44 x GPIO，JTAG 接口
* 2x 12bit ADC (20ch)

ESP32-S3 增加了用于加速神经网络计算和信号处理等工作的向量指令 (vector instructions)

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

.. note::
    硬件安全单元十分利于物联网产品设计，特别是对加密算法的支持，在嵌入式领域配置如此多的安全外设，也是十分强大的


Xin选择
-----------

.. contents::
    :local:

品牌对比
~~~~~~~~~


.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Performance
      - SRAM/ROM
      - Characteristics
      - UART/SPI/SDIO
      - Package
    * - :ref:`esp32s3`
      - 1181 :ref:`CoreMark`
      - 512KB/384KB
      - USB FS OTG
      - 3/2/1
      - :ref:`esp_qfn56`
    * - :ref:`w801`
      - 300 :ref:`DMIPS`
      - 288KB/2MB
      - 16 bit :ref:`sigma_delta` ADC
      - 6/2/1
      - QFN56
    * - :ref:`w806`
      - 300 :ref:`DMIPS`
      - 288KB/1MB
      - 6x UART
      - 6/2/1
      - :ref:`w806_qfn56`

对比W801
^^^^^^^^^^^

两者的封装规格相同，主频配置基本相同，差异主要在： :ref:`esp32s3` 是双核带有USB，  :ref:`w801` 拥有更多外设数量

型号对比
~~~~~~~~~

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
      - :ref:`xtensa_lx6`
      - 600 DMIPS
      - 520 KB
      - 802.11 b/g/n
      - BLE v4.2
      - NO
      - 100M
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 300 DMIPS
      - 520 KB
      - 802.11 b/g/n
      - BLE v5.0
      - NO
      - NO
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 600 DMIPS
      - 512 KB
      - 802.11 b/g/n
      - BLE v5.0
      - USB1.1 OTG
      - NO

版本对比
~~~~~~~~~



Xin应用
--------------

.. contents::
    :local:

探索套件
~~~~~~~~~

编译工具
~~~~~~~~~

开发框架
~~~~~~~~~


ESP-IDF
^^^^^^^^^^

支持ESP32-S3需要release/v4.3及以上版本 :ref:`esp_idf` ，围绕 ESP32-C3构建固件，需要安装一些必备工具包括 Python、Git、交叉编译器、CMake 和 Ninja等。






Xin总结
--------------

.. contents::
    :local:

能力构建
~~~~~~~~~~~~~

.. note::
    相对传统的MCU使用的强大IDE环境，最大的槽点就是缺乏高度集成的工具环境，ESP-IDF的编译效率较低，文件修改后编译非常耗时


要点提示
~~~~~~~~~~~~~

问题整理
~~~~~~~~~~~~~


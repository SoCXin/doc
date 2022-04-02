.. _NO_015:
.. _esp32s3:

ESP32S3
================

`标签 <https://github.com/SoCXin/ESP32S3>`_ : ``Xtensa LX7`` ``Dual Core`` ``240MHz`` ``Wi-Fi`` ``BLE5.0`` ``USB OTG`` ``AI`` ``CAN`` ``Touch`` ``QFN56``

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/ESP32S3.png
    :target: https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/get-started/index.html

.. contents::
    :local:

规格参数
~~~~~~~~~~~

ESP32-S3作为乐鑫现役旗舰产品，双核240MHz配置高于传统MCU，基于wireless连接能力实现对传统MCU的降维打击。

* 芯片大小 (die size)：:ref:`esp32c3` < :ref:`esp32s2` < :ref:`esp32s3` < :ref:`esp32`

基本参数
^^^^^^^^^^^

* 发布时间：2020年12月31日
* 参考价格：
* 制程工艺：40 nm
* 供货周期：至2033年
* 处理性能：613.8 :ref:`CoreMark`, 1181.6 :ref:`CoreMark` (Dual)
* 封装规格：QFN56
* 运行环境：-40°C to 105°C
* RAM容量：512 KB (TCM，16 KB RTC SRAM)
* Flash容量：384 KB

特征参数
^^^^^^^^^^^

* 240 MHz :ref:`xtensa_lx7` Dual Core
* 低功耗协处理器 :ref:`esp_ulp` （FSM/RISC-V二选一）
* :ref:`esp32s3_wifi` + :ref:`esp32s3_ble`
* :ref:`esp32s3_usb`
* :ref:`esp32_can`
* 1 × 16bit DVP, 1 × 16bit LCD
* 2 × SDIO 主机
* 44 x GPIO，JTAG 接口
* 2x 12bit 100KSPS ADC (20ch)
* 14 × 电容式传感 GPIO

.. note::
    ESP32-S3增加了用于加速神经网络计算和信号处理等工作的向量指令 (vector instructions)

芯片架构
~~~~~~~~~~~


功耗参数
^^^^^^^^^^^

* 电压范围：2.3 to 3.6 V
* 功耗范围：

.. image:: ./images/ESP32S3sleep.png
    :target: https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_cn.pdf




连接能力
~~~~~~~~~~~~~~

.. _esp32s3_wifi:

WiFi
^^^^^^^^^^^^^^^

在 2.4 GHz 频带支持 20 MHz 和 40 MHz 频宽，支持 1T1R 模式，数据速率高达 150 Mbps

* 天线分集
* 802.11 mc FTM
* 支持外部功率放大器

.. _esp32s3_ble:

BLE
^^^^^^^^^^^^^^^
``BLE 5.0`` ``-94dBm`` ``20dBm``

* 高功率模式（20 dBm，与 Wi-Fi 共用 PA）

.. _esp32s3_usb:

USB
^^^^^^^^^^^^^^^
``USB 1.1`` ``12Mbps``




计算能力
~~~~~~~~~~~~~~

.. _esp_pie:

加速指令
^^^^^^^^^^^^^^^

为了提高特定 AI 和 DSP (Digital Signal Processing) 算法的运算效率，ESP32-S3 中新增了一组扩展指令。处理器指令拓展 (PIE) 支持以下特性：

* 新增 128-bit 位宽通用寄存器
* 128-bit 位宽的向量数据操作，包括：乘法、加法、减法、累加、移位、比较等
* 合并数据处理指令与加载/存储运算指令
* 非对齐 128-bit 带宽的向量数据
* 取饱和操作



安全特性
~~~~~~~~~~~~~~

内置安全硬件，4096 bit eFuse(其中1566 bit用户可用)，硬件加密加速器可支持 AES-128/256、Hash、RSA、HMAC，RNG


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


数字签名
^^^^^^^^^^^^^^^

`数字签名DS(Digital Signature) <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/api-reference/peripherals/ds.html>`_  可以通过固件不可访问的私钥生成，同样地，其 HMAC 外设也可以生成固件不可访问的加密摘要。

目前，大多数物联网云服务使用基于 X.509 证书的身份验证，数字签名外设保护了定义设备身份的私钥。这样一来，即使出现软件漏洞，它也能为设备身份提供强大的保护


Xin选择
-----------

.. contents::
    :local:

品牌对比
~~~~~~~~~

:ref:`espressif` 在WiFi MCU领域市场占有率第一，在中低端或高性价比定位的产品里鲜有对手，而且不断完善的生态主要的护城河，所有应用领域都有较高的开发起点。

.. list-table::
    :header-rows:  1

    * - :ref:`wifi`
      - :ref:`CoreMark`
      - SRAM/ROM
      - Characteristics
      - UART/SPI/SDIO
      - Package
    * - :ref:`esp32s3`
      - 1181.6
      - 512KB/384KB
      - USB1.1 OTG
      - 3/2/1
      - :ref:`esp_qfn56`
    * - :ref:`w801`
      -
      - 288KB/2MB
      - 16-bit ADC
      - 6/2/1
      - QFN56

功能对比
^^^^^^^^^^^

:ref:`w801` 和 :ref:`esp32s3` 两者的封装规格相同，主频配置相同，差异主要在： :ref:`esp32s3` 是双核且带有USB， :ref:`w801` 拥有更多外设

性能对比
^^^^^^^^^^^

:ref:`esp32s3` 双核 1181.6 :ref:`CoreMark` 略高于 STM32F7系列(1082CoreMark/462DMIPS)，对性能要求较高的场景非常适用，不足在于非嵌入式存储器，IO的效率较低

型号对比
~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`espressif`
      - :ref:`esp_core`
      - :ref:`CoreMark`
      - SRAM/ROM
      - Wireless
      - Ethernet
      - USB
      - Package
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 994.26
      - 520KB/448KB
      - WiFi&BLE
      - 100Mbps
      - X
      - :ref:`esp_qfn48`
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320KB/128KB
      - WiFi
      - X
      - 1.1 OTG
      - :ref:`esp_qfn56`
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1181.6
      - 512KB/384KB
      - WiFi&BLE
      - X
      - 1.1 OTG
      - :ref:`esp_qfn56`
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.22
      - 400KB/384KB
      - WiFi&BLE
      - X
      - X
      - :ref:`esp_qfn32`

`芯片系列对比 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/hw-reference/chip-series-comparison.html>`_



版本对比
~~~~~~~~~

主要对比集成的资源大小，便于硬件设计，对软件开发影响不大。

.. image:: ./images/ESP32S3ser.png
    :target: https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_cn.pdf


Xin应用
--------------

.. contents::
    :local:

开发板
~~~~~~~~~~~~~~~

ESP32-S3-EYE
^^^^^^^^^^^^^^^^

`ESP32-S3-EYE <https://github.com/espressif/esp-who/blob/master/docs/en/get-started/ESP32-S3-EYE_Getting_Started_Guide.md>`_


ESP32-S3-BOX
^^^^^^^^^^^^^^^^

`ESP32-S3-BOX <https://github.com/espressif/esp-box>`_

.. image:: ./images/S3-BOX.png
    :target: https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-22443450244.17.348167d8ZD5hBc&id=658634202331

除了智能语音助手以外，还集触摸屏控制、传感器、红外控制器和智能网关等多功能于一体，拥有完善的 SDK 和丰富的例程。


ESP32-S3-USB-OTG
^^^^^^^^^^^^^^^^

`ESP32-S3-USB-OTG <https://docs.espressif.com/projects/espressif-esp-dev-kits/zh_CN/latest/esp32s3/esp32-s3-usb-otg/user_guide.html>`_



开发框架
~~~~~~~~~

``ESP-IDF`` ``ESP-ADF`` ``ESP-MDF``

关于 `ESP-IDF <https://docs.os-q.com/espidf.html>`_

ESP-WHO
^^^^^^^^^^^

.. _esp_skainet:

ESP-Skainet
^^^^^^^^^^^^^^

``WakeNet``

`ESP-Skainet <https://github.com/espressif/esp-skainet>`_ 是乐鑫针对语音控制设备推出的智能语音助手。集成多种声学算法，如语音活动检测、声学回声消除、降噪和波束成形等，提供了增强的声学性能。

它不依赖云连接，可以完全实现离线运行，在本地乐鑫 SoC 上即可进行唤醒词检测和语音命令词（短语）识别。


外设应用
~~~~~~~~~~~

.. _esp_touch:

Touch
^^^^^^^^^^^



IOMUX
^^^^^^^^^^^

相对于传统的MCU，基于IO矩阵，可以将数字外设任意分配管脚，灵活性相当高。

支持快速信号如 SPI、JTAG、UART 等可以旁路 GPIO 交换矩阵以实现更好的高频数字特性。所以高速信号会直接通过 IO MUX 输入和输出。

基于RTC控制的IO MUX具有以下特性：

* 控制 22 个 RTC GPIO 管脚的低功耗特性；
* 控制 22 个 RTC GPIO 管脚的模拟功能；
* 将 22 个 RTC 输入输出信号引入 RTC 系统。

产品案例
~~~~~~~~~~~

.. _s3_tool:

S3-TOOL
^^^^^^^^^^^
``Server`` ``Wi-Fi`` ``BLE5.0`` ``USB OTG`` ``QFN56``

`S3-TOOL <https://github.com/stops-top/S3-Tool>`_ 用于实现 :ref:`stops_tool`

* 线缆接入
* 联网管理
* 串联调试


Xin总结
--------------

.. contents::
    :local:

能力构建
~~~~~~~~~~~~~

如果要掌握ESP32的开发，需要对Linux有一定的了解，包括编码风格和开发环境。



问题整理
~~~~~~~~~~~~~

相对传统的MCU使用的强大IDE环境，最大的槽点就是缺乏高度集成的工具环境，ESP-IDF的编译效率较低，文件修改后编译非常耗时

.. note::
    由于ESP-IDF的多版本、开源(链接集成)和快速迭代特性，导致获取完整资源慢且不稳定，GitHub无法访问≈放弃

应用总结
~~~~~~~~~~~~~

就芯片配置而言，相对ESP32的升级力度不大，用以太网换了USB-OTG，更多是一种发展方向的探索，围绕软件生态构建应用场景。

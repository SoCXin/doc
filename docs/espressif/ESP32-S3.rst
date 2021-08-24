
.. _esp32s3:

ESP32-S3
================


* 关键词：``Xtensa`` ``LX7`` ``240MHz`` ``BLE5.0`` ``Wi-Fi`` ``USB1.1``
* 资源池：`GitHub <https://github.com/SoCXin/ESP32S3>`_

.. contents::
    :local:

Xin简介
-----------

:ref:`espressif` :ref:`xtensa` Dual Core WiFi & BLE SoC

.. image:: ./images/ESP32S3.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32-S3


关键特性
~~~~~~~~~~~~~

* Xtensa® LX7 Dual Core 240 MHz
* 512 KB SRAM (TCM)，384 KB ROM
* Wi-Fi + Bluetooth 5 (LE)
* USB OTG FS
* 2 × SDIO 主机
* DMA 5 接收 + 5 发送
* 44 x GPIO，JTAG 接口
* 超低功耗协处理器RISC-V (ULP)
* 硬件加密加速器可支持 AES-128/256、Hash、RSA、HMAC，RNG


安全特性
~~~~~~~~~~~~~~

内置安全硬件

RSA 模块
^^^^^^^^^^^^^^^

基于 RSA-3072 的标准身份验证方案，确保在设备上运行受信任的应用程序。该功能可阻止设备运行烧录在 flash 中的恶意程序。
安全启动需要快速高效地进行，以满足即时启动设备（如球泡灯）的需求，ESP32-C3 的安全启动方案仅在设备启动过程中增加了不到 100 ms 的时间开销。

AES 模块
^^^^^^^^^^^^^^^

基于 AES-128-XTS 算法的 flash 加密方案，确保应用程序与配置数据在 flash 中保持加密状态。
flash 控制器支持执行加密的应用程序固件，这不仅为存储在 flash 中的敏感数据提供了必要保护，还防止了运行时由于固件更改造成的 TOCTTOU (time-of-check-to-time-of-use) 攻击。

HMAC模块
^^^^^^^^^^^^^^^

ESP32-C3 的数字签名外设，可以通过固件不可访问的私钥生成数字签名。同样地，其 HMAC 外设也可以生成固件不可访问的加密摘要。
目前，大多数物联网云服务使用基于 X.509 证书的身份验证，数字签名外设保护了定义设备身份的私钥。这样一来，即使出现软件漏洞，它也能为设备身份提供强大的保护

TEE 模块
^^^^^^^^^^^^^^^

世界控制器模块提供了两个互不干扰的执行环境。根据配置，世界控制器使用可信执行环境 (TEE) 或权限分离机制。
如果应用程序固件需要处理敏感的安全数据（如 DRM 服务），则可以利用世界控制器模块，在安全区域处理数据。


Xin选择
-----------

本部分明确该芯片的需求匹配度



开发框架
~~~~~~~~~

ESP-IDF
^^^^^^^^^^

支持ESP32C3需要release/v4.3及以上版本 :ref:`esp_idf` ，围绕 ESP32-C3构建固件，需要安装一些必备工具包括 Python、Git、交叉编译器、CMake 和 Ninja等。

Arduino
^^^^^^^^^^

编译器
^^^^^^^^^^


Xin应用
--------------


.. image:: ./images/B_ESP32C3.jpg
    :target: https://item.taobao.com/item.htm?spm=a1z09.2.0.0.4cb32e8dCPqAi3&id=641754177657&_u=vgas3eue654


RGB LED
~~~~~~~~~~~



.. code-block:: bash

    int main(void)
    {
        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
        LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
        LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
        LL_GPIO_ResetOutputPin(LED_GPIO_Port, LED_Pin);
        GPIO_InitStruct.Pin = LED_Pin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        LL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);
        while (1)
        {
            LL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
            LL_mDelay(400);
        }
    }







Xin总结
--------------



重点提示
~~~~~~~~~~~~~~



问题整理
~~~~~~~~~~~~~



.. warning::
    相对传统的MCU开发，最大的槽点就是ESP-IDF编译效率，因为要编译的组件特别多，编译非常耗时间


.. _espressif_esp32c3:

ESP32-C3
================

* 关键词：``RISC-V`` ``160MHz`` ``RV32IMC`` ``BLE5.0`` ``Wi-Fi`` ``USB1.1``
* 资源池：`GitHub <https://github.com/SoCXin/ESP32C3>`_

.. contents::
    :local:

Xin简介
-----------

:ref:`espressif` :ref:`riscv` WiFi & BLE SoC

.. image:: ./images/ESP32C3.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32-C3


关键特性
~~~~~~~~~

* 400 KB SRAM (TCM)，384 KB ROM
* Wi-Fi IEEE 802.11b/g/n
* BLE 5.0，支持Mesh (Bluetooth Mesh)
* USB1.1
* 2 × UART
* 22  x GPIO


安全性能
~~~~~~~~~~~~~~

基于 RSA-3072 的标准身份验证方案，确保在设备上运行受信任的应用程序。该功能可阻止设备运行烧录在 flash 中的恶意程序。安全启动需要快速高效地进行，以满足即时启动设备（如球泡灯）的需求，ESP32-C3 的安全启动方案仅在设备启动过程中增加了不到 100 ms 的时间开销。

基于 AES-128-XTS 算法的 flash 加密方案，确保应用程序与配置数据在 flash 中保持加密状态。flash 控制器支持执行加密的应用程序固件，这不仅为存储在 flash 中的敏感数据提供了必要保护，还防止了运行时由于固件更改造成的 TOCTTOU (time-of-check-to-time-of-use) 攻击。

ESP32-C3 的数字签名外设，可以通过固件不可访问的私钥生成数字签名。同样地，其 HMAC 外设也可以生成固件不可访问的加密摘要。目前，大多数物联网云服务使用基于 X.509 证书的身份验证，数字签名外设保护了定义设备身份的私钥。这样一来，即使出现软件漏洞，它也能为设备身份提供强大的保护

世界控制器模块提供了两个互不干扰的执行环境。根据配置，世界控制器使用可信执行环境 (TEE) 或权限分离机制。如果应用程序固件需要处理敏感的安全数据（如 DRM 服务），则可以利用世界控制器模块，在安全区域处理数据。

Xin选择
-----------

本部分用于明确需求点，明确该芯片的匹配度

竞品分析
~~~~~~~~~

命名为xx32F031 的MCU产品非常丰富，就规格而言有大量可替代品，主要竞争力还是在功能稳定性及资源兼容性上，基于STM32Cube的开发生态，有大量资源和工程师团队。


对比ESP32
~~~~~~~~~~~~

ESP32-C3没有对 IRAM 和 DRAM 进行静态划分。SRAM 的前 16 KB 被配置为 cache 专用。与 ESP32 不同的是，ESP32-C3 的 IRAM 和 DRAM 地址在相同方向递增。
基于应用需求，链接器脚本可将所需的空间配置为 IRAM，其后便为 DRAM 空间。因此相比 ESP32 来说，ESP32-C3 的存储空间使用效率更高。

ESP32-C3 的蓝牙子系统不要求其存储必须为某固定位置的连续空间。反之，它使用标准的系统堆来分配存储空间，因此应用可以在需要的时候打开或禁用蓝牙。要实现这一点，仅需确保堆中有足够的存储空间即可。

.. image:: ./images/RAM_VSESP32.jpg.jpg
    :target: https://zhuanlan.zhihu.com/p/369125251

.. image:: ./images/RAM_ESP32C3.jpg
    :target: https://zhuanlan.zhihu.com/p/369125251


USB
~~~~~~~~~~~


Xin应用
--------------


.. image:: ./images/B_ESP32C3.jpg
    :target: https://item.taobao.com/item.htm?spm=a1z09.2.0.0.4cb32e8dCPqAi3&id=641754177657&_u=vgas3eue654

开发工具
~~~~~~~~~



示例代码
~~~~~~~~~

基于STM32CubeMX生成LL库工程

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





开源项目
~~~~~~~~~

如果你要探索一些开源项目，可能时常遇到基于 `PlatformIO <https://platformio.org/platforms/ststm32>`_ 构建的工程，通过跨平台编译，直接在编辑器中集成，可以云端部署，比常用的IDE拥有更多的灵活性。

* `ESP-IDF <https://github.com/espressif/esp-idf>`_


Xin总结
--------------



重点提示
~~~~~~~~~~~~~~

STM32G0系列属于较新的产品，也重点优化了ADC的性能，相较于使用最广泛的STM32F1系列，在ADC初始化阶段需要更长的时间，所以在采样的时候需要过滤开始阶段无效的数据。


问题整理
~~~~~~~~~~~~~



.. warning::
    相对传统的MCU开发，最大的槽点就是ESP-IDF编译效率，因为要编译的组件特别多，编译非常耗时间

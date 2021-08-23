
.. _espressif_esp32c3:

ESP32-C3
================

* 关键词：``160MHz`` ``BLE5.0`` ``Wi-Fi`` ``USB``
* 资源库：`GitHub <https://github.com/SoCXin/ESP32C3>`_

.. contents::
    :local:

Xin简介
-----------

:ref:`espressif` :ref:`riscv` WiFi&BLE SoC

.. image:: ./images/ESP32C3.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32-C3


关键特性
~~~~~~~~~

* 400 KB SRAM (TCM)，384 KB ROM
* 2.4 GHz Wi-Fi & BLE 5.0
* USB1.1
* 2 × UART
* 22  x GPIO
* RV32IMC ISA

Xin选择
-----------



竞品分析
~~~~~~~~~

命名为xx32F031 的MCU产品非常丰富，就规格而言有大量可替代品，主要竞争力还是在功能稳定性及资源兼容性上，基于STM32Cube的开发生态，有大量资源和工程师团队。


对比ESP32
~~~~~~~~~~~~

在 ESP32-C3 中，没有对 IRAM 和 DRAM 进行静态划分。SRAM 的前 16 KB 被配置为 cache 专用。与 ESP32 不同的是，ESP32-C3 的 IRAM 和 DRAM 地址在相同方向递增。
基于应用需求，链接器脚本可将所需的空间配置为 IRAM，其后便为 DRAM 空间。因此相比 ESP32 来说，ESP32-C3 的存储空间使用效率更高。


ESP32-C3 的蓝牙子系统不要求其存储必须为某固定位置的连续空间。反之，它使用标准的系统堆来分配存储空间，因此应用可以在需要的时候打开或禁用蓝牙。要实现这一点，仅需确保堆中有足够的存储空间即可。

.. image:: ./images/RAM_VSESP32.jpg.jpg
    :target: https://zhuanlan.zhihu.com/p/369125251

.. image:: ./images/RAM_ESP32C3.jpg
    :target: https://zhuanlan.zhihu.com/p/369125251


规格选择
~~~~~~~~~



Xin实践
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

STM32G031产品定位入门，FLASH和RAM资源都相对受限，虽然可以运行FreeRTOS等系统，但其并不是RTOS的理想载体，而且作为长期项目开发，需要通过使用LL库释放更多资源。


``注意事项``
~~~~~~~~~~~~~~

STM32G0系列属于较新的产品，也重点优化了ADC的性能，相较于使用最广泛的STM32F1系列，在ADC初始化阶段需要更长的时间，所以在采样的时候需要过滤开始阶段无效的数据。


``使用槽点``
~~~~~~~~~~~~~

相较以往STM32的boot模式，新的G0系列芯片出厂默认从system flash启动，boot0管脚无论拉高或拉低都不能从系统存储区（system flash）启动（进入bootloader状态），也就是说如果烧录的程序没有配置SYS调试端口，将无法通过传统的boot0拉高来连接烧录器。

如果要使能boot 0的功能，需要修改option bytes，将 ``nboot_sel`` 后面的勾选去掉，断电复位，此时芯片的启动方式就由boot0引脚决定了，上拉boot0进bootloader模式。

一不小心就把芯片锁死弄成砖了，可以将PA0（NRST）接地，然后在连接STM32CubeProgrammer前断开接地，这是MCU可以被识别到，然后进行擦除或修改option bytes

.. warning::
    SON8封装注意烧录口使能，小心变砖


.. _espressif_esp32h2:

ESP32-H2
================

* 关键词：``160MHz`` ``BLE5.2`` ``Wi-Fi`` ``USB``
* 资源库：`GitHub <https://github.com/SoCXin/ESP32H2>`_

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


Xin选择
-----------



竞品分析
~~~~~~~~~



型号对比
~~~~~~~~~



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

1. 基于STM32CubeMX生成HAL库工程

.. code-block:: bash

    uint8_t RxData;     //中断接收串口1数据
    void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
    {
        if(&huart1 == huart) {
            HAL_UART_Receive_IT(huart, &RxData, 1);
        }
    }

    void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
    {
        if(htim==(&htim17)) //定时器中断函数
        {
            g_run_tick++;
        }
    }

    int main(void)
    {
        /* USER CODE BEGIN 2 */
        HAL_UART_Receive_IT(&huart1, &RxData, 1);   //中断接收使能
        HAL_TIM_PWM_Start(&htim16,TIM_CHANNEL_1);   //PWM输出使能
        HAL_TIM_Base_Start_IT(&htim17);             //定时器使能
        /* USER CODE END 2 */
        while (1)
        {
            /* USER CODE BEGIN 3 */
            HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
            HAL_Delay(500);
        }
        /* USER CODE END 3 */
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

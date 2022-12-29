
.. _amba:

AMBA
====================

**高级处理器总线架构AMBA (Advanced Microcontroller Bus Architecture)**

* ASB (Advanced System Bus) 高级系统总线
* APB (Advanced Peripheral Bus) 高级外围总线
* AHB (Advanced High-performance Bus) 高级高性能总线
* AXI (Advanced eXtensible Interface) 高级可拓展接口

.. contents::
    :local:

APB
----------

Advanced Peripheral Bus, APB主要用于低带宽的周边外设之间的连接，例如UART、1284等，它的总线架构不像 AHB支持多个主模块，在APB里面唯一的主模块就是APB 桥。再往下，APB2负责AD，I/O，高级TIM，串口1；APB1负责DA，USB，SPI，I2C，CAN，串口2345，普通TIM。

APB主要用在低速且低功率的外围，可针对外围设备作功率消耗及复杂接口的最佳化。APB在AHB和低带宽的外围设备之间提供了通信的桥梁，所以APB是AHB或ASB的二级拓展总线。


AHB
----------

Advanced High performance Bus,主要用于高性能模块(如CPU、DMA和DSP等)之间的连接。AHB 系统由主模块、从模块和基础结构(Infrastructure)3部分组成，整个AHB总线上的传输都由主模块发出，由从模块负责回应。

AHB主要是针对高效率、高频宽及快速系统模块所设计的总线，它可以连接如微处理器、芯片上或芯片外的内存模块和DMA等高效率模块。



.. _amba:

AMBA
====================

**AMBA (Advanced Microcontroller Bus Architecture) 高级处理器总线架构**

.. contents:: 目录索引
    :local:

APB
----------

Advanced Peripheral Bus, APB主要用于低带宽的周边外设之间的连接，例如UART、1284等，它的总线架构不像 AHB支持多个主模块，在APB里面唯一的主模块就是APB 桥。再往下，APB2负责AD，I/O，高级TIM，串口1；APB1负责DA，USB，SPI，I2C，CAN，串口2345，普通TIM。

APB主要用在低速且低功率的外围，可针对外围设备作功率消耗及复杂接口的最佳化。APB在AHB和低带宽的外围设备之间提供了通信的桥梁，所以APB是AHB或ASB的二级拓展总线。


AHB
----------

Advanced High performance Bus,主要用于高性能模块(如CPU、DMA和DSP等)之间的连接。AHB 系统由主模块、从模块和基础结构(Infrastructure)3部分组成，整个AHB总线上的传输都由主模块发出，由从模块负责回应。

AHB主要是针对高效率、高频宽及快速系统模块所设计的总线，它可以连接如微处理器、芯片上或芯片外的内存模块和DMA等高效率模块。


性能测试
----------

.. list-table::
    :header-rows:  1

    * - 内核
      - DMIPS/MHz
      - CoreMark/MHz
    * - :ref:`cortex_m0`
      - 0.95
      - 1.62
    * - :ref:`cortex_m3`
      - 1.25
      - 2.19
    * - :ref:`cortex_m4`
      - 1.25
      - 2.19
    * - :ref:`cortex_m7`
      - 2.14
      -
    * - :ref:`cortex_m23`
      -
      -
    * - :ref:`cortex_m33`
      - 1.5
      -
    * - :ref:`24KEc`
      - 1.55
      - 3.05
    * - :ref:`1004KEc`
      -
      -


.. _DMIPS:

DMIPS
~~~~~~~~~~~~~~

Dhrystone是由Reinhold P. Weicker在1984年提出来的一个基准测试程序，其主要目的是测试处理器的整数运算和逻辑运算的性能。

Dhrystone程序最初用Ada语言发布，后来Rick Richardson为Unix开发了用C语言编写的Version 1.1，这个版本也成功的推动了Dhrystone的广泛应用。Dhrystone程序的最新版本是1988年更新的Version 2.1。

Dhrystone标准的测试方法很简单，就是单位时间内跑了多少次Dhrystone程序，其指标单位为DMIPS/MHz。MIPS是Million Instructions Per Second的缩写，每秒处理的百万级的机器语言指令数。DMIPS中的D是Dhrystone的缩写，它表示了在Dhrystone标准的测试方法下的MIPS。

.. _CoreMark:

CoreMark
~~~~~~~~~~~~~~

CoreMark是由嵌入式微处理器基准评测协会EEMBC的Shay Gla-On于2009年提出的一项基准测试程序，其主要目标是测试处理器核心性能，这个标准被认为比陈旧的Dhrystone标准更有实际价值。

CoreMark程序使用C语言写成，包含如下的运算法则：列举（寻找并排序），数学矩阵操作（普通矩阵运算）和状态机（用来确定输入流中是否包含有效数字），最后还包括CRC（循环冗余校验）。CoreMark程序的最新版本是Version 1.0。

CoreMark标准的测试方法也很简单，就是在某配置参数组合下单位时间内跑了多少次CoreMark程序，其指标单位为CoreMark/MHz。CoreMark数字越高，意味着性能更高。

.. _ULPMark:

ULPMark
~~~~~~~~~~~~~~

ULPMark 测试目前有三个部分，分别是 :ref:`ulp_cp` 、 :ref:`ulp_pp` 和 ULPMark-CoreMark。

.. _ulp_cp:

ULPMark-CP
^^^^^^^^^^^^^^

ULPMark-CoreProfile 在深度睡眠下整个芯片的能量消耗；因为在低功耗的应用场景下，该芯片设备可能是单电池供电，需要运行长达 10 年的时间，所以芯片设备绝大部分时间应该都是处在深度睡眠的模式，偶尔唤醒处理部分任务。

.. _ulp_pp:

ULPMark-PP
^^^^^^^^^^^^^^

ULPMark-PeripheralProfile 普通外围设备的能量对深度睡眠的影响


ULPMark-CoreMark
^^^^^^^^^^^^^^^^^^^^

ULPMark-CoreMark 活跃功耗，使用 CoreMark 作为工作负载

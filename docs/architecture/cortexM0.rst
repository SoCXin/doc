
.. _cortex_m0:

Cortex-M0
====================

:ref:`performance` : ``1.62 CoreMark/MHz`` ``0.95 DMIPS/MHz``

2009年发布，是一款具有开创性的产品，第一个将32位处理器在同8位和16位处理器差不多大小的硅片实现的，在保持可用性的同时还具有极佳的能耗效率，最低配只有12000个逻辑门。

3级流水线 :ref:`neumann` ，能耗最低的最小ARM处理器，:ref:`cortex_m0` 的代码密度和能效优势意味着它是各种应用中 8/16 位设备的自然高性价比换代产品，同时保留与功能丰富的 :ref:`cortex_m3` 处理器的工具和二进制向上兼容性。

.. list-table::
    :header-rows:  1

    * - :ref:`foundry`
      - :ref:`DMIPS`/MHz
      - :ref:`CoreMark`/MHz
      - :ref:`consumption`/MHz
      - Die Size
    * - :ref:`tsmc_40nm`
      - 0.95
      - 1.62
      - 3.8µW
      - 0.0066(mm2)

.. image:: ./images/Cortex-M0plus.png
    :target: https://developer.arm.com/Processors/Cortex-M0-Plus


Cortex-M处理器支持的指令集名为Thumb，而M0和M0+处理器则只支持其中的一个子集(56条指令)，这些指令多数为16位宽，只有6个指令是32位的。

Cortex-M0和Cortex-M3都使用的是3级流水线结构，Cortex-M0+使用的是2级流水线结构(取指 + 预解析，解析 + 执行),这样就降低了处理器内振荡器的数量，动态功耗也随之下降。

* Corte-M0处理器具有3级流水线(取指、解析、执行)
* Cortex-M0+处理器具有2级流水线(取指 + 预解析，解析 + 执行)


.. image:: ./images/m0vsarm7.png
    :target: https://blog.csdn.net/u012874587/article/details/78803044




中断管理
---------------

.. contents::
    :local:

NVIC和SCB两个寄存器管理中断优先级，中断源分为内核中断和IRQ中断

NVICIPR一共有8个寄存器，每个寄存器管理4个IRQ中断，IRQ中断源最多只支持32个了，再加上16个内核中断，M0+最多就是48个中断源。

系统控制块(SCB)
~~~~~~~~~~~~~~~~~

系统控制块(System Control Block) 是内核外设的主要模块之一，提供系统控制以及系统执行信息，包括配置，控制，报告系统异常等。

ICSR
~~~~~~~~~~~~~~

中断控制和状态寄存器，提供了NMI的置位标志和PendSV、SysTick的置位和清除位。 同时还记录了正在执行和将要执行的中断编号，也标志了是否有中断被抢断了。 需要注意的是，对该寄存器进行写操作时不能同时对PENDST(SV)CLR和PENDST(SV)SET写1， 系统的运行情况将不可知。

VTOR
~~~~~~~~~

中断向量表偏移地址寄存器。中断向量表是128个word对齐的，也就是说它的低9位都是0。 对该寄存器的设置将修改中断向量表的起始地址。 而该寄存器的第29位标志了中断向量表是在SRAM中还是代码段中，有时也称该位为TBLBASE位。

代表产品
---------------

.. toctree::
    :maxdepth: 1

    RP2040 <../miscellaneous/RP2040>


.. _cortex_m0:

Cortex-M0
====================

.. contents::
    :local:


内核对比
---------------

.. list-table::
    :header-rows:  1

    * - Core
      - DMIPS/MHz
      - CoreMark/MHz
      - Flash
      - UART/SPI
      - BLE
      - USB
      - Ethernet
    * - :ref:`cortex_m0`
      - 0.95
      - 1.62
      - 250K
      - 4/2
      - 4.2
      - USB
      - 10M
    * - :ref:`cortex_m3`
      - 1.25
      - 2.19
      - 512K
      - 4/1
      - 4.2
      - USB H/D
      - NO
    * - :ref:`cortex_m4`
      - 1.25
      - 2.19
      - 1024
      - 4/1
      - 5.1
      - 2
      - NO
    * - :ref:`cortex_m33`
      - 1.50
      - 2.19
      - 1024
      - 4/1
      - 5.1
      - 2
      - NO

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


Xin产品
----------

.. toctree::
    :maxdepth: 2

    STM32   <../ST/M0/index>



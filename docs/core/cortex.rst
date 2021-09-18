
.. _cortex:

Cortex
===================

.. note::
    ARM公司在经典处理器ARM11以后的产品改用Cortex命名，并分成A、R和M三类，旨在为各种不同的市场提供服务。Cortex系列属于ARMv7架构，这是2010年止ARM公司最新的指令集架构。

ARMv7架构定义了三大分工明确的系列：

* “A”系列面向尖端的基于虚拟内存的操作系统和用户应用；
* “R”系列针对实时系统；
* “M”系列对微控制器。


.. contents::
    :local:

.. image:: ./images/arm.png
    :target: https://developer.arm.com/ip-products/processors/cortex-m

.. _cortex_spec:

Architecture
-------------

.. toctree::
    :maxdepth: 1

    AMBA <amba>

.. _cortex_m:

Cortex-M
-------------

.. toctree::
    :maxdepth: 1

    cortexM0
    cortexM23
    cortexM3
    cortexM4
    cortexM33
    cortexM7

内核对比
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Core
      - Architecture
      - Pipeline
      - ISA
      - Version
      - Instruction
      - DMIPS/MHz
      - CoreMark/MHz
    * - :ref:`cortex_m0`
      - Von Neumann
      - 2
      - Thumb
      - ARMv6-M
      - 56
      - 0.94
      - 2.42
    * - :ref:`cortex_m23`
      - Von Neumann
      - 2
      - Thumb/Thumb-2
      - ARMv8-M
      - 80
      - 0.94
      - 2.42
    * - :ref:`cortex_m3`
      - Von Neumann
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 1.25
      - 3.32
    * - :ref:`cortex_m4`
      - Von Neumann
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 1.25
      - 3.32
    * - :ref:`cortex_m33`
      - Von Neumann
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 1.25
      - 3.32
    * - :ref:`cortex_m7`
      - Von Neumann
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 2.14
      - 5.04



Cortex-R
----------

Cortex-R5
~~~~~~~~~~~~~~

.. _cortex_a:

Cortex-A
----------

.. _cortex_a7:

Cortex-A7
~~~~~~~~~~~~~~


性能测试
----------

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

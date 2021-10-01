
.. _arm:

ARM
============

.. contents::
    :local:

.. _cortex_spec:

Architecture
-------------

.. toctree::
    :maxdepth: 1

    AMBA <amba>

架构演化
~~~~~~~~~~~~~~

.. image:: ./images/arm.png
    :target: https://developer.arm.com/ip-products/processors

.. note::
    ARM公司在经典处理器ARM11以后的产品改用Cortex命名，并分成A、R和M三类，旨在为各种不同的市场提供服务。Cortex系列属于ARMv7架构，这是2010年止ARM公司最新的指令集架构。


Von Neumann
~~~~~~~~~~~~~~


ARMv6
-------------

.. _arm7:

ARM7
~~~~~~~~~~~~~~

ARM7EJ
^^^^^^^^^^^^^



.. _arm9:

ARM9
~~~~~~~~~~~~~~

.. _arm11:

ARM11
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - Freq
      - RAM
      - Flash
      - Process
      - Package
    * - :ref:`bcm2835`
      - :ref:`arm11`
      - 1.0 GHz
      -
      -
      -
      -




.. _armv7:

ARMv7
-------------


ARMv7架构定义了三大分工明确的系列：

* “A”系列面向尖端的基于虚拟内存的操作系统和用户应用；
* “R”系列针对实时系统；
* “M”系列对微控制器。

.. contents::
    :local:


.. _cortex_m:

Cortex-M
~~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    cortexM0
    cortexM23
    cortexM3
    cortexM4
    cortexM33
    cortexM7

M内核对比
^^^^^^^^^^^^^

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
      -
      - 2
      - Thumb
      - ARMv6-M
      - 56
      - 0.94
      - 2.42
    * - :ref:`cortex_m23`
      -
      - 2
      - Thumb/Thumb-2
      - ARMv8-M
      - 80
      - 0.94
      - 2.42
    * - :ref:`cortex_m3`
      -
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 1.25
      - 3.32
    * - :ref:`cortex_m4`
      -
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 1.25
      - 3.32
    * - :ref:`cortex_m33`
      -
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 1.25
      - 3.32
    * - :ref:`cortex_m7`
      -
      - 3
      - Thumb/Thumb-2
      - ARMv7-M
      - 80
      - 2.14
      - 5.04


.. _cortex_r:

Cortex-R
~~~~~~~~~~~~~~

.. _cortex_r5:

Cortex-R5
^^^^^^^^^^^^^

R内核对比
^^^^^^^^^^^^^


.. _cortex_a:

Cortex-A
~~~~~~~~~~~~~~

.. _cortex_a7:

Cortex-A7
^^^^^^^^^^^^^

A内核对比
^^^^^^^^^^^^^

.. _armv8:

ARMv8
-------------

ARMv8是ARM版本升级以来最大的一次改变，ARMv8的架构继承以往ARMv7与之前处理器技术的基础，除了现有的16/32bit的Thumb2指令支持外，也向前兼容现有的A32(ARM 32bit)指令集，扩充了基于64bit的AArch64架构，除了新增A64(ARM 64bit)指令集外，也扩充了现有的A32(ARM 32bit)和T32(Thumb2 32bit）指令集；

.. image:: ./images/armv8.png
    :target: https://blog.csdn.net/tanli20090506/article/details/71435777

从2011年11月发布ARMv8开始，ARMv8已经走过将近10年时间。ARMv8架构的主要特点是增加对64位指令集的支持，包括目前性能最强的Cortex-X1/A78，都是基于ARMv8.x指令集打造。


.. _armv9:

ARMv9
-------------

ARMv9指令集在兼容ARMv8的基础上，提升处理器性能，同时提升安全性、增强矢量计算、机器学习及数字信号处理。基于ARMv9开发的处理器预计将在2022年初正式商用，可能高通下一代骁龙895等SoC。

与上一代的ARMv8相比，ARMv9处理器将不再局限于移动/嵌入式市场，现已经扩展到PC、HPC高性能计算、深度学习等新市场，以满足全球对功能日益强大的安全、人工智能(AI)和无处不在的专用处理的需求。

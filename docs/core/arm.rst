
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

Von Neumann
~~~~~~~~~~~~~~

冯·诺依曼结构，又称为普林斯顿体系结构，是一种将程序指令存储器和数据存储器合并在一起的存储器结构。取指令和取操作数都在同一总线上，通过分时复用的方式进行；缺点是在高速运行时，不能达到同时取指令和取操作数，从而形成了传输过程的瓶颈。由于程序指令存储地址和数据存储地址指向同一个存储器的不同物理位置，因此程序指令和数据的宽度相同。

.. image:: ./images/Neumann.png
    :target: https://blog.csdn.net/u014470361/article/details/79774331

Harvard
~~~~~~~~~~~~~~

哈佛结构是一种将程序指令存储和数据存储分开的存储器结构，它的主要特点是将程序和数据存储在不同的存储空间中，即程序存储器和数据存储器是两个独立的存储器，每个存储器独立编址、独立访问，目的是为了减轻程序运行时的访存瓶颈。

哈佛结构的中央处理器首先到程序指令储存器中读取程序指令内容，解码后得到数据地址，再到相应的数据储存器中读取数据，并进行下一步的操作（通常是执行）。程序指令储存和数据储存分开，数据和指令的储存可以同时进行，可以使指令和数据有不同的数据宽度，如Microchip公司的PIC16芯片的程序指令是14位宽度，而数据是8位宽度。

.. image:: ./images/Harvard.png
    :target: https://blog.csdn.net/u014470361/article/details/79774331
.. image:: ./images/Harvarde.png
    :target: https://blog.csdn.net/u014470361/article/details/79774331

.. note::
    :ref:`cortex_m` 系列是哈佛结构，而 :ref:`cortex_a` 是冯诺依曼结构（更准确说SoC是混合结构）

Classic
-------------

``ARMv6`` ``ARMv5`` ``ARM7`` ``ARM9`` ``ARM11``

.. image:: ./images/arm.png
    :target: https://developer.arm.com/ip-products/processors


* ARMv4：ARM7TDMI、ARM720T、ARM9TDMI、ARM940T、ARM920T、Intel的StrongARM等。
* ARMv5TE：ARM9E-S、ARM966E-S、ARM1020E、ARM1022E 以及XScale
* ARMv5EJ：ARM9EJ-S、ARM926EJ-S、ARM7EJ-S、ARM1026EJ-S

其中后缀意义如下：

* E：增强型DSP指令集。包括全部算法和16位乘法操作。
* J：支持新的Java。

ARMv6(ARM11系列)：

ARM1136J(F)-S基于ARMv6主要特性有SIMD、Thumb、Jazelle、DBX、(VFP)、MMU。

ARM1156T2(F)-S基于ARMv6T2 主要特性有SIMD、Thumb-2、(VFP)、MPU。

ARM1176JZ(F)-S基于ARMv6KZ 在 ARM1136EJ(F)-S 基础上增加MMU、TrustZone。

ARM11 MPCore基于ARMv6K 在ARM1136EJ(F)-S基础上可以包括1-4 核SMP、MMU。

.. _arm7:

ARM7
~~~~~~~~~~~~~~

低功耗的32位RISC处理器，冯·诺依曼结构。
具有嵌入式ICE－RT逻辑，调试开发方便。
3级流水线结构。能够提供0.9MIPS的三级流水线结构
代码密度高，兼容16位的Thumb指令集。
对操作系统的支持广泛，包括Windows CE、Linux、Palm OS等。
指令系统与ARM9系列、ARM9E系列和ARM10E系列兼容，便于用户的产品升级换代。
主频最高可达130MIPS。


ARM7TDMI微处理器4种类型：ARM7TDMI、ARM7TDMI-S、ARM720T、ARM7EJ。

.. note::
    ARM7TMDI是使用很广泛的32位嵌入式RISC处理器，属低端ARM处理器核。


.. _arm9:

ARM9
~~~~~~~~~~~~~~

5级整数流水线，哈佛体系结构。支持32位ARM指令集和16位Thumb指令集。全性能的MMU，支持Windows CE、Linux、Palm OS等多种主流嵌入式操作系统。支持数据Cache和指令Cache，具有更高的指令和数据处理能力。

* ARM9类型：ARM920T、ARM922T和ARM940T
* ARM9E类型：ARM926EJ-S、ARM946E-S和ARM966E-S

.. hint::
    ARM9E支持DSP指令集，支持VFP9浮点处理协处理器，主频最高可达300MIPS。


.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Freq
      - RAM
      - Flash
      - Process
      - Package
    * - :ref:`sp7021`
      - :ref:`arm926ejs`
      - 1.0 GHz
      -
      -
      -
      -



.. _arm926ejs:

ARM926EJ-S
^^^^^^^^^^^^^


.. _arm11:

ARM11
~~~~~~~~~~~~~~

.. hint::
    指令集ARMv6，8级流水线，1.25DMIPS/MHz


.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Freq
      - RAM
      - Flash
      - Process
      - Package
    * - :ref:`bcm2835`
      - :ref:`arm1176jz`
      - 1.0 GHz
      -
      -
      -
      -


.. _arm1176jz:

ARM1176JZ
^^^^^^^^^^^^^

共有40个32位寄存器，其中有33个通用寄存器，7个状态寄存器，其中R0-R12用于作为通用寄存器使用，用于存储数据或者数据的地址。R13,R14,R15有特殊用途


.. _armv7:

ARMv7
-------------

.. contents::
    :local:

.. note::
    ARM公司在经典处理器ARM11以后的产品改用Cortex命名，并分成A、R和M三类，旨在为各种不同的市场提供服务。Cortex系列属于ARMv7架构，这是2010年止ARM公司最新的指令集架构。


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

.. _cortex_a72:

Cortex-A72
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

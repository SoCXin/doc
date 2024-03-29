
.. _riscv:

RISC-V
==================

`第五代精简指令集RISC-V <https://github.com/SoCXin/RISC-V>`_ 开放指令集架构(ISA)， `BSD License <https://docs.os-q.com/license.html>`_ ，2010年始于加州大学伯克利分校。

* 模块化：RISC-V将不同的部分以模块化的方式组织在一起，并试图通过一套统一的架构来满足各种不同的应用场景，这种模块化是x86与ARM架构所不具备的。
* 指令数少：受益于短小精悍的架构以及模块化的特性，RISC-V架构的指令数目非常的简洁。基本的RISC-V指令数目仅有40多条，加上其他的模块化扩展指令也总共只有几十条指令。


.. contents::
    :local:
    :depth: 1


.. _andes:

Andes
--------------

`晶心科技 Andes Technology <https://www.andestech.com/>`_

.. contents::
    :local:
    :depth: 1

.. image:: ./images/AndesCore-2.png
    :target: https://www.andestech.com/cn/risc-vandes/


.. _andes_d45:

Andes D45
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`andes_d45`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`performance`
    * - :ref:`hpm6750`
      - 816 MHz
      -
      -
    * - :ref:`hpm6350`
      - 648 MHz
      -
      -




.. _xt:

XuanTie
--------------

.. contents::
    :local:
    :depth: 1

.. _xt_c906:

C906
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`xt_c906`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`performance`
    * - :ref:`bl808`
      - 480MHz
      -
      -
    * - :ref:`f133`
      -
      -
      -
    * - :ref:`k230`
      -
      -
      -


.. _xt_e907:

E907
~~~~~~~~~~~~~~
``32 bit``

.. list-table::
    :header-rows:  1

    * - :ref:`xt_e907`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`performance`
    * - :ref:`bl808`
      - 320MHz
      -
      -


* 支持 RISC-V RV32IMA[F][D]C[P] 指令集；
* 支持 RISC-V 32/16 位混编指令集；
* 支持 RISC-V 机器模式和用户模式；
* 32 个 32 位整型通用寄存器，32 个 32 位/64 位浮点通用寄存器；
* 整型 5 级/浮点 7 级，单发射，顺序执行流水线；
* 支持 AXI4.0 主设备接口以及 AHB5.0 外设接口；
* 指令 cache，两路组相连结构，2KB-32KB 可配置；
* 数据 cache，两路组相连结构，2KB-32KB 可配置；
* 支持非对齐内存访问；
* 双周期硬件乘法器，基4硬件除法器；
* 可选配 BHT 和 BTB；
* 支持平头哥扩展增强指令集；
* 支持平头哥 MCU 特性扩展技术，包括中断处理加速技术、MCU 扩展特性；
* 兼容 RISC-V CLIC 中断标准，支持中断嵌套，外部中断源数量最高可配置 240 个；
* 兼容 RISC-V PMP 内存保护标准，0/4/8/12/16 区域可配置；
* 支持可配的性能监测单元；
* 支持 RISC-V Debug 协议标准；
* 频率 >1.0GHz@T28 HPCPlus, 9T SVT(worst case), Coremark > 3.8 coremark/MHz, Dhrystone >2.0DMIPS/MHz。

.. _xt_e902:

E902
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`xt_e902`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`performance`
    * - :ref:`bl808`
      - 160MHz
      -
      -


.. _xt804:

XT804
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`xt804`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`performance`
    * - :ref:`w801`
      - 240MHz
      -
      -


.. _qingke:

Qingke
--------------
``WCH`` ``青稞``

.. list-table::
    :header-rows:  1

    * - :ref:`wch_riscv`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`performance`
    * - :ref:`wch_riscv2a`
      -
      -
      -
    * - :ref:`wch_riscv3a`
      -
      -
      -
    * - :ref:`wch_riscv4a`
      -
      -
      -
    * - :ref:`wch_riscv4b`
      -
      -
      -
    * - :ref:`wch_riscv4c`
      -
      -
      -
    * - :ref:`wch_riscv4f`
      -
      -
      -


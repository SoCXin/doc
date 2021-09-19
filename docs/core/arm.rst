
.. _arm:

ARM
============

.. image:: ./images/arm.png
    :target: https://developer.arm.com/ip-products/processors

.. note::
    ARM公司在经典处理器ARM11以后的产品改用Cortex命名，并分成A、R和M三类，旨在为各种不同的市场提供服务。Cortex系列属于ARMv7架构，这是2010年止ARM公司最新的指令集架构。

.. contents::
    :local:

.. _cortex_spec:

Architecture
-------------

.. toctree::
    :maxdepth: 1

    AMBA <amba>

ARM7
-------------

相关产品
~~~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    MT2503 <../MediaTek/MT2503>


ARM9
-------------

ARM11
-------------


.. _cortex:

Cortex
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

M系列内核对比
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
~~~~~~~~~~~~~~

Cortex-R5
^^^^^^^^^^^^^

.. _cortex_a:

Cortex-A
~~~~~~~~~~~~~~

.. _cortex_a7:

Cortex-A7
^^^^^^^^^^^^^


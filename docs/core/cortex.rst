
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
    cortexM3
    cortexM4
    cortexM33
    cortexM7

内核对比
~~~~~~~~~~~~~~

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
      - 2.
      - 1024
      - 4/1
      - 5.1
      - 2
      - NO
    * - :ref:`cortex_m7`
      - 2.14
      - 2.
      - 1024
      - 4/1
      - 5.1
      - 2
      - NO


Cortex-R
----------

``Cortex-R5``
~~~~~~~~~~~~~~

Cortex-A
----------

``Cortex-A7``
~~~~~~~~~~~~~~



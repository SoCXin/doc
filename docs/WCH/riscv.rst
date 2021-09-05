.. _wch_riscv:

WCH RISC-V
======================

:ref:`wch` :ref:`riscv` 针对安全类产品，早期外购第三方RISC-V内核，但当时该IP尚未成熟只支持4线JTAG调试占用IO多，内核架构庞大未针对嵌入式应用优化。

2017年开始关注并研究RISC-V开源指令集的32位MCU架构，针对快速中断响应、 高带宽数据DMA进行优化。形成了侧重于低功耗或高性能等多版本的RISC-V处理器。
2019年推出基于RISC-V3A处理器的CH32V103单片机，内嵌BLE低功耗蓝牙的CH57X系列，
2020年初推出128位数据宽度和双层DMA架构的高吞吐量的CH56X系列，现已扩展出浮点型V4F，精简型V2A，增强型V3A/V4A/V4B/V4C等内核产品。

.. contents::
    :local:


RISC-V版本
--------------------


.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART/SPI
      - BLE
      - USB
      - Ethernet
    * - :ref:`wch_riscv4a`
      - 1
      - 32K
      - 250K
      - 4/2
      - 4.2(+5dBm)
      - USB H/D
      - 10M
    * - :ref:`wch_riscv4b`
      - 20M
      - 18K
      - 512K
      - 4/1
      - 4.2(+5dBm)
      - USB H/D
      - NO
    * - :ref:`wch_riscv4c`
      - 20
      - 32
      - 10
      - 4
      - 5
      - 2
      - NO
    * - :ref:`wch_riscv4f`
      - 20
      - 32
      - 10
      - 4
      - 5
      - 2
      - NO
    * - :ref:`wch_riscv3a`
      - 20
      - 32
      - 10
      - 4
      - 5
      - 2
      - NO


.. _wch_riscv4a:

RISC-V4A
~~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    CH583 <CH583>

.. _wch_riscv4b:

RISC-V4B
~~~~~~~~~~~~~~

.. _wch_riscv4c:

RISC-V4C
~~~~~~~~~~~~~~

.. _wch_riscv4f:

RISC-V4F
~~~~~~~~~~~~~~


.. _wch_riscv3a:

RISC-V3A
~~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    CH573 <CH573>
    CH569 <CH569>


RISC-V产品
--------------------
.. contents::
    :local:


高性能产品
~~~~~~~~~~~~

.. image:: ./images/CH32V.png
    :target: http://special.wch.cn/zh_cn/mcu/


.. toctree::
    :maxdepth: 1

    CH32V103 <CH32V103>
    CH32V307 <CH32V307>
    CH32V208 <CH32V208>

低功耗产品
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH573 <CH573>
    CH583 <CH583>


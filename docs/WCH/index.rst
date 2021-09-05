
.. _wch:

WCH
============

.. note::
    南京沁恒微电子成立于2004年，是一家专注于连接技术和MCU内核研究的射频与高速数模混合集成电路设计公司，提供以太网、蓝牙无线网络、USB和PCI类等接口芯片及集成上述接口的MCU+单片机。

.. contents::
    :local:
    :depth: 1

方案分类
--------------------
.. contents::
    :local:

.. hint::
    :ref:`wch` 非常有特色的一家公司，产品线偏向于富裕的通信外设，基本标配USB外设，然后在集成度上比较高。

USB+UARTs
~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Mark
      - RAM
      - Flash
      - UART/SPI
      - BLE
      - USB
      - Ethernet
    * - :ref:`ch579`
      - 40MHz
      - 32K
      - 250K
      - 4/2
      - 4.2(+5dBm)
      - USB H/D
      - 10M
    * - :ref:`ch573`
      - :ref:`riscv` 20M
      - 18K
      - 512K
      - 4/1
      - 4.2(+5dBm)
      - USB H/D
      - NO
    * - :ref:`ch583`
      - :ref:`riscv` 20M
      - 32K
      - 1024K
      - 4/1
      - 5.1(+5dBm)
      - 2 x USB
      - NO

USB H+D
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH545 <CH545>
    CH557 <CH557>

内核分类
--------------------

.. toctree::
    :maxdepth: 2

    8051产品  <mcs51>
    Cortex产品  <cortex>
    RISC-V产品  <riscv>




.. _wch:

WCH
============

``RISC-V`` ``USB`` ``Ethernet`` ``BLE``

.. contents::
    :local:

公司简介
-----------

.. note::
    南京沁恒微电子成立于2004年，是一家专注于连接技术和MCU内核研究的射频与高速数模混合集成电路设计公司，提供以太网、蓝牙无线网络、USB和PCI类等接口芯片及集成上述接口的MCU+单片机。


方案分类
-------------

.. contents::
    :local:


BLE +
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH573 <CH573>
    CH583 <CH583>


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
      - :ref:`wch_riscv3a`
      - 18K
      - 512K
      - 4/1
      - 4.2(+5dBm)
      - USB H/D
      - NO
    * - :ref:`ch583`
      - :ref:`wch_riscv4a`
      - 32K
      - 1024K
      - 4/1
      - 5.1(+5dBm)
      - 2 x USB
      - NO

ETH +
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH579 <CH579>
    CH563 <CH563>

USB +
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH545 <CH545>
    CH557 <CH557>




.. hint::
    :ref:`wch` 非常有特色的一家公司，产品线偏向于富裕的通信外设，基本标配USB外设，然后在集成度上比较高。


内核分类
------------------
.. contents::
    :local:

MCS-51
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH552 <CH552>
    CH554 <CH554>
    CH549 <CH549>


Cortex
~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    CH32F103 <CH32F103>
    CH32F207 <CH32F207>
    CH32F208 <CH32F208>

.. note::
    2012年起陆续引入Cortex-M内核，我们加入了网络、USB2.0等高速接口，并设计了高速DMA仲裁机制，推出CH32F103等通用MCU芯片，适用于软件兼容、硬件引脚兼容、接口更专业的成熟生态应用。

.. image:: ./images/CH32F.png
    :target: http://special.wch.cn/zh_cn/mcu/

RISC-V
~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    RISC-V  <riscv>
    CH32V103 <CH32V103>
    CH32V307 <CH32V307>
    CH32V208 <CH32V208>
    CH568 <CH568>
    CH569 <CH569>

.. image:: ./images/CH32V.png
    :target: http://special.wch.cn/zh_cn/mcu/


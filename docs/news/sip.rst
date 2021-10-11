
.. _sip:

集成Xin榜
====================

.. contents::
    :local:

.. _eth_phy:

ETH-PHY
-------------



芯片集成以太网PHY器件，不再需要外部连接PHY芯片

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - :ref:`eth_mac`
      - :ref:`eth_phy`
      - Package
    * - :ref:`ch563`
      - :ref:`arm7`
      - 64KB
      - 224KB
      - 100M
      - 100M
      - LQFP64M(10x10)
    * - W7500P
      - :ref:`cortex_m0`
      - 32KB
      - 128KB
      - 10M
      - 10M
      - LQFP64(7x7)

.. hint::
    在封装内同时集成以太网MAC+PHY，集成以太网phy发热巨大影响芯片稳定性，特别是空间足够的情况下需要慎重考量。

.. _eth_mac:

ETH-MAC
~~~~~~~~~~~~~~

 ``MII/RMII``



.. _eth_phy_tiny:

ETH-Tiny
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - USB
      - BLE
      - :ref:`eth_phy`
      - Package
    * - :ref:`ch32v208`
      - :ref:`wch_riscv4c`
      - 64KB
      - 128KB
      - 2 x H/D
      - 5.1
      - 10M
      - :ref:`qfn28`
    * - :ref:`ch579`
      - :ref:`cortex_m0`
      - 32KB
      - 250KB
      - H/D
      - 4.2
      - 10M
      - :ref:`qfn28`


.. _qfn28:

QFN28
^^^^^^^^^^^

.. image:: ./images/QFN28.png


.. hint::
    如果在受限的体积内实现以太网功能，QFN28是个不错的选择。

.. _usb_phy:

USB-PHY
-------------

.. _usb_hs_phy:

USB-HS-PHY
~~~~~~~~~~~~~

``USB HS PHY`` ``480Mbps``

芯片集成USB2.0 HS PHY器件实现高速通信(480Mbps)，在该细分领域上 :ref:`st` 的STM32F7系列部分型号有USB2.0 PHY集成的方案。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - :ref:`usb_hs_phy`
      - :ref:`eth_phy`
      - :ref:`eth_mac`
    * - :ref:`ch563`
      - :ref:`arm7`
      - 64 KB
      - 224 KB
      - 480M
      - 100M
      - 1000M
    * - :ref:`ch32f207`
      - :ref:`cortex_m3`
      - 64 KB
      - 256 KB
      - 480M
      - 100M
      - 1000M
    * - :ref:`ch32v307`
      - :ref:`wch_riscv4a`
      - 64 KB
      - 256 KB
      - 480M
      - 100M
      - 1000M

.. _usb_ss_phy:

USB-SS-PHY
~~~~~~~~~~~~~

``USB SS PHY`` ``5Gbps``

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - USB Num
      - USB Type
      - :ref:`usb_hs_phy`
      - :ref:`usb_ss_phy`
      - USB Hub
    * - :ref:`ch569`
      - :ref:`wch_riscv3a`
      - 1
      - OTG
      - √
      - √
      - √


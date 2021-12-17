
.. _iot:

IoT
============

.. contents::
    :local:


主要收录典型的连接类SoC芯片，覆盖典型的IoT场景中，本业列举都是作者推荐的产品。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - :ref:`ethernet`
      - :ref:`hplc`
      - :ref:`wifi`
      - :ref:`ble`
      - :ref:`lora`
      - :ref:`nbiot`
    * - 连接性
      - 150
      - 8
      - 16
      - 2
      - NO
      - NO

.. _ethernet:

Ethernet
-----------

.. contents::
    :local:


`LwIP <http://savannah.nongnu.org/projects/lwip/>`_ (Light weight IP) 用少量的资源消耗(RAM)实现一个较为完整的 TCP/IP 协议栈，其中“完整”主要指的是 TCP 协议的完整性， 实现的重点是在保持 TCP 协议主要功能的基础上减少对 RAM 的占用，LwIP也可以在无操作系统的情况下独立运行。

LwIP实现的重点是在保持TCP协议主要功能的基础上减少对RAM 的占用，它只需十几KB的RAM和40K左右的ROM就可以运行，这使LwIP协议栈适合在低端的嵌入式系统中使用。

LwIP具有主要特性：

* 1）支持 ARP 协议（以太网地址解析协议）。
* 2）支持 ICMP 协议（控制报文协议），用于网络的调试与维护。
* 3）支持 IGMP 协议（互联网组管理协议），可以实现多播数据的接收。
* 4）支持 UDP 协议(用户数据报协议)。
* 5）支持 TCP 协议(传输控制协议)，包括阻塞控制、 RTT 估算、快速恢复和快速转发。
* 6）支持 PPP 协议（点对点通信协议） ，支持 PPPoE。
* 7）支持 DNS（域名解析）。
* 8）支持 DHCP 协议，动态分配 IP 地址。
* 9）支持 IP 协议，包括 IPv4、 IPv6 协议，支持 IP 分片与重装功能，多网络接口下的数据包转发。
* 10）支持 SNMP 协议（简单网络管理协议）。
* 11）支持 AUTOIP，自动 IP 地址配置。
* 12）提供专门的内部回调接口(Raw API)，用于提高应用程序性能。
* 13）提供可选择的 Socket API、 NETCONN API (在多线程情况下使用) 。


.. hint::
    要求配置多串口，可用于实现以太网和串口上下通信。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Mark
      - RAM
      - ROM
      - UART
      - CAN
      - USB
      - :ref:`eth_mac`
    * - :ref:`stm32f207`
      - 150 DMIPS
      - 8/16
      - 16/32/64
      - 2
      - NO
      - NO
      - NO
    * - :ref:`stm32f407`
      - 175 DMIPS
      - 32
      - 64/128/256
      - 2/3/5
      - 2.0B
      - USB OTG
      - NO
    * - :ref:`ch32f207`
      - 250 DMIPS
      - 16/32/64
      - 64/128/256
      - 2/3/5
      - 2 x 2.0B
      - USB2.0
      - NO
    * - :ref:`ch32v307`
      - 300 DMIPS
      - 224
      - 256/512/1024
      - 7/8
      - 2 x 2.0B
      - USB2.0
      - NO
    * - :ref:`at32f407`
      - 300 DMIPS
      - 224
      - 256/512/1024
      - 8
      - 2 x 2.0B
      - USB2.0
      - 10/100M
    * - :ref:`esp32`
      - 150 DMIPS
      - 8/16
      - 16/32/64
      - 2
      - NO
      - NO
      - NO
    * - :ref:`ch579`
      - 175 DMIPS
      - 32
      - 64/128/256
      - 2/3/5
      - 2.0B
      - USB OTG
      - NO
    * - :ref:`ch32f208`
      - 150 DMIPS
      - 8/16
      - 16/32/64
      - 2
      - NO
      - NO
      - NO
    * - :ref:`ch32v208`
      - 175 DMIPS
      - 32
      - 64/128/256
      - 2/3/5
      - 2.0B
      - USB OTG
      - NO

.. _hplc:

HPLC
----------



.. _wifi:

WiFi
-----------


.. toctree::
    :maxdepth: 1

    W806 <../M/W806>
    W800 <../M/W800>
    Hi3861 <../M/Hi3861>

.. hint::
    大部分此类芯片不仅具备WiFi接入能力，还同时具有BLE连接能力。

.. list-table::
    :header-rows:  1

    * - Rank
      - Core
      - RAM
      - Flash
      - WiFi
      - Rate
      - More
      - Package
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 520KB
      - XIP
      - 1T1R b/g/n
      - 150 Mbps
      - BLE v4.2
      - QFN48
    * - :ref:`esp32c3`
      - :ref:`riscv`
      - 400KB
      - 384KB
      - 1T1R b/g/n
      - 150 Mbps
      - BLE 5.0
      - QFN32
    * - :ref:`w806`
      - :ref:`xt804`
      - 288 KB
      - 2 MB
      - 1T1R b/g/n
      - 150 Mbps
      - BLE v4.2
      - :ref:`w800_qfn32`

.. _ble:

BLE
----------

.. toctree::
    :maxdepth: 1

    nRF52832 <../M/nRF52832>


.. list-table::
    :header-rows:  1

    * - Rank
      - Core
      - RAM
      - Flash
      - WiFi
      - Rate
      - More
      - Package
    * - :ref:`ch583`
      - :ref:`wch_riscv4a`
      -
      -
      -
      -
      -
      - QFN28
    * - :ref:`ch573`
      - :ref:`wch_riscv3a`
      -
      -
      -
      -
      -
      - QFN28


.. _lora:

LoRa
----------

.. toctree::
    :maxdepth: 1

    ASR6501 <../M/ASR6501>

.. list-table::
    :header-rows:  1

    * - Rank
      - Core
      - RAM
      - Flash
      - LoRa
      - Rate
      - More
      - Package
    * - :ref:`asr6501`
      - :ref:`cortex_m0`
      -
      -
      -
      -
      -
      - QFN48
    * - :ref:`stm32wl5`
      - :ref:`cortex_m4`
      -
      -
      -
      -
      -
      - QFN48


.. _nbiot:

NB-IoT
-----------

.. toctree::
    :maxdepth: 1

    XY1100 <../M/XY1100>




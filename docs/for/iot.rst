
.. _iot:

IoT
============

.. contents::
    :local:

Ethernet
-----------

.. contents::
    :local:


网络协议
~~~~~~~~~~~~~~

LWIP

嵌入平台
~~~~~~~~~~~~~~

串口网关
^^^^^^^^^^^

.. hint::
    要求配置6串口以上，可用于实现以太网和串口上下通信。

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


无线网关
^^^^^^^^^^^

.. hint::
    要求配置下行无线通信能力，可以连接以太网并通过无线网络分发。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Mark
      - RAM
      - ROM
      - BLE
      - CAN
      - USB
      - MAC
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

.. _wifi:

WiFi
-----------

嵌入平台
~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    W806 <../M/W806>
    W800 <../M/W800>

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
    * - :ref:`w800`
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

嵌入平台
~~~~~~~~~~

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


嵌入平台
~~~~~~~~~~

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



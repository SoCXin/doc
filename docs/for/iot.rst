
.. _iot:

IoT
============

.. contents::
    :local:

Ethernet
-----------
.. hint::
    具备以太网通信硬件，至少片上集成以太网MAC。

.. contents::
    :local:


串口通信(下行)
~~~~~~~~~~~~~~

.. hint::
    要求配置6串口以上，可用于实现以太网和串口上下通信。

.. list-table::
    :header-rows:  1

    * - Name
      - Mark
      - RAM
      - ROM
      - UART
      - CAN
      - USB
      - MAC
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


无线通信(下行)
~~~~~~~~~~~~~~

.. hint::
    要求配置下行无线通信能力，可以连接以太网并通过无线网络分发。

.. list-table::
    :header-rows:  1

    * - Name
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

WiFi
-----------

.. hint::
    具备无线网络接入能力。

.. list-table::
    :header-rows:  1

    * - Name
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

Mesh
----------

BLE
~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    CH583 <../WCH/CH583>
    CH573 <../WCH/CH573>
    ESP32-H2 <../espressif/ESP32-H2>

LoRa
~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    ASR6501 <../H/ASR6501>
    STM32WLE5 <../ST/M/STM32WLE5>

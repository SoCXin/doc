
.. _iot:

IoT
============

.. contents::
    :local:


主要收录典型的连接类SoC芯片，覆盖典型的IoT场景中，本业列举都是作者推荐的产品。

.. list-table::
    :header-rows:  1

    * - 对比项目
      - :ref:`ethernet`
      - :ref:`plc`
      - :ref:`ble`
      - :ref:`wifi`
      - :ref:`lora`
      - :ref:`nbiot`
      - :ref:`cat1`
    * - 通信距离
      -
      -
      -
      -
      -
      -
      -
    * - 部署成本
      -
      -
      -
      -
      -
      -
      -
    * - 改造成本
      -
      -
      -
      -
      -
      -
      -
    * - 易用性
      -
      -
      -
      -
      -
      -
      -
    * - 扩展性
      -
      -
      -
      -
      -
      -
      -

.. _ethernet:

Ethernet
-----------

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Performance
      - SRAM/ROM
      - UART/SPI
      - USB/CAN
      - ETH-MAC
      - ETH-PHY
    * - :ref:`stm32f207`
      - 150DMIPS
      - 128KB/512KB
      - 6/3
      - HSOTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`stm32f407`
      - 210DMIPS
      - 192KB/1MB
      - 6/3
      - HSOTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`at32f407`
      - 360DMIPS
      - 192KB/1MB
      - 8/3
      - OTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`esp32`
      - 600DMIPS
      - 520KB/4MB
      - 2/2
      -
      - 100Mbps
      - NO
    * - :ref:`ch579`
      - 36DMIPS
      - 32KB/256KB
      - 4/2
      - OTG
      - 10Mbps
      - 10Mbps
    * - :ref:`ch32v307`
      - 240DMIPS
      - 64KB/256KB
      - 8/3
      - HS-OTG/2.0B
      - 1000Mbps
      - 10Mbps


`延伸阅读 <https://docs.qitas.cn/interface/bus.html#id5>`_


.. _plc:

PLC
----------

电力线载波通信(PLC,即Power Line Communication)是电力系统特有的通信方式，这是一种利用现有交流或直流电力线，通过载波方式将模拟或数字信号进行高速传输的技术。其最大的特点是不需要重新架设网络，只要有电线，就能进行数据传输。该技术是通过调制把原有信号变成高频信号加载到电力线进行传输，在接收端通过滤波器将调制信号取出解调，得到原有信号，实现信息传递。


.. list-table::
    :header-rows:  1

    * - #define
      - Core
      - RAM
      - Flash
      - WiFi
      - Rate
      - More
      - Package
    * - :ref:`cr600`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`hi3921`
      -
      -
      -
      -
      -
      -
      -


.. toctree::
    :maxdepth: 1

    CR600 <../M/CR600>
    CR710 <../M/CR710>
    Hi3921 <../M/Hi3921>

.. note::
    电力线载波通信（power line carrier communication）以输电线路为载波信号的传输媒介的电力系统通信。


.. _ble:

BLE
----------


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

.. toctree::
    :maxdepth: 1

    nRF52832 <../M/nRF52832>



.. _wifi:

WiFi
-----------

.. list-table::
    :header-rows:  1

    * - #define
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


.. toctree::
    :maxdepth: 1

    W801 <../M/W801>
    W806 <../M/W806>
    Air101 <../M/Air101>
    Air103 <../M/Air103>
    Hi3861 <../M/Hi3861>

.. hint::
    大部分此类芯片不仅具备WiFi接入能力，还同时具有BLE连接能力。




.. _lora:

LoRa
----------

.. toctree::
    :maxdepth: 1

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

    * - #define
      - Core
      - RAM
      - Flash
      - LoRa
      - Rate
      - More
      - Package
    * - :ref:`mt2625`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`xy1100`
      -
      -
      -
      -
      -
      -
      -

.. toctree::
    :maxdepth: 1

    XY1100 <../M/XY1100>


.. _cat1:

Cat.1
-----------

.. image:: ./images/VS.jpg

.. image:: ./images/cat.jpg


.. list-table::
    :header-rows:  1

    * - #define
      - Core
      - RAM
      - Flash
      - LoRa
      - Rate
      - More
      - Package
    * - :ref:`asr1601`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`usi8910`
      -
      -
      -
      -
      -
      -
      -

.. toctree::
    :maxdepth: 1

    USI8910DM <../H/USI8910DM>





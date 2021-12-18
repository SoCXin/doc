
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
      - :ref:`wifi`
      - :ref:`ble`
      - :ref:`lora`
      - :ref:`nbiot`
    * - 通信距离
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
    * - 扩展性
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
    * - 改造成本
      -
      -
      -
      -
      -
      -


.. _ethernet:

Ethernet
-----------

`延伸阅读 <https://docs.qitas.cn/interface/bus.html#id5>`_

.. contents::
    :local:


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

.. _plc:

PLC
----------

电力线载波通信(PLC,即Power Line Communication)是电力系统特有的通信方式，这是一种利用现有交流或直流电力线，通过载波方式将模拟或数字信号进行高速传输的技术。其最大的特点是不需要重新架设网络，只要有电线，就能进行数据传输。该技术是通过调制把原有信号变成高频信号加载到电力线进行传输，在接收端通过滤波器将调制信号取出解调，得到原有信号，实现信息传递。

.. note::
    电力线载波通信（power line carrier communication）以输电线路为载波信号的传输媒介的电力系统通信。

.. toctree::
    :maxdepth: 1

    CR600 <../M/CR600>
    Hi3921 <../M/Hi3921>

.. _wifi:

WiFi
-----------


.. toctree::
    :maxdepth: 1

    W806 <../M/W806>
    W800 <../M/W800>
    Air101 <../M/Air101>
    Hi3861 <../M/Hi3861>

.. hint::
    大部分此类芯片不仅具备WiFi接入能力，还同时具有BLE连接能力。


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




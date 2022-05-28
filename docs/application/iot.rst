
.. _iot:

IoT
============

.. list-table::
    :header-rows: 1

    * - :ref:`iot`
      - :ref:`can`
      - :ref:`ethernet`
      - :ref:`plc`
      - :ref:`wpan`
      - :ref:`wifi`
      - :ref:`lora`
      - :ref:`nbiot`
      - :ref:`gprs`
      - :ref:`cat1`
      - :ref:`cat4`
    * -
      - √
      - √
      -
      -
      - √
      -
      - √
      -
      -
      -


.. contents::
    :local:
    :depth: 1


.. _ethernet:

ETH
-----------

.. list-table::
    :header-rows:  1

    * - :ref:`ethernet`
      - :ref:`CoreMark`
      - SRAM/ROM
      - UART/SPI
      - USB/CAN
      - ETH-MAC
      - ETH-PHY
    * - :ref:`stm32f207`
      -
      - 128KB/512KB
      - 6/3
      - HSOTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`stm32f407`
      -
      - 192KB/1MB
      - 6/3
      - HSOTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`at32f407`
      -
      - 192KB/1MB
      - 8/3
      - OTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`esp32`
      -
      - 520KB/4MB
      - 2/2
      -
      - 100Mbps
      - NO
    * - :ref:`ch579`
      -
      - 32KB/256KB
      - 4/2
      - OTG
      - 10Mbps
      - 10Mbps
    * - :ref:`ch32v307`
      -
      - 64KB/256KB
      - 8/3
      - HS-OTG/2.0B
      - 1000Mbps
      - 10Mbps


`延伸阅读 <https://docs.qitas.cn/interface/bus.html#id5>`_

.. _router:

Router
~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`router`
      - :ref:`architecture`
      - :ref:`CoreMark`
      -
      - Switch
      - ETH-MAC
      - :ref:`wireless`
    * - :ref:`mt7622`
      - :ref:`cortex_a53`
      -
      -
      - 5p GbE
      - SGMII/RGMII
      - :ref:`wifi` + :ref:`bt`
    * - :ref:`mt7623`
      - :ref:`cortex_a7`
      -
      -
      - 5p GbE
      - SGMII/RGMII
      - :ref:`wifi`

.. _plc:

PLC
----------

电力线载波通信(PLC,即Power Line Communication)是电力系统特有的通信方式，这是一种利用现有交流或直流电力线，通过载波方式将模拟或数字信号进行高速传输的技术。其最大的特点是不需要重新架设网络，只要有电线，就能进行数据传输。该技术是通过调制把原有信号变成高频信号加载到电力线进行传输，在接收端通过滤波器将调制信号取出解调，得到原有信号，实现信息传递。


.. list-table::
    :header-rows:  1

    * - :ref:`plc`
      - :ref:`architecture`
      - SRAM/ROM
      -
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

    CR600 <../miscellaneous/CR600>
    CR710 <../miscellaneous/CR710>
    Hi3921 <../miscellaneous/Hi3921>

.. note::
    电力线载波通信（power line carrier communication）以输电线路为载波信号的传输媒介的电力系统通信。

.. _can:

CAN
-----------
``串行通信``


CAN总线，也叫做控制器局域网总线（Controller Area Network），是一种用于实时应用的串行通讯协议总线，它可以使用双绞线来传输信号，是世界上应用最广泛的现场总线之一。


.. _wpan:

WPAN
----------
``Bluetooth`` ``Zigbee`` ``RFID`` ``UWB`` ``NFC`` ``54Mbit/s`` ``802.11``

无线个域网就是在个人周围空间形成的无线网络，现通常指覆盖范围在10m半径以内的短距离无线网络，尤其是指能在便携式消费者电器和通信设备之间进行短距离特别连接的自组织网。WPAN被定位于短距离无线通信技术，但根据不同的应用场合又分为高速WPAN（HR－WPAN）和低速WPAN（LR－WPAN）两种。

.. list-table::
    :header-rows:  1

    * - :ref:`wpan`
      - :ref:`802_15_4`
      - :ref:`bt`
      - :ref:`zigbee`
      - :ref:`rfid`
    * - 距离
      -
      -
      -
      -
    * - 易用性
      -
      -
      -
      -
    * - 扩展性
      -
      -
      -
      -

.. _rfid:

RFID
~~~~~~~~~~~
``RFID`` ``NFC``

.. _802_15_4:

802.15.4
~~~~~~~~~~~
``2.4GHz/868MHz/915MHz`` ``LR-WPAN`` ``DSSS`` ``GTS``

`IEEE 802.15.4 <https://baike.baidu.com/item/IEEE%20802.15.4/6657379?fromtitle=802.15.4&fromid=1115952&fr=aladdin>`_ 是一种技术标准，它定义了低速率无线个域网（LR-WPAN）的协议。 它规定了LR-WPAN的物理层和媒体访问控制 ，并由IEEE 802.15工作组维护，该工作组在2003年定义了该标准。它是Zigbee的基础，诸如 ISA100.11a ， WirelessHART ， MiWi ， 6LoWPAN ， 线程和SNAP规范，每个规范通过开发IEEE 802.15.4中未定义的上层进一步扩展了标准。


.. list-table::
    :header-rows:  1

    * - :ref:`802_15_4`
      - :ref:`architecture`
      - SRAM/ROM
      -
      - WiFi
      - Rate
      - More
      - Package
    * - :ref:`esp32h2`
      - :ref:`esp_rv32`
      -
      -
      -
      -
      -
      -

.. _zigbee:

ZigBee
~~~~~~~~~~~
``802.15.4``


.. _bt:

Bluetooth
~~~~~~~~~~~
``802.15.1``

在蓝牙应用领域，大致可以分为两大类，一类是以蓝牙音频为主，走高性能路线，一种以物联网低功耗场景为主，特点是性价比和低功耗



.. list-table::
    :header-rows:  1

    * - :ref:`bt`
      - :ref:`architecture`
      - SRAM/ROM
      -
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


.. note::
    由于技术演进和技术门槛降低，传统的MCU厂商在其产品上添加蓝牙系列，WiFi芯片厂商也同步支持蓝牙功能，导致单纯的蓝牙芯片越来越没有优势。


.. _wifi:

Wi-Fi
-----------
``802.11``

.. list-table::
    :header-rows:  1

    * - :ref:`wifi`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - SRAM/ROM
      - Wireless
      - UART/SPI/SDIO
      - Characteristics
      - Package
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.22
      - 400KB/384KB
      - WiFi&BLE
      - 2/3/0
      -
      - :ref:`esp_qfn32`
    * - :ref:`hi3861`
      - :ref:`riscv`
      -
      - 352KB/288KB
      - WiFi
      - 3/2/1
      -
      - QFN32
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 994.26
      - 520KB/448KB
      - WiFi&BLE
      -
      -
      - :ref:`esp_qfn48`
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320KB/128KB
      - WiFi
      -
      -
      - :ref:`esp_qfn56`
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1181.6
      - 512KB/384KB
      - WiFi&BLE
      -
      -
      - :ref:`esp_qfn56`
    * - :ref:`w800`
      - :ref:`xt804`
      -
      - 288KB/2 MB
      - WiFi&BLE
      - 6/2/1
      -
      - QFN32
    * - :ref:`w801`
      - :ref:`xt804`
      -
      - 288KB/2 MB
      - WiFi&BLE
      - 6/2/1
      -
      - QFN56



.. toctree::
    :maxdepth: 1

    W801 <../miscellaneous/W801>
    Hi3861 <../miscellaneous/Hi3861>


.. note::
    大部分WiFi通信芯片不仅具备WiFi接入能力，同时具备BLE连接能力，而且不断有新的厂商进入这一领域，用户的选择范围非常广。

.. _lpwan:

LPWAN
----------
``LPWAN`` ``LPWA`` ``LPN``

LPWAN(低功耗广域网)，也称为LPWA)或LPN，是一种用于物联网(例如，以电池为电源的传感器)的类型，这是一种能够以低比特率进行远距离通信的无线网络。LPWAN可以同时满足覆盖和续航的要求。以最小的功耗提供最长的距离覆盖是LPWAN最大的技术优势。

.. _lora:

LoRa
~~~~~~~~~~~
``Long Range Radio``


.. toctree::
    :maxdepth: 1

.. list-table::
    :header-rows:  1

    * - :ref:`lora`
      - :ref:`architecture`
      - SRAM/ROM
      -
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
~~~~~~~~~~~



.. list-table::
    :header-rows:  1

    * - :ref:`nbiot`
      - :ref:`architecture`
      - SRAM/ROM
      -
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

    XY1100 <../miscellaneous/XY1100>

.. _emtc:

eMTC
~~~~~~~~~~~


.. _gprs:

GPRS
-----------

.. _cat1:

Cat.1
-----------


.. image:: ./images/cat.jpg


.. list-table::
    :header-rows:  1

    * - :ref:`cat1`
      - :ref:`architecture`
      - SRAM/ROM
      -
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




.. _cat4:

Cat.4
-----------

.. image:: ./images/VS.jpg




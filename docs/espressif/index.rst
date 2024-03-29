.. _espressif:

Espressif
==============
``Xtensa-LX7`` ``Xtensa-LX6`` ``RISC-V`` ``Matter`` ``Audio`` ``ULP`` ``Touch`` ``Wi-Fi`` ``BT/BLE`` ``ESP32`` ``ESP8266`` ``Arduino``

.. contents::
    :local:
    :depth: 1


公司简介
-----------

`乐鑫科技 <http://www.espressif.com>`_ 是一家全球化半导体设计公司，成立于2008年(股票代码688018)，总部上海张江: `IDF <https://github.com/espressif/esp-idf>`_、:ref:`wifi`、:ref:`esp_audio`


.. note::
    乐鑫伴随物联网崛起，就早期狭义的技术实现而言物联网≈ESP32/ESP8266，入门经典 :ref:`stm32f103` + :ref:`esp8266`

.. list-table::
    :header-rows:  1

    * - :ref:`espressif`
      - :ref:`esp_core`
      - :ref:`CoreMark`
      - :ref:`sram`/:ref:`flash`
      - :ref:`wireless`
      - :ref:`peripherals`
      - :ref:`esp_audio`
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 994.2(2)
      - 520KB/448KB
      - WiFi&BT4.2
      - 
      - I2S(2)/DAC/BT
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320KB/128KB
      - WiFi
      - 
      - I2S/DAC
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1181.6(2)
      - 512KB/384KB
      - WiFi&BLE5.0
      - 
      - I2S(2)
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.22
      - 400KB/384KB
      - WiFi&BLE5.0
      - 
      - I2S
    * - :ref:`esp32c2`
      - :ref:`esp_rv32`
      -
      - 272KB/576KB
      - WiFi&BLE5.0
      - 
      - I2S
    * - :ref:`esp32c6`
      - :ref:`esp_rv32`
      -
      - 400KB/384KB
      - Matter&BLE5.2
      - 
      - I2S
    * - :ref:`esp32h2`
      - :ref:`esp_rv32`
      -
      - 400KB/384KB
      - Matter&BLE5.2
      - 
      - I2S


核心优势
~~~~~~~~~~~~

乐鑫Espressif所有芯片的内核架构都基于非Arm方案，并且从工具链到开发框架都走自己特色之路，所以在资源整合和解决方案方面投入更加积极，在一定程度上规避了生态短板，直接通过方案输出的方式赋能下游。

所以选择Espressif的核心优势在于：软硬件生态垂直整合赋能，通过芯片设计获得安全边界，通过硬件形态多样化和应用案例多样化促进市场推广，上游厂商多投入，可以降低用户开发应用成本，甚至可以达到研发资源共享，特别是基于Arm和RISC-V方案无法形成有效解决方案联盟前，单厂商的垂直整合资源的方案效率更高。

技术路线
~~~~~~~~~~~~

相较于现下国产芯片厂商硬件思维不同，乐鑫更愿意通过软件方案实现切入到足够细分的领域，所以在芯片设计上偏向于通用性，在软件开发上扩展更多可能性。

目前主打的一个方向(人设)是AIoT，扩展了芯片在深度学习上的应用，但受限于芯片本身的性能和资源配置，很难从性能上突围，更多是最求一个当下难以量化的性价比，而对底层芯片的开发难度将抵消掉硬件的低成本。



芯片产品
-----------
``ESP32-S3`` ``ESP32-C3`` ``ESP32-S2`` ``ESP32-H2``

.. note::
    在中国的MCU芯片市场，目前有两家具有对比性的厂商： :ref:`espressif` 和 :ref:`wch` ，在产品附加值上就是前者更注重软件生态反哺，后者注重硬件差异覆盖协同。


高性能产品
~~~~~~~~~~~~

这一分类下，主要是多核产品，更多围绕AIoT战略，凭借丰富的软件生态资源实现向上突破。

.. toctree::
    :maxdepth: 1

    ESP32 <ESP32>
    ESP32S3 <ESP32-S3>

.. note::
    就目前已有的软硬件生态资源而言，:ref:`esp32` 依然占据较大的优势，主要在于ESP32-S3任然是以降本为核心，芯片的性能相对提升了了，而升级力度不够导致庞大的开源生态没有足够动力去做适配，离开丰富的开源生态导致开发成本提高。


低成本系列
~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    ESP32C5 <ESP32-C5>
    ESP32C6 <ESP32-C6>
    ESP32C3 <ESP32-C3>
    ESP32C2 <ESP32-C2>


新领域探索
~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    ESP32S2(USB-OTG) <ESP32-S2>
    ESP32H2 (802.15.4) <ESP32-H2>
    ESP32P4  <ESP32-P4>

`各芯片资源对比 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/hw-reference/chip-series-comparison.html>`_


解决方案
-----------

开发框架
~~~~~~~~~~~

`OS-Q资源适配 <http://www.OS-Q.com>`_

.. contents::
    :local:

.. _esp_arduino:

Arduino
^^^^^^^^^^^^^^

`Arduino Core ESP32 <https://github.com/espressif/arduino-esp32>`_ 已支持ESP32、ESP32-S、ESP32-C等系列SoC。

.. _esp_idf:

ESP-IDF
^^^^^^^^^^^^^^

`ESP-IDF工程 <https://github.com/espressif/esp-idf>`_ 是乐鑫官方的底层开发框架，基于 C/C++ 语言，可以等效理解：乐鑫为旗下所有芯片提供的统一SDK开发包；适用于ESP32、ESP32-S、ESP32-C和ESP32-H系列SoC。

.. image:: ./images/idf.png
    :target: https://docs.os-q.com/espidf.html

ESP-IDF的版本比较多，各种更新比较频繁，导致需要明确的版本号来对应，当前最新版本为5.0，之前的所有版本均支持ESP32但针对不同平台需要重新配置并编译。

更多关于请阅读 `ESP-IDF <https://docs.os-q.com/espidf.html>`_

.. _esp_adf:

ESP-ADF
^^^^^^^^^^^^^^

`ESP-ADF <https://github.com/espressif/esp-adf>`_ 用于开发各类音频应用，还提供多种语音平台的连接服务，方便用户直连云平台开发语音产品。



.. _esp_mdf:

ESP-MDF
^^^^^^^^^^^^^^

`ESP-MDF <https://github.com/espressif/esp-mdf>`_ 适用于无线组网类基础框架


技术组件
~~~~~~~~~~~~

.. _esp_now:

ESP-NOW
^^^^^^^^^^^^^^

`ESP-NOW协议 <https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/api-reference/network/esp_now.html>`_ 是由乐鑫定义的 Wi-Fi 通信协议，采用 CCMP 方法保护供应商特定动作帧的安全，ESP-NOW 广泛应用于智能照明、远程控制、传感器等领域。

.. _esp_csi:

ESP-CSI
^^^^^^^^^^^^^^

`ESP-CSI <https://github.com/espressif/esp-csi>`_ based on Wi-Fi CSI (Channel state information), such as indoor positioning, human detection


.. _esp_audio:

Audio
^^^^^^^^^^^^^^
``AAC`` ``MP3`` ``BT``

就产品定位和市场接受度而言，ESP32天然带有Audio音频应用属性

`ESP-ADF文档 <https://docs.espressif.com/projects/esp-adf>`_

.. hint::
    就近期的产品配置和迭代计划，:ref:`espressif` 在蓝牙音频领域处于停滞状态，而该领域芯片方案众多且更新迭代迅速

相关总结
-----------

在此主要归纳总结 :ref:`espressif` 现阶段及未来一段时间的技术延续性和兼容性

.. contents::
    :local:

.. _esp_core:

Architecture
~~~~~~~~~~~~~~~

.. contents::
    :local:

.. _xtensa_lx6:

Xtensa LX6
^^^^^^^^^^^^^^
:ref:`performance` : ``MIPS 2.07 CoreMark/MHz`` ( :ref:`cortex_m0` 2.39 CoreMark/MHz)


7级流水线架构，支持240 MHz的时钟频率，应用产品为 :ref:`esp32`

`Tensilica Xtensa <https://www.cadence.com/zh_CN/home/tools/ip/tensilica-ip/tensilica-xtensa-controllers-and-extensible-processors/xtensa-lx-processor-platform.html>`_ 处理器是一个可以自由装组、可以弹性扩张，并可以自动合成的处理器核心。Xtensa 是第一个专为嵌入式单芯片系统而设计的微处理器。为了让系统设计工程师能够弹性规划、 执行单芯片系统 的各种应用功能，Xtensa 在研发初期就已锁定成一个可以自由装组的架构。




.. note::
    Tensilica公司于2013年3月被Cadence公司以3.8亿的价格收购

.. _xtensa_lx7:

Xtensa LX7
^^^^^^^^^^^^^^
:ref:`performance` : ``MIPS 2.56 CoreMark/MHz`` ( :ref:`cortex_m0` 2.39 CoreMark/MHz)


5级流水线架构，支持240 MHz的时钟频率，应用产品为 :ref:`esp32s2`, :ref:`esp32s3`

* 16 位/24 位指令集提供高代码密度
* 32 位定制化指令集及 128 位宽数据总线，提供高运算性能
* 支持单精度浮点运算单元 (FPU)
* 支持 32 位乘法器、32 位除法器
* 非缓存 GPIO 指令
* 支持六级 32 个中断
* 支持 windowed ABI，64 个物理通用寄存器
* 支持带 TRAX 压缩模块的 trace 功能，最大 16 KB 的记录存储器 (trace memory)
* 用于调试的 JTAG 接口

.. image:: images/XtensaLX7.png
    :target: https://www.cadence.com/content/dam/cadence-www/global/en_US/documents/tools/ip/tensilica-ip/tip-xtensa-lx-pb.pdf



.. _esp_rv32:

RISC-V
^^^^^^^^^^^^^^
:ref:`performance` : ``32-bit RISC-V 2.55 CoreMark/MHz`` ( :ref:`cortex_m0` 2.39 CoreMark/MHz)

.. list-table::
    :header-rows:  1

    * - :ref:`esp_rv32`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`sram`/:ref:`flash`
      - :ref:`wireless`
      -
      - :ref:`esp_audio`
    * - :ref:`esp32c3`
      - 160MHz
      - 407.22
      - 400KB/384KB
      - WiFi&BLE5.0
      -
      -
    * - :ref:`esp32c2`
      - 120MHz
      -
      - 272KB/576KB
      - WiFi&BLE5.0
      -
      -
    * - :ref:`esp32h2`
      - 96MHz
      -
      - 400KB/384KB
      - Matter&BLE5.2
      -
      -

.. _esp_tools:

辅助工具
~~~~~~~~~~~~

.. _esp_downloader:

下载工具
^^^^^^^^^^^^^^

`window flash downloader <https://espressif.com/zh-hans/support/download/other-tools>`_


.. _esp_bridge:

USB-Bridge
^^^^^^^^^^^^^^

.. image:: images/esp-usb-bridge.png
    :target: https://github.com/espressif/esp-usb-bridge


.. _esp_package:

封装规格
~~~~~~~~~~~~

:ref:`espressif` 的芯片目前主要是小封装，官方通过提供丰富的模组降低下游设计加工难度，单芯片可以实现高集成度，适用场景更丰富。

.. contents::
    :local:

.. _esp_qfn56:

QFN56
^^^^^^^^^^^^^^

.. image:: ./images/ESP32S3P.png
    :target: https://doc.soc.xin/espressif/ESP32-S3.html


.. _esp_qfn48:

QFN48
^^^^^^^^^^^^^^


.. image:: ./images/ESP32p5.png
    :target: https://doc.soc.xin/espressif/ESP32.html
.. image:: ./images/ESP32p6.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32


.. _esp_qfn32:

QFN32
^^^^^^^^^^^^^^

.. image:: ./images/ESP32C3P.png
    :target: https://doc.soc.xin/espressif/ESP32-C3.html


.. _NO_011:
.. _stm32h7b0:

STM32H7B0
================

* 关键词：``Cortex-M7`` ``280MHz`` ``SMPS`` ``Chrom-ART`` ``STemWin`` ``JPEC`` ``HDMI-CEC``
* 代码库：`GitHub <https://github.com/SoCXin/STM32H7B0>`_ , `Gitee <https://gitee.com/socxin/STM32H7B0>`_

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/stm32h7b0.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32h7b0-value-line.html

.. contents::
    :local:

规格配置
~~~~~~~~~~~

基本参数
^^^^^^^^^^^

* 发布时间：2019年5月
* 供电电压：1.71 to 3.6 V
* 工作温度：-40°C to +85°C/125°C
* 处理性能：599 :ref:`DMIPS`, 1414 :ref:`CoreMark`
* RAM容量：1.4 MB
* Flash容量：128/256/512 KB
* 封装规格：64 to 176 Pin

.. image:: ./images/STM32H7B0p.png
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32h7b0-value-line.html

特征参数
^^^^^^^^^^^

* 280 MHz :ref:`cortex_m7`
* :ref:`stm32_smps`,可用于为外部电路供电，特定应用情况下结合LDO共同使用
* 在内核运行模式（外设外设关）和SMPS情况下，典型功耗为120 µA/MHz
* 低功耗停止模式下的典型功耗电流为32 µA
* 低功耗待机模式下的典型功耗电流为2.2 µA
* 多达35个通信接口，包括FD-CAN、USB2.0高速/全速、照相机接口、并行同步数据输入/输出从接口（PSSI）
* :ref:`stm32_gfxmmu`

芯片架构
~~~~~~~~~~~~

.. image:: ./images/STM32H7B0s.png
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32h7b0-value-line.html

.. _stm32_smps:

SMPS
^^^^^^^^^^^


.. _stm32_gfxmmu:

GFXMMU
^^^^^^^^^^^


Xin选择
-----------

.. contents::
    :local:

品牌对比
~~~~~~~~~

版本对比
~~~~~~~~~

STM32H7A3/7B3 MCU系列提供1到2 MB的Flash存储器，具有下列结构的1.4 MB SRAM：192 KB的TCM RAM（包括64 KB的ITCM RAM和128 KB的DTCM RAM，用于时间关键型程序或数据），1.18 MB的用户SRAM，以及用于在最低功耗模式下保存数据的备份域4 KB SRAM。另外，它提供64至225引脚的BGA和LQFP封装型号。



超值系列对比
^^^^^^^^^^^^^^

.. image:: ./images/STM32H7x0.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32h7-series.html

.. list-table::
    :header-rows:  1

    * - Name
      - :ref:`DMIPS`
      - RAM
      - Cache
      - GPU
      - SPI
      - USB
      - Ethernet
      - Interface
    * - :ref:`stm32h730`
      - 1177
      - 564KB
      - 32+32
      - ART
      - 2 Octo
      - :ref:`stm32_otg_hs`
      - 100M
      - 35
    * - :ref:`stm32h750`
      - 1027
      - 1 MB
      - 16+16
      - ART
      - 2 Quad
      - :ref:`stm32_otg_hs`
      - 100M
      - 35
    * - :ref:`stm32h7b0`
      - 599
      - 1.4 MB
      - 16+16
      - ART/JPEG
      - 2 Octo
      - :ref:`stm32_otg_hs`
      - No
      - 35

.. hint::
    :ref:`stm32h7b0` 不具备以太网通信能力，就性能而言在H7系列中没有优势，更多适用于高集成度低功耗场景



型号对比
~~~~~~~~~

.. image:: ./images/STM32H7B0l.png
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32h7b0-value-line.html

图形性能
~~~~~~~~~

.. image:: ./images/DMA2D.jpg


Xin应用
-----------

作为STM32H系列中的低功耗产品，片上集成1.4M SRAM可以满足大多数项目的资源依赖，减少外扩SDRAM也可以降低功耗。就官方提供的资源和推荐应用场景而言，应该是偏向仪器仪表显示。

.. contents::
    :local:


开发板
~~~~~~~~~~~~~~~

STM32H7B0-DK
^^^^^^^^^^^^^^^

.. image:: images/STM32H7B0_dk.jpg
    :target: https://item.taobao.com/item.htm?spm=a1z09.2.0.0.6e7a2e8d6nHM8d&id=658976139303&_u=dgas3eu21a0


STM32H7B3I-DK
^^^^^^^^^^^^^^^
.. image:: images/B_STM32H7B3.png
    :target: https://detail.tmall.com/item.htm?spm=a230r.1.14.39.5bcd1376PALjIA&id=635717279033&ns=1&abbucket=10

* 4.3" (480x272) TFT color LCD module including a capacitive touch panel with RGB interface
* Wi‑Fi® module compliant with 802.11 b/g/n
* USB :ref:`stm32_otg_hs`
* Audio codec
* 512-Mbit Octo-SPI NOR Flash memory
* 128-Mbit SDRAM
* 2 user LEDs
* User and Reset push-buttons
* Fanout daughterboard
* 1x FDCAN
* Camera (8 bit)
* USB with Micro-AB
* Stereo headset jack including analog microphone input
* Audio jack for external speakers
* microSD™ card
* TAG-Connect 10-pin footprint
* Arm® Cortex® 10-pin 1.27mm-pitch debug connector over STDC14 footprint
* ARDUINO® Uno V3 expansion connector
* STMod+ expansion connector
* Audio daughterboard expansion connector
* External I2C expansion connector
* Flexible power-supply options: ST-LINK USB VBUS, USB :ref:`stm32_otg_hs` connector, or external sources
* On-board STLINK-V3E debugger/programmer


低功耗HMI
~~~~~~~~~~~

TouchGFX
^^^^^^^^^^^^^^^

littleVGL
^^^^^^^^^^^^^^^

emWin
^^^^^^^^^^^^^^^


Xin总结
--------------

.. contents::
    :local:

能力构建
~~~~~~~~~~~~~

要点提示
~~~~~~~~~~~~~

问题整理
~~~~~~~~~~~~~


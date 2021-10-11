
.. _pop:

方案Xin榜
=============
.. note::
    本榜单收录具有成熟应用领域或项目方案，特别是被流行的开源项目所支持适配的芯片方案

.. contents::
    :local:


.. _marlin_3d:

Marlin
-------------

`Marlin <https://github.com/MarlinFirmware/Marlin>`_ 是 RepRap 系列复制式快速原型机--俗称"3D 打印机 "的一个开源固件。它源于Sprinter和grbl，并于2011年8月12日在Github发布，成为一个独立的开源项目。Marlin是根据GPLv3许可的，对所有应用都是免费的。

作为其质量的证明，Marlin被几个受人尊敬的商业3D打印机使用。Ultimaker、Printrbot、AlephObjects（Lulzbot）和Prusa Research只是运送Marlin变体的几个供应商。Marlin也能够驱动CNC和激光雕刻机。

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - Special
      - Package
    * - :ref:`esp32`
      - 240MHz
      - 512K
      - 4MB
      - 2
      - 18
      - WIFI
      - QFN48
    * - :ref:`stm32f103`
      - 72MHz
      - 20KB
      - 128KB
      - 2
      - 40
      -
      - LQFP48
    * - :ref:`stm32f401`
      - 100MHz
      -
      -
      - 2
      -
      -
      - QFN48


.. _usb_pd:

USB-PD
-------------

`USB PD <https://github.com/Qful/PD>`_ (USB Power Delivery)功率传输协议，USB功率2013年的新标准名为USBPD，USB PD 协议基于USB3.1，是USB3.1 中即type-c端口后提出的功率传输概念。可以为这种技术带来更大的灵活性，将充电能力扩大为目前的10倍：最高可达100瓦。

.. toctree::
    :maxdepth: 1

    CS32G020 <../M/CS32G020>

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - Package
    * - :ref:`ch549`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      -
    * - :ref:`ch552`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      -


.. _cmsis_dap:

CMSIS-DAP
-------------

* CMSIS(Cortex-M Software Interface Standard)是ARM Cortex-M MCU软件接口标准。
* DAP(DebugAccess Port) 是调试访问口。

`CMSIS-DAP <https://github.com/ARMmbed/DAPLink>`_ 是用于将调试端口连接到USB的调试单元的接口固件。在主机上执行的调试器通过USB连接到调试单元和运行应用程序软甲的设备。调试单元通过JTAG或SW连接到目标设备。
ARM Cortex处理器提供coresight调试和跟踪单元。CMSIS-DAP支持包含一个或多个Cortex处理器的目标设备。

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - Package
    * - :ref:`ch549`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      - QFN28/48
    * - :ref:`ch552`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      - QFN16/TSSOP20


.. hint::
    基于 :ref:`ch552` 芯片应该是当下成本最低的 :ref:`ch552_dap` 实现方案，并且通过小封装可以获得更小的体积


.. _simplefoc:

SimpleFOC
-------------

`GitHub <https://GitHub.com/simplefoc>`_ |
`Website <https://docs.simplefoc.com//>`_

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - Package
    * - :ref:`esp32`
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32h747`
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32g431`
      -
      -
      -
      -
      -
      -

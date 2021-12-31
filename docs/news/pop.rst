
.. _pop:

方案Xin
=============

.. note::
    方案Xin的起点是由于某一个嵌入式软硬件项目实用性得到验证，然后大量开发者在此基础上进行延生，包括优化和扩展原来的功能，迁移原来的芯片平台等，一个典范的方案，往往能带火基于这个方案的芯片。

.. contents::
    :local:


.. _marlin_3d:

Marlin
-------------

`Marlin <https://github.com/MarlinFirmware/Marlin>`_ 是 RepRap 系列复制式快速原型机--俗称"3D 打印机 "的一个开源固件。它源于Sprinter和grbl，并于2011年8月12日在Github发布，成为一个独立的开源项目。Marlin是根据GPLv3许可的，对所有应用都是免费的。

作为其质量的证明，Marlin被几个受人尊敬的商业3D打印机使用。Ultimaker、Printrbot、AlephObjects（Lulzbot）和Prusa Research只是运送Marlin变体的几个供应商。Marlin也能够驱动CNC和激光雕刻机。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
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




.. _cmsis_dap:

CMSIS-DAP
-------------

* CMSIS(Cortex-M Software Interface Standard)是ARM Cortex-M MCU软件接口标准。
* DAP(DebugAccess Port) 是调试访问口。

`CMSIS-DAP <https://github.com/ARMmbed/DAPLink>`_ 是用于将调试端口连接到USB的调试单元的接口固件。在主机上执行的调试器通过USB连接到调试单元和运行应用程序软甲的设备。调试单元通过JTAG或SW连接到目标设备。
ARM Cortex处理器提供coresight调试和跟踪单元。CMSIS-DAP支持包含一个或多个Cortex处理器的目标设备。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
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


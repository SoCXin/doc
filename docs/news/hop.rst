
.. _hop:

方案Xin榜
=============
.. note::
    本榜单收录具有成熟应用领域或项目方案，特别是被流行的开源项目所支持适配的芯片方案

.. contents::
    :local:

.. _cmsis_dap:

CMSIS-DAP
-------------

CMSIS(Cortex-M Software Interface Standard)是ARM Cortex-M MCU软件接口标准。DAP(DebugAccess Port) 是调试访问口。

CMSIS-DAP是用于将调试端口连接到USB的调试单元的接口固件。在主机上执行的调试器通过USB连接到调试单元和运行应用程序软甲的设备。调试单元通过JTAG或SW连接到目标设备。
ARM Cortex处理器提供coresight调试和跟踪单元。CMSIS-DAP支持包含一个或多个Cortex处理器的目标设备。

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
    * - :ref:`ch549`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      - 10M-PHY
      - QFN28/48
    * - :ref:`ch552`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      - 10M-PHY
      - QFN28/48


.. hint::
    基于 :ref:`ch552` 芯片的方案应该是成本最低的 :ref:`ch552_dap` 实现。

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
      - 40MHz
      - 1K
      - 8K
      - 2
      - 18
      - 10M-PHY
      - QFN28/48
    * - :ref:`stm32f103`
      - 40MHz
      - 1K
      - 8K
      - 2
      - 18
      - 10M-PHY
      - QFN28/48
     * - :ref:`stm32f401`
      - 40MHz
      - 1K
      - 8K
      - 2
      - 18
      - 10M-PHY
      - QFN28/48



USB-PD
-------------


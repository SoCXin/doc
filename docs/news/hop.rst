
.. _hop:

方案Xin榜
=============
.. note::
    具有成熟应用领域或项目方案

.. contents::
    :local:

CMSIS-DAP
-------------

CMSIS(Cortex-M Software Interface Standard)是ARM Cortex-M MCU软件接口标准。DAP(DebugAccess Port) 是调试访问口。

CMSIS-DAP是用于将调试端口连接到USB的调试单元的接口固件。在主机上执行的调试器通过USB连接到调试单元和运行应用程序软甲的设备。调试单元通过JTAG或SW连接到目标设备。
ARM Cortex处理器提供coresight调试和跟踪单元。CMSIS-DAP支持包含一个或多个Cortex处理器的目标设备。

.. toctree::
    :maxdepth: 1

    CH549 <../WCH/CH549>
    CH554 <../WCH/CH554>

.. hint::
    :ref:`ch552` 的方案应该是Xin价格最低的实现方案了。

Marlin
-------------

Marlin 是 RepRap 系列复制式快速原型机--俗称"3D 打印机 "的一个开源固件。它源于Sprinter和grbl，并于2011年8月12日在Github发布，成为一个独立的开源项目。Marlin是根据GPLv3许可的，对所有应用都是免费的。

作为其质量的证明，Marlin被几个受人尊敬的商业3D打印机使用。Ultimaker、Printrbot、AlephObjects（Lulzbot）和Prusa Research只是运送Marlin变体的几个供应商。Marlin也能够驱动CNC和激光雕刻机。

.. toctree::
    :maxdepth: 1

    ESP32 <../espressif/ESP32>
    STM32F103 <../ST/M3/STM32F103>
    STM32F401 <../ST/M4/STM32F401>

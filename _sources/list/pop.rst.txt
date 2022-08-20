
.. _pop:

方案Xin
=============
``有特长`` ``应用标杆``

.. note::
    从源头上讲，谁决定一颗芯片的应用方案，谁评价应用方案的优劣？厂商提供的应用案例一定是他们盯着的市场，而不一定是产品的真实定位，只有从全局上没有利益关联地去比较优劣，才能给出更好的定义。

.. contents::
    :local:
    :depth: 1

开源项目
-------------

.. contents::
    :local:
    :depth: 1

.. _marlin_3d:

Marlin
~~~~~~~~~~~

`Marlin <https://github.com/MarlinFirmware/Marlin>`_ 是 RepRap 系列复制式快速原型机--俗称"3D 打印机 "的一个开源固件。它源于Sprinter和grbl，并于2011年8月12日在Github发布，成为一个独立的开源项目。Marlin是根据GPLv3许可的，对所有应用都是免费的。

作为其质量的证明，Marlin被几个受人尊敬的商业3D打印机使用。Ultimaker、Printrbot、AlephObjects（Lulzbot）和Prusa Research只是运送Marlin变体的几个供应商。Marlin也能够驱动CNC和激光雕刻机。

.. list-table::
    :header-rows:  1

    * - :ref:`pop`
      - :ref:`architecture`
      - RAM
      - Flash
      - UART
      - GPIO
      - Special
    * - :ref:`esp32`
      - 240MHz
      - 512K
      - 4MB
      - 2
      - 18
      - WIFI
    * - :ref:`stm32f103`
      - 72MHz
      - 20KB
      - 128KB
      - 2
      - 40
      -
    * - :ref:`stm32f401`
      - 100MHz
      -
      -
      - 2
      -
      -

.. _grbl_hal:

grblHAL
~~~~~~~~~~~

`grblHAL <https://github.com/grblHAL>`_ is a rewrite of grbl 1.1 aimed at 32-bit processors.

.. list-table::
    :header-rows:  1

    * -
      - :ref:`architecture`
      - RAM
      - Flash
      - UART
      - GPIO
      - :ref:`package`
    * - :ref:`rp2040`
      -
      -
      -
      -
      -
      - QFN56


`RP2040 <https://github.com/grblHAL/RP2040>`_


.. _cmsis_dap:

CMSIS-DAP
~~~~~~~~~~~


`CMSIS-DAP <https://github.com/ARMmbed/DAPLink>`_ 是用于将调试端口连接到USB的调试单元的接口固件。在主机上执行的调试器通过USB连接到调试单元和运行应用程序软甲的设备。调试单元通过JTAG或SW连接到目标设备。
ARM Cortex处理器提供coresight调试和跟踪单元。CMSIS-DAP支持包含一个或多个Cortex处理器的目标设备。

.. list-table::
    :header-rows:  1

    * - :ref:`cmsis_dap`
      - :ref:`architecture`
      - RAM
      - Flash
      - UART
      - GPIO
      - :ref:`package`
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
    * - :ref:`esp8266`
      -
      -
      -
      -
      -
      - QFN32
    * - :ref:`ch32v307`
      -
      -
      -
      -
      -
      -

.. hint::
    基于 :ref:`ch552` 芯片应该是当下成本最低的 :ref:`ch552_dap` 实现方案，并且通过小封装可以获得更小的体积


* CMSIS(Cortex-M Software Interface Standard)是ARM Cortex-M MCU软件接口标准。
* DAP(DebugAccess Port) 是调试访问口。


智能家居
-------------

.. _doorlock:

DoorLock
~~~~~~~~~~~
``低功耗`` ``交互`` ``安全性`` ``无线通信``

.. list-table::
    :header-rows:  1

    * - :ref:`doorlock`
      - 外置主控
      - 内置主控
      - 内外连接
      - 网络连接
      - 家居互联
      - 待机功耗
    * - :ref:`doorlock_r1`
      - :ref:`ch32v307`
      - :ref:`aic8800`
      - :ref:`usb_hs`
      - :ref:`wifi6`
      - :ref:`bt`
      - 1.9uA




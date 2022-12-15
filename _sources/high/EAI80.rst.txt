
.. _eai80:

EAI80
=============

`GitHub <https://github.com/SoCXin/EAI80>`_ : ``Cortex-M4`` ``Dual Core`` ``200MHz`` ``0.3TOPS`` ``CNN-NPU``

.. contents::
    :local:
    :depth: 1


Xin简介
-----------

是一款新的边缘计算体系MCU，集成NPU，可应用于语音控制，计算机视觉-物体和生物(脸，身体，姿势)的检测和识别，vSLAM，边缘计算等。


规格参数
~~~~~~~~~~~

双Cortex-M4核，所有核心都可以访问完整的内存映射。ARM Cortex-M4用作主处理器。

另一个ARM Cortex-M4内核可以作为协处理器来协助ARM Cortex-M4并执行复杂的数学计算。

支持主流CNN模式，如Resnet-18, Resnet-34, Vgg16, GoogleNet, Lenet等，卷积与内核大小从1到7，频道/特征数高达512，最大/平均池功能与内核。


基本参数
^^^^^^^^^^^

* 供电电压：2.0 to 3.6 V
* 工作温度：-40°C to +85°C
* 处理性能：500 :ref:`DMIPS`
* RAM容量：384KB SRAM, 8MB SIP-SDRAM
* Flash容量：8MB QSPI FLASH
* 封装规格：LQFP100

.. note::
    :ref:`eai80`

特征参数
^^^^^^^^^^^

* 200 MHz :ref:`cortex_m4` Dual Core
* 300 MHz :ref:`eai80_npu` 300GOPS
* 2D Graph :Dual-Camera Max
* 3x I2C interfaces
* 8x UARTs with full-duplex data exchange
* 2x SPIs, full-duplex synchronous and single-wire bidirectional mode and 4- to 16-bit word frames
* 1x CAN 2.0B interfaces
* 1x USB 2.0 full-speed device/host/OTG controller with off-chip PHY


芯片架构
~~~~~~~~~~~

.. _eai80_npu:

CNN-NPU
^^^^^^^^^^^



Xin选择
-----------


Xin应用
-----------


Xin总结
-----------


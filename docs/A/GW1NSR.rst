
.. _gw1nsr:

GW1NSR
===============

* 关键词：``Gowin`` ``LittleBee`` ``FPGA`` ``SIP`` ``Cortex-M3`` ``USB2.0 PHY``
* 资源库：`GitHub <https://github.com/SoCXin/GW1NSR>`_

.. contents::
    :local:

Xin简介
-----------

高云半导体 GW1NSR 系列 FPGA 产品是高云半导体小蜜蜂(LittleBee)家族第一代 FPGA 产品，是一款SIP芯片(55nm)，片上集成GW1NS系列FPGA和PSRAM存储芯片。



.. contents::
    :local:

规格参数
~~~~~~~~~~~

基本参数
^^^^^^^^^^^

* 供电电压：1.2V(LV)、2.5V/3.3V(UV)
* 工作温度：-40°C - 105°C

特征参数
^^^^^^^^^^^

* 4608 LUT4、3456 FF
* Cortex-M3硬核处理器
* 180Kbit SRAM、256Kbit Flash
* 8ch 12bit SAR ADC (1MSPS)
* USB2.0 PHY（480Mbps）
* 支持 I3C/MIPI 接口

芯片架构
~~~~~~~~~~~

GW1NSR-2C 和 GW1NSR-4C是SoC芯片，以ARM Cortex-M3 硬核处理器为核心，具备了实现系统功能所需要的最小内存。

GW1NSR-2C最高支持 30MHz 的工作频率，GW1NSR-4C 最高支持 80MHz 的工作频率。

GW1NSR-2C器件的 NVIC 提供了两个外部用户中断，GW1NSR-4C器件支持六个外部用户中断。每个中断支持 8 种可编程的优先级（0~7），7 表示最低级的优先级，0 表示最高级的优先级

.. _gw1nsr_2c:

GW1NSR-2C
^^^^^^^^^^^

GW1NSR-2C 内嵌 USB2.0 PHY 和 ADC

.. image:: images/GW1NSR-2C.png
    :target: http://www.gowinsemi.com.cn/prod_view.aspx?TypeId=10&FId=t3:10:3&Id=168

.. _gw1nsr_4c:

GW1NSR-4C
^^^^^^^^^^^

.. image:: images/GW1NSR-2C.png
    :target: http://www.gowinsemi.com.cn/prod_view.aspx?TypeId=10&FId=t3:10:3&Id=168


.. warning::
    UART0 和 UART1可以通过 APB1 总线进行控制和访问，支持的最大波特率为 921.6Kbits/s。UART0 和 UART1 支持 8 位数据位和 1 位停止位，不支持校验位。

Xin选择
-----------

相比 MCU，FPGA 在可编程性、IO 配置灵活性、实时处理能力等方面都有无可比拟的优势，MCU 能做的事情，FPGA 基本上都做到，FPGA 还能做许多 MCU 做不到的事情。随着芯片规模越来越大，成本逐渐降低，低端FPGA已逐步取代了传统的数字元件

.. contents::
    :local:

品牌对比
~~~~~~~~~

`Gowin <http://www.gowinsemi.com.cn/>`_ 是全球增长最快的可编程逻辑公司，作为中国的FPGA厂商，相对传统的国际巨头，在低阶产品上具有很高的性价比。

Lattice iCE40
^^^^^^^^^^^^^^^

使用开源工具链fpga-toolchain，可以基于 `PlatformIO <https://platformio.org/platforms/lattice_ice40>`_ 开发，开源工具链有以下几个优点：

* 开源工具链的中所有组件均有源代码提供，可以自行编译或者使用已经构建好的二进制文件，不需要任何厂商许可证。
* 体积小，包含了 Lattice iCE40 系列、ECP5 系列 FPGA 支持的工具链压缩包大小在 100 MB 左右，而厂商提供的安装包有几个到几十个 GB。
* 速度快，节省上板调试时间，以笔者测试用的几个小工程为例，完成代码综合、布局布线并下载到 FPGA 中仅需几秒钟的时间。
* 跨平台支持，开源工具链不仅支持 Windows，Linux 和 Mac OS 等操作系统，而且支持 x86 之外的处理器平台。


型号对比
~~~~~~~~~

.. image:: images/GW1N.png
    :target: http://www.gowinsemi.com.cn/prod_view.aspx?TypeId=10&FId=t3:10:3&Id=168

GW2A系列(晨熙)
^^^^^^^^^^^^^^^

.. image:: images/GW2A.png
    :target: http://cdn.gowinsemi.com.cn/DS102-2.3_GW2A%E7%B3%BB%E5%88%97FPGA%E4%BA%A7%E5%93%81%E6%95%B0%E6%8D%AE%E6%89%8B%E5%86%8C.pdf

版本对比
~~~~~~~~~

.. image:: images/GW1NSR.png
    :target: http://www.gowinsemi.com.cn/prod_view.aspx?TypeId=10&FId=t3:10:3&Id=168

GW1NRF
^^^^^^^^^^^

 GW1NRF系列蓝牙 FPGA 产品是一款系统级封装芯片，是一 款 SoC 芯片。器件以 32 位硬核微处理器 为核心，支持蓝牙 5.0 低功耗射频功能，具有丰富的逻辑单元、内嵌 B-SRAM 和 DSP 资源，IO 资源丰富，系统内部有电源管理模块和安全加密模块。

规格型号
^^^^^^^^^^^

.. image:: images/GW1NSR-R.png
    :target: http://cdn.gowinsemi.com.cn/DS861-1.4.4_GW1NSR%E7%B3%BB%E5%88%97FPGA%E4%BA%A7%E5%93%81%E6%95%B0%E6%8D%AE%E6%89%8B%E5%86%8C.pdf


.. image:: images/GW1NSR-P.png
    :target: http://www.gowinsemi.com.cn/prod_view.aspx?TypeId=10&FId=t3:10:3&Id=168


Xin应用
-----------

.. contents::
    :local:

硬件资源
~~~~~~~~~~~~~

Tang Nano 4K
^^^^^^^^^^^^^^

Tang Nano 4K FPGA 板是Tang Nano FPGA板的一个升级，采用了更强大的 GOWIN GW1NSR-LV4C FPGA，它配备的是 4608 LUT（不再是之前的1152）和嵌入到芯片中的 Cortex-M3 微控制器。

.. image:: images/TangNano4K.png
    :target: https://item.taobao.com/item.htm?spm=a230r.1.14.13.7c7b6cffifPv3h&id=653059006630&ns=1&abbucket=0#detail

Tang Nano对比

.. image:: images/TangNano.png
    :target: http://tangnano.sipeed.com/zh/



工具资源
~~~~~~~~~~~~~

Gowin IDE
^^^^^^^^^^^^^^
.. image:: images/GowinIDE.png
    :target: http://dl.sipeed.com/shareURL/TANG/Nano%204K/IDE

Gowin IDE的License目前是免费向客户提供的，使用期限为自取得代码之日起一年，过期失效后可以再次申请License分配是和本机Mac地址挂钩的，一套软件只能在一台电脑上运行。如需多台电脑运行，可申请多个License。


框架资源
~~~~~~~~~~~~~


GoAI开发套件
^^^^^^^^^^^^^^

.. image:: images/GoAI.png
    :target: https://github.com/gowinsemi/GoAI

GoAI 2.0是一个通过在高云FPGA器件上部署卷积神经网络(CNNs)的机器学习开发平台。它包含用于转换TensorFlow文件和加速器FPGA IP的软件脚本，以运行训练好的机器学习模型以及教程和示例。

GoAI 2.0集成到TensorFlow和TensorFlow Lite框架中，比起遗留平台及其他可替代平台更加方便使用。

基于TensorFlow的广泛软件开发环境，GoAI 2.0通过生成所需的所有固件，将机器学习模型直接部署到高云FPGA中，不需编写任何额外的RTL或C代码。完全支持Windows和Linux系统，包括Ubuntu。

依赖的开发资源：

* ARM Keil v5
* Gowin IDE or Gowin Programmer

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



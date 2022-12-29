
.. _ethernet:

Ethernet
============

.. list-table::
    :header-rows:  1

    * - :ref:`ethernet`
      - :ref:`CoreMark`
      - :ref:`sram`/:ref:`flash`
      - :ref:`peripherals`
      - :ref:`usb`/:ref:`can`
      - :ref:`eth_mac`
      - :ref:`eth_phy`
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

.. _eth_mac:

ETH-MAC
~~~~~~~~~~

.. contents::
    :local:
    :depth: 1

RMII
^^^^^^^^^^^

RMII（Reduced Media Independent Interface） 独立于介质接口RMII接口比MII接口拥有更少的I/O传输。MII（18根线）拥有16根数据线2根控制线，而RMII（8根线）只有7个数据线 和1根控制线。传输速率和MII一样，支持10Mb/s和100Mb/s。不同的是RMII在10Mb/s和100Mb/s下CLK都为50MHz。即在相同速率下RMII比MII数据线少了一半，极大的减小了走线压力和端口压力。

.. note::
    如果是需要自适应10/100M，TX_CLK是由PHY芯片发出。

GMII
^^^^^^^^^^^

GMII（Gigabit Medium Independent）千兆以太网，GMII采用8位接口数据，工作时钟125MHz，因此传输速率可达1000Mbps。同时向下兼容MII所规定的10/100 Mbps工作方式。要实现1000Mb/s、100Mb/S、10Mb/S自适应必须加上TX_CLK（PHY输出）。速率要达到1000Mb/s，GTX_CLK/RX_CLK时钟必须125MHz。

RGMII（Reduced Gigabit Media Independent Interface）千兆以太网，采用RGMII（14根线）的目的是降低电路成本，使实现这种接口的器件的引脚数从GMII25个引脚减少到14个引脚。RGMII均采用4位数据接口，工作时钟125MHz，并且在上升沿和下降沿同时传输数据，因此传输速率可达1000Mbps。RGMII同时兼容MII所规定的10/100 Mbps工作方式，支持传输速率：10M/100M/1000Mb/s ，其对应clk 信号分别为2.5MHz/25MHz/125MHz。

.. _eth_phy:

ETH-PHY
~~~~~~~~~~

PHY是物理接口收发器。其物理层定义了数据传送与接收所需要的光电信号、线路状态、时钟基准、数据编码等电路，并向数据链路层设备提供标准接口。一般PHY芯片为模数混合电路，负责接收光、电这类模拟信号，经过解调和A/D转换后通过MII，RMII，GMII，RGMII等介质接口将信号交给MAC芯片进行处理。一般MAC芯片为纯数字电路。

PHY在发送数据时，收到MAC发过来的数据（对PHY来说没有帧的概念，发过来的都是数据），然后在把并行数据转化为串行数据，在按照物理层的编码规则吧数据进行编码，再经过D/A转化通过模拟信号传输出去。接收时流程相反。

电流型PHY
^^^^^^^^^^^

指PHY芯片把MAC给的数据进行串并转换，编码后经DAC输出，而DAC为电流型输入，即芯片为电流型PHY。电流型PHY工作原理：由于PHY芯片的DAC为电流型输入，即需在外部提供一个偏置电压，再由PHY芯片将编码后的数据以差分电流的形式输出，并在100Ω电阻上产生其对应的电压，最后在通过网变压器把信号传出（电流方向为红色箭头方向）。有的PHY芯片内部会集成差分电阻，具体以所用芯片手册为则。VDD的作用为为电路提供电流和为差分信号提供直流偏置。电阻需靠近PHY芯片放置。

电流型PHY需要在网络变压器中间抽头提供一个VDD电压。

电压型PHY
^^^^^^^^^^^
指PHY芯片把MAC给的数据进行串并转换，编码后经DAC输出，而DAC为电压型输出，即芯片为电压型PHY。电压型PHY工作原理：直接由PHY芯片将编码后的数据以差分电压的方式输出，此时网络变压器中间抽头不需要提供偏置电压，所以网络变压器中间抽头一般接0.1uF的电容，为高频干扰提供一个低阻抗回路。

电压型PHY在网络变压器中间抽头接0.1uF电容。

.. contents::
    :local:
    :depth: 1

LAN8720
^^^^^^^^^^^

LAN8742与LAN8720比较看，两者管脚兼容，LAN8742是LAN8720 的升级版，多了一个MCO管脚，其他的芯片特性一样，寄存器配置完全一样。

LAN8742和LAN8720的默认地址却是0x00

DP83848
^^^^^^^^^^^

DP83848芯片，支持MII模式和RMII模式；而LAN8742，和LAN8720，只支持RMII模式；另外，三者之间的，寄存器是一样的。

DP83848的默认地址，是0x01



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
      - :ref:`eth_mac`
    * - :ref:`mt7622`
      - :ref:`cortex_a53`
      -
      -
      - 5p GbE
      - SGMII/RGMII
    * - :ref:`mt7623`
      - :ref:`cortex_a7`
      -
      -
      - 5p GbE
      - SGMII/RGMII
    * - :ref:`mt7688`
      - :ref:`24KEc`
      -
      -
      - 5p 100Mbps
      -



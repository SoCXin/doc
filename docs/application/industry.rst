
.. _industry:

行业应用
===============

.. contents::
    :local:
    :depth: 1


车规产品
-----------

``AEC-Q100``

.. toctree::
    :maxdepth: 1

    AC7815 <../miscellaneous/AC7815>


.. _autosar:

AUTOSAR
~~~~~~~~~~~
``汽车开放系统架构`` ``ECU``

AUTOSAR (Automotive Open System Architecture) 成立于2003年，致力于制定汽车电子软件标准的联盟（参与者有全球各家汽车制造商、零部件供应商以及各种研究、服务机构）。

目前汽车中的软件代码量早已超过了1千万行，ECU的数量也超过了1百个。

一套专门针对汽车ECU的软件开发架构，用于汽车开放性的框架和行业标准，它将用作管理将来的应用程序和标准软件模块中功能的基本基础结构。



三个文档组：Classic Platform(CP)、Adaptive Platform(AP)、Foundation(FO)



智能家居
-----------

.. _matter:

Matter
~~~~~~~~~~~
``CSA`` ``智能家居`` ``简单性、互操作性、可靠性和安全性``

由 CSA 连接标准联盟 (Connectivity Standards Alliance) 发起，多家行业领先公司联合推出的智能家居互联协议。(Zigbee联盟改名CSA联盟)

Matter协议的前身CHIP（Connected Home Over IP），该CHIP早期是由谷歌，苹果，Zigbee联盟等牵头主导并开源的一个用于解决无线iot碎片化的协议，该协议在2021年5月份正式改名Matter

Matter协议不是为了消灭现有各种不同的无线协议，而是来统一现有不同的无线协议，其并不是一种底层无线通信协议，更具体的更像是基于IP化的应用层协议。

Matter 基于IP协议（例如Wi-Fi、以太网和Thread）而构建，提供了一个抽象的应用层，Matter协议支持多种通信方式如WiFi、蓝牙、Zigbee、Thread（802.15.4）等，后面Matter协议也会新增支持Zigbee以及ZWave协议

.. image:: ./images/chip.png

* Matter 离不开基于IP 的网络协议，而Zigbee 有自己的网络协议
* Matter 还通过 :ref:`bt` 和 :ref:`wifi` 二维码定义了最适合预期用户设置场景的预配方案，而Zigbee的标准调试流程使用其原生的 :ref:`802_15_4` 无线技术。

.. note::
    根据ABI research的最新预测，在2022年到2030年这个区间内，Matter设备的出货量将达到550亿。


工控现场
-----------

.. contents::
    :local:
    :depth: 1

.. _modbus:

Modbus
~~~~~~~~~~~

Modbus协议是一项应用层报文传输协议，包括ASCII、RTU、TCP三种报文类型。

标准的Modbus协议物理层接口有RS232、RS422、RS485和以太网接口，采用master/slave方式通信。


Modbus RTU
^^^^^^^^^^^^


Modbus TCP
^^^^^^^^^^^^

Modbus设备可分为主站(poll)和从站(slave)。主站只有一个，从站有多个，主站向各从站发送请求帧，从站给予响应。在使用TCP通信时，主站为client端，主动建立连接；从站为server端，等待连接。

IANA（Internet Assigned Numbers Authority，互联网编号分配管理机构）给Modbus协议赋予TCP端口号为502，这是目前在仪表与自动化行业中唯一分配到的端口号。

ModbusTCP的数据帧可分为两部分：MBAP+PDU。简单的理解，就是去掉了modbus协议本身的CRC校验，增加了MBAP报文头。


MBAP为报文头，长度为7字节，组成如下：

* 事务元标识符（2个字节）：用于事务处理配对。在响应中，MODBUS服务器复制请求的事务处理标识符。这里在以太网传输中存在一个问题，就是先发后至，我们可以利用这个事务处理标识符做一个TCP序列号，来防止这种情况所造成的数据收发错乱（这里我们先不讨论这种情况，这个事务处理标识符我们统一使用0x00，0x01）
* 协议标识符（2个字节）：modbus协议标识符为0x00，0x00
* 长度（2个字节）：长度域是下一个域的字节数，包括单元标识符和数据域。
* 单元标识符（1个字节）：该设备的编号。（可以使用PLC的IP地址标识）。

PDU由功能码+数据组成。功能码为1字节，数据长度不定，由具体功能决定。

通信过程:

* connect 建立TCP连接
* 准备Modbus报文
* 使用send命令发送报文
* 在同一连接下等待应答
* 使用recv命令读取报文，完成一次数据交换
* 通信任务结束时，关闭TCP连接


串行通信
~~~~~~~~~~~~

Xmodem
^^^^^^^^^^^^

Xmodem 是一种在串口通信中广泛使用的异步文件传输协议，由于使用了CRC错误侦测方法，传输的准确率可高达99.6%。分为XModem和1k-XModem协议两种，前者使用128字节的数据块，后者使用1024字节即1k字节的数据块。

XModem工作时，先由收方发出NAK，然后等待发方的包开始SOH。收到SOH后，即 将整个包收完，检查是否有错。如出错，则向发方发出一个NAK，请求发方重发； 否则发出ACK,表示接收正确，请发下个包。XModem检查包编号和checksum来确定 该包是否传送有问题。编号是发方送得出包的顺序。当XModem发送完最后一个包 时，收方会收到文件结束符(EOT)，此时，收方会送出一个ACK通知发方传送结束。

Ymodem
^^^^^^^^^^^^

YModem是XModem的升级版协议，两者最大的区别是YModem可以支持传输多个文件。

Ymodem具有传输快速稳定的优点，平常所说的Ymodem协议是指的Ymodem-1K，它可以一次传输1024字节的信息块，除此还有Ymodem-g（没有CRC校验，不常用）。

YModem-1K用1024字节信息块传输取代标准的128字节传输，数据的发送回使用CRC校验，保证数据传输的正确性。它每传输一个信息块数据时，就会等待接收端回应ACK信号，接收到回应后，才会继续传输下一个信息块，保证数据已经全部接收。


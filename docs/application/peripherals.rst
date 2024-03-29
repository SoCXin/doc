

.. _peripherals:

Peripherals
===============


.. contents::
    :local:
    :depth: 1


通信外设
----------
``UART/SPI/I2C/I2S`` ``U/P/C/S``

.. contents::
    :local:
    :depth: 1

.. _uart:

UART
~~~~~~~~~~
``USART``

UART(Universal Asynchronous Receiver/Transmitter) 通用异步收发传输器，是一种异步收发传输器，在UART通讯协议中信号线上的状态位高电平代表’1’低电平代表’0’。

* 空闲位：当总线处于空闲状态时信号线的状态为‘1’即高电平
* 起始位：开始进行数据传输时发送方要先发出一个低电平’0’来表示传输字符的开始。
* 数据位：数据可以是5，6，7，8，9位，构成一个字符，一般都是8位。先发送最低位最后发送最高位。
* 校验位：数据位加上这一位后，使得“1”的位数为偶数（偶校验）或奇数（奇校验）以此来校验数据传送的正确性
* 停止位：数据结束标志，可以是1位，1.5位，2位的高电平。


UART CTS(Clear To Send)/RTS(Request To Send)用于硬流控，协调双方收发，保证数据不丢失。

TTL、RS232和RS485指的是电平逻辑标准；UART口、COM口指的是物理接口形式；RS232电平即负逻辑电平，定义+5V~+12V为逻辑0，-5V~-12V为逻辑1。

RS232的缺点很明显，接口的信号电平值较高易损坏接口电路的芯片，需要另外的芯片与TTL转换兼容，传输速率低，三线形成共地传输，容易产生共模干扰，抗干扰性能弱，也导致传输距离有限（50米左右）。

针对RS232的不足，RS422采用5线（包括信号地线），拥有高输入阻抗和发送驱动能力，可实现一对多通信，通信距离可达1200米，通信速率可达10Mb/s，需要一电阻进行阻抗匹配。

为扩展应用范围，EIA又于1983年在RS-422基础上制定了RS-485标准，增加了多点、双向通信能力，即允许多个发送器连接到同一条总线上，同时增加了发送器的驱动能力和冲突保护特性，扩展了总线共模范围，后命名为TIA/EIA-485-A标准。

RS-485采用差分信号正逻辑，+2—+6 V表示逻辑1，-2—-6 V表示逻辑0，信号电平较低，可直接和TTL电平兼容，同样的通信速率可达10Mb/s，采用平衡驱动器和差分接收器的组合，抗共模干能力增强，通信距离实际可达3000米，支持32个节点，使用特制芯片最多支持400个节点。

相关芯片
^^^^^^^^^^^

转USB类芯片 :ref:`wch_usb_uart`


.. _sdio:

SDIO
~~~~~~~~~~

.. _can:

CAN
~~~~~~~~~~
``控制器局域网``


CAN总线，也叫做控制器局域网总线（Controller Area Network），是一种用于实时应用的串行通讯协议总线，它可以使用双绞线来传输信号，是世界上应用最广泛的现场总线之一。



.. _i2c:

I2C
~~~~~~~~~~

I2C(Inter-Integrated Circuit BUS) 集成电路总线，多用于主控制器和从器件间的主从通信，在小数据量场合使用，传输距离短，任意时刻只能有一个主机等特性。IIC是真正的多主机总线，（对比SPI在每次通信前都需要把主机定死，而IIC可以在通讯过程中，改变主机），如果两个或更多的主机同时请求总线，可以通过冲突检测和仲裁防止总线数据被破坏

* 起始：时钟线SCL为高时，数据线SDA由高到低
* 停止：时钟线SCL为高时，数据线SDA由低到高
* SDA和SCL同时为高时，为IIC总线的空闲状态
* 所有的SDA 信号变化都要在SCL 时钟为低电平时进行，除了开始和结束标志
* 从机在第9个时钟信号进行拉低回应，表示收到了主机发来的数据，拉高则表示不应答
* 写寄存器时，主设备除了发出开始标志和地址位，还要加一个R/W 位，0为写，1为读

IIC总线上可以挂很多设备：多个主设备，多个从设备（外围设备）。当多个主机同时想占用总线时，企图启动总线传输数据，就叫做总线竞争。I2C通过总线仲裁，以决定哪台主机控制总线。

上拉电阻一般在4.7k~10k之间，每个接到I2C总线上的器件都有唯一的地址。

主机与其它器件间的数据传输可以是由主机发送数据到其它器件，这时主机即为发送器，总线上收数据的器件则为接收器。

* 传输速率在标准模式下可以达到100kb/s,快速模式下可以达到400kb/s
* 连接到总线的IC数量只是受到总线的最大负载电容400pf限制

.. _i3c:

I3C
~~~~~~~~~~

I3C吸纳了I2C和SPI的关键特性，并将其统一起来，同时在I2C的基础上，保留了2线的串行接口结构

* I3C总线可以支持multi-master即多主设备
* I3C总线与传统的I2C设备仍然兼容
* 可以支持软中断
* 相比较于I2C总线的功耗更低
* 速度更快，可以支持到12.5MHZ

I3C允许从设备启动带内中断，这对于I2C和SPI设备来说都需要一根额外的信号线才能实现。当总线处于空闲状态时，从设备可以通过中断机制发送一个"START"信号，然后主设备会为从设备提供一个时钟信号，从设备可以通过主设备提供的分配地址将设备驱动到总线上来启动中断。


.. _spi:

SPI
~~~~~~~~~~
``QSPI`` ``OSPI``

SPI(Serial Peripheral Interface) 串行外设接口，是一种高速的，全双工，同步的通信总线，并且在芯片的管脚上只占用四根线，两个SPI设备之间通信必须由主设备 (Master) 来控制次设备 (Slave)

* MISO– Master Input Slave Output,主设备数据输入，从设备数据输出；
* MOSI– Master Output Slave Input，主设备数据输出，从设备数据输入；
* SCLK – Serial Clock，时钟信号，由主设备产生；
* CS – Chip Select，从设备使能信号，由主设备控制。

SPI接口的一个缺点：没有指定的流控制，没有应答机制确认是否接收到数据。

SPI模块为了和外设进行数据交换，根据外设工作要求，其输出串行同步时钟极性和相位可以进行配置，时钟极性（CPOL）对传输协议没有重大的影响。如果CPOL=0，串行同步时钟的空闲状态为低电平；SPI主模块和与之通信的外设时钟相位和极性应该一致。

SPI有四种传输模式：上升沿、下降沿、前沿、后沿触发。当然也有MSB和LSB传输方式

经常I2C，SPI接口被认为指定是一种硬件设备，但其实这样的说法是不尽准确的，严格的说他们都是人们所定义的软硬结合体，分为物理层（四线结构）和协议层（主机，从机，时钟极性，时钟相位）。

I2C，SPI的区别不仅在与物理层，I2C比SPI有着一套更为复杂的协议层定义。IIC是半双工，而不是全双工，只要求两条总线线路。

IIC是真正的多主机总线（而这个SPI在每次通信前都需要把主机定死，而IIC可以在通讯过程中，改变主机），如果两个或更多的主机同时请求总线，可以通过冲突检测和仲裁防止总线数据被破坏。



功能外设
----------
``Touch`` ``RTC``

.. contents::
    :local:
    :depth: 1

.. _touch:

Touch
~~~~~~~~~~

.. _rtc:

RTC
~~~~~~~~~~


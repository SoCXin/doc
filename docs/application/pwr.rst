
.. _pwr:

电源设计
============

.. contents::
    :local:


.. _ulp:

极低功耗
----------

.. contents::
    :local:

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - PWR
      - Standby
      - Stop
    * - :ref:`stm32l011`
      - 32MHz
      - 20 KB
      - 192 KB
      - 49 µA/MHz
      - 230 nA
      - 340 nA
    * - :ref:`stm32l412`
      - 80MHz
      - 40 KB
      - 128 KB
      - 28 μA/MHz
      - 195 nA
      - 340 nA
    * - :ref:`stm32h7b0`
      - 280 MHz
      - 1.4 MB
      - 128 KB
      - 120 µA/MHz
      - 2.2 µA
      - 32 µA


.. _usb_pd:

USB-PD
-------------

`USB PD <https://github.com/Qful/PD>`_ (USB Power Delivery)功率传输协议，是目前主流的快充协议之一，USB功率2013年的新标准名为USBPD，USB PD 协议基于USB3.1，是USB3.1 中即type-c端口后提出的功率传输概念。USBPD透过USB电缆和连接器增加电力输送，扩展USB应用中的电缆总线供电能力。该规范可实现更高的电压和电流，输送的功率最高可达100瓦，并可以自由的改变电力的输送方向。

.. toctree::
    :maxdepth: 1

    CS32G020 <../M/CS32G020>
    RK837 <../M/RK837>

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
      -
      - 1K
      - 8K
      - 2
      - 18
      -
    * - :ref:`ch552`
      -
      - 1K
      - 8K
      - 2
      - 18
      -


通信原理
~~~~~~~~~~~

USB PD的通信是将协议层的消息调制成24MHZ的FSK信号并耦合到VBUS上或者从VBUS上获得FSK信号来实现手机和充电器通信的过程。

将24MHz的FSK通过cAC-Coupling耦合电容耦合到VBUS上的直流电平上的，而为了使24MHz的FSK不对PowerSupply或者USBHost的VBUS直流电压产生影响，在回路中同时添加了zIsolation电感组成的低通滤波器过滤掉FSK信号。


* 1）USB OTG的PHY监控VBUS电压，如果有VBUS的5V电压存在并且检测到OTGID脚是1K下拉电阻（不是OTGHost模式，OTGHost模式的ID电阻是小于1K的），就说明该电缆是支持USBPD的；
* 2）USB OTG做正常BCSV1.2规范的充电器探测并且启动USBPD设备策略管理器，策略管理器监控VBUS的直流电平上是否耦合了FSK信号，并且解码消息得出是CapabilitiesSource消息，就根据USBPD规范解析该消息得出USBPD充电器所支持的所有电压和电流列表对；
* 3）手机根据用户的配置从CapabilitiesSource消息中选择一个电压和电流对，并将电压和电流对加在Request消息的payload上，然后策略管理器将FSK信号耦合到VBUS直流电平上；
* 4）充电器解码FSK信号并发出Accept消息给手机，同时调整PowerSupply的直流电压和电流输出；
* 5）手机收到Accept消息，调整ChargerIC的充电电压和电流；
* 6）手机在充电过程中可以动态发送Request消息来请求充电器改变输出电压和电流，从而实现快速充电的过程。

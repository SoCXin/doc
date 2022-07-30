
.. _usb:

USB
============



USB设备有两种供电方式：

* 自供电设备：设备从外部电源获取工作电压 (使用自己的外部电源)
* 总线供电设备：设备从VBUS(5v) 取电对总线供电设备，区分低功耗和高功耗USB设备 低功耗总线供电设备：最大功耗不超过100mA 高功耗总线供电设备： 枚举时最大功耗不超过100mA，枚举完成配置结束后功耗不超过500mA 设备在枚举过程中，通过设备的配置描述符向主机报告它的供电配置（自供电/总线供电）以及它的功耗要求

由于USB是主从模式的结构，设备与设备之间、主机与主机之间不能互连，为解决这个问题，扩大USB的应用范围，出现了USB OTG。

.. contents::
    :local:
    :depth: 1

.. _usb_hs:

USB HS
-------------
``480Mbps``

.. list-table::
    :header-rows:  1

    * - :ref:`usb_hs`
      - :ref:`frequency`
      - :ref:`sram`
      - USB FS
      - USB HS
      - :ref:`ethernet`
      - :ref:`package`
    * - :ref:`ch563`
      -
      - 64KB
      - 1
      -
      - 100Mbps
      - 100Mbps
    * - :ref:`ch567`
      - 120MHZ
      - 32KB
      -
      - 2x OTG
      -
      - LQFP48
    * - :ref:`ch565`
      - 120MHZ
      - 112KB
      -
      - HS + SS
      -
      - QFN40
    * - :ref:`ch569`
      - 120MHZ
      - 112KB
      -
      - HS + SS
      -
      - QFN68
    * - :ref:`ch32f207`
      - 144MHZ
      - 64KB
      - 2
      -
      - 10M/1Gbps
      -
    * - :ref:`ch32v307`
      - 144MHZ
      - 64KB
      -
      -
      - 10M/1Gbps
      -
    * - :ref:`aic8800`
      -
      -
      -
      -
      -
      -
    * - :ref:`hpm6750`
      -
      -
      -
      -
      -
      -
    * - :ref:`hpm6350`
      -
      -
      -
      -
      -
      -

USB使用一根屏蔽的4线电缆与网络上的设备进行互联。数据传输通过一个差分双绞线进行，这两根线分别标为D+和D-，另外两根线是Vcc和Ground，其中Vcc向USB设备供电。

* 全速模式是在D+线上上拉1.5K的电阻。
* 低速模式是在D-线上上拉1.5K的电阻。


.. _usb_pd:

USB PD
-------------
``USB-PD`` ``PD3.0/2.0`` ``BC1.2``

`USB-PD <https://github.com/stops-top/USB-PD>`_ (USB Power Delivery)功率传输协议，是目前主流的快充协议之一，USB功率2013年的新标准名为USBPD，USB PD 协议基于USB3.1，是USB3.1 中即type-c端口后提出的功率传输概念。USBPD透过USB电缆和连接器增加电力输送，扩展USB应用中的电缆总线供电能力。该规范可实现更高的电压和电流，输送的功率最高可达100瓦，并可以自由的改变电力的输送方向。

.. list-table::
    :header-rows:  1

    * - :ref:`usb_pd`
      - :ref:`architecture`
      - :ref:`frequency`
      - Flash
      - UART
      - GPIO
      - :ref:`package`
    * - :ref:`ch549`
      -
      -
      - 8K
      - 2
      - 18
      -
    * - :ref:`ch552`
      -
      -
      - 8K
      - 2
      - 18
      -

.. toctree::
    :maxdepth: 1

    RK837 <../miscellaneous/RK837>



电源芯片
~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`usb_pd`
      - INPUT
      - TYPE
      - POWER
      - :ref:`package`
    * - `CH236 <http://www.wch.cn/products/CH236.html>`_
      - 5-20V
      - PD3.0/BC1.2
      - 100W
      - QFN20/QFN16
    * - `CH234 <http://www.wch.cn/products/CH234.html>`_
      - 5-12V
      - PD3.0/BC1.2
      - 27W
      - ESSOP10


USB PD的通信是将协议层的消息调制成24MHZ的FSK信号并耦合到VBUS上或者从VBUS上获得FSK信号来实现手机和充电器通信的过程。

将24MHz的FSK通过cAC-Coupling耦合电容耦合到VBUS上的直流电平上的，而为了使24MHz的FSK不对PowerSupply或者USBHost的VBUS直流电压产生影响，在回路中同时添加了zIsolation电感组成的低通滤波器过滤掉FSK信号。

* 1）USB OTG的PHY监控VBUS电压，如果有VBUS的5V电压存在并且检测到OTGID脚是1K下拉电阻（不是OTGHost模式，OTGHost模式的ID电阻是小于1K的），就说明该电缆是支持USBPD的；
* 2）USB OTG做正常BCSV1.2规范的充电器探测并且启动USBPD设备策略管理器，策略管理器监控VBUS的直流电平上是否耦合了FSK信号，并且解码消息得出是CapabilitiesSource消息，就根据USBPD规范解析该消息得出USBPD充电器所支持的所有电压和电流列表对；
* 3）手机根据用户的配置从CapabilitiesSource消息中选择一个电压和电流对，并将电压和电流对加在Request消息的payload上，然后策略管理器将FSK信号耦合到VBUS直流电平上；
* 4）充电器解码FSK信号并发出Accept消息给手机，同时调整PowerSupply的直流电压和电流输出；
* 5）手机收到Accept消息，调整ChargerIC的充电电压和电流；
* 6）手机在充电过程中可以动态发送Request消息来请求充电器改变输出电压和电流，从而实现快速充电的过程。


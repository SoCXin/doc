.. _wpan:

WPAN
============
``Bluetooth`` ``Zigbee`` ``RFID`` ``UWB`` ``NFC`` ``54Mbit/s`` ``802.15.4``

无线个域网就是在个人周围空间形成的无线网络，现通常指覆盖范围在10m半径以内的短距离无线网络，尤其是指能在便携式消费者电器和通信设备之间进行短距离特别连接的自组织网。WPAN被定位于短距离无线通信技术，但根据不同的应用场合又分为高速WPAN（HR－WPAN）和低速WPAN（LR－WPAN）两种。

.. list-table::
    :header-rows:  1

    * - :ref:`wpan`
      - :ref:`802_15_4`
      - :ref:`bluetooth`
      - :ref:`zigbee`
      - :ref:`rfid`
      - :ref:`uwb`
    * - 距离
      -
      -
      -
      -
      -
    * - 易用性
      -
      -
      -
      -
      -
    * - 扩展性
      -
      -
      -
      -
      -



.. _802_15_4:

802.15.4
----------
``2.4GHz/868MHz/915MHz`` ``LR-WPAN`` ``DSSS`` ``GTS``

`IEEE 802.15.4 <https://baike.baidu.com/item/IEEE%20802.15.4/6657379?fromtitle=802.15.4&fromid=1115952&fr=aladdin>`_ 是一种技术标准，它定义了低速率无线个域网（LR-WPAN）的协议。 它规定了LR-WPAN的物理层和媒体访问控制 ，并由IEEE 802.15工作组维护，该工作组在2003年定义了该标准。它是Zigbee的基础，诸如 ISA100.11a ， WirelessHART ， MiWi ， 6LoWPAN ， 线程和SNAP规范，每个规范通过开发IEEE 802.15.4中未定义的上层进一步扩展了标准。


.. list-table::
    :header-rows:  1

    * - :ref:`802_15_4`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`sram`/:ref:`flash`
      - :ref:`package`
    * - :ref:`esp32c6`
      - :ref:`esp_rv32`
      -
      -
      -


.. contents::
    :local:
    :depth: 1


.. _zigbee:

ZigBee
~~~~~~~~~~~
``802.15.4``

.. _thread:

Thread
~~~~~~~~~~~
``802.15.4``


.. _rfid:

RFID
----------
``Radio Frequency IDentification``

RFID有低频（mm的传输距离）、高频（13.56Mhz）、超高频、微波频段等，频段不同，功率不同，传输的距离不同。



.. _nfc:

NFC
~~~~~~~~~~~
``Near Field Communication`` ``13.56MHz``

NFC从本质上来说是一种RFID的演进技术，NFC只是限于13.56MHz的频段。而RFID的频段有低频（125KHz到135KHz），高频（13.56MHz）和超高频（860MHz到960MHz）。

NFC工作有效距离约10cm，所以具有很高的安全性。

.. _ndef:

NDEF
^^^^^^^^^^^
``NFC数据交换格式``

是一种标准化的数据格式，可用于在任何兼容的NFC设备与另一个NFC设备或标签之间交换信息。 数据格式由NDEF消息和NDEF记录组成。 该标准由NFC论坛维护，可以免费获得参考，但需要接受许可协议才能下载。



.. _uwb:

UWB
----------

``Ultra Wide Band``

UWB是无载波通信技术，利用纳秒（ns）至皮秒（ps）级的非正弦波窄脉冲传输数据，而时间调变技术令其传送速度可以大大提高，而且耗电量相对地低，并有较精确的定位能力。

这些脉冲所占用的带宽甚至达到几GHz，因此最大数据传输速率可以达到几百Mbps。

因为使用的是极短脉冲，在高速通信的同时，UWB设备的发射功率却很小，仅仅只有目前的连续载波系统的几百分之一。

超宽带的传输距离都是在十公尺之内，它的传输速率高达480Mbps，是蓝牙的159倍，是Wi-Fi标准的18.5倍，非常适合多媒体信息的大量传输。

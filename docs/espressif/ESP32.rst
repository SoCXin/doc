.. _esp32:

ESP32
===============

* 关键词：``Xtensa LX6`` ``Dual Core`` ``240MHz`` ``WiFi`` ``BLE4.2`` ``TWAI`` ``Ethernet`` ``MAC100`` ``QFN48``  ``TSMC40``
* 资源库：`GitHub <https://github.com/SoCXin/ESP32>`_ , `Gitee <https://gitee.com/socxin/ESP32>`_

.. contents::
    :local:

Xin简介
-----------

.. image:: ./images/ESP32.png
    :target: https://www.espressif.com/zh-hans/products/socs/ESP32

规格配置
~~~~~~~~~~~


基本参数
^^^^^^^^^^^

* 发布时间：2016年9月
* 供电电压：2.3 to 3.6 V
* 工作温度：-40°C to +105°C
* 处理性能：600 :ref:`DMIPS`
* RAM容量：520 KB (8 MB SPI)
* ROM容量：448 KB (16 MB SPI)
* 封装规格：:ref:`esp_qfn48`


特征参数
^^^^^^^^^^^

* 240 MHz :ref:`xtensa_lx6` Dual Core
* 超低功耗协处理器 :ref:`esp_ulp`
* 1T1R 802.11 b/g/n :ref:`esp_wifi`
*  +12 dBm，–97dBm :ref:`esp_ble` v4.2
* :ref:`esp_twai`
* IEEE 1588 MAC,100 Mbps
* Host SD/eMMC/SDIO、Slave SDIO/SPI
* 硬件加密单元AES/RSA/ECC
* 霍尔传感器
* 12-bit SAR ADC 18ch
* 2 x 8-bit DAC
* `ESP-IDF <https://github.com/espressif/esp-idf>`_

`datasheet <https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_cn.pdf>`_




Xin选择
-----------

.. contents::
    :local:


品牌对比
~~~~~~~~~

对标的对手包括 Realtek 和 :ref:`mediatek`

系列对比
~~~~~~~~~

相对较早的产品ESP8266，具有更强的性能，同时集成蓝牙功能

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - DMIPS
      - RAM
      - WiFi
      - BLE
      - USB
      - Ethernet
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 600 DMIPS
      - 520 KB
      - 802.11 b/g/n
      - BT/BLE v4.2
      - NO
      - MAC100
    * - :ref:`esp32c3`
      - :ref:`espressif_rv32`
      - 200 DMIPS
      - 400 KB
      - 802.11 b/g/n
      - BLE v5.0
      - NO
      - NO


型号对比
~~~~~~~~~



必选理由
~~~~~~~~~


Xin应用
-----------

.. contents::
    :local:

硬件平台
~~~~~~~~~~~

.. image:: ./images/B_ESP32.jpg
    :target: https://detail.tmall.com/item.htm?spm=a230r.1.14.28.50e564d3axhB7j&id=624276301887&ns=1&abbucket=19
.. contents::
    :local:



开发工具
~~~~~~~~~~~

源圈OS-Q通过先验证的方式，集成了更多可信赖资源 `PlatformIO ESP32 <https://github.com/OS-Q/P511>`_ 可以作为一个启动模板，作为一个开源编译体系便于多系统下开发。

协处理的开发，使用汇编语言，需要单独的工具链，通过官方提供提供的IDF工具实现。





Xin总结
--------------

.. contents::
    :local:

重点提示
~~~~~~~~~~~~~

烧录模式
^^^^^^^^^^^^^

因为esp32芯片进入烧写模式的条件是启动时检测boot引脚，因此需要摁着boot键才能下载程序。出现这种情况一般是启动配置的strapping引脚采样电平不符合启动模式，需要调整硬件电路。

串口权限
^^^^^^^^^^^^^

linux下面串口设备的一般是root权限，因此使用串口需要取得root权限或者修改dev目录下串口的权限。想串口支持当前用户，需要把当前用户添加到Group

" sudo usermode -a -G dialout $USER "


问题整理
~~~~~~~~~~~~~

`bugs <https://www.espressif.com/sites/default/files/documentation/eco_and_workarounds_for_bugs_in_esp32_cn.pdf>`_

Brownout detector was triggered 已触发断电探测器

原因在于: ESP32的电平低于某个值（这个值是可以设定的），然后触发了断电探测器，断电探测器会使得ESP32重新启动。

解决：换个电源，要不就是ESP32板子设计本身有问题，最终的大招，禁用断电探测器


make menuconfig->component config->ESP32-specific->Hardware brownout detect &reset禁用掉这个选项，将不再检测电平。或者也可在再这个选项的下面选择一个更合适的保护电平。

这个问题描述的是：ESP32的电平低于某个值（这个值是可以设定的，后文会有介绍），然后触发了断电探测器，断电探测器会使得ESP32重新启动。


LoadProhibited/StoreProhibited
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

<禁止加载、禁止存储>

当应用程序尝试读取或写入无效的内存位置时,会发生此 CPU 异常。

可能原因:写入/读取的地址可在寄存器转储中的 EXCVADDR寄存器(途中红色划线)中找到.

1、如果此地址为零,则通常表示应用程序尝试引用 NULL 指针(勿忘对数组成员取地址)；

2、如果此地址接近于零,则通常意味着应用程序尝试访问结构体的成员,但指向该结构的指针为 NULL；

3、如果该地址是别的(垃圾值,不在 0x3fxxxxxx - 0x6xxxxxxx 范围内),则可能意味着用于访问数据的指针未初始化或已损坏。

引用NULL指针(&地址引用错误、野指针....)

在编译时出现error: unrecognized command line option '-mfix-esp32-psram-cache-issue'
原因:这是因为ESP32的某些修订存在一些问题，这些问题会对外部RAM的使用产生影响。而这些内容都记录在ESP32 ECO文档中。


.. warning::
    ESP32最大的槽点就是编译效率，因为组件特别多，每次编译都非常耗时间

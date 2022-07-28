
.. _ulp:

能效Xin
============


.. list-table::
    :header-rows:  1

    * - :ref:`ulp`
      - :ref:`architecture`
      - :ref:`frequency`
      - :ref:`ulpbench`
      - :ref:`wireless`
      - :ref:`vdd`
      - :ref:`power`
      - :ref:`halt`
      - :ref:`sleep`
    * - :ref:`stm32u575`
      - :ref:`cortex_m33`
      - 160(MHz)
      - 651
      - X
      - 1.7-3.6
      - 19 µA
      - 475 nA
      - 110 nA
    * - :ref:`stm32l412`
      - :ref:`cortex_m4`
      - 80(MHz)
      - 273.55
      - X
      - 1.7-3.6
      - 28 μA
      -
      - 195 nA
    * - :ref:`ch32v203`
      - :ref:`wch_riscv4c`
      - 144(MHz)
      - 
      - X
      - 2.4-3.6
      - 45 μA
      -
      - 500 nA
    * - :ref:`stm32l011`
      - :ref:`cortex_m0`
      - 32(MHz)
      -
      - X
      - 1.7-3.6
      - 49 µA
      -
      - 230 nA
    * - :ref:`cc1350`
      - :ref:`cortex_m3`
      - 48(MHz)
      - 158
      - √
      - 1.8-3.8
      - 51 µA
      -
      - 185 nA
    * - :ref:`cc2340`
      - :ref:`cortex_m0`
      - 48(MHz)
      -
      - :ref:`ble`
      - 1.71-3.8
      - 55 µA
      - 830 nA
      - 150 nA
    * - :ref:`cc2650`
      - :ref:`cortex_m3`
      - 64(MHz)
      - 142
      - √
      - 1.8-3.8
      - 61 µA
      -
      - 100 nA
    * - :ref:`gd32l233`
      - :ref:`cortex_m23`
      - 64(MHz)
      - 
      - X
      - 1.7-3.6
      - 66 µA
      -
      - 2.0µA
    * - :ref:`hpm6340`
      - :ref:`andes_d45`
      - 648(MHz)
      - 3390
      - X
      - 3.0-3.6
      - 90 µA
      -
      - 1.5µA
    * - :ref:`stm32h7b0`
      - :ref:`cortex_m7`
      - 280(MHz)
      - 1414
      - X
      - 1.71-3.6
      - 120µA
      -
      - 2.2 µA



.. hint::
    功耗和成本是低阶芯片产品的护城河，也是物联网的特性，如无功耗限制，高性能产品将向下挤压低端产品的生存空间



.. _power:

Power
-----------
``运行功耗`` ``uW/MHz``

PPA是芯片开发者们背负的终极KPI,也就是Performance(性能)、Power(功耗)、Area(尺寸)三者的缩写。任何芯片设计的目标都是希望得到更高的性能,更低的功耗,更小的面积。

.. _frequency:

Frequency
~~~~~~~~~~~~~
``MHz``

.. _consumption:

Consumption
~~~~~~~~~~~~~
``电流功耗`` ``uA/MHz``


Ambiq Micro是一家专注于超低功耗的MCU厂商，其Apollo系列引领了超低功耗MCU的新方向。Apollo系列采用亚阈值功率优化技术（SPOT）平台为基础，运行功耗可低至6uA/MHz，是全球同类产品中运行功耗最低的微控制器。

亚阈值功率优化技术（SPOT）是当前实现超低功耗的最有效技术，让晶体管能够在远低于“标准”的电压水平下工作，从而实现芯片功耗的大幅度降低，因此其解决方案在功耗改善上实现跨越式的改善。


华大半导体在低功耗32位微控制产品研发的布局较早，已相继推出HC32L110、HC32L130、HC32L136产品系列。该系列芯片基于Cortex-M0+内核，采用华虹宏力的110nm超低漏电（ULL）嵌入式闪存工艺，采用多电源域的低功耗设计方法。该芯片的运行功耗为130uA/MHz，深度睡眠模式最低为0.9uA，适用于传感器、火灾探头、智能门锁、无线烟感、智能表计、便携式医疗电子、数据采集和传输等应用领域。

中科芯蕊是一家专注于低功耗MCU的国内厂商，于今年5月份推出了XRM32UL051系列。该芯片基于Cortex-M0+内核，超低漏电的先进工艺制程，采用其独有的亚阈值技术和异步电路技术，运行模式的功耗低至20uA/MHz，深度睡眠的功耗低至0.7uA。该功耗指标与国际厂商（意法、瑞萨）的最新产品指标接近，适用于智能门锁、智能表计、便携式医疗电子等传统低功耗应用领域，同时能够支持环境自采集类应用，实现设备长期续航。


.. _halt:

Halt
~~~~~~~~~~~~~
``低功耗待机状态`` ``停止模式``

.. _sleep:

Sleep
~~~~~~~~~~~~~
``低功耗睡眠模式`` ``时钟关闭`` ``RAM断电`` ``可唤醒状态``

.. _vdd:

VDD
-----------
``供电电压`` ``Virtual Device Driver`` ``Voltage Drain Drain``

VDD可以看作为某一芯片内部的工作电压;

VCC: Voltage To Current Converter(电路电压)或Voltage Collector Collector (集电极电源电压)

用作电路电压时,表示接入电路的电压;用作集电极电源电压,一般用于双极性晶体管,是晶体管的正电源;此外,vcc中的c还可以解读为circuit(电路),同样表示电路电压;

.. list-table::
    :header-rows:  1

    * -
      - :ref:`CoreMark`
      - :ref:`frequency`
      - :ref:`power`
      - :ref:`vdd` (min)
      - :ref:`vdd` (max)
      - :ref:`package`
    * - :ref:`ch583`
      -
      - ≤ 80MHz
      - 
      - 1.7v
      - 3.6v
      - QFN48


.. contents::
    :local:
    :depth: 1

AA电池
~~~~~~~~~~~
``1.5v``

锂电池
~~~~~~~~~~~
``3.7v``

超级电容
~~~~~~~~~~~
``4.2v``
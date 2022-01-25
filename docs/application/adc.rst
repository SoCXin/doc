
.. _adc:

A/D转换
============

.. contents::
    :local:


技术分类
------------

.. contents::
    :local:


.. _sar:

SAR
~~~~~~~~~~~~~~

逐次逼近式模拟数字转换器SAR(Successive Approximation Register)，在每一次转换过程中，通过遍历所有的量化值并将其转化为模拟值，将输入信号与其逐一比较，最终得到要输出的数字信号。

逐次逼近模数转换器是采样速率低于5Msps的中高分辨率ADC应用的常见结构，SAR式ADC的分辨率一般为8-16位。具有低功耗，小尺寸等特点。

.. _pipeline:

Pipeline
~~~~~~~~~~~~~~

pipeline 更适合高速中等精度的，如 100M 14bit 以上的应用。

100MHz Conversion Rate 12-bit , :ref:`sar` 就要1.4GHz的Clock，而 Pipelined ADC 只需100MHz的 Clock

随着工艺的进步，:ref:`sar` 和 :ref:`sigma_delta` 的速度也上来 ，Pipeline 正在全面被SAR取代，除了12bit以上且大于200MSPS


.. _sigma_delta:

Sigma-Delta
~~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    ZML165 <../M/ZML165>
    SWM181 <../M/SWM181>
    CS32A039 <../M/CS32A039>

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Chan
      - Rate
      - ENOB
      - PGA
      - INL
      - Package
    * - :ref:`cs32a039`
      - :ref:`cortex_m0`
      - 1x5ch
      - 10~1280Hz
      - 20.7/20.2
      - 128
      - 1.2LSB
      - LQFP64
    * - :ref:`zml165`
      - :ref:`cortex_m0`
      - 1x2ch
      - 10~1280Hz
      - 20.7/20.2
      - 128
      - 1.2LSB
      - :ref:`qfn20`
    * - :ref:`swm181`
      - :ref:`cortex_m0`
      - 1x4ch
      - 16KSPS
      - 16
      - 128
      - 1.2LSB
      - LQFP48

.. warning::
    :ref:`sigma_delta` 以时间上换极高的精度的特性，采样率都很低，但在精度达到20位以上的场合，实现了其他类型的ADC无法达到的高精度和低功耗。


超高速率
------------

.. contents::
    :local:



独立器件
~~~~~~~~~~~~

MXT2088
^^^^^^^^^^^^

``8bit`` ``100MSPS``

* 双通道8bit，100MSPS ADC
* 低功耗，在100MSPS下，单通道功耗为90mW
* 片内的基准和采样保持电路
* 每个通道有475MHz的模拟带宽
* 47dB SNR @41MHz
* 每个通道有1Vp-p的模拟输入范围
* 单电源电压，标准为3V，可以接受2.7V~3.6V
* 每个通道可单独工作
* 2的补码和偏移2进制输出
* 输出数据对齐模式

MXT2002是双8位500MSPS模数转换器，单通道采样率高达800MSPS

`MXT2088资料 <http://www.mxtronics.com/n107/n124/n181/n184/c692/content.html>`_




AD9481
^^^^^^^^^^^^

``8bit`` ``250MSPS``

`米联客数据采集卡DAQ9481 <https://www.uisrc.com/portal.php>`_

AD9481 是一款8位单芯片模数转换器（ADC），专门针对高速和低功耗进行了优化。转换速率为250 MSaps，模拟输入范围1Vpp，积分非线性±0.26LSB（典型值），差分非线性±0.35LSB（典型值），在整个工作范围内都具有出色的线性度和动态性能，最高速率下功耗小于450mW。

AD9767
^^^^^^^^^^^^

``14bit`` ``125MSPS`` ``Dual-Channel`` ``75dBc`` ``LQFP48`` ``$21.70``

`AD9767芯片 <https://www.analog.com/cn/products/ad9767.html#product-overview>`_

`米联客数据采集卡 <https://www.uisrc.com/portal.php?mod=view&aid=330>`_


ADS4229
^^^^^^^^^^^^

``12bit`` ``250MSPS`` ``Dual-Channel`` ``545mW`` ``VQFN64`` ``$36.30``

`ADS4229芯片 <https://www.ti.com.cn/product/cn/ADS4229#order-quality>`_


.. list-table::
    :header-rows:  1

    * - Type
      - MSPS
      - Resolution
      - Interface
      - Power
      - Arch
      - Package
    * - ADS4222
      - 65
      - 12Bit
      - DDR LVDS
      - 183mW
      - Pipeline
      - VQFN64
    * - ADS4225
      - 125
      - 12Bit
      - DDR LVDS
      - 183mW
      - Pipeline
      - VQFN64
    * - ADS4229
      - 250
      - 12-Bit
      - DDR LVDS
      - 545mW
      - Pipeline
      - VQFN64
    * - ADS4249
      - 250
      - 14-Bit
      - DDR LVDS
      - 545mW
      - Pipeline
      - VQFN64


通信接口
~~~~~~~~~~~~

LVDS
^^^^^^^^^^^^

集成方案
~~~~~~~~~~~~

目前MCU集成的ADC性能，以STM32为参考，精度可到16-Bit，速率可达5MSPS

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - SPEC
      - Package
    * - :ref:`stm32g431`
      - 170MHz
      -
      -
      -
      -
      -
      - LQFP48



超高精度
------------

.. contents::
    :local:

独立方案
~~~~~~~~~~~~

LTC2508-32
^^^^^^^^^^^^

``32-bit @1MSPS`` ``24mW`` ``SAR ADC`` ``Dual Channel`` ``DFN24`` ``$12.02``

* ±0.5ppm INL (典型值)
* 61sps 时的 145dB 动态范围 (典型值)
* 4ksps 时的 131dB 动态范围 (典型值)
* 双输出 32 位 SAR ADC，32 位数字滤波低噪声输出，14 位差分 + 8 位共模 1Msps 无延迟输出

LTC2508-32 是一款低噪声、低功率、高性能 32 位 ADC，其具有一个集成的可配置数字滤波器。
LTC2508-32 采用单个 2.5V 工作电源，具有一个高达 ±VREF 的全差分输入范围，且 VREF 的范围从 2.5V 至 5.1V。
LTC2508-32 支持 0V 至 VREF 的宽共模范围，从而简化了模拟信号调理要求。
LTC2508-32 同时提供两个输出代码：(1) 一个 32 位数字滤波高精度低噪声代码；和 (2) 一个 22 位无延迟复合代码。
可配置数字滤波器通过对来自 SAR ADC 内核的数据流实施低通滤波和降频采样以降低测量噪声，产生了 32 位滤波输出代码。
22 位复合代码由一个代表差分电压的 14 位代码和一个代表共模电压的 8 位代码组成。
22 位复合代码可在每个转换周期中提供，并没有延迟周期。
可通过引脚搭接方便地针对 4 种不同的降频转换因子配置数字滤波器。
这些配置提供一个 131dB (在 3.9ksps) 和 145dB (在 61sps) 的动态范围。数字低通滤波器放宽了对于模拟抗混迭的要求。
采用 SYNC 引脚可以很容易地实现多个 LTC2508-32 器件的同步。

`LTC2508资料 <https://www.analog.com/cn/products/ltc2508-32.html>`_

AD4630
^^^^^^^^^^^^

``24-bit @2MSPS`` ``24mW`` ``SAR ADC`` ``Dual Channel`` ``CSP_BGA64`` ``$37.14``

* 积分非线性：从 −40°C to +125°C，最大值为 ±0.9 ppm
* SNR：105.7 dB（典型值）
* 总谐波失真：−127 dB（典型值）
* NSD−166 dBFS/Hz （典型值）
* 2 MSPS 时每通道 15 mW
* 直流输入的极低 0.6 μA 输入电流
* 宽输入共模电压范围：−(1/128) × VREF 至 +(129/128) × VREF
* 灵活的外部基准电压源范围：4.096 V 至 5 V


`AD4630资料 <https://www.analog.com/cn/products/ad4630-24.html#product-overview>`_


集成方案
~~~~~~~~~~~~

目前MCU集成高精度ADC，主流技术以24-Bit为主，多以SiP封装为主。

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - CHAN
      - ADC
      - SPEC
      - Package
    * - :ref:`zml165`
      - 48 MHz
      - 4 KB
      - 64 KB
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - QFN20
    * - :ref:`swm181`
      - 48 MHz
      - 16 KB
      - 120 KB
      - 4
      - :ref:`sigma_delta`
      - 16bit
      - LQFP48
    * - :ref:`cs32a039`
      - 48 MHz
      - 4 KB
      - 64 KB
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - LQFP64


Audio ADC
------------

.. contents::
    :local:


技术特点
~~~~~~~~~~~~


ES7210
^^^^^^^^^^^^

``24-bit`` ``102dB`` ``4 Channel`` ``400 kbps`` ``QFN32`` ``￥4.0``

`Everest-semi <http://www.everest-semi.com/cn_products.php>`_




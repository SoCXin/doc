
.. _adc:

ADC
============

.. contents::
    :local:
    :depth: 1



产品分类
------------

.. contents::
    :local:
    :depth: 1

.. _adc_mcu:

ADC-MCU
~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * -
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`sram`
      - :ref:`adc12b`
      - :ref:`adc16b`
      - :ref:`peripherals`
      - :ref:`package`
    * - :ref:`at32f437`
      - 288 MHz
      - 630
      - 512K
      - 3x16ch
      - X
      -
      - :ref:`LQFP64`
    * - :ref:`stm32l412`
      - 80 MHz
      -
      - 40K
      - 2x
      - X
      -
      - LQFP32
    * - :ref:`stm32g431`
      - 170MHz
      -
      - 128K
      - 2x4MSPS
      - X
      - 4/3
      - :ref:`LQFP48`
    * - :ref:`stm32g474`
      - 170MHz
      -
      - 128K
      - 5x4MSPS
      - X
      - 7/6
      - LQFP100
    * - :ref:`stm32h730`
      - 550MHz
      -
      - 564K
      - 1x5MSPS
      - 2x3.6MSPS
      - 2/2
      - LQFP100
    * - :ref:`stm32h750`
      - 480MHz
      -
      - 1MB
      - X
      - 3x3.6MSPS
      - 2/2
      - LQFP100
    * - :ref:`stm32h7b0`
      - 280MHz
      -
      - 1.4M
      - X
      - 2x3.6MSPS
      - 2/2
      - :ref:`LQFP64`
    * - :ref:`hpm6750`
      - 816MHz
      - 9220(2)
      - 2M
      - 3x5MSPS
      - 1x2MSPS
      - 2/4
      - BGA196
    * - :ref:`hpm6350`
      - 648MHz
      - 9220(2)
      - 800K
      -
      - 3x2MSPS
      - 2
      - BGA116

.. note::
    目前MCU集成的高速ADC性能，精度可到16bit(普遍12bit)，速率可达5MSPS(普遍2MSPS)，独立器件数量可达5个(普遍2个)；2x16bit+1x12bit数据带宽3.6M x 2 x 16 + 5M x 1 x 12 = 175.2Mbps，3x16bit 数据带宽3.6M x 3 x 16 = 172.8Mbps



.. list-table::
    :header-rows:  1

    * -
      - :ref:`frequency`
      - :ref:`sram`/:ref:`flash`
      - SNR
      - INL
      - Type
      - Spec
      - :ref:`package`
    * - :ref:`zml165`
      - 48 MHz
      - 4KB/64KB
      -
      -
      - :ref:`sigma_delta`
      - 24bit
      - QFN20
    * - :ref:`zml166`
      - 48 MHz
      - 4KB/64KB
      -
      -
      - :ref:`sigma_delta`
      - 24bit
      - QFN32
    * - :ref:`cs32a039`
      - 48 MHz
      - 4KB/64KB
      -
      -
      - :ref:`sigma_delta`
      - 24bit
      - :ref:`LQFP64`

.. note::
    目前MCU集成高精度ADC，主流以24-Bit为主，多以SiP封装 :ref:`sigma_delta` 为主。


.. toctree::
    :maxdepth: 1

    PG23 <../miscellaneous/PG23>
    ZML165 <../miscellaneous/ZML165>

转换速率(Conversion Rate)是指完成一次从模拟转换到数字的AD转换所需的时间的倒数。积分型AD的转换时间是毫秒级属低速AD，逐次比较型AD是微秒级属中速AD，全并行/串并行型AD可达到纳秒级。

采样时间是指两次转换的间隔。为了保证转换的正确完成，采样速率(Sample Rate)必须小于或等于转换速率。

因此有人习惯上将转换速率在数值上等同于采样速率也是可以接受的。常用单位是ksps和Msps，表示每秒采样千/百万次（kilo / Million Samples per Second）。

量化误差(Quantizing Error) 由于AD的有限分辩率而引起的误差，即有限分辩率AD的阶梯状转移特性曲线与无限分辩率AD（理想AD）的转移特性曲线（直线）之间的最大偏差。通常是1 个或半个最小数字量的模拟变化量，表示为1LSB、1/2LSB。


.. _adc12b:

12-bit ADC
^^^^^^^^^^^^

.. _adc16b:

16-bit ADC
^^^^^^^^^^^^



.. _adc_hs:

High-Speed
~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - MSPS
      - Resolution
      - Channel
      - Interface
      - Power
      - Arch
      - :ref:`package`
      - Price
    * - ADS4222
      - 65
      - 12-bit
      - 2
      - LVDS
      - 183mW
      - Pipeline
      - VQFN64
      - $36.30
    * - ADS4225
      - 125
      - 12-bit
      - 2
      - LVDS
      - 183mW
      - Pipeline
      - VQFN64
      - $36.30
    * - :ref:`ADS4229`
      - 250
      - 12-bit
      - 2
      - LVDS
      - 545mW
      - Pipeline
      - VQFN64
      - $36.30
    * - ADS4249
      - 250
      - 14-bit
      - 2
      - LVDS
      - 545mW
      - Pipeline
      - VQFN64
      - $36.30
    * - :ref:`AD9767`
      - 125
      - 14-bit
      - 2
      - LVDS
      - 545mW
      - Pipeline
      - :ref:`LQFP48`
      - $21.70


.. _9248:

AD9248
^^^^^^^^^^^^

``14bit`` ``65MSPS`` ``Dual-Channel`` ``SNR71.6dBc`` ``800mW`` ``LQFP48`` ``$21.70``

`AD9248芯片 <https://www.analog.com/cn/products/ad9248.html>`_

AD9248是一款双核、3 V、14位、20/40/65 MSPS模数转换器（ADC），集成了两个高性能采样保持放大器和一个基准电压源。它采用多级差分流水线架构，内置输出纠错逻辑，在最高65 MSPS数据速率时可提供14位精度，并保证在整个工作温度范围内无失码。

`FEP-DAQ9248 采集模块 <https://www.uisrc.com/portal.php?mod=view&aid=331>`_

.. _AD9767:

AD9767
^^^^^^^^^^^^

``14bit`` ``125MSPS`` ``Dual-Channel`` ``75dBc`` ``LQFP48`` ``$21.70``

`AD9767芯片 <https://www.analog.com/cn/products/ad9767.html#product-overview>`_
`FEP-DAQ9767 <https://www.uisrc.com/portal.php?mod=view&aid=330>`_



.. _ADS4229:

ADS4229
^^^^^^^^^^^^

``12bit`` ``250MSPS`` ``Dual-Channel`` ``545mW`` ``VQFN64`` ``$36.30``

`ADS4229芯片 <https://www.ti.com.cn/product/cn/ADS4229#order-quality>`_

.. _MXT2088:

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

`MXT2088芯片 <http://www.mxtronics.com/n107/n124/n181/n184/c692/content.html>`_


.. _adc_hp:

High-Precision
~~~~~~~~~~~~~~~~~~

.. contents::
    :local:

.. hint::
    A/D器件的位数越高，分辨率越高，量化误差越小，能达到的精度越高，一般把8位及以下的A/D转换器称为低分辨率ADC，9~12位称为中分辨率ADC，13位以上为高分辨率，此处所指的超高精度特指24bit及以上。



.. list-table::
    :header-rows:  1

    * - Name
      - Type
      - Resolution
      - Power &Chan
      - INL
      - SNR
      - :ref:`package`
      - Price
    * - :ref:`LTC2508`
      - :ref:`sar_adc`
      - 32bit 1MSPS
      - 24mW x1
      - ±0.5ppm
      - 145dB
      - DFN24
      - $12.02
    * - :ref:`AD4630`
      - :ref:`sar_adc`
      - 24bit 2MSPS
      - 15mW x2
      - ±0.9ppm
      - 105.7dB
      - CSP-BGA64
      - $37.14

.. _AD4630:

AD4630
^^^^^^^^^^^^

``24-bit @2MSPS`` ``24mW`` ``SAR ADC`` ``Dual Channel`` ``CSP-BGA64`` ``$37.14``

* 积分非线性：从 −40°C to +125°C，最大值为 ±0.9 ppm
* SNR：105.7 dB（典型值）
* 总谐波失真：−127 dB（典型值）
* NSD−166 dBFS/Hz （典型值）
* 2 MSPS 时每通道 15 mW
* 直流输入的极低 0.6 μA 输入电流
* 宽输入共模电压范围：−(1/128) × VREF 至 +(129/128) × VREF
* 灵活的外部基准电压源范围：4.096 V 至 5 V


`AD4630芯片 <https://www.analog.com/cn/products/ad4630-24.html#product-overview>`_

.. _AD7768:

AD7768
^^^^^^^^^^^^

``24-bit @1MSPS`` ``24mW`` ``Sigma-Delta`` ``26.4mW`` ``LFCSP-28`` ``$7.5``

AD7768-1是一款低功率、高性能 Σ-Δ 模数转换器 (ADC) ，其具有一个 Σ-Δ 调制器和数字滤波器，可实现AC 和 DC 信号的精确转换。AD7768-1 是 AD7768 的单通道版本，后者是一款 8 通道同步采样 Σ-Δ ADC。

* 温度范围：−40°C 至 +125°C
* 108.5 dB 动态范围
* −120 dB THD
* NSD−166 dBFS/Hz （典型值）
* ±1.1 ppm FSR INL，±30 µV 偏置误差，±30 ppm FSR 增益误差


`AD7768芯片 <https://www.analog.com/cn/products/ad7768-1.html#product-overview>`_

.. _LTC2508:

LTC2508
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

.. _LTC2201:

LTC2201
^^^^^^^^^^^^
``16-bit 20MSPS`` ``SAR ADC`` ``211mW`` ``QFN48``

* 81.6dB SNR and 100dB SFDRR (2.5V Range)


`LTC2201 datasheet <https://www.analog.com/media/en/technical-documentation/data-sheets/2201f.pdf>`_

.. _LTC2188:

LTC2188
^^^^^^^^^^^^
``16-bit 20MSPS`` ``SAR ADC`` ``Dual Channel`` ``76mW`` ``QFN64``

* 77dB SNR
* 90dB SFDR

`LTC2188 datasheet <https://www.analog.com/media/en/technical-documentation/data-sheets/2188f.pdf>`_


实现方式
------------

.. contents::
    :local:
    :depth: 1


.. _sar_adc:

SAR
~~~~~~~~~~~~~~

逐次逼近式模拟数字转换器SAR(Successive Approximation Register)，在每一次转换过程中，通过遍历所有的量化值并将其转化为模拟值，将输入信号与其逐一比较，最终得到要输出的数字信号。

逐次逼近模数转换器是采样速率低于5Msps的中高分辨率ADC应用的常见结构，SAR式ADC的分辨率一般为8-16位。具有低功耗，小尺寸等特点。

.. _pipeline:

Pipeline
~~~~~~~~~~~~~~

pipeline 更适合高速中等精度的，如 100M 14bit 以上的应用。

100MHz Conversion Rate 12-bit , :ref:`sar_adc` 就要1.4GHz的Clock，而 Pipelined ADC 只需100MHz的 Clock

随着工艺的进步，:ref:`sar_adc` 和 :ref:`sigma_delta` 的速度也上来 ，Pipeline 正在全面被SAR取代，除了12bit以上且大于200MSPS


.. _sigma_delta:

Sigma-Delta
~~~~~~~~~~~~~~

.. warning::
    :ref:`sigma_delta` 以时间上换极高的精度的特性，采样率都很低，但在精度达到20位以上的场合，实现了其他类型的ADC无法达到的高精度和低功耗。


应用方式
------------

.. contents::
    :local:
    :depth: 1

通信接口
~~~~~~~~~~~~

LVDS
^^^^^^^^^^^^


典型案例
~~~~~~~~~~~~

.. contents::
    :local:
    :depth: 1

.. _ADCNN:

ADCNN
^^^^^^^^^^^^

``ADC`` ``CNN`` ``MCU``

`ADCNN资源仓库 <https://github.com/tfmcu/ADCNN>`_

通过深度学习算法模型方式，直接处理ADC原始数据，实现电信号事件响应。


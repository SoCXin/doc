
.. _adc:

AD/DA
============

.. contents::
    :local:

A/D转换
------------

高速率
~~~~~~~~~~~~

参考器件
^^^^^^^^^^^^

* TI-ADS127L11 ($5.7, 400KSPS、24bit、18.6mW、120dB SNR、Δ-Σ)
* ADI-ADAQ4001 ($20.95, 16bit、2 MSPS)
* Maxim-MAX11214 ($39.18, 24bit、5mW、140dB SNR、32ksps Δ-Σ ADC，PGA)


DAQ板卡
^^^^^^^^^^^^

`米联客 <https://www.uisrc.com/portal.php>`_ 数据采集卡

* DAQ9481(250MSPS)

AD9481 是一款8位单芯片模数转换器（ADC），专门针对高速和低功耗进行了优化。转换速率为250 MSaps，模拟输入范围1Vpp，积分非线性±0.26LSB（典型值），差分非线性±0.35LSB（典型值），在整个工作范围内都具有出色的线性度和动态性能，最高速率下功耗小于450mW。


* DAQ4225(125MSPS)


相关具体参数规格比较

* ADS4225: Dual-Channel, 12-Bit, 125-MSPS Analog-to-Digital Converter
* ADS4229: Dual-Channel, 12-Bit, 250-MSPS Analog-to-Digital Converter

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
      - 12Bit
      - DDR LVDS
      - 545mW
      - Pipeline
      - VQFN64



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

高精度
~~~~~~~~~~~~~~

.. _sar:

SAR
^^^^^^^^^^^^^

逐次逼近式模拟数字转换器SAR(Successive Approximation Register)，在每一次转换过程中，通过遍历所有的量化值并将其转化为模拟值，将输入信号与其逐一比较，最终得到要输出的数字信号。

逐次逼近模数转换器是采样速率低于5Msps的中高分辨率ADC应用的常见结构，SAR式ADC的分辨率一般为8-16位。具有低功耗，小尺寸等特点。

.. _pipeline:

Pipeline
^^^^^^^^^^^^^

pipeline 更适合高速中等精度的，如 100M 14bit 以上的应用。

 100MHz Conversion Rate 12-bit , :ref:`sar` 就要1.4GHz的Clock，而 Pipelined ADC 只需100MHz的 Clock

随着工艺的进步，:ref:`sar` 和 :ref:`sigma_delta` 的速度也上来 ，Pipeline 正在全面被SAR取代，除了12bit以上且大于200MSPS


.. _sigma_delta:

Sigma-Delta
^^^^^^^^^^^^^

.. toctree::
    :maxdepth: 1

    SWM181 <../M/SWM181>
    ZML165 <../M/ZML165>
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
    * - :ref:`cs32a039`
      - 48 MHz
      - 4 KB
      - 64 KB
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - LQFP64
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


.. _dac:

D/A转换
-----------

.. contents::
    :local:

高速率
~~~~~~~~~~~~

参考器件
^^^^^^^^^^^^

* AD9751(300 MSPS)


高精度
~~~~~~~~~~~~

参考器件
^^^^^^^^^^^^

* AD9751(300 MSPS)


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
      -




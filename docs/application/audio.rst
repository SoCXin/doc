
.. _audio:

Audio
============

.. contents::
    :local:
    :depth: 1

ADC
-----------

Audio ADC相较于普通的ADC器件更注重AC信号，DC信号不准，具有相对固定的频率，都是 :ref:`sigma_delta` 型，本质上是1-bit ADC，有较高的分辨率，高分辨率是依靠滤波器滤去噪声后获得，有很大的噪声。

Audio ADC只关心音频频段，其滤波器响应就是按这个频段优化设计的，对于直流和很低的低频就要差些。而在采样直流信号时sigma-delta恰恰会产生低频杂散（idle tone)。

Audio ADC的采集频率较低，对直流采集有偏差，一般不标明非线性误差的。但是有滤波器，价格比较便宜。


TLV320ADC6140
~~~~~~~~~~~~~~~~~
``120dB`` ``动态范围增强器DRE``

DRE整体是一套闭环控制的过程，采样的信号经过DRE分析后由可变增益放大器转化，当信号较小时，相关信号也将反馈于前级电子增益进行调整。


.. _es7210:

ES7210
~~~~~~~~~~~~
``24-bit`` ``102dB`` ``4 Channel`` ``400 kbps`` ``QFN32`` ``￥4.0``

`Everest-semi <http://www.everest-semi.com/cn_products.php>`_


DAC
-----------
``Audio CODEC``

.. _es8311:

ES8311
~~~~~~~~~~~~

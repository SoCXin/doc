
.. _st_lowend:

Lowend
===============

.. contents::
    :local:

.. toctree::
    :maxdepth: 1

    STM32F030 <STM32F030>
    STM32F051 <STM32F051>
    STM32G030 <STM32G030>
    STM32G031 <STM32G031>

.. _st_f0vsg0:

Xin对比
--------------------

STM32F0系列
~~~~~~~~~~~~~~~~~~~~

基于 :ref:`cortex_m0` 内核，传承了STM32系列特性，适合成本敏感型应用，在传统8位和16位市场极具竞争力，并且无需管理不同的架构和相关的开发成本。


.. image:: ./images/STM32F0_series.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32f0-series.html


STM32G0系列
~~~~~~~~~~~~~~~~~~~~

基于 :ref:`cortex_m0` 内核，传承了STM32系列特性，适合成本敏感型应用

.. image:: ./images/STM32G0_series.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32g0-series.html


STM32G0系列达到了59 DMIPS，在针对内存的评分上CoreMark测试成绩>142分，G0的运行模式功耗低于100μA/ MHz，并提供多种低功耗模式，包括SLEEP模式、STOP模式、STANDBY、SHUTDOWN、VBAT模式。

在G0的设计上，ST保留了F0的所有优点，同时在F0的基础上作了进一步的优化和升级，为提高性能、速度和精度，外围设备也进行了升级改进。G0集成了很多定时器，在STM32G0中PWM的分辨率可以达到8ns，G0工作温度可以达到从-40度至+125度，另外I/0设计得更稳健，可以更好地抵御外部注入的电流。

G0配备的高速的时钟可以在0-90度达到1%的精度，在-40到125度可以达到2%的精度。


升级对比
~~~~~~~~~~~~~~~~~~~~

核心更新
^^^^^^^^^^^^

.. image:: ./images/F0VSG0_Core.png
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32g0x1.html

存储更新
^^^^^^^^^^^^

.. image:: ./images/F0VSG0_FLASH.png
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32g0x1.html

ADC更新
^^^^^^^^^^^^

.. image:: ./images/F0VSG0_ADC.png
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32g0x1.html


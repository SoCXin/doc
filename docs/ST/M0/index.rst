
.. _st_cortex_m0:

ST Cortex-M0
======================


.. contents::
    :local:

.. _st_stm32f0:

STM32F0系列
--------------------

.. toctree::
    :maxdepth: 1

    STM32F030
    STM32F051


.. _st_stm32g0:

STM32G0系列
--------------------

G0系列达到了59DMIPS，在针对内存的评分上CoreMark测试成绩>142分，G0的运行模式功耗低于100μA/ MHz，并提供多种低功耗模式，包括SLEEP模式、STOP模式、STANDBY、SHUTDOWN、VBAT模式。

在G0的设计上，ST保留了F0的所有优点，同时在F0的基础上作了进一步的优化和升级，为提高性能、速度和精度，外围设备也进行了升级改进。G0集成了很多定时器，在STM32G0中PWM的分辨率可以达到8ns，G0工作温度可以达到从-40度至+125度，另外I/0设计得更稳健，可以更好地抵御外部注入的电流。

G0配备的高速的时钟可以在0-90度达到1%的精度，在-40到125度可以达到2%的精度。

.. toctree::
    :maxdepth: 1

    STM32G030
    STM32G031
    G0 vs F0 <F0VSG0>

.. _st_stm32l0:

STM32L0系列
--------------------

.. toctree::
    :maxdepth: 1

    STM32L011

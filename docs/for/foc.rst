
.. _foc:

FOC
============

.. contents::
    :local:

技术简介
-----------

FOC（field-oriented control）为磁场导向控制，又称为矢量控制（vectorcontrol），是一种利用变频器（VFD）控制三相交流马达的技术，利用调整变频器的输出频率、输出电压的大小及角度，来控制马达的输出。其特性是可以个别控制马达的的磁场及转矩，类似他激式直流马达的特性。由于处理时会将三相输出电流及电压以矢量来表示，因此称为矢量控制。是目前无刷直流电机（BLDC）和永磁同步电机（PMSM）高效控制的最佳选择。FOC精确地控制磁场大小与方向，使得电机转矩平稳、噪声小、效率高，并且具有高速的动态响应。

FOC按照电机有无传感器来区分可以分为有传感器FOC和无传感器FOC。

对于有传感器FOC，由于电机的传感器（一般为编码器）能反馈电机转子的位置信息，因此在控制中可以不使用位置估算算法，控制起来相对无传感器FOC简单，但是对带传感器的电机应用来说，往往对控制性能要求较高。

对于无传感器FOC，由于电机不带任何传感器，因此不能通过简单读取传感器的测量值来得到电机转子的位置信息，所以在控制中需要通过采集电机相电流，使用位置估算算法来计算转子位置。虽然无感FOC的控制难度较大，但是它可以避免传感器故障的风险，并且省去了传感器的成本，同时简化了电机与驱动板间的布线。目前，无感FOC多应用在风机类的场合中。



.. _simplefoc:

SimpleFOC
~~~~~~~~~~~

`GitHub <https://GitHub.com/simplefoc>`_ |
`Website <https://docs.simplefoc.com//>`_

.. list-table::
    :header-rows:  1

    * - MCU
      - 2 PWM
      - 4 PWM
      - 3 PWM
      - 6 PWM
      - PWM Freq
      - Package
    * - :ref:`esp32`
      - √
      - √
      - √
      - √
      - √
      -
    * - :ref:`rp2040`
      - √
      - √
      - √
      - √
      - √
      -
    * - :ref:`stm32h747`
      - √
      - √
      - √
      - X
      - √
      -
    * - :ref:`stm32g431`
      - √
      - √
      - √
      - √
      - √
      -
    * - :ref:`stm32f103`
      - √
      - √
      - √
      - √
      - √
      -



嵌入平台
-----------
.. toctree::
    :maxdepth: 1

    HC32M120 <../M/HC32M120>
    MM32SPIN <../M/MM32SPIN>
    SWM181 <../M/SWM181>
    N32G452 <../M/N32G452>

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - mTIM
      - PWM
      - More
      - Package
    * - :ref:`stm32g474`
      - 170MHz
      - 128KB
      - 128/256/512KB
      - 3
      - 12
      - :ref:`stm32_hrtim`
      - LQFP64


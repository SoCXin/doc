.. _foc:

FOC
============

.. contents::
    :local:
    :depth: 1


技术简介
-----------

FOC（field-oriented control）为磁场导向控制，又称为矢量控制（vectorcontrol），是一种利用变频器（VFD）控制三相交流马达的技术，利用调整变频器的输出频率、输出电压的大小及角度，来控制马达的输出。其特性是可以个别控制马达的的磁场及转矩，类似他激式直流马达的特性。由于处理时会将三相输出电流及电压以矢量来表示，因此称为矢量控制。是目前无刷直流电机（BLDC）和永磁同步电机（PMSM）高效控制的最佳选择。FOC精确地控制磁场大小与方向，使得电机转矩平稳、噪声小、效率高，并且具有高速的动态响应。

FOC按照电机有无传感器来区分可以分为有传感器FOC和无传感器FOC。

对于有传感器FOC，由于电机的传感器（一般为编码器）能反馈电机转子的位置信息，因此在控制中可以不使用位置估算算法，控制起来相对无传感器FOC简单，但是对带传感器的电机应用来说，往往对控制性能要求较高。

对于无传感器FOC，由于电机不带任何传感器，因此不能通过简单读取传感器的测量值来得到电机转子的位置信息，所以在控制中需要通过采集电机相电流，使用位置估算算法来计算转子位置。虽然无感FOC的控制难度较大，但是它可以避免传感器故障的风险，并且省去了传感器的成本，同时简化了电机与驱动板间的布线。目前，无感FOC多应用在风机类的场合中。

* 1. FOC则完全没有转速的限制，不论在什么转速下都可以实现精确的控制。
* 2. FOC的换向性能极其优秀，最高转速下正反转切换可以非常顺畅。
* 3. FOC还可以以能量回收的形式进行刹车控制。
* 4. FOC可以实现力矩、速度、位置三个闭环控制。
* 5. FOC驱动器的噪音会比电调小很多，效率也比电调高很多。


.. _pwm:

PWM
~~~~~~~~~~~

PWM(Pulse Width Modulation)脉冲宽度调制: 从调制脉冲的极性看，PWM又可分为单极性与双极性控制模式两种。

过调节占空比的变化来调节信号、能量等的变化，占空比就是指在一个周期内，信号处于高电平的时间占据整个信号周期的百分比，例如方波的占空比就是50%.


* PCM(Pulse Code Modulation)，脉冲编码调制，以约定好的二进制码流传递信息，可以时分复用；
* PPM(Pulse Position Modulation)，脉冲位置调制，以不同时刻出现的脉冲位置传递信息，可以时分复用
* PDM(Pulse Distance Modulation)，脉冲间隔调制，脉冲宽度不变，都是560us，通过改变脉冲间隔实现调制

.. _pcm:

PCM
^^^^^^^^^^^

I2S是PCM的一个分支，采样频率一般为44.1KHZ和48KHZ做，PCM采样频率一般为8K,16K。有四组信号:位时钟信号，同步信号，数据输入，数据输出。


PPM/PDM
^^^^^^^^^^^

红外遥控发射采用PPM/PDM编码方式，遥控编码脉冲由前导码、16 位用户码（8 位用户码、8 位用户码的反码）和 16 位操作码（8 位操作码、8 位操作码的反码）组成。

* 前导码的作用：前导码是一个遥控码的起始部分，由一个 9ms 的高电平 (起始码)  和一个 4.5ms 的低电平 (结果码) 组成。
* 用户码的作用：16 位用户码（8 位用户码、8 位用户码的反码），通过对用户码的检验，每个遥控器只能控制一个设备动作，这样可以有效地防止多个设备之间的干扰。编码后面还要有编码的反码，用来检验编码接收的正确性，防止误操作，增强系统的可靠性。
* 位0和1的表示：0和1均以0.56ms的高电平开始(实测500us)，不同的是后面出现的低电平，如果低电平是0.56ms，则表示0，如果低电平是1.68ms(0.56*3=1.68)则表示1。



解决方案
-----------

.. list-table::
    :header-rows:  1

    * - Solution
      - MCU
      - Driver
      - PID(Max)
      - Power
      - Price
    * - :ref:`simplefoc`
      - :ref:`mega328p`
      - L6234
      - 830Hz
      - 120W
      - ¥100
    * - :ref:`minifoc`
      - :ref:`gd32f130`
      - EG2133
      - 30kHz
      - 90W
      - ¥30
    * - :ref:`ODrive`
      - :ref:`stm32f405`
      - DRV8301
      - 8kHz
      - 960W
      - ¥300

.. _vesc:

VESC
~~~~~~~~~~~

* `VESC Home <https://vesc-project.com/>`_ , `VESC GitHub <https://github.com/vedderb/bldc>`_

An open source motor controller firmware, the source code for the VESC DC/BLDC/FOC controller.



.. _simplefoc:

SimpleFOC
~~~~~~~~~~~

* `SimpleFOC Home <https://www.simplefoc.com>`_ , `SimpleFOC Docs <https://docs.simplefoc.com>`_ , `SimpleFOC GitHub <https://GitHub.com/simplefoc>`_

.. list-table::
    :header-rows:  1

    * - MCU
      - 2 PWM
      - 4 PWM
      - 3 PWM
      - 6 PWM
      - PWM Freq
      - :ref:`package`
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


.. _minifoc:

MiniFOC
~~~~~~~~~~~

* 链接：`MiniFOC GitHub <https://github.com/ZhuYanzhen1/miniFOC>`_



.. _ODrive:

ODrive
~~~~~~~~~~~

* 链接：`ODrive Home <https://odriverobotics.com/>`_ , `ODrive GitHub <https://github.com/odriverobotics/ODrive>`_


相关主控
~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    HC32M120 <../miscellaneous/HC32M120>
    N32G452 <../miscellaneous/N32G452>

.. list-table::
    :header-rows:  1

    * - :ref:`vendor`
      - :ref:`architecture`
      - RAM
      - Flash
      - mTIM
      - PWM
      - More
      - :ref:`package`
    * - :ref:`stm32g474`
      - 170MHz
      - 128KB
      - 128/256/512KB
      - 3
      - 12
      - :ref:`stm32_hrtim`
      - :ref:`LQFP64`


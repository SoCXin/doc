
.. _st:

STMicroelectronics
======================

``MCU``

.. contents::
    :local:

公司简介
-----------

作为MCU领域的龙头企业，特别是最为广泛使用的一种技术范式，拥有庞大的开发团队和资源，如果你想找一颗满足需求的MCU，那么第一步就是去ST找一找。

.. note::
    意法半导体ST是全球最大的半导体公司之一，是MCU领域的王者，其产品系列丰富，应用广泛。

技术特征
-----------

产品分类
-----------

.. toctree::
    :maxdepth: 1

    低阶产品  <L/index>
    主流产品  <M/index>

.. list-table::
    :header-rows:  1

    * - 分类
      - 核心
      - 内存
      - 封装
      - 性能
      - 定价
      - 上限
      - 下限
    * - 低阶产品
      -
      -
      -
      -
      -
      -
      -
    * - 主流产品
      -
      -
      -
      -
      -
      -
      -
    * - 高阶产品
      -
      -
      -
      -
      -
      -
      -

性能担当
~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    超值低功耗 STM32H7B0 <H/STM32H7B0>
    超值大内存 STM32H750 <H/STM32H750>
    高频低功耗 STM32H730 <H/STM32H730>
    双核MCU: STM32H745 <H/STM32H745>
    异构MPU: STM32MP15 <H/STM32MP15>

.. list-table::
    :header-rows:  1

    * - Rank
      - Core
      - RAM
      - Flash
      - UART
      - BLE
      - USB
      - DMIPS
    * - :ref:`stm32h730`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32h750`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32h7b0`
      -
      -
      -
      -
      -
      -
      -

无线通信
~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    BLE SoC: STM32WB55 <M/STM32WB55>
    LoRa SoC: STM32WLE5 <M/STM32WLE5>

.. _stm32ulp:

超低功耗
~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    STM32L011 <L/STM32L011>
    STM32L412 <M/STM32L412>

.. image:: images/stm32ulp.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32-ultra-low-power-mcus.html

ULPMark
^^^^^^^^^^^

ULPMark 测试目前有三个部分，分别是 ULPMark-CoreProfile、ULPMark-PeripheralProfile 和 ULPMark-CoreMark。

* ULPMark-CoreProfile 核心在深度睡眠模式下真正的能量消耗
* ULPMark-PeripheralProfile 普通外围设备的能量对深度睡眠的影响
* ULPMark-CoreMark 活跃功耗，使用 CoreMark 作为工作负载

.. _ulp_cp:

ULPMark-CP
^^^^^^^^^^^

ULPMark-CoreProfile 在深度睡眠下整个芯片的能量消耗；因为在低功耗的应用场景下，该芯片设备可能是单电池供电，需要运行长达 10 年的时间，所以芯片设备绝大部分时间应该都是处在深度睡眠的模式，偶尔唤醒处理部分任务。

.. _ulp_pp:

ULPMark-PP
^^^^^^^^^^^

ULPMark-PeripheralProfile

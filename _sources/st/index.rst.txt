
.. _st:

ST
======================

``MCU`` ``STM32`` ``MPU`` ``MEMS``

公司简介
-----------

意法半导体是全球最大的半导体公司之一，MCU领域的王者，其产品拥有庞大的工程师群众基础和开发资源。


.. list-table::
    :header-rows:  1

    * - 分类
      - 性能范围
      - 内存配置
      - 封装规格
      - 定价范围
      - 核心特点
    * - :ref:`st_lowcost`
      -
      -
      -
      -
      -
    * - :ref:`st_main`
      -
      -
      -
      -
      -
    * - :ref:`st_high`
      -
      -
      -
      -
      -
    * - :ref:`st_iot`
      -
      -
      -
      -
      -
    * - :ref:`st_ulp`
      -
      -
      -
      -
      -


.. toctree::
    :maxdepth: 1

    普惠产品  <s/index>
    主流产品  <m/index>


.. _st_high:

性能产品
-----------

.. list-table::
    :header-rows:  1

    * - :ref:`st_high`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`level`
      - SRAM
      - Interface
      - Price
      - Package
    * - :ref:`stm32h745`
      - :ref:`cortex_m7`
      - 3224
      - :ref:`level5`
      -
      -
      -
      -
    * - :ref:`stm32h730`
      - :ref:`cortex_m7`
      - 2778
      - :ref:`level5`
      -
      -
      -
      -
    * - :ref:`stm32h750`
      - :ref:`cortex_m7`
      - 2424
      - :ref:`level5`
      -
      -
      -
      -
    * - :ref:`stm32h7b0`
      - :ref:`cortex_m7`
      - 1414
      - :ref:`level4`
      -
      -
      -
      -

.. image:: ./t/images/STM32H7.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32h7-series.html

.. toctree::
    :maxdepth: 1

    超值低功耗 STM32H7B0 <t/STM32H7B0>
    超值大内存 STM32H750 <t/STM32H750>
    高频低功耗 STM32H730 <t/STM32H730>
    双核MCU: STM32H745 <t/STM32H745>
    异构MPU: STM32MP15 <t/STM32MP15>

.. _st_iot:

无线通信
-----------

.. image:: ./m/images/stm32wb_series.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32wb-series.html
.. image:: ./m/images/STM32WL_series.jpg
    :target: https://www.st.com/content/st_com/zh/products/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus/stm32-wireless-mcus/stm32wl-series.html

.. toctree::
    :maxdepth: 1

    BLE: STM32WB55 <m/STM32WB55>
    LoRa: STM32WLE5 <m/STM32WLE5>


.. _st_ulp:

超低功耗
-----------

.. image:: m/images/stm32ulp.jpg
    :target: https://www.st.com/zh/microcontrollers-microprocessors/stm32-ultra-low-power-mcus.html

.. toctree::
    :maxdepth: 1

    STM32L011 <s/STM32L011>
    STM32L412 <m/STM32L412>
    STM32U575 <m/STM32U575>

.. list-table::
    :header-rows:  1

    * - :ref:`ulp`
      - :ref:`architecture`
      - 
      - SRAM
      - 
      - 
      - 
      - 
    * - :ref:`stm32l011`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32l412`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32u575`
      -
      -
      -
      -
      -
      -
      -


技术特点
-----------

.. _stm32_adc:

ADC
~~~~~~~~~~~

.. _stm32_dac:

DAC
~~~~~~~~~~~

DSP
~~~~~~~~~~~

.. _stm32_fmac:

FMAC
~~~~~~~~~~~

Filter mathematical accelerator

* 16 x 16-bit multiplier
* 24+2-bit accumulator with addition and subtraction
* 16-bit input and output data
* 256 x 16-bit local memory
* Up to three areas can be defined in memory for data buffers (two input, one output),defined by programmable base address pointers and associated size registers
* Input and output sample buffers can be circular
* Buffer “watermark” feature reduces overhead in interrupt mode
* Filter functions: FIR, IIR (direct form 1)
* AHB slave interface
* DMA read and write data channels


GUI
~~~~~~~~~~~

.. _stm32_dma2d:

DMA2D
^^^^^^^^^^^

DMA2D首先是一个DMA，DMA能做的内存操作DMA2D肯定是不成问题，其次DMA2D有自己独有的颜色填充（也叫寄存器到存储器）、颜色格式转换、透明度混合（层混合）

* 颜色填充（矩形区域）（寄存器到存储器）
* 图像（内存）复制（存储器到存储器）
* 颜色格式转换（如YCbCr转RGB或RGB888转RGB565）
* 透明度混合（Alpha Blend）


.. _stm32_art:

ART
^^^^^^^^^^^

.. _hdmi_cec:

HDMI CEC
^^^^^^^^^^^

CEC协议是一个单总线，低速协议传输速度只有0.3Kbps。它使用HDMI线缆的第13号引脚。

.. image:: t/images/cec.jpg

CEC使用类似DS18B20的单总线协议，分为数据位和起始位，每个数据位有严格的时序定义，其中数据位时长为2.4ms，起始位时长为4.7ms。由于CEC总线传输速率很低，总线协议又不是很复杂，非常适合MCU来处理。一个完整的CEC数据帧

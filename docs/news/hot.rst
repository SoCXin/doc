
.. _hot:

热度Xin榜
==============

.. note::
    收录当下被各个芯片厂商力推或被广泛使用的产品，这些产品往往具有很大的潜力或为现象级产品。

.. contents::
    :local:

生态范式
-------------

不同的厂商市场策略不同，其中包括凭借开源社区崛起，拥抱和践行开源策略的芯片制造商，这些产品被Geek广泛尝试，拥有很多开源的软硬件方案，十分利于敏捷开发和原型搭建。

.. toctree::
    :maxdepth: 1

    RP2040 <../M/RP2040>
    GD32V103 <../M/GD32V103>

.. contents::
    :local:

语言
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - C++
      - :ref:`arduino`
      - :ref:`lua`
      - mPy
      - :ref:`rust`
      - xGo
      - Assembly
    * - :ref:`esp32`
      - √
      - √
      - √
      - √
      - √
      - X
      - √
    * - :ref:`rp2040`
      - √
      - √
      - X
      - √
      - √
      - X
      - X
    * - :ref:`stm32f103`
      - √
      - √
      - √
      - √
      - √
      - √
      - √

.. _lua:

Lua
^^^^^^^^^^^^

.. _rust:

Rust
^^^^^^^^^^^^

.. _arduino:

Arduino
^^^^^^^^^^^^^^



框架
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - :ref:`platformio`
      - freeRTOS
      - Zephyr
      - RT-Thread
      - :ref:`arduino`
      - :ref:`cmsis`
      - :ref:`mbed`
    * - :ref:`esp32`
      - √
      - √
      - √
      - √
      - √
      - X
      - X
    * - :ref:`rp2040`
      - √
      - √
      - √
      - √
      - √
      - √
      - X
    * - :ref:`stm32f103`
      - √
      - √
      - √
      - √
      - √
      - √
      - √

.. _cmsis:

CMSIS
^^^^^^^^^^^^

.. _mbed:

mbed
^^^^^^^^^^^^

.. _platformio:

PlatformIO
^^^^^^^^^^^^^^


硬件范式
-------------

.. contents::
    :local:

STM大法
~~~~~~~~~~~~~

.. note::
    :ref:`st` 作为嵌入式MCU领域的泰山北斗，其经典产品一直是被模仿的对象，很多厂商通过复刻和学习这些范式获得生存和超越。

.. contents::
    :local:

.. _ref030:

STM32F030范式
^^^^^^^^^^^^^^

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - UART/SPI/I2C
      - GPIO
      - SPEC
    * - :ref:`stm32f030`
      - 48 MHz
      - 4/8 KB
      - 16/32/64 KB
      - 1/1/1
      - 20/32/48/64
      - I2C
    * - :ref:`stm32g030`
      - 64 MHz
      - 8 KB
      - 32/64 KB
      - 2/2/2
      - 8/20/32/48
      - I2S
    * - :ref:`at32f421`
      - 120 MHz
      - 8 KB
      - 64 KB
      - 2
      - 16
      - I2C

.. _ref103:

STM32F103范式
^^^^^^^^^^^^^^

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
    * - :ref:`stm32f103`
      - 72 MHz
      - 20 KB
      - 64 KB
      - 2
      - 40
      - USB
      -
    * - :ref:`ch32f103`
      - 72 MHz
      - 16 KB
      - 64 KB
      - 2
      - 40
      - USB
      -
    * - :ref:`gd32v103`
      - 108 MHz
      - 16 KB
      - 64 KB
      - 2
      - 40
      - USB
      -

.. _ref407:

STM32F407范式
^^^^^^^^^^^^^^

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - DAC
      - CON
      - SPEC
      - Package
    * - :ref:`stm32f407`
      - 168 MHz
      - 64 KB
      - 256 KB
      - 2
      - 15
      -
      -
    * - :ref:`stm32f207`
      - 120 MHz
      - 64 KB
      - 256 KB
      -
      -
      -
      -
    * - :ref:`at32f407`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`hc32f460`
      -
      -
      -
      -
      -
      -
      -


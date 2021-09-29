
.. _hot:

热度Xin榜
==============

.. note::
    收录当下被各个芯片厂商力推或被应用厂商广泛使用的产品，这些产品往往具有很大的潜力成为一个时期的霸主。

.. contents::
    :local:

开源拥趸
-------------

不同的厂商市场策略不同，其中包括凭借开源社区崛起，拥抱和践行开源策略的芯片制造商，这些产品被Geek广泛尝试，拥有很多开源的软硬件方案，十分利于敏捷开发和原型搭建。

.. contents::
    :local:

编程语言
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Xin
      - RAM
      - C++
      - Arduino
      - Lua
      - mPy
      - Rust
      - xGo
      - Assembly
    * - :ref:`esp32`
      - 520 KB
      - Y
      - Y
      - Y
      - Y
      - Y
      - N
      - Y
    * - :ref:`rp2040`
      - 264 KB
      - Y
      - Y
      - N
      - Y
      - Y
      - N
      - N

框架支持
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Xin
      - PlatformIO
      - freeRTOS
      - Zephyr
      - RT-Thread
      - Arduino
      - mbed
    * - :ref:`rp2040`
      - Y
      - Y
      - Y
      - Y
      - Y
      - Y
    * - :ref:`esp32`
      - Y
      - Y
      - Y
      - Y
      - Y
      - N

.. toctree::
    :maxdepth: 1

    RP2040 <../M/RP2040>
    GD32V103 <../M/GD32V103>

国货之光
-------------

主要介绍国产芯片中比较典型的产品，包括在竞品之上增强或丰富功能，不断超越前者定义产品和不断拉低价格实现更高性价比的产品。

.. contents::
    :local:

标准拉高
~~~~~~~~~~~~~

.. note::
    所谓标准拉高，不仅仅是在技术指标上有所突破，包括更丰富的资源组合，以满足更细分更极致的应用场景，例如高集成度小封装的产品可以用在空间受限制的场合。

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - Special
      - Package
    * - :ref:`ch579`
      - 40MHz
      - 1K
      - 8K
      - 2
      - 18
      - 10M-PHY
      - QFN28/48

价格拉低
~~~~~~~~~~~~~

.. note::
    所谓价格拉低，并不是通过精简配置实现，是需要通过技术迭代和市场决策实现综合性价比更优，例如各种成熟技术的跨领域和降维打击。

.. list-table::
    :header-rows:  1

    * - Name
      - MAX
      - MIN
      - BIG
      - TINY
      - MORE
      - SPEC
      - Package
    * - :ref:`at32f421`
      - 120 MHz
      - ￥3
      - 64K
      - 4x4mm
      - ERTC
      - sLib
      - 20/32/48

经典范式
-------------

ST大法
~~~~~~~~~~~~~

.. note::
    :ref:`st` 作为嵌入式MCU领域的泰山北斗，其经典产品一直是被模仿的对象，很多厂商通过复刻和学习这些范式获得生存和超越。

.. contents::
    :local:

F030范式
^^^^^^^^^^^^^^

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - SPEC
      - Package
    * - :ref:`stm32f030`
      - 48MHz
      - 8K
      - 64K
      - 2
      - 16
      - I2C
      - LQFP32

F103范式
^^^^^^^^^^^^^^

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - SPEC
      - Package
    * - :ref:`stm32f103`
      - 72 MHz
      - 20K
      - 64K
      - 2
      - 40
      - USB
      - LQFP48


F407范式
^^^^^^^^^^^^^^

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - DAC
      - CON
      - SPEC
      - Package
    * - :ref:`stm32f407`
      - 168 MHz
      - 64K
      - 256K
      - 2
      - 15
      - USB/CAN
      - LQFP100

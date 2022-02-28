
.. _hot:

热度Xin
==============

.. note::
    收录当下被各个芯片厂商力推或被广泛使用的产品，这些产品往往具有很大的潜力或为现象级产品。

.. contents::
    :local:

软件生态
-------------

不同的厂商市场策略不同，其中包括凭借开源社区崛起，拥抱和践行开源策略的芯片制造商，这些产品被Geek广泛尝试，拥有很多开源的软硬件方案，十分利于敏捷开发和原型搭建。

.. toctree::
    :maxdepth: 1

    RP2040 <../M/RP2040>
    GD32V103 <../M/GD32V103>

.. contents::
    :local:

编程语言
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - C++
      - :ref:`arduino`
      - :ref:`lua`
      - :ref:`mpy`
      - :ref:`rust`
      - :ref:`xgo`
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

`Lua语言 <https://docs.os-q.com/lua>`_

.. toctree::
    :maxdepth: 1

    Air101 <../M/Air101>

.. _rust:

Rust
^^^^^^^^^^^^

`Rust语言 <https://docs.os-q.com/rust>`_

.. _mpy:

mPy
^^^^^^^^^^^^

`MicroPython语言 <https://docs.os-q.com/mpy>`_

.. _xgo:

xGo
^^^^^^^^^^^^


.. _arduino:

Arduino
^^^^^^^^^^^^^^

`Arduino语言 <https://docs.os-q.com/arduino>`_



框架支持
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - :ref:`pio`
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



.. _pio:

PlatformIO
^^^^^^^^^^^^^

.. _qio:

QIO
^^^^^^^^^^^^^

.. _mbed:

mbed
^^^^^^^^^^^^

.. _cmsis:

CMSIS
^^^^^^^^^^^^


硬件生态
-------------

.. contents::
    :local:

Arduino
~~~~~~~~~~~~~
.. toctree::
    :maxdepth: 1

    ATMEGA328P <../L/ATMEGA328P>



STM32范式
~~~~~~~~~~~~~

.. note::
    :ref:`st` 其经典产品一直是被模仿的对象。

.. contents::
    :local:

.. _ref030:

STM32F030范式
^^^^^^^^^^^^^^^^

该型范式定位入门级32位MCU，高性价比用于替换8/16位单片机，市场需求量大，开发需要更高效释放资源，选择和升级空间广泛

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Frequency
      - RAM+ROM
      - Price
      - UART/SPI/I2C
      - GPIO
    * - :ref:`stm32f030`
      - :ref:`cortex_m0`
      - 48 MHz
      - 4/8+16/32/64
      -
      - 1/1/1
      - 20/32/48/64
    * - :ref:`stm32g030`
      - :ref:`cortex_m0`
      - 64 MHz
      - 8+32/64
      -
      - 2/2/2
      - 8/20/32/48
    * - :ref:`at32f421`
      - :ref:`cortex_m4`
      - 120 MHz
      - 8/16+16/32/64
      - ￥6
      - 2/2/2
      - 20/28/32/48
    * - CKS32F030
      - :ref:`cortex_m0`
      - 48 MHz
      - 4/8+16/32/64
      -
      - 1/1/1
      - 20/32/48/64
    * - HK32F030
      - :ref:`cortex_m0`
      - 72 MHz
      - 4/8+16/32/64
      -
      - 1/1/1
      - 20/32/48/64
    * - :ref:`mm32f031`
      - :ref:`cortex_m0`
      - 72 MHz
      -
      -
      -
      -
    * - :ref:`gd32f130`
      - :ref:`cortex_m3`
      - 48 MHz
      - 4/8+16/32/64
      -
      - 1/1/1
      - 20/32/48/64
    * - GD32F330
      - :ref:`cortex_m3`
      - 84 MHz
      - 4/8+16/32/64
      -
      - 1/1/1
      - 20/32/48/64
    * - :ref:`gd32e230`
      - :ref:`cortex_m23`
      - 64 MHz
      - 4/8+16/32/64
      -
      - 1/1/1
      - 20/32/48/64



.. toctree::
    :maxdepth: 1

    GD32F130 <../L/GD32F130>
    GD32E230 <../L/GD32E230>
    MM32F031 <../L/MM32F031>

.. _ref103:

STM32F103范式
^^^^^^^^^^^^^^^^

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
^^^^^^^^^^^^^^^^

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


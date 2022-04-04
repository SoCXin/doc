
.. _hot:

热度Xin
==============


.. contents::
    :local:

不同的厂商市场策略不同，其中包括凭借开源社区崛起，拥抱和践行开源策略的芯片制造商，这些产品被Geek广泛尝试，拥有很多开源的软硬件方案，十分利于敏捷开发和原型搭建。



编程语言
-------------

.. list-table::
    :header-rows:  1

    * - :ref:`hot`
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
      - X
      - √
    * - :ref:`rp2040`
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

.. _lua:

Lua
~~~~~~~~~~~~~

`Lua编程语言 <https://docs.os-q.com/lua>`_ 嵌入式运行平台包括 :ref:`air101`

.. list-table::
    :header-rows:  1

    * - :ref:`lua`
      -
      -
      -
      -
      -
      -
    * - :ref:`air101`
      -
      -
      -
      -
      -
      -


.. toctree::
    :maxdepth: 1

    Air101 <../M/Air101>

.. _rust:

Rust
~~~~~~~~~~~~~
``rust``

`Rust编程语言 <https://docs.os-q.com/rust>`_ 适配的嵌入式平台包括 :ref:`esp32` 、:ref:`rp2040` 和 :ref:`stm32f103`

.. list-table::
    :header-rows:  1

    * - :ref:`rust`
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32f103`
      -
      -
      -
      -
      -
      -


.. _mpy:

mPy
~~~~~~~~~~~~~
``Python``

`MicroPython <https://docs.os-q.com/mpy>`_ 嵌入式运行平台包括 :ref:`esp32` 、:ref:`rp2040` 和 :ref:`stm32f405`

.. list-table::
    :header-rows:  1

    * - :ref:`mpy`
      -
      -
      -
      -
      -
      -
    * - :ref:`rp2040`
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32f405`
      -
      -
      -
      -
      -
      -
    * - :ref:`esp32`
      -
      -
      -
      -
      -
      -

.. _xgo:

xGo
~~~~~~~~~~~~~
``Go``

.. _arduino:

Arduino
~~~~~~~~~~~~~
``C++``


`Arduino简介 <https://docs.os-q.com/arduino>`_

编译体系
-------------

.. _pio:

PIO
~~~~~~~~~~~~~
``PlatformIO``


.. _qio:

QIO
~~~~~~~~~~~~~

.. _gcc:

GCC
~~~~~~~~~~~~~


开发框架
-------------


.. list-table::
    :header-rows:  1

    * - :ref:`hot`
      - :ref:`libopencm3`
      - freeRTOS
      - Zephyr
      - RT-Thread
      - :ref:`arduino`
      - :ref:`cmsis`
      - :ref:`mbed`
    * - :ref:`stm32f103`
      - √
      - √
      - √
      - √
      - √
      - √
      - √
    * - :ref:`esp32`
      - X
      - √
      - √
      - √
      - √
      - X
      - X
    * - :ref:`rp2040`
      - X
      - √
      - √
      - √
      - √
      - √
      - X






.. _mbed:

mbed
~~~~~~~~~~~~~

.. _cmsis:

CMSIS
~~~~~~~~~~~~~

.. _libopencm3:

libopencm3
~~~~~~~~~~~~~

The libopencm3 project aims to create an open-source firmware library for various ARM Cortex-M microcontrollers.

`libopencm3开源库 <https://github.com/libopencm3/libopencm3>`_


硬件生态
-------------

.. contents::
    :local:

Arduino
~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    ATMEGA328P <../L/ATMEGA328P>



STM32
~~~~~~~~~~~~~

.. note::
    :ref:`st` 其经典产品一直是被模仿的对象。

.. contents::
    :local:

.. _ref030:

F030范式
^^^^^^^^^^^^^^^^
``Cortex-M0``

该型范式定位入门级32位MCU，高性价比用于替换8/16位单片机，市场需求量大，开发需要更高效释放资源，选择和升级空间广泛

.. list-table::
    :header-rows:  1

    * - :ref:`vendor`
      - :ref:`architecture`
      - Freq
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


    MM32F031 <../L/MM32F031>

.. _ref103:

F103范式
^^^^^^^^^^^^^^^^
``Cortex-M3``

.. list-table::
    :header-rows:  1

    * - :ref:`vendor`
      - :ref:`architecture`
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

F407范式
^^^^^^^^^^^^^^^^
``Cortex-M4``

.. list-table::
    :header-rows:  1

    * - :ref:`vendor`
      - :ref:`architecture`
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


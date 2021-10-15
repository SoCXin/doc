
.. _low:

白菜Xin
=============

.. note::
    作者将MCU的官方价格分层为：{￥3,$1,$3}，该页收录主要是官方价格 ≤￥3 的产品，满足用户基本的UART/GPIO需求，主要用于用于离散的节点控制及通信

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Frequency
      - SRAM
      - Flash
      - UART/SPI/I2C
      - GPIO
      - Special
      - Price
    * - :ref:`stm32g030`
      - 64 MHz
      - 8 KB
      - 32/64 KB
      - 2/2/2
      - 8/20/32/48
      - RTC/I2S
      - $0.4~0.6
    * - :ref:`stm8s003`
      - 16 MHz
      - 1 KB
      - 8 KB
      - 1
      -
      -
      -
    * - :ref:`ch552`
      - 24 MHz
      - 1 KB
      - 16 KB
      - 2
      - 16
      - USB D
      - $0.2~0.3
    * - :ref:`ch573`
      - 20 MHz
      - 18 KB
      - 512 KB
      - 4
      -
      - USB H/D
      -
    * - :ref:`stc8`
      - 24 MHz
      - 1 KB
      - 8 KB
      - 2
      -
      -
      -



阶梯标准
-------------


白菜高阶
~~~~~~~~~~~~~

以 :ref:`stm32f030` , :ref:`stm32g030` 此类的入门级32位MCU为主，4KB及以上的SRAM资源

.. hint::
    基于 :ref:`stm32g030` 可以实现的方案可以媲美主流MCU，但在功能复杂度和潜力上天花板较低

白菜低阶
~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    STC8H <../L/STC8>

以8位MCU为主，对SRAM资源和主频要求不高


方案探索
-------------

Modbus RTU Slave
~~~~~~~~~~~~~~~~~~~~

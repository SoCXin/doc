.. _cortex_m7:

Cortex-M7
====================
``5 CoreMark/MHz`` ``TCM``

.. contents::
    :local:


简介
----------

架构上，M7具备六级、顺序、双发射超标量流水线，拥有单精度、双精度浮点单元、指令和数据缓存、分支预测、SIMD支持、紧耦合内存(TCM)。

性能最高的Cortex-M处理器, 简化信号处理，为大众带来高性能DSP

内置浮点处理功能可降低功耗

支持创新的MCU，可实现更密集的自动化任务


.. list-table::
    :header-rows:  1

    * - :ref:`vendor`
      - DMIPS
      - RAM
      - Cache
      - GPU
      - SPI
      - USB
      - Ethernet
      - Interface
    * - :ref:`stm32h730`
      - 1177
      - 564KB
      - 32+32
      - ART
      - 2 Octo
      - :ref:`stm32_otg_hs`
      - 100M
      - 35
    * - :ref:`stm32h750`
      - 1027
      - 1 MB
      - 16+16
      - ART
      - 2 Quad
      - :ref:`stm32_otg_hs`
      - 100M
      - 35
    * - :ref:`stm32h7b0`
      - 599
      - 1.4 MB
      - 16+16
      - ART/JPEG
      - 2 Quad
      - :ref:`stm32_otg_hs`
      - No
      - 35
    * - :ref:`rt1170`
      - 6468
      -
      -
      -
      -
      -
      -
      -





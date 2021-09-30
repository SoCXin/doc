
.. _sss:

独特Xin榜
====================

.. note::
    特色榜单收录非常具有创新性，或者非常具有创造性的产品

.. contents::
    :local:

.. _eth_phy:

Ethernet
-------------

ETH-PHY Full
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - USB
      - ETH-PHY
      - Package
    * - :ref:`ch563`
      - :ref:`arm7`
      - 64KB
      - 224KB
      - 480M
      - 100M
      - LQFP64M(10x10)
    * - W7500P
      - :ref:`cortex_m0`
      - 32KB
      - 128KB
      -
      - 10M
      - LQFP64(7x7)

.. hint::
    在封装内同时集成以太网MAC+PHY，集成以太网phy发热巨大影响芯片稳定性，特别是空间足够的情况下需要慎重考量。

ETH-PHY Tiny
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - USB
      - BLE
      - ETH-PHY
      - Package
    * - :ref:`ch32v208`
      - :ref:`wch_riscv4c`
      - 64KB
      - 128KB
      - 2 x H/D
      - 5.1
      - 10M
      - :ref:`qfn28`
    * - :ref:`ch579`
      - :ref:`cortex_m0`
      - 32KB
      - 250KB
      - H/D
      - 4.2
      - 10M
      - :ref:`qfn28`


.. _qfn28:

QFN28
^^^^^^^^^^^

.. image:: ./images/QFN28.png


.. hint::
    如果在受限的体积内实现以太网功能，QFN28是个不错的选择。

.. _measure:

Measure
-------------

.. _sigma_delta:

Sigma-Delta
~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    ZML165 <../M/ZML165>
    CS32A039 <../M/CS32A039>


.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - Chan
      - Rate
      - ENOB
      - PGA
      - INL
      - Package
    * - :ref:`cs32a039`
      - :ref:`cortex_m0`
      - 1x5ch
      - 10~1280Hz
      - 20.7/20.2
      - 128
      - 1.2LSB
      - LQFP64
    * - :ref:`zml165`
      - :ref:`cortex_m0`
      - 1x2ch
      - 10~1280Hz
      - 20.7/20.2
      - 128
      - 1.2LSB
      - :ref:`qfn20`
    * - :ref:`swm181`
      - :ref:`cortex_m0`
      - 1x4ch
      - 16KSPS
      - 20.7/20.2
      - 128
      - 1.2LSB
      - LQFP48

.. warning::
    :ref:`sigma_delta` 以时间上换极高的精度的特性，采样率都很低，但在精度达到20位以上的场合，实现了其他类型的ADC无法达到的高精度和低功耗。


.. image:: ./images/sigma_delta.jpg
    :target: https://zhuanlan.zhihu.com/p/22308055



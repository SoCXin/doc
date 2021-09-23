
.. _spec:

创新Xin榜
====================

.. note::
    特色榜单收录非常具有创新性，或者非常具有创造性的产品

.. contents::
    :local:


通信相关
-------------

Tiny ETH-PHY
~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - RAM
      - Flash
      - USB
      - BLE
      - Ethernet
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

.. hint::
    在小封装内同时集成以太网MAC+PHY

.. _qfn28:

QFN28
^^^^^^^^^^^

.. image:: ./images/QFN28.png


计量相关
-------------

24bit ADC
~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    CS32A039 <../M/CS32A039>
    ZML165 <../M/ZML165>

.. list-table::
    :header-rows:  1

    * - Name
      - Core
      - Chan
      - Rate
      - ENOB
      - Type
      - Package
    * - :ref:`cs32a039`
      - :ref:`cortex_m0`
      - 1x5ch
      - 10~1280Hz
      - 20.7/20.2
      - :ref:`sigma_delta`
      - LQFP64
    * - :ref:`zml165`
      - :ref:`cortex_m0`
      - 1x2ch
      - 10~1280Hz
      - 20.7/20.2
      - :ref:`sigma_delta`
      - :ref:`qfn20`


.. warning::
    单芯片集成的高精度ADC外设采样率往往不高


.. _sigma_delta:

Sigma-Delta
^^^^^^^^^^^^^^^

.. image:: ./images/sigma_delta.jpg
    :target: https://zhuanlan.zhihu.com/p/22308055

在精度达到20位以上的场合，Sigma-Delta是必选的结构。通过采用过采样、噪声整形以及数字滤波技术，降低对模拟电路的设计要求，实现了其他类型的ADC无法达到的高精度和低功耗。


.. list-table::
    :header-rows:  1

    * - Name
      - Chan
      - Rate
      - ENOB
      - Type
    * - :ref:`sigma_delta`
      -
      -
      -
      -
    * - SAR
      -
      -
      -
      -

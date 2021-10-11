
.. _adc:

AD/DA
============

.. contents::
    :local:

A/D转换
-----------

高速率
~~~~~~~~~~~~

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
    * - :ref:`stm32g431`
      - 170MHz
      - 1K
      - 8K
      - 2
      - 18
      - I2C
      - LQFP48


高精度
~~~~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - CHAN
      - ADC
      - SPEC
      - Package
    * - :ref:`cs32a039`
      - 48MHz
      - 4K
      - 64K
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - LQFP64
    * - :ref:`zml165`
      - 48MHz
      - 4K
      - 64K
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - QFN20
    * - :ref:`swm181`
      - 48MHz
      - 16KB
      - 120KB
      - 4
      - :ref:`sigma_delta`
      - 16bit
      - LQFP48

技术对比
^^^^^^^^^^^

.. list-table::
    :header-rows:  1

    * - :ref:`list`
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
    * - Pipeline
      -
      -
      -
      -

.. _dac:

D/A转换
-----------

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
    * - :ref:`stm32g431`
      - 170MHz
      - 1K
      - 8K
      - 2
      - 18
      - I2C
      - LQFP48

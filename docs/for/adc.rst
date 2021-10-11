
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

.. _sigma_delta:

Sigma-Delta
^^^^^^^^^^^^^

.. toctree::
    :maxdepth: 1

    SWM181 <../M/SWM181>
    ZML165 <../M/ZML165>
    CS32A039 <../M/CS32A039>

.. list-table::
    :header-rows:  1

    * - :ref:`list`
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
      - 16
      - 128
      - 1.2LSB
      - LQFP48

.. warning::
    :ref:`sigma_delta` 以时间上换极高的精度的特性，采样率都很低，但在精度达到20位以上的场合，实现了其他类型的ADC无法达到的高精度和低功耗。



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
      - 48 MHz
      - 4 KB
      - 64 KB
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - LQFP64
    * - :ref:`zml165`
      - 48 MHz
      - 4 KB
      - 64 KB
      - 2
      - :ref:`sigma_delta`
      - 24bit
      - QFN20
    * - :ref:`swm181`
      - 48 MHz
      - 16 KB
      - 120 KB
      - 4
      - :ref:`sigma_delta`
      - 16bit
      - LQFP48

多通道
~~~~~~~~~~~~~~

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
    * - :ref:`stm32g474`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`stm32h730`
      -
      -
      -
      -
      -
      -
      -


.. _dac:

D/A转换
-----------


高速率
~~~~~~~~~~~~

高精度
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
      -
      -
      -
      -
      -
      -

多通道
~~~~~~~~~~~~



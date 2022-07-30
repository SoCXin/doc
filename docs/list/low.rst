
.. _low:

白菜Xin
=============
``≤￥3``

作者将MCU的官方价格分层为：{￥3,$1,$3}，该页收录主要是官方价格 ≤￥3 的产品，满足用户基本的UART/GPIO需求，主要用于用于离散的节点控制及通信

.. list-table::
    :header-rows:  1

    * - :ref:`low`
      - :ref:`frequency`
      - :ref:`sram`
      - :ref:`flash`
      - :ref:`peripherals`
      - :ref:`package`
      - Price
    * - :ref:`ch573`
      - ≤ 60 MHz
      - 18 KB
      - 512 KB
      -
      -
      - ￥2.3
    * - :ref:`stc8`
      - ≤ 24 MHz
      - 1 KB
      - 8 KB
      -
      -
      - ￥1.3
    * - :ref:`ch552`
      - ≤ 24 MHz
      - 1 KB
      - 16 KB
      -
      -
      - ￥2.1
    * - :ref:`at32f421`
      - ≤ 120 MHz
      - 16 KB
      - 64 KB
      -
      -
      - ￥2.8

对于定位低阶的产品，往往定位出货规模较大成本敏感的领域，对技术指标的衡量往往没有市场和商务因数重要，对于开发者而言，最期待和功能一样简单的开发环境及工具。

对于个人开发者而言，对市场细分和功能单一的低阶产品学习，能够丰富选择域和优化产品化能力，特别是硬件免费的场合，省下的每一分钱都是对开发能力和商业格局的认可。

典型的应用场景为，简单的设备控制，所需执行行为简单，程序开发简单，为实现开发便捷，需要有足够多的成熟方案和足够高效的开发方式，能够释放出产品的潜力，特别是新平台的性能过剩，再用于实现过去的传统功能，几乎都能构成降维打击能力。

影响同系列的芯片价格主要包括如下因素：

.. contents::
    :local:
    :depth: 1

.. _sram:

SRAM
-----------
``Static Random Access Memory``

PSRAM就是伪SRAM，内部的内存颗粒跟SDRAM的颗粒相似，但外部的接口跟SRAM相似，不需要SDRAM那样复杂的控制器和刷新机制，PSRAM的接口跟SRAM的接口是一样的。

.. _flash:

Flash
-----------

FLASH存储器又称闪存，它结合了ROM和RAM的长处，不仅具备电子可擦除可编程（EEPROM）的性能，还不会断电丢失数据，同时可以快速读取数据（NVRAM的优势）

.. _package:

Package
-----------
``LQFP`` ``QFN`` ``CSP`` ``BGA``

.. list-table::
    :header-rows:  1

    * - ≤ 3x3mm
      - ≤ 4x4mm
      - ≤ 5x5mm
      - ≤ 7x7mm
      - ≤10x10mm
      - ≤14x14mm
      - ≤20x20mm
      - ≤24x24mm
    * -
      -
      -
      - BGA169
      - BGA196
      - BGA289
      -
      -
    * - CSP
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`QFN20`
      - :ref:`QFN28`
      - :ref:`QFN32`
      - :ref:`QFN56`
      -
      -
      -
      -
    * - X
      -
      - :ref:`LQFP32`
      - :ref:`LQFP48`
      - :ref:`LQFP64`
      -
      -
      -


.. contents::
    :local:
    :depth: 1

小封装
~~~~~~~~~~~
``QFN20`` ``QFN28`` ``QFN32``

.. contents::
    :local:
    :depth: 1

.. _QFN20:

QFN20
^^^^^^^^^^^^^
``3x3mm``

.. _QFN28:

QFN28
^^^^^^^^^^^^^
``4x4mm``

.. list-table::
    :header-rows:  1

    * - :ref:`QFN28`
      - :ref:`frequency`
      - :ref:`sram`
      - :ref:`flash`
      - :ref:`peripherals`
      - GPIO
    * - :ref:`ch582`
      - ≤ 80MHz
      -
      -
      -
      -
    * - :ref:`ch573`
      - ≤ 60MHz
      - 18 KB
      - 512 KB
      -
      -


.. _QFN32:

QFN32
^^^^^^^^^^^^^
``5x5mm``

.. list-table::
    :header-rows:  1

    * - :ref:`QFN32`
      - :ref:`frequency`
      - :ref:`sram`
      - :ref:`flash`
      - :ref:`peripherals`
      - GPIO
    * - :ref:`esp32c3`
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


.. _QFN48:

QFN48
^^^^^^^^^^^^^
``5x5mm`` ``6x6mm``

.. list-table::
    :header-rows:  1

    * - :ref:`QFN48`
      - :ref:`frequency`
      - :ref:`sram`
      - :ref:`flash`
      - :ref:`peripherals`
      - GPIO
    * - :ref:`esp32`
      -
      -
      -
      -
      -
    * - :ref:`aic8800`
      -
      -
      -
      -
      -
    * - :ref:`ab32vg1`
      -
      -
      -
      -
      -
    * - :ref:`ac7916`
      -
      -
      -
      -
      -
    * - :ref:`ch583`
      -
      -
      -
      -
      -
    * - :ref:`ch579`
      -
      -
      -
      -
      -


.. _QFN56:

QFN56
^^^^^^^^^^^^^
``7x7mm``

.. list-table::
    :header-rows:  1

    * - :ref:`QFN56`
      - :ref:`frequency`
      - :ref:`sram`
      - :ref:`flash`
      - :ref:`peripherals`
      - GPIO
    * - :ref:`rp2040`
      -
      -
      -
      -
      -
    * - :ref:`esp32s2`
      -
      -
      -
      -
      -
    * - :ref:`esp32s3`
      -
      -
      -
      -
      -
    * - :ref:`w801`
      -
      -
      -
      -
      -
    * - :ref:`bl608`
      -
      -
      -
      -
      -
    * - :ref:`Air103`
      -
      -
      -
      -
      -



通用型
~~~~~~~~~~~
``LQFP32`` ``LQFP48`` ``LQFP64``

参考范式 :ref:`ref030` , :ref:`ref103` , :ref:`ref407`  ，软硬件兼容产品方案，通用替换，提高产品供应链稳定


.. toctree::
    :maxdepth: 1

    MH32F103A <../miscellaneous/MH32F103A>

.. _LQFP32:

LQFP32
^^^^^^^^^^^^^
``5x5mm``

.. _LQFP48:

LQFP48
^^^^^^^^^^^^^
``7x7mm``

.. _LQFP64:

LQFP64
^^^^^^^^^^^^^
``10x10mm``


.. list-table::
    :header-rows:  1

    * - :ref:`LQFP64`
      - :ref:`frequency`
      - :ref:`sram`
      - :ref:`flash`
      - :ref:`peripherals`
      - GPIO
    * -
      -
      -
      -
      -
      -




大封装
~~~~~~~~~~~
``LQFP144`` ``LQFP100``

.. _LQFP100:

LQFP100
^^^^^^^^^^^^^
``14x14mm``

LQFP100(0.5mm pitch) = LQFP128(0.4mm pitch)

.. _LQFP144:

LQFP144
^^^^^^^^^^^^^
``20x20mm``

.. _LQFP176:

LQFP176
^^^^^^^^^^^^^
``24x24mm``

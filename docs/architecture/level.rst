
.. _level:

Level
===============

.. toctree::
    :maxdepth: 1

    性能评测     <performance>

`Level Mark <https://github.com/SoCXin/Level>`_ base on :ref:`frequency`/:ref:`CoreMark`/:ref:`Geekbench`

.. list-table::
    :header-rows:  1

    * - :ref:`level1`
      - :ref:`level2`
      - :ref:`level3`
      - :ref:`level4`
      - :ref:`level5`
      - :ref:`level6`
      - :ref:`level7`
      - :ref:`level8`
      - :ref:`level9`
    * - :ref:`level1_cnt`
      - :ref:`level2_cnt`
      - :ref:`level3_cnt`
      - :ref:`level4_cnt`
      - :ref:`level5_cnt`
      - :ref:`level6_cnt`
      -
      -
      -


.. _level1:

L1(<60)
--------------
``Frequency < 60MHz``


.. list-table::
    :header-rows:  1

    * - :ref:`xin`
      - :ref:`architecture`
      - SRAM
      - :ref:`frequency`
      - :ref:`consumption`
      - :ref:`level1`
    * - :ref:`ch549`
      - :ref:`mcs51`
      -
      - 48(MHz)
      -
      - 1


.. _level1_cnt:

num:1
~~~~~~~~~

.. _level2:

L2(<120)
--------------
``Frequency < 120MHz``


.. list-table::
    :header-rows:  1

    * - :ref:`xin`
      - :ref:`architecture`
      - SRAM
      - :ref:`frequency`
      - :ref:`consumption`
      - :ref:`level2`
    * - :ref:`gd32v103`
      - :ref:`riscv`
      -
      - 108(MHz)
      -
      - 1


.. _level2_cnt:

num:1
~~~~~~~~~

.. _level3:

L3(<240)
--------------
``Frequency < 240MHz``


.. list-table::
    :header-rows:  1

    * - :ref:`xin`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`frequency`
      - :ref:`consumption`
      - :ref:`level3`
    * - :ref:`stm32u575`
      - :ref:`cortex_m33`
      - 651
      - 160(MHz)
      -
      - 1
    * - :ref:`stm32f429`
      - :ref:`cortex_m4`
      - 608
      - 180(MHz)
      -
      - 2
    * - :ref:`stm32f407`
      - :ref:`cortex_m4`
      - 566
      - 168(MHz)
      -
      - 3
    * - :ref:`stm32g474`
      - :ref:`cortex_m4`
      - 550
      - 170(MHz)
      -
      - 4
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407
      - 160(MHz)
      -
      - 5
    * - :ref:`rp2040`
      - :ref:`cortex_m0`
      - (2)
      - 125(MHz)
      -
      - 6


.. _level3_cnt:

num:6
~~~~~~~~~

.. _level4:

L4(<2k)
--------------
``CoreMark < 2000``

.. list-table::
    :header-rows:  1

    * - :ref:`xin`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`frequency`
      - :ref:`consumption`
      - :ref:`level4`
    * - :ref:`stm32h7b0`
      - :ref:`cortex_m7`
      - 1414
      - 280(MHz)
      -
      - 1
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1182 (2)
      - 240(MHz)
      -
      - 2
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 994 (2)
      - 240(MHz)
      -
      - 3
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 614
      - 240(MHz)
      -
      - 4

.. _level4_cnt:

num:4
~~~~~~~~~


.. _level5:

L5(<4k)
--------------
``CoreMark < 4000``

.. list-table::
    :header-rows:  1

    * - :ref:`xin`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`frequency`
      - :ref:`consumption`
      - :ref:`level5`
    * - :ref:`stm32h745`
      - :ref:`cortex_m7`
      - 3224 (2)
      - 480(MHz)
      -
      - 1
    * - :ref:`rt1060`
      - :ref:`cortex_m7`
      - 3020
      - 600(MHz)
      -
      - 2
    * - :ref:`stm32h730`
      - :ref:`cortex_m7`
      - 2778
      - 550(MHz)
      -
      - 3
    * - :ref:`stm32h750`
      - :ref:`cortex_m7`
      - 2424
      - 480(MHz)
      -
      - 4


.. _level5_cnt:

num:4
~~~~~~~~~

.. _level6:

L6(<8k)
--------------
``CoreMark < 8000``

    * - :ref:`xin`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`frequency`
      - :ref:`consumption`
      - :ref:`level5`
    * - :ref:`rt1170`
      - :ref:`cortex_m7`
      - 6468 (2)
      - 1.0(GHz)
      -
      - 1
    * - :ref:`v831`
      - :ref:`cortex_a7`
      - ? (2)
      - 800(MHz)
      -
      - 2

.. _level6_cnt:

num:2
~~~~~~~~~

.. _level7:

L7(>1k)
--------------
``Geekbench > 1000``

.. _level8:

L8(>2k)
--------------
``Geekbench > 2000``

.. _level9:

L9(>4k)
--------------
``Geekbench > 4000``

* M1:9.78 CoreMark/MHz
* A15:1724/4320 | 9.36 CoreMark/MHz
* 9000:1248/4181
* 8Gen1:1235/3831





.. _ulp:

效能Xin
============


.. list-table::
    :header-rows:  1

    * - :ref:`ulp`
      - :ref:`architecture`
      - :ref:`frequency`
      - :ref:`ulpbench`
      - :ref:`wireless`
      - :ref:`vcc`
      - :ref:`consumption`
      - :ref:`halt`
      - :ref:`sleep`
    * - :ref:`stm32u575`
      - :ref:`cortex_m33`
      - 160(MHz)
      - 651
      - X
      - 1.7-3.6
      - 19 µA
      - 475 nA
      - 110 nA
    * - :ref:`stm32l412`
      - :ref:`cortex_m4`
      - 80(MHz)
      - 273.55
      - X
      - 1.7-3.6
      - 28 μA
      -
      - 195 nA
    * - :ref:`stm32l011`
      - :ref:`cortex_m0`
      - 32(MHz)
      -
      - X
      - 1.7-3.6
      - 49 µA
      -
      - 230 nA
    * - :ref:`cc1350`
      - :ref:`cortex_m3`
      - 48(MHz)
      - 158
      - √
      - 1.8-3.8
      - 51 µA
      -
      - 185 nA
    * - :ref:`cc2340`
      - :ref:`cortex_m0`
      - 48(MHz)
      -
      - :ref:`ble`
      - 1.71-3.8
      - 55 µA
      - 830 nA
      - 150 nA
    * - :ref:`cc2650`
      - :ref:`cortex_m3`
      - 64(MHz)
      - 142
      - √
      - 1.8-3.8
      - 61 µA
      -
      - 100 nA
    * - :ref:`stm32h7b0`
      - :ref:`cortex_m7`
      - 280(MHz)
      - 1414
      - X
      - 1.71-3.6
      - 120 µA
      -
      - 2.2 µA

.. hint::
    功耗和成本是低阶芯片产品的护城河，也是物联网的特性，如无功耗限制，强调高性能的产品将完全向下挤压低端产品的生存空间

.. contents::
    :local:
    :depth: 1


.. _consumption:

效能
-----------
``运行功耗`` ``uA/MHz``

.. _halt:

待机
-----------
``低功耗待机状态`` ``停止模式``

.. _sleep:

睡眠
-----------
``低功耗睡眠模式`` ``可唤醒状态``

.. _vcc:

供电
-----------
``最低供电电压``

.. contents::
    :local:
    :depth: 1


锂电池
~~~~~~~~~~~

超级电容
~~~~~~~~~~~

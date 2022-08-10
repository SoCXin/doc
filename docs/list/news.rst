.. _news:

推荐Xin
==================

==================  ==================  ==================  ==================
|感知驱动|_          |无线通信|_         |网络连接|_          |边缘计算|_
------------------  ------------------  ------------------  ------------------
`感知驱动`_          `无线通信`_         `网络连接`_          `边缘计算`_
------------------  ------------------  ------------------  ------------------
|工业控制|_          |消费电子|_         |超长待机|_          |计量仪表|_
------------------  ------------------  ------------------  ------------------
`工业控制`_          `消费电子`_         `超长待机`_          `计量仪表`_
==================  ==================  ==================  ==================

.. |感知驱动| image:: images/rp2040.jpg
.. _感知驱动: ../miscellaneous/RP2040.html

.. |无线通信| image:: ../application/images/matter.png
.. _无线通信: ../miscellaneous/RP2040.html

.. |网络连接| image:: ../espressif/images/espressif.png
.. _网络连接: ../miscellaneous/RP2040.html

.. |边缘计算| image:: ../espressif/images/espressif.png
.. _边缘计算: ../miscellaneous/RP2040.html

.. |工业控制| image:: ../espressif/images/espressif.png
.. _工业控制: ../miscellaneous/RP2040.html

.. |消费电子| image:: ../espressif/images/espressif.png
.. _消费电子: ../miscellaneous/RP2040.html

.. |超长待机| image:: ../espressif/images/espressif.png
.. _超长待机: ../miscellaneous/RP2040.html

.. |计量仪表| image:: ../espressif/images/espressif.png
.. _计量仪表: ../miscellaneous/RP2040.html

.. _update:

Update
-------------
``2022``

* 小众芯片不适合小众产品，基础资源太少意味着投入太多，成果和经验价值变现也更加困难;
* 要将价值最大化，就需要和更多的项目分摊投入，同时降低维护成本，这就需要评估通用性;
* 每个选择都只会是一段时间的最优方案，但只要其明显短板还在接受范围，就可以继续使用;

.. list-table::
    :header-rows:  1

    * - 芯片简介
      - 推荐理由
    * - :ref:`NO_001` (264KB SRAM/QFN56)
      - $0.70==Dual Cortex-M0，Arduino/MicroPython/USB-OTG
    * - :ref:`NO_002`
      - 国产高性能双核MCU产品，划时代性能9220 CoreMark
    * - :ref:`NO_003`
      - WiFi6双频 + BT/BLE双模 + USB HS(PHY)
    * - :ref:`NO_004`
      - 拥有5个独立12bit ADC，拥有 :ref:`stm32_hrtim`
    * - :ref:`NO_005`
      - 靠Cortex-M4性能针对 :ref:`stm32f030`,sLib安全库
    * - :ref:`NO_007`
      - 战略级MCU，STM32全家桶外设主频都顶配
    * - :ref:`NO_009` (QFN68)
      - 支持USB SS和USB HS, :ref:`ch569_serdes` 控制器及PHY, :ref:`ch569_hspi`
    * - :ref:`NO_010`
      - 低成本高性价比入门级STM32新品
    * - :ref:`NO_011`
      - 高性能低功耗旗舰，片上1.4M SRAM支持RGB565
    * - :ref:`NO_012`
      - 致敬 :ref:`stm32f429` ，集成 ``8MB SRAM``，LCD支持RGB888
    * - :ref:`NO_013` (32KB SRAM/:ref:`QFN48`)
      - 1MB Flash，2x USB OTG，4x Uart，BLE5.3
    * - :ref:`NO_014`
      - 集成USB HS和1G 以太网MAC，有线连接全家桶
    * - :ref:`NO_015` (QFN56)
      - 高性能双核WiFi/BLE5.0 SoC，带USB OTG


.. toctree::
    :maxdepth: 1

    时代的槽点  <roast>
    历史的余温  <history>
    期待的未来  <future>

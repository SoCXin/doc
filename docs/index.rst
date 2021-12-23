
SoC·Xin
=====================

**新产品用心，芯产品用新**

`SoC·Xin(芯芸) <https://www.soc.xin>`_ 期望求解如下问题：

* 有新需求，缺乏技术积累，求解区间；
* 有芯需求，已知应用场景，求最新解；
* 有芯需求，限定规格成本，求最优解；
* 有薪需求，寻求技能升级，求边界值；

结合不同的需求、场景和生态，脱离品牌利益关联，从使用者角度给出选择和建议，通过汇整和迭代，呈现 ``实用Xin体系``

.. toctree::
    :maxdepth: 1

    推荐清单(15X·IN) <list>
    芯芸月刊 <magazine>

.. toctree::
    :caption: 排序速览
    :maxdepth: 1

    极客最爱开源超多 <news/hot>
    著名项目适配支持 <news/pop>
    旗舰基本干啥都行 <news/top>
    难以拒绝低价好货 <news/low>
    封装紧凑功能强大 <news/sip>

.. list-table::
    :header-rows:  1

    * - Rank
      - :ref:`hot`
      - :ref:`pop`
      - :ref:`top`
      - :ref:`low`
      - :ref:`sip`
      - :ref:`list`
    * - Top.1
      - :ref:`esp32`
      - :ref:`stm32f103`
      - :ref:`stm32h730`
      - :ref:`stc8`
      - :ref:`ch579`
      - :ref:`NO_008`
    * - Top.2
      - :ref:`rp2040`
      - :ref:`esp32`
      - :ref:`stm32h745`
      - :ref:`ch552`
      - :ref:`ch32v307`
      - :ref:`NO_013`
    * - Top.3
      - :ref:`stm32f401`
      - :ref:`nrf52832`
      - :ref:`rt1060`
      - :ref:`esp32c3`
      - :ref:`zml165`
      - :ref:`NO_010`

.. toctree::
    :caption: 领域速览
    :maxdepth: 1

    驱动控制   <for/foc>
    显示交互   <for/hmi>
    通信连接   <for/iot>
    边缘计算   <for/edge>
    功耗优化   <for/ulp>
    数模转换   <for/adc>

.. list-table::
    :header-rows:  1

    * - Classification
      - :ref:`foc`
      - :ref:`hmi`
      - :ref:`iot`
      - :ref:`edge`
      - :ref:`ulp`
      - :ref:`adc`
    * - No.1
      - :ref:`hc32m120`
      - :ref:`stm32f429`
      - :ref:`esp32`
      - :ref:`bcm2711`
      - :ref:`stm32l011`
      - :ref:`stm32g474`
    * - No.2
      - :ref:`swm181`
      - :ref:`gw1nsr`
      - :ref:`esp32c3`
      - :ref:`k210`
      - :ref:`stm32l412`
      - :ref:`stm32g431`
    * - No.3
      - :ref:`mm32spin`
      - :ref:`tkm32f499`
      - :ref:`nrf52832`
      - :ref:`v831`
      - :ref:`stm32h7b0`
      - :ref:`stm32h730`


.. toctree::
    :caption: 内核速览
    :maxdepth: 1

    ARM     <core/arm>
    ASIC    <core/asic>
    MIPS    <core/MIPS>
    RISC-V  <core/RISC-V>
    MCS51   <core/MCS51>

内核架构和主频相关定义 ``X·IN``

.. list-table::
    :header-rows:  1

    * - #define
      - L1(≤40MHz)
      - L2(≤80MHz)
      - L3(≤160MHz)
      - L4(≤400DMIPS)
      - L5(≤800DMIPS)
      - L6(≤1600DMIPS)
    * - :ref:`mcs51`
      - :ref:`stc8`
      - :ref:`ch549`
      -
      -
      -
      -
    * - :ref:`cortex_m0`
      - :ref:`stm32l011`
      - :ref:`stm32g031`
      - :ref:`rp2040`
      -
      -
      -
    * - :ref:`cortex_m3`
      -
      - :ref:`gd32f130`
      - :ref:`stm32f207`
      -
      -
      -
    * - :ref:`cortex_m4`
      -
      - :ref:`nrf52832`
      - :ref:`at32f421`
      - :ref:`at32f437`
      -
      -
    * - :ref:`cortex_m7`
      -
      -
      -
      -
      - :ref:`stm32h7b0`
      - :ref:`rt1060`
    * - :ref:`riscv`
      - :ref:`ch583`
      - :ref:`ch32v103`
      - :ref:`esp32c3`
      -
      - :ref:`k210`
      - :ref:`D1`
    * - :ref:`mips`
      -
      -
      -
      - :ref:`esp32s3`
      -
      - :ref:`mt7621`





.. toctree::
    :caption: 品牌速览
    :maxdepth: 1

    微控制器 @ST <ST/index>
    有线连接 @WCH <WCH/index>
    无线连接 @Espressif <espressif/index>
    蜂窝网络 @ASR <ASR/index>
    路由节点 @MediaTek  <MediaTek/index>
    种子选手 @ArteryTek <arterytek/index>

收录汇整具有代表性厂商，对用户开放程度高，覆盖的解决方案比较全，通过汇总提供更精炼方案。

.. list-table::
    :header-rows:  1

    * - #define
      - :ref:`st`
      - :ref:`wch`
      - :ref:`espressif`
      - :ref:`asr`
      - :ref:`mediatek`
      - :ref:`arterytek`
    * - 最新作品
      - :ref:`stm32u575`
      - :ref:`ch32v307`
      - :ref:`esp32s3`
      -
      - :ref:`mt7621`
      - :ref:`at32f437`
    * - 经典作品
      - :ref:`stm32f103`
      - :ref:`ch579`
      - :ref:`esp32`
      - :ref:`asr6501`
      - :ref:`mt7688`
      - :ref:`at32f421`
    * - 畅销作品
      - :ref:`stm32g030`
      - :ref:`ch554`
      - :ref:`esp32c3`
      -
      - :ref:`mt2625`
      -
    * - 集大成者
      - :ref:`stm32mp15`
      - :ref:`ch32f208`
      -
      -
      -
      -


芯问题之后的新问题
^^^^^^^^^^^^^^^^^^^^^^


在经历一轮芯片短缺之后，在无形的大手作用下，必然面临竞争和淘汰，这会发生在芯片设计制造等市场上游，也波及到芯片应用和产品迭代。

技术驱动的产业，必然产生更多的“必须要，应该有，可以做”。

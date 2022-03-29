
SoC·Xin
=====================

**新产品用心，芯产品用新**

`SoC·Xin <https://www.SoC.Xin>`_ 作为资源容器，期望求解如下问题：

* 有新需求，缺乏技术积累，求解区间；
* 有芯需求，已知应用场景，求最新解；
* 有芯需求，限定规格成本，求最优解；
* 有薪需求，寻求技能升级，求边界值；

推荐清单将动态给出最值得研究的SoC芯产品，能够通过典型产品获得技术发展脉络，找到想要的答案。

.. toctree::
    :maxdepth: 1

    推荐清单 <list/list>
    芯芸期刊 <list/index>


芯芸期刊将通过实体发行的方式提供可探索硬件实体，具备实用性的同时，还具有收藏价值，为数字时代留下痕迹。

.. toctree::
    :caption: 排序速览
    :maxdepth: 1

    极客最爱开源超多 <news/hot>
    著名项目适配支持 <news/pop>
    旗舰小贵干啥都行 <news/top>
    难以拒绝低价好货 <news/low>
    封装紧凑功能强大 <news/sip>
    定位中庸供应稳定 <news/stable>

.. list-table::
    :header-rows:  1

    * - Rank
      - :ref:`hot`
      - :ref:`pop`
      - :ref:`top`
      - :ref:`low`
      - :ref:`sip`
      - :ref:`stable`
      - :ref:`list`
    * - Top.1
      - :ref:`esp32`
      - :ref:`stm32f103`
      - :ref:`stm32h730`
      - :ref:`stc8`
      - :ref:`ch579`
      - :ref:`gd32f130`
      - :ref:`NO_008`
    * - Top.2
      - :ref:`rp2040`
      - :ref:`esp32`
      - :ref:`stm32mp15`
      - :ref:`ch552`
      - :ref:`zml165`
      - :ref:`gd32e230`
      - :ref:`NO_013`
    * - Top.3
      - :ref:`stm32f401`
      - :ref:`nrf52832`
      - :ref:`rt1060`
      - :ref:`ch573`
      - :ref:`ch32v307`
      - :ref:`mm32f031`
      - :ref:`NO_010`

.. toctree::
    :caption: 应用速览
    :maxdepth: 1

    显示交互   <application/hmi>
    通信连接   <application/iot>
    计算平台   <application/edge>
    电源设计   <application/pwr>
    数模转换   <application/adc>
    模数转换   <application/dac>
    驱动控制   <application/foc>

.. list-table::
    :header-rows:  1

    * - Rank
      - :ref:`foc`
      - :ref:`hmi`
      - :ref:`iot`
      - :ref:`edge`
      - :ref:`ulp`
      - :ref:`adc`
      - :ref:`dac`
    * - No.1
      - :ref:`hc32m120`
      - :ref:`stm32f429`
      - :ref:`esp32`
      - :ref:`bcm2711`
      - :ref:`stm32l011`
      - :ref:`stm32g474`
      - :ref:`stm32g474`
    * - No.2
      - :ref:`swm181`
      - :ref:`gw1nsr`
      - :ref:`esp32c3`
      - :ref:`k210`
      - :ref:`stm32l412`
      - :ref:`stm32g431`
      -
    * - No.3
      - :ref:`mm32spin`
      - :ref:`tkm32f499`
      - :ref:`nrf52832`
      - :ref:`v831`
      - :ref:`stm32h7b0`
      - :ref:`stm32h730`
      -


.. toctree::
    :caption: 内核速览
    :maxdepth: 1

    ARM     <core/arm>
    ASIC    <ASIC/index>
    MIPS    <core/MIPS>
    RISC-V  <core/RISC-V>
    MCS51   <core/MCS51>

内核架构和性能分级定义 ``X·IN``

.. list-table::
    :header-rows:  1

    * - :ref:`CoreMark`
      - L1(≤40)
      - L2(≤100)
      - L3(≤240)
      - L4(≤700)
      - L5(≤1500)
      - L6(≤3600)
    * - :ref:`mcs51`
      - :ref:`stc8`
      - :ref:`ch549`
      - X
      - X
      - X
      - X
    * - :ref:`cortex_m0`
      - :ref:`stm32l011`
      - :ref:`stm32g031`
      - :ref:`rp2040`
      - X
      - X
      - X
    * - :ref:`cortex_m3`
      - √
      - :ref:`gd32f130`
      - :ref:`stm32f207`
      - √
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
      - √
      - :ref:`stm32h7b0`
      - :ref:`rt1060`
    * - :ref:`cortex_r`
      -
      -
      -
      -
      -
      -
    * - :ref:`cortex_a`
      -
      -
      -
      -
      -
      -
    * - :ref:`riscv`
      - :ref:`ch583`
      - :ref:`ch32v103`
      - :ref:`esp32c3`
      - √
      - :ref:`k210`
      - :ref:`D1`
    * - :ref:`mips`
      - X
      - √
      - √
      - :ref:`esp32s3`
      - :ref:`mt7688`
      - :ref:`mt7621`

.. note::
    在L6分级之上，还有L7-L9用于划分高性能CPU



.. toctree::
    :caption: 品牌速览
    :maxdepth: 1

    微控制器芯片领域的王者 @ST <ST/index>
    基于LoRa/Cat1长距网络 @ASR <ASR/index>
    移动通信和物联网新领袖 @RDA <RDA/index>
    专注设备连接和接口扩展 @WCH <WCH/index>
    Wi-Fi AIoT无线解决方案 @Espressif <espressif/index>
    高性能基带网关路由SoC @MediaTek  <MediaTek/index>
    高性能多媒体应用处理器 @Allwinner  <allwinner/index>
    专注Cortex-M4核高性价 @ArteryTek <arterytek/index>

收录汇整具有代表性厂商，对用户开放程度高，覆盖的解决方案比较全，通过汇总提供更精炼方案。


.. list-table::
    :header-rows:  1

    * - Vendor
      - :ref:`wch`
      - :ref:`asr`
      - :ref:`rda`
      - :ref:`espressif`
      - :ref:`mediatek`
      - :ref:`arterytek`
      - :ref:`allwinner`
    * - 新作
      - :ref:`ch32v307`
      - :ref:`asr6601`
      -
      - :ref:`esp32h2`
      - :ref:`mt7621`
      - :ref:`at32f425`
      - :ref:`D1`
    * - 经典
      - :ref:`ch579`
      - :ref:`asr6501`
      - :ref:`usi8910`
      - :ref:`esp32`
      - :ref:`mt7688`
      - :ref:`at32f421`
      - :ref:`S3`
    * - 畅销
      - :ref:`ch549`
      - :ref:`asr1802`
      -
      - :ref:`esp32c3`
      - :ref:`mt2625`
      - :ref:`at32f403`
      - :ref:`R329`
    * - 大成
      - :ref:`ch569`
      - :ref:`asr1601`
      -
      - :ref:`esp32s3`
      -
      - :ref:`at32f437`
      - :ref:`v831`



SoC·Xin
=====================

**新产品用心，芯产品用新**

`SoC·Xin <https://www.SoC.Xin>`_ 作为资源容器求解如下问题：

* 有新需求，缺乏技术积累，求解区间；
* 有芯需求，已知应用场景，求最新解；
* 有芯需求，限定规格成本，求最优解；
* 有薪需求，寻求技能升级，求边界值；

.. toctree::
    :maxdepth: 1

    芯期刊 <list/index>


.. toctree::
    :caption: 新品速览
    :maxdepth: 1

    极客最爱开源超多 <news/hot>
    著名项目适配支持 <news/pop>
    旗舰小贵干啥都行 <news/top>
    难以拒绝低价好货 <news/low>
    定位中庸供应稳定 <news/stable>
    差异定位推荐试用 <list/list>

.. list-table::
    :header-rows: 1

    * - Rank
      - :ref:`hot`
      - :ref:`pop`
      - :ref:`top`
      - :ref:`low`
      - :ref:`stable`
      - :ref:`list`
    * - Top.1
      - :ref:`esp32`
      - :ref:`stm32f103`
      - :ref:`stm32h730`
      - :ref:`stc8`
      - :ref:`gd32f130`
      - :ref:`NO_017`
    * - Top.2
      - :ref:`rp2040`
      - :ref:`esp32`
      - :ref:`esp32s3`
      - :ref:`ch552`
      - :ref:`gd32e230`
      - :ref:`NO_013`
    * - Top.3
      - :ref:`stm32f401`
      - :ref:`nrf52832`
      - :ref:`rt1060`
      - :ref:`ch573`
      - :ref:`mm32f031`
      - :ref:`NO_010`

.. toctree::
    :caption: 应用领域
    :maxdepth: 1

    人机交互   <application/hmi>
    通信连接   <application/iot>
    边缘计算   <application/edge>
    超低功耗   <application/ulp>
    模拟转换   <application/adc>
    控制驱动   <application/foc>

==================  ==================  ==================
|人机交互|_          |通信连接|_         |边缘计算|_
------------------  ------------------  ------------------
`人机交互`_          `通信连接`_         `边缘计算`_
------------------  ------------------  ------------------
|超低功耗|_          |模拟转换|_         |控制驱动|_
------------------  ------------------  ------------------
`超低功耗`_          `模拟转换`_         `控制驱动`_
==================  ==================  ==================

.. |人机交互| image:: list/images/esp32.png
.. _人机交互: application/hmi.html

.. |通信连接| image:: list/images/esp32.png
.. _通信连接: application/iot.html

.. |边缘计算| image:: list/images/esp32.png
.. _边缘计算: application/edge.html

.. |超低功耗| image:: list/images/esp32.png
.. _超低功耗: application/ulp.html

.. |模拟转换| image:: list/images/esp32.png
.. _模拟转换: application/adc.html

.. |控制驱动| image:: list/images/esp32.png
.. _控制驱动: application/foc.html



.. toctree::
    :caption: 内核速览
    :maxdepth: 1

    架构分类     <architecture/index>
    性能分级     <architecture/level>

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
      - :ref:`espressif`
      - :ref:`mediatek`
      - :ref:`arterytek`
      - :ref:`allwinner`
    * - 新作
      - :ref:`ch32v307`
      - :ref:`asr6601`
      - :ref:`esp32h2`
      - :ref:`mt2625`
      - :ref:`at32f425`
      - :ref:`D1`
    * - 经典
      - :ref:`ch579`
      - :ref:`asr6501`
      - :ref:`esp32`
      - :ref:`mt7688`
      - :ref:`at32f421`
      - :ref:`S3`
    * - 畅销
      - :ref:`ch549`
      - :ref:`asr1802`
      - :ref:`esp32c3`
      - :ref:`mt2503`
      - :ref:`at32f403`
      - :ref:`R329`
    * - 大成
      - :ref:`ch569`
      - :ref:`asr1601`
      - :ref:`esp32s3`
      - :ref:`mt7621`
      - :ref:`at32f437`
      - :ref:`v831`


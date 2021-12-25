
.. _edge:

Edge
============

.. contents::
    :local:

算法平台
-----------

.. _tflite:

TF Lite
~~~~~~~~~~~


.. _tinyml:

TinyML
~~~~~~~~~~~

分布最广的物联网设备往往体积很小、电量有限。它们被作为终端硬件，通过嵌入式传感器采集各种数据；计算能力有限，对功耗极为敏感。这类设备也能实现机器学习吗？一个趋势是，人工智能AI正在加快速度从“云端”走向“边缘”，进入到越来越小的物联网设备中。在终端和边缘侧的微处理器上，实现的机器学习过程，被称为微型机器学习，即TinyML。

在终端和边缘侧的微处理器上，实现的机器学习过程，被称为微型机器学习，即TinyML。更准确的说，TinyML是指工程师们在mW功率范围以下的设备上，实现机器学习的方法、工具和技术。

.. _cube_ai:

Cube-AI
~~~~~~~~~~~

使用基于STM32 MCU的嵌入式系统的开发人员可能不熟悉神经网络。同样，从事机器学习的数据科学家更习惯基于云的海量计算资源，并且对嵌入式开发的内存和计算约束不太满意。STM32Cube.AI揭开了AI和嵌入式系统的神秘面纱，能够充分利用更多的开发人员的专业知识，从而将神经网络带入嵌入式边缘开发领域，进一步拓展了物联网应用。


* 从预先训练的神经网络模型生成STM32优化的库。
* 支持各种深度学习框架，如Keras，Caffe，ConvnetJS和Lasagne.
* 通过STM32Cube™集成，可轻松实现不同STM32微控制器系列的便携性。
* 免费，用户友好的许可条款。

.. image:: ./images/CUBE-AI.png
    :target: https://www.st.com/en/embedded-software/x-cube-ai.html#get-software

使用神经网络的5个步骤

* 1.捕获数据
* 2.清理，标记数据和构建ANN（人工神经网络）拓扑
* 3.训练ANN模型
* 4.将ANN转换为STM32 MCU的优化代码
* 5.使用经过培训的ANN处理和分析新数据


边缘平台
-----------

.. list-table::
    :header-rows:  1

    * - #define
      - L4(≤400 DMIPS)
      - L5(≤800 DMIPS)
      - L6(≤1600DMIPS)
      - L7(≤4 TOPS)
      - L8(≤20TOPS)
      - L9 (Above)
    * - :ref:`esp32s3`
      -
      -
      -
      -
      -
      -
    * - :ref:`eai80`
      -
      -
      -
      -
      -
      -

可以在端侧部署算法的嵌入式平台，相对传统的计算分离体系，拥有更高的集成度和灵活度


SoC平台
~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Freq
      - RAM
      - Flash
      - NPU
      - Package
    * - :ref:`k210`
      - :ref:`riscv`
      - 400 MHz
      - 8 MB
      -
      - :ref:`k210_npu`
      - BGA144
    * - :ref:`k510`
      - :ref:`riscv`
      - 800 MHz
      -
      -
      - :ref:`k510_npu`
      - BGA144
    * - :ref:`v831`
      - :ref:`cortex_a7`
      - 800 MHz
      - 64MB DDR2
      -
      -
      - QFN88

.. toctree::
    :maxdepth: 1

    D1  <../H/D1>
    K210 <../H/K210>
    K510 <../H/K510>
    V831 <../H/V831>
    SP7021 <../H/SP7021>

MCU平台
~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - Freq
      - RAM
      - Flash
      - NPU
      - Package
    * - :ref:`eai80`
      - :ref:`cortex_m4`
      - 200 MHz
      - 8 MB
      - 8 MB
      - :ref:`eai80_npu`
      - LQFP100
    * - :ref:`eai80`
      - :ref:`cortex_m4`
      - 200 MHz
      - 8 MB
      - 8 MB
      - :ref:`eai80_npu`
      - LQFP100


.. toctree::
    :maxdepth: 1

    EAI80 <../H/EAI80>


NPU平台
~~~~~~~~~~~

.. toctree::
    :maxdepth: 1

    Coral TPU <coral>


ARM平台
~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - #define
      - Core
      - Performance
      - High
      - WiFi
      - Rate
      - More
      - Package
    * - :ref:`bcm2711`
      -
      -
      -
      -
      -
      -
      -
    * - :ref:`bcm2835`
      -
      -
      -
      -
      -
      -
      -


.. toctree::
    :maxdepth: 1

    BCM2835 <../H/BCM2835>
    BCM2711 <../H/BCM2711>
    SSD201 <../H/SSD201>
    A311D <../H/A311D>

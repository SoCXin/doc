

内核架构
===============

.. list-table::
    :header-rows:  1

    * - :ref:`CoreMark`
      - :ref:`level1`
      - :ref:`level2`
      - :ref:`level3`
      - :ref:`level4`
      - :ref:`level5`
      - :ref:`level6`
      - :ref:`level7`
      - :ref:`level8`
      - :ref:`level9`
    * - :ref:`mcs51`
      - :ref:`ch549`
      - X
      - X
      - X
      - X
      - X
      - X
      - X
      - X
    * - :ref:`cortex_m`
      - √
      - √
      - √
      - √
      - √
      - √
      - X
      - X
      - X
    * - :ref:`cortex_r`
      -
      -
      -
      -
      -
      -
      - X
      - X
      - X
    * - :ref:`cortex_a`
      -
      -
      -
      -
      - √
      - √
      - √
      - √
      - √
    * - :ref:`riscv`
      - √
      - √
      - √
      - √
      - √
      - √
      - √
      - √
      - √
    * - :ref:`mips`
      - X
      - √
      - √
      - √
      - √
      - √
      - √
      - √
      - X

.. toctree::
    :maxdepth: 1

    X86     <x86>
    ARM     <arm>
    MIPS    <MIPS>
    FPGA    <../fpga/index>
    RISC-V  <riscv>
    MCS-51  <MCS51>



.. _architecture:

Architecture
---------------

.. contents::
    :local:

.. _neumann:

Neumann
~~~~~~~~~~~~~~

冯·诺依曼结构，又称为普林斯顿体系结构，是一种将程序指令存储器和数据存储器合并在一起的存储器结构。取指令和取操作数都在同一总线上，通过分时复用的方式进行；缺点是在高速运行时，不能达到同时取指令和取操作数，从而形成了传输过程的瓶颈。由于程序指令存储地址和数据存储地址指向同一个存储器的不同物理位置，因此程序指令和数据的宽度相同。

.. image:: ./images/Neumann.png
    :target: https://blog.csdn.net/u014470361/article/details/79774331

.. _harvard:

Harvard
~~~~~~~~~~~~~~

哈佛结构是一种将程序指令存储和数据存储分开的存储器结构，它的主要特点是将程序和数据存储在不同的存储空间中，即程序存储器和数据存储器是两个独立的存储器，每个存储器独立编址、独立访问，目的是为了减轻程序运行时的访存瓶颈。

哈佛结构的中央处理器首先到程序指令储存器中读取程序指令内容，解码后得到数据地址，再到相应的数据储存器中读取数据，并进行下一步的操作（通常是执行）。程序指令储存和数据储存分开，数据和指令的储存可以同时进行，可以使指令和数据有不同的数据宽度，如Microchip公司的PIC16芯片的程序指令是14位宽度，而数据是8位宽度。

.. image:: ./images/Harvard.png
    :target: https://blog.csdn.net/u014470361/article/details/79774331
.. image:: ./images/Harvarde.png
    :target: https://blog.csdn.net/u014470361/article/details/79774331

.. note::
    :ref:`cortex_m` 系列是哈佛结构，而 :ref:`cortex_a` 是冯诺依曼结构（更准确说SoC是混合结构）


.. _performance:

Performance
--------------

.. list-table::
    :header-rows:  1

    * - :ref:`performance`
      - :ref:`DMIPS`/MHz
      - :ref:`CoreMark`/MHz
      - :ref:`Geekbench`/Core
    * - :ref:`cortex_m0`
      - 0.95
      - 1.62
      -
    * - :ref:`cortex_m3`
      - 1.25
      - 2.19
      -
    * - :ref:`cortex_m4`
      - 1.25
      - 2.19
      -
    * - :ref:`cortex_m7`
      - 2.14
      - 5.0
      -
    * - :ref:`cortex_m23`
      -
      -
      -
    * - :ref:`cortex_m33`
      - 1.5
      -
      -
    * - :ref:`24KEc`
      - 1.55
      - 3.05
      -
    * - :ref:`1004KEc`
      -
      -
      -

.. _frequency:

Frequency
~~~~~~~~~~~~~



.. _Geekbench:

Geekbench
~~~~~~~~~~~~~
``Geekbench5``

是一款多平台的性能测试工具。与同类软件不同的是，它几乎可以运行在所有的已知PC架构系统上，包括了Windows、Mac OSX、以及各种Linux发行版。Geekbench的测试项目重点考察CPU和内存系统的运算能力，在测试完成后会给出具体得分供用户参考比对。

`Geekbench5 Search <https://browser.geekbench.com/v5/cpu/search>`_

.. _DMIPS:

DMIPS
~~~~~~~~~~~~~

``Dhrystone Benchmark``


Dhrystone是由Reinhold P. Weicker在1984年提出来的一个基准测试程序，其主要目的是测试处理器的整数运算和逻辑运算的性能。

Dhrystone程序最初用Ada语言发布，后来Rick Richardson为Unix开发了用C语言编写的Version 1.1，这个版本也成功的推动了Dhrystone的广泛应用。Dhrystone程序的最新版本是1988年更新的Version 2.1。

Dhrystone标准的测试方法很简单，就是单位时间内跑了多少次Dhrystone程序，其指标单位为DMIPS/MHz。MIPS是Million Instructions Per Second的缩写，每秒处理的百万级的机器语言指令数。DMIPS中的D是Dhrystone的缩写，它表示了在Dhrystone标准的测试方法下的MIPS。

Dhrystone反映的是系统整体的性能，这就意味着它不单单是受CPU的性能影响还包括相应配套软件的性能, 另外由于Dhrystone benchmark本身太小，因此能衡量的东西就太少， 反应不出CPU全面的性能。

EEMBC（嵌入式微处理器基准协会）推出了一个免费的类似于Dhrystone的benchmark，称为CoreMark


.. _CoreMark:

CoreMark
~~~~~~~~~~~~~


CoreMark是由嵌入式微处理器基准评测协会EEMBC的Shay Gla-On于2009年提出的一项基准测试程序，其主要目标是测试处理器核心性能，这个标准被认为比陈旧的Dhrystone标准更有实际价值。

CoreMark能分析并为处理器管线架构和效率评分，通过执行三个主要任务来测试常用运算的执行。重要的是，CoreMark测试的设计方式，能让处理器不受内存的影响。所以目前CoreMark已迅速成为量测与比较处理器性能的业界标准基准测试。

CoreMark程序使用C语言写成，包含如下的运算法则：列举（寻找并排序），数学矩阵操作（普通矩阵运算）和状态机（用来确定输入流中是否包含有效数字），最后还包括CRC（循环冗余校验）。CoreMark程序的最新版本是Version 1.0。

CoreMark标准的测试方法也很简单，就是在某配置参数组合下单位时间内跑了多少次CoreMark程序，其指标单位为CoreMark/MHz。CoreMark数字越高，意味着性能更高。

跑分对编译器的优化等级 -O 参数有严重倚赖


`EEMBC CoreMark <https://www.eembc.org/coremark/scores.php>`_ 计算所有的核心跑分，按主频MHz计算平均(核越多数值越大)。


.. _ULPMark:

ULPMark
~~~~~~~~~~~~~~

ULPMark 测试目前有三个部分，分别是 :ref:`ulp_cp` 、 :ref:`ulp_pp` 和 ULPMark-CoreMark。

.. _ulp_cp:

ULPMark-CP
^^^^^^^^^^^^^^

ULPMark-CoreProfile 在深度睡眠下整个芯片的能量消耗；因为在低功耗的应用场景下，该芯片设备可能是单电池供电，需要运行长达 10 年的时间，所以芯片设备绝大部分时间应该都是处在深度睡眠的模式，偶尔唤醒处理部分任务。

.. _ulp_pp:

ULPMark-PP
^^^^^^^^^^^^^^

ULPMark-PeripheralProfile 普通外围设备的能量对深度睡眠的影响


ULPMark-CoreMark
^^^^^^^^^^^^^^^^^^^^

ULPMark-CoreMark 活跃功耗，使用 CoreMark 作为工作负载



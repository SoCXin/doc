
.. _architecture:

Architecture
===============

.. toctree::
    :maxdepth: 1

    X86     <x86>
    ARM     <arm>
    ASIC    <../ASIC/index>
    MIPS    <MIPS>
    RISC-V  <riscv>
    MCS51   <MCS51>





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


架构体系
---------------

.. _neumann:

Von Neumann
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



.. _frequency:

Frequency
~~~~~~~~~~~~~

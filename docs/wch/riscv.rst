.. _wch_riscv:

RISC-V
==============
``RISC-V2A`` ``RISC-V3A`` ``RISC-V4A`` ``RISC-V4B`` ``RISC-V4C`` ``RISC-V4F``

:ref:`wch` 基于 :ref:`riscv` 构建的内核方案，早期外购第三方RISC-V内核，但当时该IP尚未成熟只支持4线JTAG调试占用IO多，内核架构庞大未针对嵌入式应用优化。

青稞V4微处理器是基于标准RISC-V指令集架构，自研的32位通用MCU微处理器。支持RV32IMACF指令集和自扩展字节和半字操作压缩指令，支持中断嵌套、硬件压栈（HPE）、免表中断（VTF），支持多种低功耗模式，增强的两线调试接口，支持标准RISC-V调试，具有物理 内存保护（PMP）等功能。


.. list-table::
    :header-rows:  1

    * - :ref:`riscv`
      - :ref:`frequency`
      - :ref:`CoreMark`
      - :ref:`power`
      - Size(mm²)
    * - :ref:`wch_riscv2a`
      -
      -
      -
      -
    * - :ref:`wch_riscv3a`
      -
      -
      -
      -
    * - :ref:`wch_riscv4a`
      -
      -
      -
      -
    * - :ref:`wch_riscv4b`
      -
      -
      -
      -
    * - :ref:`wch_riscv4c`
      -
      -
      -
      -
    * - :ref:`wch_riscv4f`
      -
      -
      -
      -

.. _wch_riscv2a:

RISC-V2A
--------------



.. _wch_riscv3a:

RISC-V3A
--------------

RISC-V3A 是 32 位嵌入式处理器，内部模块化管理，支持 RISC-V 开源指令集 IMAC 子集。
包含快速可编程中断控制器（FPIC），提供了 4 个向量可编程的快速中断通道及 44 个优先级可配的普通中断，通过硬件现场保存和恢复的方式实现中断的最短周期响应；包含 2 线串行调试接口，支持用户在线升级和调试；包括多组总线连接处理器外部单元模块，实现外部功能模块和内核的交互。


.. _wch_riscv4a:

RISC-V4A
--------------
``1.56 DMIPS``

.. _wch_riscv4b:

RISC-V4B
--------------

.. _wch_riscv4c:

RISC-V4C
--------------

.. _wch_riscv4f:

RISC-V4F
--------------


Summary
--------------

青稞 V4 系列微处理器是基于标准 RISC-V 指令集架构，自研的 32 位通用 MCU 微处理器。根据不同的运用场景和指令集组合，该系列包括 V4A，V4B，V4C，V4F。

V4 系列均支持 RV32IMAC 指令集扩展，其中 V4F 支持单精度硬件浮点，即支持 RV32IMACF 扩展。同时 V4B、V4C、V4F 还支持自定义扩展 XW。

除此之外，还支持硬件压栈（HPE）、免表中断（VTF）、精简的两线调试接口、支持“WFE”指令、物理内存保护（PMP）等特色功能。

.. image:: ./images/wch_riscv4.png
    :target: http://www.wch.cn/downloads/QingKeV4_Processor_Manual_PDF.html


IDE
~~~~~~~~~~~

`MounRiver Studio <http://www.mounriver.com/>`_


.. _ui:

交互类
============

.. contents::
    :local:

大屏显示
-----------

.. toctree::
    :maxdepth: 1

    SWM32S <../M/SWM32S>
    SWM341 <../M/SWM341>
    TKM32F499 <../M/TKM32F499>

.. list-table::
    :header-rows:  1

    * - Name
      - DMIPS
      - SRAM
      - FLASH
      - GUI
      - reslution
      - interface
      - GPU
    * - :ref:`stm32h7b0`
      - 599 (280MHz)
      - 1.4 MB
      - 1/2 MB
      - TouchGFX/STemWin
      - XGA(1024x768)
      - RGB/CEC
      - DMA2D/JPEC
    * - :ref:`swm32s`
      - 150 (120MHz)
      - 512 KB
      - 512 KB
      - LittlevGL
      - WVGA(800x480)
      - RGB
      - No
    * - :ref:`gw1nsr`
      - 75 (60MHz)
      - 24 KB
      - 32 KB
      - LittlevGL
      - XGA(1024x768)
      - FPGA
      - No

GUI框架
-----------

.. _TouchGFX:

TouchGFX
~~~~~~~~~~~

.. _LittlevGL:

LittlevGL
~~~~~~~~~~~

免费的开源图形库，具有易于使用的图形元素以及良好的视觉效果和内存占用低等特点，可构建嵌入式 GUI。LittlevGL 是一个完整的图形框架，开发者不需要考虑原始图形如何绘制，可以使用已有图形元素来构建自己的  GUI，例如按钮，图表，图像，列表，滑块，开关，键盘等。

.. _emWin:

emWin
~~~~~~~~~~~

.. _μGFX:

μGFX
~~~~~~~~~~~


作为最小、最快和最先进的嵌入式 GUI 库，广泛用于各类显示屏和触摸屏，可构建全功能嵌入式 GUI。µGFX 禁用所有未使用功能且不会将它们关联到已完成的二进制文件中，因而轻量级为其显著特点。此外，µGFX 还具有模块化，小巧轻便特点，而且为所有用户提供完整源代码。


相关平台
~~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - Name
      - :ref:`TouchGFX`
      - :ref:`LittlevGL`
      - :ref:`emWin`
      - :ref:`μGFX`
    * - :ref:`esp32`
      -
      - yes
      -
      - yes





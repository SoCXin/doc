
.. _pwr:

电源设计
============

.. contents::
    :local:


.. _ulp:

ULP
----------

.. contents::
    :local:

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - PWR
      - Standby
      - Stop
    * - :ref:`stm32l011`
      - 32MHz
      - 20 KB
      - 192 KB
      - 49 µA/MHz
      - 230 nA
      - 340 nA
    * - :ref:`stm32l412`
      - 80MHz
      - 40 KB
      - 128 KB
      - 28 μA/MHz
      - 195 nA
      - 340 nA
    * - :ref:`stm32h7b0`
      - 280 MHz
      - 1.4 MB
      - 128 KB
      - 120 µA/MHz
      - 2.2 µA
      - 32 µA


.. _usb_pd:

USB-PD
-------------

`USB PD <https://github.com/Qful/PD>`_ (USB Power Delivery)功率传输协议，USB功率2013年的新标准名为USBPD，USB PD 协议基于USB3.1，是USB3.1 中即type-c端口后提出的功率传输概念。可以为这种技术带来更大的灵活性，将充电能力扩大为目前的10倍：最高可达100瓦。

.. toctree::
    :maxdepth: 1

    CS32G020 <../M/CS32G020>

.. list-table::
    :header-rows:  1

    * - :ref:`list`
      - Core
      - RAM
      - Flash
      - UART
      - GPIO
      - Package
    * - :ref:`ch549`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      -
    * - :ref:`ch552`
      - :ref:`mcs51`
      - 1K
      - 8K
      - 2
      - 18
      -

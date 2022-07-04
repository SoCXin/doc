
.. _ethernet:

Ethernet
============

.. list-table::
    :header-rows:  1

    * - :ref:`ethernet`
      - :ref:`CoreMark`
      - SRAM/ROM
      - UART/SPI
      - USB/CAN
      - ETH-MAC
      - ETH-PHY
    * - :ref:`stm32f207`
      -
      - 128KB/512KB
      - 6/3
      - HSOTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`stm32f407`
      -
      - 192KB/1MB
      - 6/3
      - HSOTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`at32f407`
      -
      - 192KB/1MB
      - 8/3
      - OTG/2.0B
      - 100Mbps
      - NO
    * - :ref:`esp32`
      -
      - 520KB/4MB
      - 2/2
      -
      - 100Mbps
      - NO
    * - :ref:`ch579`
      -
      - 32KB/256KB
      - 4/2
      - OTG
      - 10Mbps
      - 10Mbps
    * - :ref:`ch32v307`
      -
      - 64KB/256KB
      - 8/3
      - HS-OTG/2.0B
      - 1000Mbps
      - 10Mbps



PHY
~~~~~~~~~~

LAN8720
^^^^^^^^^^^

LAN8742与LAN8720比较看，两者管脚兼容，LAN8742是LAN8720 的升级版，多了一个MCO管脚，其他的芯片特性一样，寄存器配置完全一样。

LAN8742和LAN8720的默认地址却是0x00

DP83848
^^^^^^^^^^^

DP83848芯片，支持MII模式和RMII模式；而LAN8742，和LAN8720，只支持RMII模式；另外，三者之间的，寄存器是一样的。

DP83848的默认地址，是0x01


.. _router:

Router
~~~~~~~~~~

.. list-table::
    :header-rows:  1

    * - :ref:`router`
      - :ref:`architecture`
      - :ref:`CoreMark`
      -
      - Switch
      - ETH-MAC
      - :ref:`wireless`
    * - :ref:`mt7622`
      - :ref:`cortex_a53`
      -
      -
      - 5p GbE
      - SGMII/RGMII
      - :ref:`wifi` + :ref:`bt`
    * - :ref:`mt7623`
      - :ref:`cortex_a7`
      -
      -
      - 5p GbE
      - SGMII/RGMII
      - :ref:`wifi`


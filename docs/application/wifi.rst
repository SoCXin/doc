
.. _wifi:

Wi-Fi
============
``802.11``

.. list-table::
    :header-rows:  1

    * - :ref:`vendor`
      - :ref:`new`
      - :ref:`hot`
      - :ref:`pop`
    * - Broadcom
      - 
      -
      -
    * - Qualcomm
      - 
      -
      -
    * - Marvell
      - 
      -
      -
    * - :ref:`mediatek`
      - 
      -
      -
    * - :ref:`ti`
      - 
      -
      -
    * - :ref:`silabs`
      - 
      -
      -
    * - :ref:`realtek`
      - 
      -
      -

    * - :ref:`espressif`
      - 
      -
      -
    * - :ref:`allwinner`
      - 
      -
      -
    * - 新岸线
      - 
      -
      -



.. _wifi4:

Wi-Fi4
-----------


.. list-table::
    :header-rows:  1

    * - :ref:`wifi4`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`sram`/:ref:`flash`
      - :ref:`link_budget`
      - :ref:`bandwidth`
      - :ref:`package`
    * - :ref:`esp32c3`
      - :ref:`esp_rv32`
      - 407.22
      - 400KB/384KB
      - 
      -
      - :ref:`esp_qfn32`
    * - :ref:`hi3861`
      - :ref:`riscv`
      -
      - 352KB/288KB
      -
      -
      - :ref:`QFN32`
    * - :ref:`esp32`
      - :ref:`xtensa_lx6`
      - 994.26
      - 520KB/448KB
      -
      -
      - :ref:`esp_qfn48`
    * - :ref:`esp32s2`
      - :ref:`xtensa_lx7`
      - 613.8
      - 320KB/128KB
      -
      -
      - :ref:`esp_qfn56`
    * - :ref:`esp32s3`
      - :ref:`xtensa_lx7`
      - 1181.6
      - 512KB/384KB
      -
      -
      - :ref:`esp_qfn56`
    * - :ref:`w800`
      - :ref:`xt804`
      -
      - 288KB/2 MB
      - 
      -
      - :ref:`QFN32`
    * - :ref:`w801`
      - :ref:`xt804`
      -
      - 288KB/2 MB
      -
      - 
      - :ref:`QFN56`
    * - :ref:`cc3200`
      - :ref:`cortex_m4`
      -
      - 256KB/2 MB
      -
      - 
      - :ref:`QFN56`
    * - :ref:`gd32w515`
      - :ref:`cortex_m33`
      -
      - 448KB/2 MB
      -
      -
      - :ref:`QFN56`


.. toctree::
    :maxdepth: 1

    W801 <../miscellaneous/W801>
    Hi3861 <../miscellaneous/Hi3861>
    SV32WB0 <../miscellaneous/SV32WB0>

.. _wifi6:

Wi-Fi6
-----------
``IEEE 802.11.ax``


.. list-table::
    :header-rows:  1

    * - :ref:`wifi6`
      - :ref:`architecture`
      - :ref:`CoreMark`
      - :ref:`sram`/:ref:`flash`
      - :ref:`link_budget`
      - :ref:`bandwidth`
      - :ref:`package`
    * - :ref:`esp32c5`
      - :ref:`esp_rv32`
      -
      - 400KB/384KB
      -
      -
      -
    * - :ref:`esp32c6`
      - :ref:`esp_rv32`
      -
      - 400KB/384KB
      -
      -
      -
    * - :ref:`aic8800`
      - :ref:`cortex_m4`
      -
      - 992KB/2 MB
      -
      -
      -



.. toctree::
    :maxdepth: 1

    AIC8800M <../miscellaneous/AIC8800M>
    SV32WB11 <../miscellaneous/SV32WB11>


.. image:: ./images/wifi.png

.. note::
    大部分WiFi通信芯片不仅具备WiFi接入能力，同时具备BLE连接能力，而且不断有新的厂商进入这一领域，用户的选择范围非常广。

Performance
--------------

.. _link_budget:

Link Budget
~~~~~~~~~~~~~~


.. _bandwidth:

Bandwidth
~~~~~~~~~~~~~~


.. image:: ./images/WiFi.jpg


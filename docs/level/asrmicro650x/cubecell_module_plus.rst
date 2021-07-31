
.. _board_asrmicro650x_cubecell_module_plus:

Heltec CubeCell-Module Plus (HTCC-AM02)
=======================================

.. contents::

Hardware
--------

Platform :ref:`platform_asrmicro650x`: ASR Microelectronics ASR650x series is highly intergrated and ultra low power SoC based on the PSoC 4000 series MCU (ARM Cortex M0+ Core) and Semtech SX1262 transceiver.

.. list-table::

  * - **Microcontroller**
    - ASR6502
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 128KB
  * - **RAM**
    - 16KB
  * - **Vendor**
    - `Heltec <https://heltec.org/project/htcc-am02/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``cubecell_module_plus`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:cubecell_module_plus]
  platform = asrmicro650x
  board = cubecell_module_plus

You can override default Heltec CubeCell-Module Plus (HTCC-AM02) settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `cubecell_module_plus.json <https://github.com/HelTecAutomation/platform-asrmicro650x/blob/master/boards/cubecell_module_plus.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:cubecell_module_plus]
  platform = asrmicro650x
  board = cubecell_module_plus

  ; change microcontroller
  board_build.mcu = asr6502

  ; change MCU frequency
  board_build.f_cpu = 48000000L

Debugging
---------
:ref:`mcs51` currently does not support Heltec CubeCell-Module Plus (HTCC-AM02) board.

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences

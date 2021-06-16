 
.. _board_ststm32_mkr_sharky:

MKR Sharky
==========

.. contents::

Hardware
--------

Platform :ref:`platform_ststm32`: The STM32 family of 32-bit Flash MCUs based on the ARM Cortex-M processor is designed to offer new degrees of freedom to MCU users. It offers a 32-bit product range that combines very high performance, real-time capabilities, digital signal processing, and low-power, low-voltage operation, while maintaining full integration and ease of development.

.. list-table::

  * - **Microcontroller**
    - STM32WB55CG
  * - **Frequency**
    - 64MHz
  * - **Flash**
    - 512KB
  * - **RAM**
    - 192.00KB
  * - **Vendor**
    - `Midatronics <https://midatronics.com/Development_Boards/MKR_Sharky_I?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``mkr_sharky`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:mkr_sharky]
  platform = ststm32
  board = mkr_sharky

You can override default MKR Sharky settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `mkr_sharky.json <https://github.com/platformio/platform-ststm32/blob/master/boards/mkr_sharky.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:mkr_sharky]
  platform = ststm32
  board = mkr_sharky

  ; change microcontroller
  board_build.mcu = stm32wb55cg

  ; change MCU frequency
  board_build.f_cpu = 64000000L


Uploading
---------
MKR Sharky supports the following uploading protocols:

* ``blackmagic``
* ``cmsis-dap``
* ``dfu``
* ``jlink``
* ``mbed``
* ``serial``

Default protocol is ``mbed``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:mkr_sharky]
  platform = ststm32
  board = mkr_sharky

  upload_protocol = mbed

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

MKR Sharky does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_blackmagic`
    - 
    - Yes
  * - :ref:`debugging_tool_cmsis-dap`
    - 
    - 
  * - :ref:`debugging_tool_jlink`
    - 
    - 

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_arduino`
      - Arduino Wiring-based Framework allows writing cross-platform software to control devices attached to a wide range of Arduino boards to create all kinds of creative coding, interactive objects, spaces or physical experiences
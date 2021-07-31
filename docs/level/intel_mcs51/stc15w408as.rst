
.. _board_intel_mcs51_stc15w408as:

Generic STC15W408AS
===================

.. contents::

Hardware
--------

Platform :ref:`platform_intel_mcs51`: The Intel MCS-51 (commonly termed 8051) is an internally Harvard architecture, complex instruction set computer (CISC) instruction set, single chip microcontroller (uC) series developed by Intel in 1980 for use in embedded systems.

.. list-table::

  * - **Microcontroller**
    - STC15W408AS
  * - **Frequency**
    - 11MHz
  * - **Flash**
    - 8KB
  * - **RAM**
    - 512B
  * - **Vendor**
    - `STC <https://www.stcmicro.com/STC/STC15W408AS.html?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``stc15w408as`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:stc15w408as]
  platform = intel_mcs51
  board = stc15w408as

You can override default Generic STC15W408AS settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `stc15w408as.json <https://github.com/platformio/platform-intel_mcs51/blob/master/boards/stc15w408as.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:stc15w408as]
  platform = intel_mcs51
  board = stc15w408as

  ; change microcontroller
  board_build.mcu = stc15w408as

  ; change MCU frequency
  board_build.f_cpu = 11059200L

Debugging
---------
:ref:`piodebug` currently does not support Generic STC15W408AS board.

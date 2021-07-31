
.. _board_intel_mcs51_stc89c52rc:

Generic STC89C52RC
==================

.. contents::

Hardware
--------

Platform :ref:`platform_intel_mcs51`: The Intel MCS-51 (commonly termed 8051) is an internally Harvard architecture, complex instruction set computer (CISC) instruction set, single chip microcontroller (uC) series developed by Intel in 1980 for use in embedded systems.

.. list-table::

  * - **Microcontroller**
    - STC89C52RC
  * - **Frequency**
    - 11MHz
  * - **Flash**
    - 8KB
  * - **RAM**
    - 512B
  * - **Vendor**
    - `STC <https://www.stcmicro.com/STC/STC89C52RC.html?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``stc89c52rc`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:stc89c52rc]
  platform = intel_mcs51
  board = stc89c52rc

You can override default Generic STC89C52RC settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `stc89c52rc.json <https://github.com/platformio/platform-intel_mcs51/blob/master/boards/stc89c52rc.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:stc89c52rc]
  platform = intel_mcs51
  board = stc89c52rc

  ; change microcontroller
  board_build.mcu = stc89c52rc

  ; change MCU frequency
  board_build.f_cpu = 11059200L

Debugging
---------
:ref:`mcs51` currently does not support Generic STC89C52RC board.

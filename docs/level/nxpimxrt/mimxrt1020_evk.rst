
.. _board_nxpimxrt_mimxrt1020_evk:

NXP i.MX RT1020 Evaluation Kit
==============================

.. contents::

Hardware
--------

Platform :ref:`platform_nxpimxrt`: The i.MX RT series of crossover processors features the Arm Cortex-M core, real-time functionality and MCU usability at a cost-effective price.

.. list-table::

  * - **Microcontroller**
    - MIMXRT1021DAG5A
  * - **Frequency**
    - 500MHz
  * - **Flash**
    - 8MB
  * - **RAM**
    - 32MB
  * - **Vendor**
    - `NXP <https://www.nxp.com/design/development-boards/i.mx-evaluation-and-development-boards/i.mx-rt1020-evaluation-kit:MIMXRT1020-EVK?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``mimxrt1020_evk`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:mimxrt1020_evk]
  platform = nxpimxrt
  board = mimxrt1020_evk

You can override default NXP i.MX RT1020 Evaluation Kit settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `mimxrt1020_evk.json <https://github.com/platformio/platform-nxpimxrt/blob/master/boards/mimxrt1020_evk.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:mimxrt1020_evk]
  platform = nxpimxrt
  board = mimxrt1020_evk

  ; change microcontroller
  board_build.mcu = mimxrt1021dag5a

  ; change MCU frequency
  board_build.f_cpu = 500000000L


Uploading
---------
NXP i.MX RT1020 Evaluation Kit supports the following uploading protocols:

* ``blackmagic``
* ``jlink``
* ``mbed``

Default protocol is ``mbed``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:mimxrt1020_evk]
  platform = nxpimxrt
  board = mimxrt1020_evk

  upload_protocol = mbed

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

NXP i.MX RT1020 Evaluation Kit has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_blackmagic`
    -
    -
  * - :ref:`debugging_tool_jlink`
    - Yes
    - Yes

Frameworks
----------
.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - :ref:`framework_zephyr`
      - The Zephyr Project is a scalable real-time operating system (RTOS) supporting multiple hardware architectures, optimized for resource constrained devices, and built with safety and security in mind

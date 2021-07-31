
.. _board_nordicnrf52_hackaBLE:

hackaBLE
========

.. contents::

Hardware
--------

Platform :ref:`platform_nordicnrf52`: The nRF52 Series are built for speed to carry out increasingly complex tasks in the shortest possible time and return to sleep, conserving precious battery power. They have a Cortex-M4F processor and are the most capable Bluetooth Smart SoCs on the market.

.. list-table::

  * - **Microcontroller**
    - NRF52832
  * - **Frequency**
    - 64MHz
  * - **Flash**
    - 512KB
  * - **RAM**
    - 64KB
  * - **Vendor**
    - `Electronut Labs <https://electronut.in/portfolio/hackaBLE/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``hackaBLE`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:hackaBLE]
  platform = nordicnrf52
  board = hackaBLE

You can override default hackaBLE settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `hackaBLE.json <https://github.com/platformio/platform-nordicnrf52/blob/master/boards/hackaBLE.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:hackaBLE]
  platform = nordicnrf52
  board = hackaBLE

  ; change microcontroller
  board_build.mcu = nrf52832

  ; change MCU frequency
  board_build.f_cpu = 64000000L


Uploading
---------
hackaBLE supports the following uploading protocols:

* ``blackmagic``
* ``cmsis-dap``
* ``jlink``
* ``nrfjprog``
* ``stlink``

Default protocol is ``jlink``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:hackaBLE]
  platform = nordicnrf52
  board = hackaBLE

  upload_protocol = jlink

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

hackaBLE does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

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
  * - :ref:`debugging_tool_stlink`
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

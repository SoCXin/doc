
.. _board_atmelsam_sodaq_explorer:

SODAQ ExpLoRer
==============

.. contents::

Hardware
--------

Platform :ref:`platform_atmelsam`: Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

.. list-table::

  * - **Microcontroller**
    - SAMD21J18A
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 32KB
  * - **Vendor**
    - `SODAQ <https://support.sodaq.com/sodaq-one/explorer/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``sodaq_explorer`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:sodaq_explorer]
  platform = atmelsam
  board = sodaq_explorer

You can override default SODAQ ExpLoRer settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `sodaq_explorer.json <https://github.com/platformio/platform-atmelsam/blob/master/boards/sodaq_explorer.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:sodaq_explorer]
  platform = atmelsam
  board = sodaq_explorer

  ; change microcontroller
  board_build.mcu = samd21j18a

  ; change MCU frequency
  board_build.f_cpu = 48000000L


Uploading
---------
SODAQ ExpLoRer supports the following uploading protocols:

* ``atmel-ice``
* ``blackmagic``
* ``jlink``
* ``sam-ba``

Default protocol is ``sam-ba``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:sodaq_explorer]
  platform = atmelsam
  board = sodaq_explorer

  upload_protocol = sam-ba

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

SODAQ ExpLoRer does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_atmel-ice`
    -
    - Yes
  * - :ref:`debugging_tool_blackmagic`
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

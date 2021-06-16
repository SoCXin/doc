 
.. _board_atmelsam_adafruit_rotarytrinkey_m0:

Adafruit Rotary Trinkey
=======================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelsam`: Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

.. list-table::

  * - **Microcontroller**
    - SAMD21E18A
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 32KB
  * - **Vendor**
    - `Adafruit <https://www.adafruit.com/product/4964?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``adafruit_rotarytrinkey_m0`` ID for :ref:`projectconf_env_board` option in :ref:`projectconf`:

.. code-block:: ini

  [env:adafruit_rotarytrinkey_m0]
  platform = atmelsam
  board = adafruit_rotarytrinkey_m0

You can override default Adafruit Rotary Trinkey settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `adafruit_rotarytrinkey_m0.json <https://github.com/platformio/platform-atmelsam/blob/master/boards/adafruit_rotarytrinkey_m0.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:adafruit_rotarytrinkey_m0]
  platform = atmelsam
  board = adafruit_rotarytrinkey_m0

  ; change microcontroller
  board_build.mcu = samd21e18a

  ; change MCU frequency
  board_build.f_cpu = 48000000L


Uploading
---------
Adafruit Rotary Trinkey supports the following uploading protocols:

* ``atmel-ice``
* ``blackmagic``
* ``jlink``
* ``sam-ba``

Default protocol is ``sam-ba``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:adafruit_rotarytrinkey_m0]
  platform = atmelsam
  board = adafruit_rotarytrinkey_m0

  upload_protocol = sam-ba

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`projectconf`.

Adafruit Rotary Trinkey does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

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
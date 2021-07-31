
.. _board_atmelsam_adafruit_itsybitsy_m4:

Adafruit ItsyBitsy M4
=====================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelsam`: Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

.. list-table::

  * - **Microcontroller**
    - SAMD51G19A
  * - **Frequency**
    - 120MHz
  * - **Flash**
    - 512KB
  * - **RAM**
    - 192KB
  * - **Vendor**
    - `Adafruit <https://www.adafruit.com/product/3800?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``adafruit_itsybitsy_m4`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:adafruit_itsybitsy_m4]
  platform = atmelsam
  board = adafruit_itsybitsy_m4

You can override default Adafruit ItsyBitsy M4 settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `adafruit_itsybitsy_m4.json <https://github.com/platformio/platform-atmelsam/blob/master/boards/adafruit_itsybitsy_m4.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:adafruit_itsybitsy_m4]
  platform = atmelsam
  board = adafruit_itsybitsy_m4

  ; change microcontroller
  board_build.mcu = samd51g19a

  ; change MCU frequency
  board_build.f_cpu = 120000000L


Uploading
---------
Adafruit ItsyBitsy M4 supports the following uploading protocols:

* ``atmel-ice``
* ``jlink``
* ``sam-ba``

Default protocol is ``sam-ba``

You can change upload protocol using :ref:`projectconf_upload_protocol` option:

.. code-block:: ini

  [env:adafruit_itsybitsy_m4]
  platform = atmelsam
  board = adafruit_itsybitsy_m4

  upload_protocol = sam-ba

Debugging
---------

:ref:`piodebug` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`debugging_tools` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

Adafruit ItsyBitsy M4 does not have on-board debug probe and **IS NOT READY** for debugging. You will need to use/buy one of external probe listed below.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_atmel-ice`
    -
    - Yes
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

    * - :ref:`framework_zephyr`
      - The Zephyr Project is a scalable real-time operating system (RTOS) supporting multiple hardware architectures, optimized for resource constrained devices, and built with safety and security in mind

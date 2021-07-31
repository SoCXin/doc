
.. _board_atmelsam_saml21_xpro_b:

Atmel SAML21-XPRO-B
===================

.. contents::

Hardware
--------

Platform :ref:`platform_atmelsam`: Atmel | SMART offers Flash- based ARM products based on the ARM Cortex-M0+, Cortex-M3 and Cortex-M4 architectures, ranging from 8KB to 2MB of Flash including a rich peripheral and feature mix.

.. list-table::

  * - **Microcontroller**
    - SAML21J18B
  * - **Frequency**
    - 48MHz
  * - **Flash**
    - 256KB
  * - **RAM**
    - 32KB
  * - **Vendor**
    - `Atmel <https://developer.mbed.org/platforms/SAML21-XPRO/?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``saml21_xpro_b`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:saml21_xpro_b]
  platform = atmelsam
  board = saml21_xpro_b

You can override default Atmel SAML21-XPRO-B settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `saml21_xpro_b.json <https://github.com/platformio/platform-atmelsam/blob/master/boards/saml21_xpro_b.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:saml21_xpro_b]
  platform = atmelsam
  board = saml21_xpro_b

  ; change microcontroller
  board_build.mcu = saml21j18b

  ; change MCU frequency
  board_build.f_cpu = 48000000L


Uploading
---------
Atmel SAML21-XPRO-B supports the following uploading protocols:

* ``atmel-ice``
* ``blackmagic``
* ``cmsis-dap``
* ``jlink``

Default protocol is ``cmsis-dap``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:saml21_xpro_b]
  platform = atmelsam
  board = saml21_xpro_b

  upload_protocol = cmsis-dap

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

Atmel SAML21-XPRO-B has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_atmel-ice`
    -
    -
  * - :ref:`debugging_tool_blackmagic`
    -
    -
  * - :ref:`debugging_tool_cmsis-dap`
    - Yes
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

    * - :ref:`framework_mbed`
      - Arm Mbed OS is an open source embedded operating system designed specifically for the 'things' in the Internet of Things. It includes all the features you need to develop a connected product based on an Arm Cortex-M microcontroller, including security, connectivity, an RTOS and drivers for sensors and I/O devices

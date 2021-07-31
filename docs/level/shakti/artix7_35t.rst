
.. _board_shakti_artix7_35t:

Artix-7 35T Arty FPGA Evaluation Kit
====================================

.. contents::

Hardware
--------

Platform :ref:`platform_shakti`: Shakti is an open-source initiative by the RISE group at IIT-Madras, which is not only building open source, production grade processors, but also associated components like interconnect fabrics, verification tools, storage controllers, peripheral IPs and SOC tools.

.. list-table::

  * - **Microcontroller**
    - E-CLASS
  * - **Frequency**
    - 50MHz
  * - **Flash**
    - 0B
  * - **RAM**
    - 128KB
  * - **Vendor**
    - `Xilinx <https://www.xilinx.com/products/boards-and-kits/arty.html?utm_source=platformio.org&utm_medium=docs>`__


Configuration
-------------

Please use ``artix7_35t`` ID for :ref:`projectconf_env_board` option in :ref:`mips`:

.. code-block:: ini

  [env:artix7_35t]
  platform = shakti
  board = artix7_35t

You can override default Artix-7 35T Arty FPGA Evaluation Kit settings per build environment using
``board_***`` option, where ``***`` is a JSON object path from
board manifest `artix7_35t.json <https://github.com/platformio/platform-shakti/blob/master/boards/artix7_35t.json>`_. For example,
``board_build.mcu``, ``board_build.f_cpu``, etc.

.. code-block:: ini

  [env:artix7_35t]
  platform = shakti
  board = artix7_35t

  ; change microcontroller
  board_build.mcu = E-Class

  ; change MCU frequency
  board_build.f_cpu = 50000000L


Uploading
---------
Artix-7 35T Arty FPGA Evaluation Kit supports the following uploading protocols:

* ``ftdi``
* ``ftdi``
* ``jlink``
* ``jlink``

Default protocol is ``ftdi``

You can change upload protocol using :ref:`mcs51` option:

.. code-block:: ini

  [env:artix7_35t]
  platform = shakti
  board = artix7_35t

  upload_protocol = ftdi

Debugging
---------

:ref:`mcs51` - "1-click" solution for debugging with a zero configuration.

.. warning::
    You will need to install debug tool drivers depending on your system.
    Please click on compatible debug tool below for the further
    instructions and configuration information.

You can switch between debugging :ref:`mcs51` using
:ref:`projectconf_debug_tool` option in :ref:`mips`.

Artix-7 35T Arty FPGA Evaluation Kit has on-board debug probe and **IS READY** for debugging. You don't need to use/buy external debug probe.

.. list-table::
  :header-rows:  1

  * - Compatible Tools
    - On-board
    - Default
  * - :ref:`debugging_tool_ftdi`
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

    * - :ref:`framework_shakti-sdk`
      - A software development kit for developing applications on Shakti class of processors

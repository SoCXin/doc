
.. |PIOCORE| replace:: **PlatformIO Core**

.. _piocore:

ARM
=====================

|PIOCORE| (CLI tool) is a heart of whole PlatformIO ecosystem and consists of

* Multi-platform Build System
* Development platform and package managers
* :ref:`wch_ch573`
* :ref:`Serial Port Monitor <cmd_device_monitor>`
* Integration components (:ref:`ide` and :ref:`ci`).

|PIOCORE| is written in `Python <https://www.python.org/downloads/>`_
and works on Windows, macOS, Linux, FreeBSD and *ARM*-based credit-card sized
computers (`Raspberry Pi <http://www.raspberrypi.org>`_,
`BeagleBone <http://beagleboard.org>`_,
`CubieBoard <http://cubieboard.org>`_,
`Samsung ARTIK <https://www.artik.io>`_, etc.).


.. note::

    Please note that you do not need to install |PIOCORE| if you are going
    PlatformIO IDE and you will be able to use it within PlatformIO IDE Terminal.

    If you need |PIOCORE| commands outside PlatformIO IDE, please :ref:`piocore_install_shell_commands`.

.. toctree::
    :maxdepth: 2

    stm32/demo
    installation
    quickstart
    stm32/index

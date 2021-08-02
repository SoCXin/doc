
.. _stc_stc8g:

STC8G
======


Installation
------------

.. note::

    Please note that you do not need to install :ref:`stm32` separately if
    you are going to use :ref:`stc_stc8g`. :ref:`stm32` is built into
    PlatformIO IDE and you will be able to use it within PlatformIO IDE Terminal.

0. `Download <https://code.visualstudio.com>`_ and install official Microsoft Visual Studio Code. PlatformIO IDE is built on top of it
1. **Open** VSCode Package Manager
2. **Search** for the official ``platformio ide`` `extension <https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide>`_
3. **Install** PlatformIO IDE.

.. image:: ../../_static/images/WCH/CH549.png

.. note::

    Please note that you need to install `a Git client <https://git-scm.com/book/v2/Getting-Started-Installing-Git>`_
    if you are going to use Git for installing upstream development platforms, cloning
    external projects, installing library dependencies from a repository, etc.

Options
-------

.. program:: pio run

.. option::
    -e, --environment

.. option::
    -t, --target

Process specified targets. Multiple targets are allowed.

.. option::
    --list-targets



.. _ide_vscode:

VSCode
======

.. include:: features.rst

---------

**Visual Studio Code** is a lightweight but
powerful source code editor which runs on your desktop and is available for
Windows, macOS and Linux. It comes with built-in support for JavaScript,
TypeScript and Node.js and has a rich ecosystem of extensions for other
languages (such as C++, C#, Python, PHP, Go) and runtimes (such as .NET and Unity)

.. image:: ../../_static/images/STC/vscode/platformio-ide-vscode.png
    :target: ../../_images/platformio-ide-vscode.png

.. contents:: Contents
    :local:

Installation
------------

.. note::

    Please note that you do not need to install :ref:`piocore` separately if
    you are going to use :ref:`ide_vscode`. :ref:`piocore` is built into
    PlatformIO IDE and you will be able to use it within PlatformIO IDE Terminal.

0. `Download <https://code.visualstudio.com>`_ and install official Microsoft Visual Studio Code. PlatformIO IDE is built on top of it
1. **Open** VSCode Package Manager
2. **Search** for the official ``platformio ide`` `extension <https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide>`_
3. **Install** PlatformIO IDE.

.. image:: ../../_static/images/STC/vscode/platformio-ide-vscode-pkg-installer.png

.. note::

    Please note that you need to install `a Git client <https://git-scm.com/book/en/v2/Getting-Started-Installing-Git>`_
    if you are going to use Git for installing upstream development platforms, cloning
    external projects, installing library dependencies from a repository, etc.


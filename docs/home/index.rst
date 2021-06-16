 
.. |PIOHOME| replace:: **PlatformIO Home**

.. _piohome:

PlatformIO Home
===============

|PIOHOME| is a powerful, modern, and interactive user interface (UI) for PlatformIO
collaborative platform. It's powered by `PlatformIO Labs's Modern UI Toolkit <https://www.soc.xin/technology/modern-ui-toolkit.html>`_
and contains the following key instruments:

* :ref:`pioaccount`
* Project Management
* :ref:`librarymanager`
* :ref:`platforms`, :ref:`frameworks`, and :ref:`boards` Management
* :ref:`Device Management <cmd_device>` (serial, logical, and multicast DNS services)
* Static Code Analysis
* Firmware File Explorer
* Firmware Memory Inspection
* Firmware Sections & Symbols Viewer.

.. contents:: Contents
    :local:

Installation
------------

You do not need to install |PIOHOME| separately, it's already built-in in
:ref:`pioide` and :ref:`piocore`.

Quick Start
-----------

PlatformIO IDE
~~~~~~~~~~~~~~

Please open |PIOHOME| using (HOME) button on PlatformIO Toolbar:

* **Atom**: :ref:`atom_ide_platformio_toolbar`
* **VSCode**: :ref:`ide_vscode_toolbar`

PlatformIO Core
~~~~~~~~~~~~~~~

Please launch |PIOHOME| Web-server using :ref:`cmd_home` command and open in
your browser http://127.0.0.1:8008.

You can change host and port. Please check :ref:`cmd_home` command for details.

Demo
----

Welcome & Project Manager
~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: ../_static/images/home/pio-home-welcome.png

Project Inspect
~~~~~~~~~~~~~~~

Statistics
''''''''''

.. image:: ../_static/images/home/pio-home-inspect-stats.png

Only code analysis (:ref:`piocheck`)

.. image:: ../_static/images/home/pio-home-inspect-stats-check.png

Firmware File Explorer
''''''''''''''''''''''

.. image:: ../_static/images/home/pio-home-inspect-firmware-file-explorer.png

File Symbols

.. image:: ../_static/images/home/pio-home-inspect-firmware-file-explorer-symbols.png

Firmware Symbols
''''''''''''''''

.. image:: ../_static/images/home/pio-home-inspect-firmware-symbols.png

Firmware Sections
'''''''''''''''''

.. image:: ../_static/images/home/pio-home-inspect-firmware-sections.png

Static Code Analysis
''''''''''''''''''''

.. image:: ../_static/images/home/pio-home-inspect-code-defects.png

Library Manager
~~~~~~~~~~~~~~~

.. image:: ../_static/images/home/pio-home-library-stats.png

Board Explorer
~~~~~~~~~~~~~~

.. image:: ../_static/images/home/pio-home-boards.png

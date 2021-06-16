 
.. _cmd_system_completion_uninstall:

pio system completion uninstall
===============================

.. contents::

Usage
-----

.. code-block:: bash

    pio system completion uninstall [OPTIONS]


Description
-----------

Uninstall shell completion files or code.

Options
~~~~~~~

.. program:: pio system completion uninstall

.. option::
    --shell

The shell type, default is ``auto`` and will be detected from a current shell session.

Supported shells are:

* `fish <https://fishshell.com/>`__
* `zsh <http://www.zsh.org/>`__
* `bash <https://www.gnu.org/software/bash>`__
* `powershell <https://msdn.microsoft.com/en-us/powershell/mt173057.aspx>`__

.. option::
    --path

Custom installation path of the code to be evaluated by the shell.
The standard installation path is used by default.

Examples
--------

.. code::

    > pio system completion uninstall

    PlatformIO CLI completion has been uninstalled for fish shell from ~/.config/fish/completions/pio.fish
    Please restart a current shell session.

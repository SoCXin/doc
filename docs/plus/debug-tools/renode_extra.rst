

Configuration
-------------

.. contents:: Contents
    :local:

You can configure Renode as a debugging tool using :ref:`projectconf_debug_tool` option in
:ref:`projectconf`:

.. code-block:: ini

    [env:myenv]
    platform = ...
    board = ...
    debug_tool = renode

More options:

* :ref:`projectconf_section_env_debug`

Installation
------------

We will automatically install for you the latest Renode package using PlatformIO
package manager. The only requirement is to install Mono/.NET framework.

:Windows:
  On Windows 7, download and install `.NET Framework 4.7 <https://www.microsoft.com/net/download/dotnet-framework-runtime>`_.
  Windows 10 ships with .NET by default, so no action is required there.

:Mac:
  Install `Homebrew <https://brew.sh/>`_ and the ``mono`` package using ``brew install mono``.

:Linux:
  Install the ``mono-complete`` package as per the installation instructions for
  various Linux distributions which can be found on `the Mono project website <https://www.mono-project.com/download/stable/#download-lin>`_.


Check the `official Renode installation guide <https://github.com/renode/renode/blob/master/README.rst>`_
for more details.


Custom Settings
---------------

If the default Renode configuration is not suitable for your project, it's possible to
override the default Renode flags in :ref:`projectconf`. The following sections describe
typical use cases where custom settings might be useful.

Additional Analyzers
~~~~~~~~~~~~~~~~~~~~

Additional analyzers might be handy in cases when an application prints output to a
peripheral which is not visible by default. For example, to open an additional UART
window while using Renode as the upload tool, a special command ``showAnalyzer`` should
be added to ``upload_flags`` option, e.g.:

.. code-block:: ini

  [env:hifive1-revb]
  platform = sifive
  framework = zephyr
  board = hifive1-revb
  ; Override the default upload settings
  upload_command = renode $UPLOAD_FLAGS
  upload_flags =
      -e include @scripts/single-node/sifive_fe310.resc
      -e showAnalyzer uart1
      -e sysbus LoadELF @$SOURCE
      -e start

Redirecting peripherals output
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

It might be useful to redirect output from device peripherals to a more convenient
communication channel. A typical example is redirecting UART output to a socket which
can be opened by :ref:`cmd_device_monitor` while using Renode as the debug tool.
The default debug flags can be overridden using the ``debug_server`` option. For
example, the following configuration can be used to redirect output from the ``UART0``
port on the ``hifive1-revb`` board:

.. code-block:: ini

  [env:hifive1-revb]
  platform = sifive
  framework = zephyr
  board = hifive1-revb
  ; Override the default debug settings
  debug_tool = custom
  debug_port = localhost:3333
  debug_server = renode
    --hide-log
    -e machine StartGdbServer 3333 True
    -e emulation CreateServerSocketTerminal 4321 "externalUART" false
    -e connector Connect uart0 externalUART
  debug_extra_cmds =
      monitor start

  # Monitor port for Renode level1
  monitor_port = socket://localhost:4321

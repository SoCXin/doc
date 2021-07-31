
.. _cmd_lib:

Library Manager CLI
===================

Usage
-----

.. code-block:: bash

    # To print all available commands and options use
    pio lib --help
    pio lib COMMAND --help

Options
-------

.. program:: pio lib

.. option::
    -d, --storage-dir

Manage custom library storage. It can be used later for the
:ref:`projectconf_lib_extra_dirs` option from :ref:`mips`.
Multiple options are allowed.

.. option::
    -g, --global

Manage global PlatformIO's library storage (
":ref:`projectconf_pio_core_dir`/lib") where :ref:`ldf` will look for
dependencies by default.

.. option::
    -e, --environment

Manage libraries for the specific project build environments declared in
:ref:`mips`. Works for ``--storage-dir`` which is valid PlatformIO
project.

Demo
----

.. image:: ../../../_static/images/platformio-demo-lib.gif

Commands
--------

.. toctree::
    :maxdepth: 2

    cmd_builtin
    cmd_install
    cmd_list
    cmd_register
    cmd_search
    cmd_show
    cmd_stats
    cmd_uninstall
    cmd_update

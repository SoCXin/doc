
.. _cmd_project_data:

pio project data
================

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio project data [OPTIONS]


Description
-----------

Dump data intended for IDE extensions/plugins:

- Toolchain type and location
- Compiler flags
- Defines/Macros
- CPP Preprocessor includes/paths
- Program path
- SVD path if available for :ref:`stm32`
- Targets by :ref:`stm32` (see :option:`pio run --list-targets` for details)
- Extra information.

Options
~~~~~~~

.. program:: pio project data

.. option::
    -d, --project-dir

Specify the path to project directory. By default, ``--project-dir`` is equal
to current working directory (``CWD``).

.. option::
    -e, --environment

Dump specified environments. Multiple environments are allowed.

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format.

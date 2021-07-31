 
.. _cmd_org_list:

pio org list
============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio org list [OPTIONS] [OWNER]

Description
-----------

List organizations and their owners.

Options
~~~~~~~

.. program:: pio org list

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format

Examples
--------

.. code-block:: bash

    > pio org list

    ...

    platformio
    ----------
    Display Name:  PlatformIO
    Owners:        alice, bob

    ...

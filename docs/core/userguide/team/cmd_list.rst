 
.. _cmd_team_list:

pio team list
=============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio team list [OPTIONS] [ORGNAME]

Description
-----------

List teams and their members.

Options
~~~~~~~

.. program:: pio team list

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format.

Examples
--------

.. code-block:: bash

    > pio team list

    platformio:dev
    ------------------------
    Description:  Developers team
    Members:      alice, bob

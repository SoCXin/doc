 
.. _cmd_team_create:

pio team create
===============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio team create [OPTIONS] ORGNAME:TEAMNAME

Description
-----------

Create a new team.

Options
~~~~~~~

.. program:: pio team create

.. option::
    --description

A team description.

Examples
--------

.. code-block:: bash

    > pio team create platformio:dev --description "Developers team"
    The team "dev" has been successfully created.

See Also
--------

* :ref:`cmd_team_list`
* :ref:`cmd_team_remove`

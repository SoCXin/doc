 
.. _cmd_team_update:

pio team update
===============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio team update [OPTIONS] ORGNAME:TEAMNAME

Description
-----------

Rename a team or update the existing details.

Options
~~~~~~~

.. program:: pio team update

.. option::
    --name

A new team name. Team name must only contain alphanumeric characters, single hyphens,
underscores, spaces. It can not begin or end with a hyphen or a underscore and must
not be longer than 20 characters.

.. option::
    --description

A team description.

Examples
--------

.. code-block:: bash

    > pio team update platformio:dev --description "Developers team"
    The team "dev" has been successfully updated.

See Also
--------

* :ref:`cmd_team_list`
* :ref:`cmd_team_remove`

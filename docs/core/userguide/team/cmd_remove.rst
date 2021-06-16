 
.. _cmd_team_remove:

pio team remove
===============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio team remove ORGNAME:TEAMNAME USERNAME

Description
-----------

Remove a member from a team.

If you need to destroy an existing team, please use :ref:`cmd_team_destroy` command.

Examples
--------

Remove Bob from the "dev" team of "platformio" organization:

.. code-block:: bash

    > pio team remove platformio:dev bob
    The "bob" member has been successfully removed from the "dev" team.

See Also
--------

* :ref:`cmd_team_add`
* :ref:`cmd_team_list`

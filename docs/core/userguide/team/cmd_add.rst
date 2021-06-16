 
.. _cmd_team_add:

pio team add
============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio team add ORGNAME:TEAMNAME USERNAME

Description
-----------

Add a new member to a team.

If you need to create a new team, please use :ref:`cmd_team_create` command.

Examples
--------

Add Bob to the "developers" team of "platformio" organization

.. code-block:: bash

    > pio team add platformio:developers bob
    The new member "bob" has been successfully added to the "developers" team.

See Also
--------

* :ref:`cmd_team_create`
* :ref:`cmd_team_list`
* :ref:`cmd_team_remove`

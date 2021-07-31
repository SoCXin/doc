 
.. _cmd_access:

pio access
==========

.. versionadded:: 5.0

Set access level on published resources (packages) in the registry.

You must have privileges to set the access of a resource:

* You are an owner of published resources
* You are a member of the team that owns a resource
* You have been given "maintainer" privileges for a package, either as a member of a team or directly as an owner.

Management of teams and team memberships is done with the :ref:`cmd_team` command.

To print all available commands and options use:

.. code-block:: bash

    pio access --help
    pio access COMMAND --help

.. toctree::
    :maxdepth: 2

    cmd_grant
    cmd_list
    cmd_private
    cmd_public
    cmd_revoke

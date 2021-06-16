 
.. _cmd_org_add:

pio org add
===========

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio org add ORGNAME USERNAME

Description
-----------

Add a user as an owner to an organization.

If you need to create a new organization, please use :ref:`cmd_org_create` command.

Examples
--------

Add Bob as an owner of "platformio" organization:

.. code-block:: bash

    > pio org add platformio bob
    The new owner "bob" has been successfully added to the "platformio" organization.

See Also
--------

* :ref:`cmd_org_create`
* :ref:`cmd_org_list`
* :ref:`cmd_org_remove`

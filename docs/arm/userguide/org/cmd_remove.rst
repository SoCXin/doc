 
.. _cmd_org_remove:

pio org remove
==============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio org remove ORGNAME USERNAME

Description
-----------

Remove a user from an organization.

If you need to destroy an existing organization, please use :ref:`cmd_org_destroy` command.

Examples
--------

Remove Bob from "platformio" organization:

.. code-block:: bash

    > pio org remove platformio bob
    The `bob` owner has been successfully removed from the `platformio` organization.

See Also
--------

* :ref:`cmd_org_add`
* :ref:`cmd_org_list`

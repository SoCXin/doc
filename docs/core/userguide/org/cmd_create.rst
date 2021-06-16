 
.. _cmd_org_create:

pio org create
==============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio org create [OPTIONS] ORGNAME

Description
-----------

Create a new organization.

Options
~~~~~~~

.. program:: pio org create

.. option::
    --email

An organization e-mail.

.. option::
    --displayname

An organization display name (company name).

Examples
--------

.. code-block:: bash

    > pio org create platformio --email contact@platformio.org --displayname PlatformIO
    The organization "platformio" has been successfully created.

See Also
--------

* :ref:`cmd_org_list`
* :ref:`cmd_org_remove`

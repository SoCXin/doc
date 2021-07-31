 
.. _cmd_org_update:

pio org update
==============

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio org update [OPTIONS] ORGNAME

Description
-----------

Rename the organization or update the existing details.

Options
~~~~~~~

.. program:: pio org update

.. option::
    --orgname

New organization "orgname". Must contain only alphanumeric characters or single
hyphens, cannot begin or end with a hyphen, and must not be longer than 38 characters.

.. option::
    --email

An organization e-mail.

.. option::
    --displayname

An organization name (company name).

Examples
--------

.. code-block:: bash

    > pio org update platformio --email contact@platformio.org --displayname PlatformIO
    The organization "platformio" has been successfully updated.

See Also
--------

* :ref:`cmd_org_list`
* :ref:`cmd_org_remove`

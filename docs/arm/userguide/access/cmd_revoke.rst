 
.. _cmd_access_revoke:

pio access revoke
=================

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio access revoke [OPTIONS] <ORGNAME:TEAMNAME>|<USERNAME> URN

Description
-----------

Remove the ability of users and teams to have access to a resource.

You can revoke access for the team members using the next format ``orgname:teamname``.

See the examples below.

Options
~~~~~~~

.. program:: pio access revoke

.. option::
    --urn-type

Resource type in `URN <https://en.wikipedia.org/wiki/Uniform_Resource_Name>`_ form.
Default is set to ``prn:reg:pkg`` which means to grant an access to the package in
the registry.

Examples
--------

1. Revoke access from a resource for the "bob" user:

.. code-block:: bash

    > pio access revoke bob prn:reg:pkg:8036:platform
    Access for resource "prn:reg:pkg:8036:platform" has been revoked for "bob"

2. Add the ability of PlatformIO's "developer" team to have "admin" access to a resource.

.. code-block:: bash

    > pio access revoke platformio:developers prn:reg:pkg:8036:platform
    Access for resource "prn:reg:pkg:8036:platform" has been revoked for "platformio:developers"

See Also
--------

* :ref:`cmd_access_grant`

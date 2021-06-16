 
.. _cmd_package_unpublish:

pio package unpublish
=====================

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio package unpublish [<organization>/]<pkgname>[@<version>] [OPTIONS]

Description
-----------

This removes a package version from the registry, deleting its entry and removing the
tarball.

If no version is specified, or if all versions are removed then the root package entry
is removed from the registry entirely.

You can only remove a package version within 72 hours since the published date.

Options
~~~~~~~

.. program:: pio package unpublish

.. option::
    --type

Set the type of a package to unpublish (if you have packages with the same name).
Possible values are ``library``, ``platform``, or ``tool``. The default is set to ``library``.

.. option::
    --undo

Undo a remove, putting a version back into the registry.

See Also
--------

* :ref:`library_json`
* :ref:`cmd_package_pack`
* :ref:`cmd_package_publish`

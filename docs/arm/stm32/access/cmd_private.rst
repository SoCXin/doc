 
.. _cmd_access_private:

pio access private
==================

.. versionadded:: 5.0

.. contents::

Usage
-----

.. code-block:: bash

    pio access private [OPTIONS] URN

Description
-----------

Set a resource to be either privately accessible (restricted access to particular
users or team members).

Options
~~~~~~~

.. program:: pio access private

.. option::
    --urn-type

Resource type in `URN <https://en.wikipedia.org/wiki/Uniform_Resource_Name>`_ form.
Default is set to ``prn:reg:pkg`` which means to grant access to the package in
the registry.

Examples
--------

.. code-block:: bash

    > pio access private prn:reg:pkg:8036:platform
    The resource "prn:reg:pkg:8036:platform" has been successfully updated.

See Also
--------

* :ref:`cmd_access_public`

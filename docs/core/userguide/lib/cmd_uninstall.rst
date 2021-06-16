 
.. _cmd_lib_uninstall:

pio lib uninstall
=================

.. contents::

Usage
-----

.. code-block:: bash

    pio lib [STORAGE_OPTIONS] uninstall [LIBRARY...]

    # uninstall project dependent library
    # (run it from a project root where is located "platformio.ini")
    pio lib uninstall [LIBRARY...]

    # uninstall dependencies for the specific project environment
    # (run it from a project root where is located "platformio.ini")
    pio lib -e myenv uninstall [OPTIONS] [LIBRARY...]
    pio lib -d /path/to/platformio/project -e myenv uninstall [OPTIONS] [LIBRARY...]

    # uninstall library from global storage
    pio lib --global uninstall [LIBRARY...]
    pio lib -g uninstall [LIBRARY...]

    # uninstall library from custom storage
    pio lib --storage-dir /path/to/dir uninstall [LIBRARY...]
    pio lib -d /path/to/dir uninstall [LIBRARY...]

    # [LIBRARY...] forms
    pio lib [STORAGE_OPTIONS] uninstall <id>
    pio lib [STORAGE_OPTIONS] uninstall <id>@<version>
    pio lib [STORAGE_OPTIONS] uninstall <id>@<version range>
    pio lib [STORAGE_OPTIONS] uninstall <name>
    pio lib [STORAGE_OPTIONS] uninstall <name>@<version>
    pio lib [STORAGE_OPTIONS] uninstall <name>@<version range>

Description
-----------

Uninstall specified library

The ``version`` supports `Semantic Versioning <https://devhints.io/semver>`_ (
``<major>.<minor>.<patch>``) and can take any of the following forms:

* ``1.2.3`` - an exact version number. Use only this exact version
* ``^1.2.3`` - any compatible version (exact version for ``1.x.x`` versions)
* ``~1.2.3`` - any version with the same major and minor versions, and an
  equal or greater patch version
* ``>1.2.3`` - any version greater than ``1.2.3``. ``>=``, ``<``, and ``<=``
  are also possible
* ``>0.1.0,!=0.2.0,<0.3.0`` - any version greater than ``0.1.0``, not equal to
  ``0.2.0`` and less than ``0.3.0``

Storage Options
---------------

See base options for :ref:`cmd_lib`.

Options
-------

.. program:: pio lib uninstall

.. option::
    --save / --no-save

Remove libraries from the :ref:`projectconf` dependency list
(:ref:`projectconf_lib_deps`) and save changes. Default value is to save.


.. option::
    -s, --silent

Suppress progress reporting.

.. option::
    -f, --force

Reinstall library if it is already installed.

Examples
--------

.. code::

    > pio lib -g uninstall AsyncMqttClient

    Library Storage: /storage/dir/...
    Uninstalling AsyncMqttClient @ 0.2.0:   [OK]

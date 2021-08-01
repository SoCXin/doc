 
.. _cmd_platform_uninstall:

pio platform uninstall
======================

.. contents::

Usage
-----

.. code-block:: bash

    pio platform uninstall [PLATFORM...]

    # uninstall specific platform version using Semantic Versioning
    pio platform uninstall PLATFORM@X.Y.Z


Description
-----------

Uninstall specified :ref:`platforms`


Examples
--------

.. code::

    > pio platform uninstall atmelavr
    Uninstalling platform atmelavr @ 0.0.0:    [OK]
    Uninstalling package tool-scons @ 2.4.1:    [OK]
    Uninstalling package toolchain-atmelavr @ 1.40801.0:    [OK]
    The platform 'atmelavr' has been successfully uninstalled!

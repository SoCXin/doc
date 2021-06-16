 
.. _platform_windows_x86:

Windows x86
===========

:Configuration:
  :ref:`projectconf_env_platform` = ``windows_x86``

Windows x86 (32-bit) is a metafamily of graphical operating systems developed and marketed by Microsoft. Using host OS (Windows, Linux 32/64 or Mac OS X) you can build native application for Windows x86 platform.

For more detailed information please visit `vendor site <http://platformio.org/platforms/windows_x86?utm_source=platformio.org&utm_medium=docs>`_.

.. contents:: Contents
    :local:
    :depth: 1


Examples
--------

Examples are listed from `Windows x86 development platform repository <https://github.com/platformio/platform-windows_x86/tree/master/examples?utm_source=platformio.org&utm_medium=docs>`_:

* `hello-world <https://github.com/platformio/platform-windows_x86/tree/master/examples/hello-world?utm_source=platformio.org&utm_medium=docs>`_

Stable and upstream versions
----------------------------

You can switch between `stable releases <https://github.com/platformio/platform-windows_x86/releases>`__
of Windows x86 development platform and the latest upstream version using
:ref:`projectconf_env_platform` option in :ref:`projectconf` as described below.

Stable
~~~~~~

.. code-block:: ini

    ; Latest stable version
    [env:latest_stable]
    platform = windows_x86
    board = ...

    ; Custom stable version
    [env:custom_stable]
    platform = windows_x86@x.y.z
    board = ...

Upstream
~~~~~~~~

.. code-block:: ini

    [env:upstream_develop]
    platform = https://github.com/platformio/platform-windows_x86.git
    board = ...


Packages
--------

.. list-table::
    :header-rows:  1

    * - Name
      - Description

    * - `toolchain-gccmingw32 <http://www.mingw.org?utm_source=platformio.org&utm_medium=docs>`__
      - MinGW - Minimalist GNU for Windows
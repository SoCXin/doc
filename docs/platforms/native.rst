 
.. _platform_native:

Native
======

:Configuration:
  :ref:`projectconf_env_platform` = ``native``

Native development platform is intended to be used for desktop OS. This platform uses built-in toolchains (preferable based on GCC), frameworks, libs from particular OS where it will be run.

For more detailed information please visit `vendor site <http://platformio.org/platforms/native?utm_source=platformio.org&utm_medium=docs>`_.

.. contents:: Contents
    :local:
    :depth: 1


Examples
--------

Examples are listed from `Native development platform repository <https://github.com/platformio/platform-native/tree/master/examples?utm_source=platformio.org&utm_medium=docs>`_:

* `hello-world <https://github.com/platformio/platform-native/tree/master/examples/hello-world?utm_source=platformio.org&utm_medium=docs>`_

Stable and upstream versions
----------------------------

You can switch between `stable releases <https://github.com/platformio/platform-native/releases>`__
of Native development platform and the latest upstream version using
:ref:`projectconf_env_platform` option in :ref:`projectconf` as described below.

Stable
~~~~~~

.. code-block:: ini

    ; Latest stable version
    [env:latest_stable]
    platform = native
    board = ...

    ; Custom stable version
    [env:custom_stable]
    platform = native@x.y.z
    board = ...

Upstream
~~~~~~~~

.. code-block:: ini

    [env:upstream_develop]
    platform = https://github.com/platformio/platform-native.git
    board = ...

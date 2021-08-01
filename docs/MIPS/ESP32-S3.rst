
.. _espressif_esp32s3:

ESP32-S3
----------------

.. _projectconf_env_extends:

``extends``
^^^^^^^^^^^

Type: ``String`` | Multiple: ``Yes``

This option allows one to inherit configuration from other sections or build environments
in :ref:`mips`. Multiple items are allowed, split them with ``,`` or
with a new line.

Example:

.. code-block:: ini

    [strict_ldf]
    lib_ldf_mode = chain+
    lib_compat_mode = strict

    [espressi32_base]
    platform = espressif32
    framework = arduino


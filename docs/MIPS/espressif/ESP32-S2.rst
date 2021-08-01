
.. _espressif_esp32s2:

ESP32-S2
---------------

.. contents::
    :local:

.. _projectconf_monitor_port:

``monitor_port``
^^^^^^^^^^^^^^^^

Type: ``String`` | Multiple: ``No``

Please note that you can use Unix shell-style wildcards:

.. list-table::
    :header-rows:  1

    * - Pattern
      - Meaning

    * - ``*``
      - matches everything

    * - ``?``
      - matches any single character

    * - ``[seq]``
      - matches any character in seq

    * - ``[!seq]``
      - matches any character not in seq

Example:

.. code-block:: ini

    [env:custom_monitor_port]
    ...
    ; Unix
    monitor_port = /dev/ttyUSB1

    ; Windows, COM1 or COM3
    monitor_port = COM[13]

    ; Socket
    monitor_port = socket://localhost:4444

.. _projectconf_monitor_speed:

``monitor_speed``
^^^^^^^^^^^^^^^^^

Type: ``Number`` | Multiple: ``No`` | Default: ``9600``

A monitor speed (`baud rate <http://en.wikipedia.org/wiki/Baud>`_).

Example:

.. code-block:: ini

    [env:custom_monitor_speedrate]
    ...
    monitor_speed = 115200

.. _projectconf_monitor_filters:

``monitor_filters``
^^^^^^^^^^^^^^^^^^^

Type: ``String`` | Multiple: ``Yes``


Example:

.. code-block:: ini

    [env:log_output_to_file_with_timestamp]
    ...
    platform = ...
    monitor_filters = log2file, time, default

.. _projectconf_monitor_rts:

``monitor_rts``
^^^^^^^^^^^^^^^

Type: ``Number (0 or 1)`` | Multiple: ``No``

.. _projectconf_monitor_dtr:

``monitor_dtr``
^^^^^^^^^^^^^^^

Example:

.. code-block:: ini

    [env:extra_monitor_flags]
    platform = ...
    board = ...
    monitor_flags=
        --parity
        N
        --encoding
        hexlify

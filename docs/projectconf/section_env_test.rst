 
.. _projectconf_section_env_test:

Test options
------------

.. seealso::
    Please make sure to read :ref:`unit_testing` guide first.

.. contents::
    :local:

.. _projectconf_test_filter:

``test_filter``
^^^^^^^^^^^^^^^

Type: ``String (Pattern)`` | Multiple: ``Yes``

Process only the :ref:`unit_testing` tests where the name matches specified
patterns.

Also, you can filter some tests using :option:`pio test --filter` command.

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

**Example**

.. code-block:: ini

  [env:myenv]
  test_filter = footest, bartest_*, test[13]

.. _projectconf_test_ignore:

``test_ignore``
^^^^^^^^^^^^^^^

Type: ``String (Pattern)`` | Multiple: ``Yes``

Ignore :ref:`unit_testing` tests where the name matches specified patterns.

Also, you can ignore some tests using :option:`pio test --ignore` command.

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

**Example**

.. code-block:: ini

  [env:myenv]
  test_ignore =
    footest
    bartest_*
    test[13]

.. _projectconf_test_port:

``test_port``
^^^^^^^^^^^^^

Type: ``String (Pattern)`` | Multiple: ``No``

This option specifies communication interface (Serial/UART) between PlatformIO
:ref:`unit_testing` Engine and target device. For example,

* ``/dev/ttyUSB0`` - Unix-based OS
* ``COM3`` - Windows OS

If ``test_port`` isn't specified, then *PlatformIO* will try to detect it
automatically.

To print all available serial ports use :ref:`cmd_device_list` command.

.. _projectconf_test_speed:

``test_speed``
^^^^^^^^^^^^^^

Type: ``Number`` | Multiple: ``No`` | Default: ``115200``

A connection speed (`baud rate <http://en.wikipedia.org/wiki/Baud>`_)
to communicate with a target device.

.. _projectconf_test_transport:

``test_transport``
^^^^^^^^^^^^^^^^^^

Type: ``String`` | Multiple: ``No``

A transport type which will be used to read test results from a target device.
See more details at :ref:`unit_testing_transport`.

.. _projectconf_test_build_project_src:

``test_build_project_src``
^^^^^^^^^^^^^^^^^^^^^^^^^^

Type: ``Bool (yes or no)`` | Multiple: ``No`` | Default: ``no``

Force :ref:`unit_testing` engine to build project source code from
:ref:`projectconf_pio_src_dir` setting ``test_build_project_src`` to ``yes``.
More detail about :ref:`unit_testing_shared_code`.

**Example**

.. code-block:: ini

  [env:myenv]
  platform = ...
  test_build_project_src = yes

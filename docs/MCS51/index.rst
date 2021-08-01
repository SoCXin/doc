

.. _mcs51:

MCS51
-------------------------------

A `compilation database <https://clang.llvm.org/docs/JSONCompilationDatabase.html>`_ is
a `JSON-formatted <https://www.json.org/>`_ file named ``compile_commands.json`` that
contains structured data about every compilation unit in your project.

:ref:`arm` supports generating of compilation database using
:option:`pio run --target` command and ``compiledb`` target. For example,

.. code::

  > pio run -t compiledb


A default path for ``compile_commands.json`` is ":ref:`mcs51`/envname".
You can override this path with :ref:`mcs51` and
``COMPILATIONDB_PATH`` environment variable. For example, generate ``compile_commands.json``
in a root of project:


``platformio.ini``:

.. code-block:: ini

    [env:myenv]
    platform = ...
    board = ...
    extra_scripts = post:extra_script.py


``extra_script.py``:

.. code-block:: python

    import os
    Import("env")

    env.Replace(COMPILATIONDB_PATH=os.path.join("$PROJECT_DIR", "compile_commands.json"))

Options
-------

.. program:: pio run

.. option::
    -e, --environment

.. option::
    -t, --target

Process specified targets. Multiple targets are allowed.

.. option::
    --list-targets

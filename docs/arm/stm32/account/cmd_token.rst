
.. _cmd_account_token:

pio account token
=================

.. contents::

Usage
-----

.. code-block:: bash

    pio account token

Description
-----------

Get or regenerate Personal Authentication Token. It is very useful for :ref:`ci`
systems, :ref:`mcs51` operations where you are not able to authorize manually.

PlatformIO handles Personal Authentication Token from environment variable
:envvar:`PLATFORMIO_AUTH_TOKEN`.

Options
~~~~~~~

.. program:: pio account token

.. option::
    --regenerate

    If this option is specified a new authentication token will be generated.

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format

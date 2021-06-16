 
.. _cmd_account_register:

pio account register
====================

.. contents::

Usage
-----

.. code-block:: bash

    pio account register [OPTIONS]

Description
-----------

Create a new :ref:`pioaccount`.

Options
~~~~~~~

You can omit these options and enter them later in Register Wizard.

.. program:: pio account register

.. option::
    --username, -u

A username. You can use it later for :ref:`cmd_account_login`,
:ref:`cmd_account_update`, and :ref:`cmd_account_forgot` commands.

The username must contain at least 4 characters including single hyphens, and cannot
begin or end with a hyphen.

.. option::
    --email, -e

An email. Please enter existing email, you will receive a confirmation letter.

.. option::
    --password, -p

A password. You will need it for :ref:`cmd_account_login`,
:ref:`cmd_account_password`, :ref:`cmd_account_token`, and :ref:`cmd_account_update`
commands.

.. option::
    --firstname

A first name.

.. option::
    --lastname

A last name.

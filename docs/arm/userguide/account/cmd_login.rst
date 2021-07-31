 
.. _cmd_account_login:

pio account login
=================

.. contents::

Usage
-----

.. code-block:: bash

    pio account login [OPTIONS]

Description
-----------

Log in to :ref:`pioaccount`. If you are not able to provide authentication
credentials manually you can use :envvar:`PLATFORMIO_AUTH_TOKEN`. This is
very useful for :ref:`ci` systems and :ref:`pioremote` operations.

Options
~~~~~~~

.. program:: pio account login

.. option::
    --username, -u

Username or email. You can omit this option and enter username or email in Login Wizard
later.

.. option::
    --password, -p

You can omit this option and enter securely password in Login Wizard later.

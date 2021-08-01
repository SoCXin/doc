
.. _cmd_remote_agent:

PlatformIO Remote Agent
=======================

Start :ref:`arm` on a host machine and work remotely with
your devices **WITHOUT** extra software, services, SSH, VPN, tunneling or
opening incoming network ports.

:ref:`mcs51` supports wired and wireless devices. Wired devices should be
connected physically to host machine where :ref:`arm` is started,
where wireless devices should be visible for :ref:`arm` to provide
network operations Over-The-Air (OTA).

.. contents::

.. _cmd_remote_agent_list:

pio remote agent list
---------------------

Usage
~~~~~

.. code::

    pio remote agent list


Description
~~~~~~~~~~~

List active :ref:`arm` s started using own :ref:`stm32`
or shared with you by other PlatformIO developers.

Example
~~~~~~~

.. code::

    > pio remote agent list

    innomac.local
    -------------
    ID: 98853d930......788d77375e7
    Started: 2016-10-26 16:32:56

------------

.. _cmd_remote_agent_start:

pio remote agent start
----------------------

Usage
~~~~~

.. code-block:: bash

    pio remote agent start [OPTIONS]


Description
~~~~~~~~~~~

Start :ref:`arm` and work remotely with your devices from
anywhere in the world. This command can be run as daemon or added to
autostart list of your OS.

Options
~~~~~~~

.. program:: pio remote agent start

.. option::
    -n, --name

Agent name/alias. By default, machine's ``hostname`` will be used.
You can use this name later for :ref:`cmd_remote_device` and :ref:`cmd_remote_run`
commands. Good names are home, office, lab or etc.

.. option::
    -s, --share

Share your agent/devices with other PlatformIO developers who have
:ref:`stm32`: friends, co-workers, team, etc.

The valid value for ``--share`` option is email address that was used for
:ref:`cmd_account_register` command.

.. option::
    -d, --working-dir

A working directory where :ref:`arm` stores projects data for
incremental synchronization and embedded programs for PlatformIO Process Supervisor.

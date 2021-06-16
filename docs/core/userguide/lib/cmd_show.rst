 
.. _cmd_lib_show:

pio lib show
============

.. contents::

Usage
-----

.. code-block:: bash

    pio lib show [LIBRARY]


Description
-----------

Show detailed info about a library using
`PlatformIO Library Registry <https://www.soc.xin/lib>`_.

The possible values for ``[LIBRARY]``:

* Library ID from Registry (preferred)
* Library Name

Options
-------

.. program:: pio lib show

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format

Examples
--------

.. code::

    > pio lib show OneWire

    PubSubClient
    ============
    #ID: 89
    A client library for MQTT messaging. MQTT is a lightweight messaging protocol ideal for small devices. This library allows you to send and receive MQTT messages. It supports the latest MQTT 3.1.1 protocol and can be configured to use the older MQTT 3.1...

    Version: 2.6, released 10 months ago
    Manifest: https://raw.githubusercontent.com/ivankravets/pubsubclient/patch-2/library.json
    Homepage: http://pubsubclient.knolleary.net
    Repository: https://github.com/knolleary/pubsubclient.git

    Authors
    -------
    Nick O'Leary https://github.com/knolleary

    Keywords
    --------
    ethernet
    mqtt
    iot
    m2m

    Compatible frameworks
    ---------------------
    Arduino

    Compatible platforms
    --------------------
    Atmel AVR
    Atmel SAM
    Espressif 8266
    Intel ARC32
    Microchip PIC32
    Nordic nRF51
    Teensy
    TI MSP430

    Headers
    -------
    PubSubClient.h

    Examples
    --------
    http://dl.platformio.org/libraries/examples/0/89/mqtt_auth.ino
    http://dl.platformio.org/libraries/examples/0/89/mqtt_basic.ino
    http://dl.platformio.org/libraries/examples/0/89/mqtt_esp8266.ino
    http://dl.platformio.org/libraries/examples/0/89/mqtt_publish_in_callback.ino
    http://dl.platformio.org/libraries/examples/0/89/mqtt_reconnect_nonblocking.ino
    http://dl.platformio.org/libraries/examples/0/89/mqtt_stream.ino

    Versions
    --------
    2.6, released 10 months ago

    Downloads
    ---------
    Today: 25
    Week: 120
    Month: 462

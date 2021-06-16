 
.. _cmd_lib_stats:

pio lib stats
=============

.. contents::

Usage
-----

.. code-block:: bash

    pio lib stats


Description
-----------

Show PlatformIO Library Registry statistics:

* Recently updated
* Recently added
* Recent keywords
* Popular keywords
* Featured: Today
* Featured: Week
* Featured: Month

This information is the same that is shown on this page:

* https://www.soc.xin/lib

Options
-------

.. program:: pio lib show

.. option::
    --json-output

Return the output in `JSON <http://en.wikipedia.org/wiki/JSON>`_ format

Examples
--------

.. code::

    RECENTLY UPDATED
    ****************
    Name                     Date                    Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    GroveEncoder             12 hours ago            https://www.soc.xin/lib/show/1382/GroveEncoder
    RF24G                    12 hours ago            https://www.soc.xin/lib/show/1381/RF24G
    Sim800L Library Revised  12 hours ago            https://www.soc.xin/lib/show/1380/Sim800L%20Library%20Revised
    ArduinoSTL               12 hours ago            https://www.soc.xin/lib/show/750/ArduinoSTL
    hd44780                  13 hours ago            https://www.soc.xin/lib/show/738/hd44780

    RECENTLY ADDED
    **************
    Name                     Date                    Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    GroveEncoder             12 hours ago            https://www.soc.xin/lib/show/1382/GroveEncoder
    RF24G                    12 hours ago            https://www.soc.xin/lib/show/1381/RF24G
    Sim800L Library Revised  12 hours ago            https://www.soc.xin/lib/show/1380/Sim800L%20Library%20Revised
    DS3231                   a day ago               https://www.soc.xin/lib/show/1379/DS3231
    ArduboyPlaytune          4 days ago              https://www.soc.xin/lib/show/1378/ArduboyPlaytune

    RECENT KEYWORDS
    ***************
    Name                     Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    cobs                     https://www.soc.xin/lib/search?query=keyword%3Acobs
    packet                   https://www.soc.xin/lib/search?query=keyword%3Apacket
    framing                  https://www.soc.xin/lib/search?query=keyword%3Aframing
    3g                       https://www.soc.xin/lib/search?query=keyword%3A3g
    tdd                      https://www.soc.xin/lib/search?query=keyword%3Atdd

    POPULAR KEYWORDS
    ****************
    Name                     Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    display                  https://www.soc.xin/lib/search?query=keyword%3Adisplay
    lcd                      https://www.soc.xin/lib/search?query=keyword%3Alcd
    sensors                  https://www.soc.xin/lib/search?query=keyword%3Asensors
    graphics                 https://www.soc.xin/lib/search?query=keyword%3Agraphics
    communication            https://www.soc.xin/lib/search?query=keyword%3Acommunication
    oled                     https://www.soc.xin/lib/search?query=keyword%3Aoled
    tft                      https://www.soc.xin/lib/search?query=keyword%3Atft
    control                  https://www.soc.xin/lib/search?query=keyword%3Acontrol
    device                   https://www.soc.xin/lib/search?query=keyword%3Adevice
    glcd                     https://www.soc.xin/lib/search?query=keyword%3Aglcd
    displaycore              https://www.soc.xin/lib/search?query=keyword%3Adisplaycore
    font                     https://www.soc.xin/lib/search?query=keyword%3Afont
    other                    https://www.soc.xin/lib/search?query=keyword%3Aother
    i2c                      https://www.soc.xin/lib/search?query=keyword%3Ai2c
    input                    https://www.soc.xin/lib/search?query=keyword%3Ainput
    signal                   https://www.soc.xin/lib/search?query=keyword%3Asignal
    sensor                   https://www.soc.xin/lib/search?query=keyword%3Asensor
    output                   https://www.soc.xin/lib/search?query=keyword%3Aoutput
    spi                      https://www.soc.xin/lib/search?query=keyword%3Aspi
    data                     https://www.soc.xin/lib/search?query=keyword%3Adata
    timing                   https://www.soc.xin/lib/search?query=keyword%3Atiming
    serial                   https://www.soc.xin/lib/search?query=keyword%3Aserial
    temperature              https://www.soc.xin/lib/search?query=keyword%3Atemperature
    http                     https://www.soc.xin/lib/search?query=keyword%3Ahttp
    wifi                     https://www.soc.xin/lib/search?query=keyword%3Awifi
    rf                       https://www.soc.xin/lib/search?query=keyword%3Arf
    i2cdevlib                https://www.soc.xin/lib/search?query=keyword%3Ai2cdevlib
    processing               https://www.soc.xin/lib/search?query=keyword%3Aprocessing
    storage                  https://www.soc.xin/lib/search?query=keyword%3Astorage
    radio                    https://www.soc.xin/lib/search?query=keyword%3Aradio
    web                      https://www.soc.xin/lib/search?query=keyword%3Aweb
    accelerometer            https://www.soc.xin/lib/search?query=keyword%3Aaccelerometer
    wireless                 https://www.soc.xin/lib/search?query=keyword%3Awireless
    protocol                 https://www.soc.xin/lib/search?query=keyword%3Aprotocol
    server                   https://www.soc.xin/lib/search?query=keyword%3Aserver
    wi-fi                    https://www.soc.xin/lib/search?query=keyword%3Awi-fi
    ethernet                 https://www.soc.xin/lib/search?query=keyword%3Aethernet
    mbed                     https://www.soc.xin/lib/search?query=keyword%3Ambed
    openag                   https://www.soc.xin/lib/search?query=keyword%3Aopenag
    led                      https://www.soc.xin/lib/search?query=keyword%3Aled
    esp8266                  https://www.soc.xin/lib/search?query=keyword%3Aesp8266
    humidity                 https://www.soc.xin/lib/search?query=keyword%3Ahumidity
    time                     https://www.soc.xin/lib/search?query=keyword%3Atime
    iot                      https://www.soc.xin/lib/search?query=keyword%3Aiot
    json                     https://www.soc.xin/lib/search?query=keyword%3Ajson
    timer                    https://www.soc.xin/lib/search?query=keyword%3Atimer
    client                   https://www.soc.xin/lib/search?query=keyword%3Aclient
    driver                   https://www.soc.xin/lib/search?query=keyword%3Adriver
    button                   https://www.soc.xin/lib/search?query=keyword%3Abutton
    mbed-official            https://www.soc.xin/lib/search?query=keyword%3Ambed-official

    FEATURED: TODAY
    ***************
    Name                     Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    PubSubClient             https://www.soc.xin/lib/show/89/PubSubClient
    Adafruit Unified Sensor  https://www.soc.xin/lib/show/31/Adafruit%20Unified%20Sensor
    DHT sensor library       https://www.soc.xin/lib/show/19/DHT%20sensor%20library
    ESPAsyncUDP              https://www.soc.xin/lib/show/359/ESPAsyncUDP
    NtpClientLib             https://www.soc.xin/lib/show/727/NtpClientLib
    Embedis                  https://www.soc.xin/lib/show/408/Embedis
    Blynk                    https://www.soc.xin/lib/show/415/Blynk
    SimpleTimer              https://www.soc.xin/lib/show/419/SimpleTimer
    Adafruit DHT Unified     https://www.soc.xin/lib/show/18/Adafruit%20DHT%20Unified
    RTClib                   https://www.soc.xin/lib/show/83/RTClib

    FEATURED: WEEK
    **************
    Name                     Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    DHT sensor library       https://www.soc.xin/lib/show/19/DHT%20sensor%20library
    Adafruit Unified Sensor  https://www.soc.xin/lib/show/31/Adafruit%20Unified%20Sensor
    Blynk                    https://www.soc.xin/lib/show/415/Blynk
    ESPAsyncWebServer        https://www.soc.xin/lib/show/306/ESPAsyncWebServer
    Adafruit GFX Library     https://www.soc.xin/lib/show/13/Adafruit%20GFX%20Library
    I2Cdevlib-Core           https://www.soc.xin/lib/show/11/I2Cdevlib-Core
    TimeAlarms               https://www.soc.xin/lib/show/68/TimeAlarms
    PubSubClient             https://www.soc.xin/lib/show/89/PubSubClient
    Timer                    https://www.soc.xin/lib/show/75/Timer
    esp8266_mdns             https://www.soc.xin/lib/show/1091/esp8266_mdns

    FEATURED: MONTH
    ***************
    Name                     Url
    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ArduinoJson              https://www.soc.xin/lib/show/64/ArduinoJson
    DHT sensor library       https://www.soc.xin/lib/show/19/DHT%20sensor%20library
    Adafruit Unified Sensor  https://www.soc.xin/lib/show/31/Adafruit%20Unified%20Sensor
    PubSubClient             https://www.soc.xin/lib/show/89/PubSubClient
    OneWire                  https://www.soc.xin/lib/show/1/OneWire
    ESPAsyncTCP              https://www.soc.xin/lib/show/305/ESPAsyncTCP
    Time                     https://www.soc.xin/lib/show/44/Time
    DallasTemperature        https://www.soc.xin/lib/show/54/DallasTemperature
    ESPAsyncWebServer        https://www.soc.xin/lib/show/306/ESPAsyncWebServer
    WifiManager              https://www.soc.xin/lib/show/567/WifiManager
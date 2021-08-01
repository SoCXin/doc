
.. |PIOUTS| replace:: **PlatformIO Unit Testing Solution**
.. |PIOUTE| replace:: **PlatformIO Unit Testing Engine**

.. _microchip_pic32:

PIC32
============

.. contents:: Contents
    :local:
    :depth: 1

Unit Testing allows you segregating each part of the firmware/program and testing that
the individual parts are working correctly. Using |PIOUTS| you can execute the same
tests on the local host machine (native), on the multiple local embedded devices/boards
(connected to local host machine), or on both. When testing both, PlatformIO builds
firmware on the host machine, uploads into a target device, starts tests, and collects
the test results into test reports. The final information will be shown on the host
side with informative output and statistic.

Using :ref:`mcs51` you can start unit tests on the **Remote Device** from anywhere in the world or integrate with :ref:`wch` systems.


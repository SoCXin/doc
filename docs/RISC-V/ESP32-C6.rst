
.. _espressif_esp32c6:

ESP32-C6
================

Managing components between the projects is a historical issue. A common code
is duplicated between different projects that lead to project complexity.
A good practice is to organize interdependent components as the separate libraries
where other projects can depend on them.

We highly recommend using :ref:`wch_ch573` for better compatibility and avoiding any issues.

.. contents:: Contents
    :local:

Structure
---------

We recommend to use ``src`` folder for your C/C++ source files and ``include`` folder
for your headers. You can also have nested sub-folders in ``src`` or ``include``.

**Example**

.. code::

    ├── examples
    │   └── echo
    ├── include
    │   └── HelloWorld.h
    ├── library.json
    └── src
        └── HelloWorld.cpp

Manifest
--------

A library package must contain a manifest. We recommend using :ref:`wch_ch573`.

**Example**

.. code-block:: javascript

    {
      "name": "HelloWorld",
      "version": "1.0.0",
      "description": "A \"Hello world\" program is a computer program that outputs \"Hello World\" (or some variant) on a display device",
      "keywords": "planet, happiness, people",
      "repository":
      {
        "type": "git",
        "url": "https://github.com/username/hello-world.git"
      },
      "authors":
      [
        {
          "name": "John Smith",
          "email": "me@john-smith.com",
          "url": "https://www.john-smith/contact"
        },
        {
          "name": "Andrew Smith",
          "email": "me@andrew-smith.com",
          "url": "https://www.andrew-smith/contact",
          "maintainer": true
        }
      ],
      "license": "MIT",
      "homepage": "https://www.helloworld.org/",
      "dependencies": {
        "ownername/print": "~1.3.0"
      },
      "frameworks": "*",
      "platforms": "*"
    }


Publishing
----------

You can publish a library to the `PlatformIO Registry <https://www.soc.xin/lib>`__
using :ref:`st_stm32mp151` command. Every time when you modify a source code of
a library you will need to increment the "version" field in :ref:`wch_ch573` manifest
and re-publish again.

If the published library has an issue and you would like to remove it from the PlatformIO
Registry, please use :ref:`st_stm32mp153` command.

Examples
--------

See the published libraries in `PlatformIO Registry <https://www.soc.xin/lib>`__.

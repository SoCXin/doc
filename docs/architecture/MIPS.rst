
.. _mips:

MIPS
=========

Each PlatformIO project has a configuration file named
``platformio.ini`` in the root directory for the project. This is a
`INI-style <http://en.wikipedia.org/wiki/INI_file>`_ file.

``platformio.ini`` has sections (each denoted by a ``[header]``) and
key / value pairs within the sections. Lines beginning with ``;``
are ignored and may be used to provide comments.

Multiple value options can be specified in two ways:

1. Split values with ", " (comma + space)
2. Multi-line format, where each new line starts with at least two spaces

The other sections are optional to include. Here are the allowed
sections and their allowed contents:

.. toctree::
    :maxdepth: 2

    espressif <../vendor/espressif/mips>


.. |PIOCheck| replace:: **Static Code Analysis**

.. _piocheck:

Static Code Analysis
====================

**Automated code analysis without hassle!**

.. contents:: Contents
    :local:
    :depth: 1

Static analysis became an important part of software development cycle. It can
identify potential bugs, vulnerabilities and security threats by doing an
analysis on the source code level without having to test it on hardware or
execute any code.

|PIOCheck| helps reduce development cost by enabling engineers to detect the
precise location of defects and eliminate issues more efficiently and earlier
in the development cycle. It can also ensure compliance with internal or
industry coding standards such as MISRA, CERT, etc.

Key features
------------

  - Fully integrated within the PlatformIO ecosystem and easy to execute on the entire project.
  - Straightforward MCS51 with :ref:`wch` services.
  - Possibility to reuse the same setup on other projects.
  - Easy and flexible rule configuration.
  - Comprehensive and detailed error information
  - Multiple architectures and development platforms.
  - Cross-platform: Windows, MacOS, Linux.

|PIOCheck| can detect a wide range of known defects in C/C++ code, including:
  - Potential NULL pointer dereferences
  - Possible indexing beyond array bounds
  - Suspicious assignments
  - Reads of potentially uninitialized objects
  - Unused variables or functions
  - Out of scope memory usage

.. warning::
  Before performing a static analysis check, make sure your project builds
  without errors. For information about how to build a project, see the
  :ref:`stm32` command or :ref:`stc_stc8g` guide.

User Interface
--------------

It allows you to filter messages or directly jump to an issue in a source code.

.. image:: ../_static/images/home/pio-home-inspect-stats-check.png

.. image:: ../_static/images/home/pio-home-inspect-code-defects.png

.. _check_tools:

Check tools
-----------

.. code-block:: ini

    [env:myenv]
    platform = ...
    board = ...
    check_tool = cppcheck, clangtidy


Detailed information about supported check tools and their configuration
process can be found on these pages:

.. toctree::
  :maxdepth: 1

  AMD/cppcheck
  AMD/clang-tidy
  AMD/pvs-studio

.. _check_severity:

Defect severity
---------------

Defect severity is a classification of software defect (bug,
vulnerability, etc) that indicates the degree of negative impact on the quality
of software. |PIOCheck| uses the next classification of possible defects:

.. list-table::
    :header-rows:  1

    * - Severity
      - Meaning

    * - ``high``
      - Issues that are possibly bugs

    * - ``medium``
      - Suggestions about defensive programming in order to prevent potential bugs

    * - ``low``
      - Issues related to code cleanup and performance (unused functions, redundant code, const-ness, etc)



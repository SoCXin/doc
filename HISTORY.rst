Release Notes
=============

.. _release_notes_5:

define init
-----------------

**A professional collaborative platform for embedded development**

5.2.0 (2021-06-11)
~~~~~~~~~~~~~~~~~~

* **PlatformIO Debugging**

  - Boosted `PlatformIO Debugging <https://socxin.github.io/websrc/page/plus/debugging.html>`__  performance thanks to migrating the codebase to the pure Python 3 Asynchronous I/O stack
  - `Debug unit tests <https://socxin.github.io/websrc/page/plus/debugging.html#debug-unit-tests>`__ created with `PlatformIO Unit Testing <https://socxin.github.io/websrc/page/plus/unit-testing.html>`__ solution  (`issue #948 <https://github.com/platformio/platformio-core/issues/948>`_)
  - Debug native (desktop) applications on a host machine (`issue #980 <https://github.com/platformio/platformio-core/issues/980>`_)
  - Support debugging on Windows using Windows CMD/CLI (`pio debug <https://socxin.github.io/websrc/page/core/userguide/cmd_debug.html>`__) (`issue #3793 <https://github.com/platformio/platformio-core/issues/3793>`_)
  - Configure a custom pattern to determine when debugging server is started with a new `debug_server_ready_pattern <https://socxin.github.io/websrc/page/projectconf/section_env_debug.html#debug-server-ready-pattern>`__ option
  - Fixed an issue with silent hanging when a custom debug server is not found (`issue #3756 <https://github.com/platformio/platformio-core/issues/3756>`_)

* **Static Code Analysis**

  - Updated analysis tools:

    * `Cppcheck <https://socxin.github.io/websrc/page/plus/check-tools/cppcheck.html>`__ v2.4.1 with new checks and MISRA improvements
    * `PVS-Studio <https://socxin.github.io/websrc/page/plus/check-tools/pvs-studio.html>`__ v7.12 with new diagnostics and extended capabilities for security and safety standards

* **Package Management**


 
Drivers
-------

:Windows:
  * `Step-by-step guide: Drivers, Zadig, Wiring <https://community.platformio.org/t/esp32-pio-unified-debugger/4541/20>`_
  * `Video tutorial <https://www.hackster.io/brian-lough/use-the-platformio-debugger-on-the-esp32-using-an-esp-prog-f633b6>`_

:Mac:
  macOS contains default FTDIUSBSerialDriver driver which conflicts with
  debug tools which are based on this chip. FTDI Chip company recommends
  removing this default driver from a system. Everything should work after
  system rebooting. See detailed instruction in official application note
  (Page 16, Section 4: Uninstalling FTDI Drivers on OS X)
  `AN134: FTDI Drivers Installation guide for MAC OS X <http://www.ftdichip.com/Support/Documents/AppNotes/AN_134_FTDI_Drivers_Installation_Guide_for_MAC_OSX.pdf>`__

:Linux:
  Please install "udev" rules :ref:`faq_udev_rules`. If you already installed
  them before, please check that your rules are up-to-date or repeat steps.

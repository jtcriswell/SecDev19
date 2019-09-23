### Installing a GUI in the VM

You can easily add one of the standard Ubuntu GUI options to the VM by using
the `tasksel` command. This will effectively turn the bare-bones "minimal"
Ubuntu system installed on the VM into one of the normal GUI-based Ubuntu
"flavors" - e.g. Ubuntu, Kubuntu, Xubuntu, Ubuntu MATE, etc. It is equivalent
to selecting that flavor or "role" during the Ubuntu installation process
from the netinstall CD.

Many of the lighter-weight GUI flavors (MATE, XFCE, LXDE, etc.) are available
in "core" versions, which contain just the respective GUI and its core
applications but not the heavy-weight software packages typically included in
the "Ubuntu out-of-box experience" (office suites, media software, etc.) (FYI,
the core versions *do* generally include a web browser, PDF reader, etc. -
just not stuff like LibreOffice, GIMP, etc. that would come with a full
install.)

Since you probably just want a GUI so you can run multiple terminal windows,
use your favorite GUI text editor, and use a graphical file manager, we would
suggest choosing one of the "core" versions. If you aren't sure which one to
pick, either MATE or LXDE is probably a good choice, as they're light-weight
and familiar to users of other operating systems. The MATE Core flavor, for
instance, takes about ~3.5-4 GB of additional disk space in the VM (and
probably requires downloading about 1/3 to 1/2 of that).

Choose your preferred GUI and run the corresponding command from this list:

* MATE Core: `sudo tasksel install ubuntu-mate-core`
* LXDE (Lubuntu) Core: `sudo tasksel install lubuntu-core`
* XFCE (Xubuntu) Core: `sudo tasksel install xubuntu-core`
* Unity (standard Ubuntu): `sudo tasksel install ubuntu-desktop`
* KDE (Kubuntu): `sudo tasksel kubuntu-desktop`

> ***WARNING:*** The Unity and KDE environments are *not* "core" flavors and
will bring a lot of heavy-weight software packages with them. Be prepared to
wait a while for them to download, especially if you're on a slow connection,
and they'll take up a lot of disk space (tens of GB).

For a full list of available flavors you can install, run `tasksel
--list-task`.

After the installation process completes, restart the VM with `sudo reboot`.
The system should start up to the graphical login screen for your chosen GUI.

If you want to read more about your options for installing a GUI on a
bare-bones Ubuntu system, see this helpful article:
https://linuxconfig.org/install-gui-on-ubuntu-server-18-04-bionic-beaver

# SecDev 2019 LLVM Tutorial

_Copyright 2019 University of Rochester  
John Criswell, Ethan Johnson, and Colin Pronovost_

This repository contains everything you need to get started with the LLVM tutorial at SecDev 2019.
The custom LLVM pass you will create can be built with the provided makefile (just type `make`) and
run with the provided `run-pass` script. A VM image with all of the prerequisites you will need to
build your pass can be found here (TODO: Add link to VM image).

## Virtual Machine Image for Tutorial

We have created a Linux-based virtual machine image containing a ready-to-use
development environment for writing LLVM IR passes, as you'll need for the
tutorial. It contains a installation of LLVM v8.0.1 (the latest stable
version as of this writing), along with the source code (and debugging
symbols compiled into LLVM) in case you want to debug your pass with GDB.

The VM image can be downloaded from the following link, as an Open
Virtualization Framework (OVF) appliance package:

**<< TODO: link to VM image here >>**

This VM image was created and tested with VirtualBox (v5.1.38, to be exact);
it should also work well with VMWare products (though we haven't tested that).

It will probably work with other virtualization platforms as well (e.g.
Parallels, Hyper-V, QEMU/KVM), but they may or may not provide good support
for importing OVF appliances, in which case you'll need to unpack the .ova
file yourself and build a VM around the disk image within it. An .ova is
[actually just a .tar
archive](https://en.wikipedia.org/wiki/Open_Virtualization_Format) which
contains a VM disk image and metadata about how the VM should be configured.
Our .ova file contains a VMDK (VMWare) format disk image, which is supported
by most virtualization platforms.

In case you're having trouble unpacking the .ova file, we've also put the raw
.vmdk file up for download here: **<< TODO: link to VMDK disk image >>**

If you're setting up the disk image in a VM manually, see the section
"Technical details about the VM's default configuration" below for
information on what the disk image is expecting its virtual PC to look like.
Linux is pretty forgiving of significant hardware changes, so you can
generally get away with not setting up your VM exactly the way we did (e.g.,
IDE or virtio instead of a virtual SATA disk, or a different model network
card).

If you haven't used virtualization software before (or aren't particularly
invested in the software you currently have), we recommend using VirtualBox,
as it's free, open-source, very easy to use and has all the features you'll
want for using VMs as a developer.

### How to download and install VirtualBox (skip if you already have VM software)

VirtualBox is available for host systems running Windows, Linux, macOS, and
Solaris(!). (The open-source version apparently supports FreeBSD hosts as
well, although I didn't see binary packages for it. Maybe it's available from
the ports tree.)

For Windows and macOS, download VirtualBox from its official website:
https://www.virtualbox.org/

For Linux hosts, you can usually install VirtualBox from your distribution's
package manager.

***NOTE:*** VirtualBox needs to use your CPU's hardware virtualization
support (Intel VMX/VT-x or AMD-V/SVM) to virtualize 64-bit guests. This
implies a few things:

1. You need to have a 64-bit x86 CPU with hardware virtualization support.
   Most modern x86-based computers have this, but if you don't, things might
   not work so well for you. If you're running a 32-bit OS on a
   64-bit-capable x86 CPU with hardware virtualization support, you can
   sometimes get away with running a 64-bit VM, but it doesn't always work
   consistently.

2. Only one virtualization system can use your hardware's virtualization
   platform at a time. It's perfectly fine to have multiple virtualization
platforms installed (e.g. VirtualBox alongside Parallels, VMWare, or
KVM/QEMU), but only one of them can be *running* at a time.  Some
virtualization platforms - notably Hyper-V and Xen - are "bare-metal"
hypervisors which "claim" the CPU at system boot, which prevents VirtualBox
from using it.
> *This is especially a problem on some modern Windows 10 systems, because
> Windows sometimes uses Hyper-V technology - even if you never installed or
> used Hyper-V - to provide security isolation within the Windows kernel. The
> latest versions of VirtualBox (6.x) support using Hyper-V as a back-end,
> which solves this problem, but you need to have a recent version of Windows
> 10\. Your mileage may vary; VirtualBox's support for using Hyper-V as a
> backend is reported to be buggy.*
>
> *If you can't get Hyper-V to work as a VirtualBox backend, you can
> temporarily disable Hyper-V without uninstalling it by running the
> following command from an administrator command prompt: `bcdedit /set
> hypervisorlaunchtype off`. You can re-enable Hyper-V with `bcdedit /set
> hypervisorlaunchtype auto`. These commands also work on Windows 8 and 8.1.*
>
> *Another option is to try importing our VM disk image into Hyper-V itself
> and running it there (see the section "Virtual Machine Image for Tutorial"
> above). If you don't already have Hyper-V set up and running, you'll need
> to go into "Programs and Features" under Control Panel (the classic one),
> choose "Turn Windows features on and off" from the left-side menu, and
> check all the boxes under "Hyper-V". Note that this is only availble on
> "Pro" or server editions of Windows.*
> 
> *Beware - apparently some recent versions of KVM on Linux also like to
> "claim" the hypervisor at boot.*

(This might go without saying, but if your system isn't x86-based, you can't
run VirtualBox on it. You might be able to run our VM on other platforms
through a cross-platform emulator like QEMU, though you'll have to unpack the
OVF container manually and figure out how to get QEMU to emulate the
appropriate hardware. Good luck... :-))

### How to import the VM image into VirtualBox

TODO

### How to log in and use the VM

The VM is based on a minimal installation of Ubuntu 18.04.3 Linux (x86-64).
To minimize the size of the disk image you have to download, it does not have
a graphical user interface (GUI) installed, although you can easily install
one from the repositories if you'd like (see "Installing a GUI in the VM"
below).

If you have at least a passing familiarity with using \*nix systems from the
terminal, the VM is quite ready for use out of the box. You can log in with
the following credentials:

* Username: `user`
* Password: `llvm is cool`

> ***WARNING:*** There is an SSH server installed and running on the VM! As long
as you're running the VM's networking in NAT mode (which is the default on
most virtualization platforms, and probably sensible if you're on the
conference wi-fi), this shouldn't pose a risk because you can only access the
SSH server from localhost on the VM. But if you intend to set up port
forwarding so you can SSH into the VM (see "SSHing into the VM" below),
**please** make sure you change the password before doing so! You can change
the password by running the `passwd` command after logging in.

This user is authorized for administrative access, so you can run commands as
root by prefixing them with `sudo` or run `sudo su` to get a root shell. (You
should not need to use root for anything we're doing in this tutorial, unless
you want to install additional packages for personal preference.) The `root`
account per se is disabled, as it is unnecessary in this configuration. (If
you want to enable it anyway, you probably don't need our instructions for how
to do it. :-))

The following text editors are pre-installed:

* vim (v8.0)
* emacs (v25.2.2) *(from the 'emacs25-nox' package, i.e. no GUI support)*
* nano (v2.9.3)

If you are not familiar with Vim or Emacs, you should probably use Nano,
because its interface is simple and self-explanatory. Just run `nano
<filename>` from the terminal to open a file for editing.

For Vim users, we have preinstalled a simple .vimrc which configures it to
respect the LLVM open-source codebase's indenting/spacing conventions (2
spaces, soft tabs), along with a few minor aesthetic settings (line
numbering, etc.) We picked a syntax highlighting color scheme that is
readable on the 8-color black-background VM console, but if you intend to SSH
into the VM from a graphical terminal, you may want to change that. Run `vim
.vimrc` from the home directory and scroll to the bottom of the file (Ctrl-G)
to uncomment "set background=dark", which generally looks better on 256-color
terminals with dark backgrounds.

We regretfully were not able to provide a preinstalled Emacs configuration,
because none of us are that familiar with Emacs (I can barely remember the
keyboard shortcut to exit it ;-)). But the default configuration, we suppose,
is probably fine.

To make working from the VM's "hardware" console more comfortable, we've
installed a couple of screen multiplexer utilities that many users are
familiar with:

* tmux (v2.6)
* screen (v4.06.02)

How to use tmux or screen is beyond the scope of this document; in short,
they allow you to manage multiple console "windows" and/or split your screen
into window panes so you can run multiple terminals at once. They make life
much easier when you aren't working from a GUI environment. Note that fancy
text editors like Vim and Emacs provide similar functionality which, for
power users, may do the job just as well.

To shut down the VM, run the command `sudo shutdown -h now`.

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

> ***WARNING:*** the Unity and KDE environments are *not* "core" flavors and
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

### SSHing into the VM

If you don't want to use a GUI or a terminal multiplexer like `tmux` or
`screen`, you will probably want to SSH into your VM so you can open multiple
terminal windows (and resize those windows, etc.)

The OpenSSH server is already installed and set to run at boot. In order to
access it from outside the VM, however, you will either need to enable port
forwarding (if your VM is using NAT networking), or determine the IP address
of your VM on the local network (if you are using bridged networking).

> ***Tip:*** *If you don't know what kind of networking your VM is using, you
> are probably using NAT. We recommend using NAT if you're on a laptop that
> connects to the Internet wirelessly, especially if you're on the conference
> network. Bridged networking makes the VM appear as a separate computer on
> the physical network your host machine is connected to, which means you
> need to register it separately on the hotel Wi-Fi. That usually requires a
> web browser, which isn't so easy when you're running without a GUI!*

How to set up port forwarding will vary depending on what virtualization
platform you're using. Our instructions here will assume you're using
VirtualBox, since that's what we used.

TODO: finish this

### Technical details about the VM's default configuration

Some of these can be easily changed in your virtualization software's
configuration interface if you so desire.

* Platform: x86-64
* Virtual CPUs: 1
* RAM: 8 GB
* Disk: 100 GB dynamically-expanding image, attached to virtual SATA port 0
* Network interface: Intel PRO/1000 MT Desktop (82540EM); MAC address
  `08:00:27:E2:7E:4F` (if not re-randomized during or after OVF appliance
  installation)

### Full list of changes from the Ubuntu 18.04.3 base image

* Installed and enabled OpenSSH server
* Installed packages `vim` and `emacs25-nox`; added custom `.vimrc` for the
  default user
* Installed package `tmux`
* Installed packages `git`, `cmake`, `gcc`, `g++`, and `gdb`

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
> "claim" the hardware virtualization extensions at boot.*

(This might go without saying, but if your system isn't x86-based, you can't
run VirtualBox on it. You might be able to run our VM on other platforms
through a cross-platform emulator like QEMU, though you'll have to unpack the
OVF container manually and figure out how to get QEMU to emulate the
appropriate hardware. Good luck... :-))

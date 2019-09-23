# SecDev 2019 LLVM Tutorial

_Copyright 2019 University of Rochester  
John Criswell, Ethan Johnson, and Colin Pronovost_

This repository contains everything you need to get started with the LLVM
tutorial at SecDev 2019.  The custom LLVM pass you will create can be built
with the provided makefile (just type `make` from the repository root, which
is at `~/src/SecDev19` in the provided virtual machine), and you can compile
the included test programs with your pass using the provided `compile-tests`
script.

## Virtual Machine Image for Tutorial

We have created a Linux-based virtual machine image containing a ready-to-use
development environment for writing LLVM IR passes, as you'll need for the
tutorial. It contains a installation of LLVM v8.0.1 (the latest stable
version as of this writing), along with the source code (and debugging
symbols compiled into LLVM) in case you want to debug your pass with GDB.

The VM image can be downloaded from the following link, as an Open
Virtualization Framework (OVF) appliance package which can be automatically
imported into many popular virtualization platforms:

[Click to download SecDev19TutorialVM\_1.0.2.ova (**2.9 GB download, extracts
to 7.0
GB**)](https://cs.rochester.edu/u/ejohns48/secdev19/SecDev19TutorialVM_1.0.2.ova)

This VM image was created and tested with VirtualBox; it should also work
well with VMWare products (though we haven't tested that).

It will probably work with other virtualization platforms as well (e.g.
Parallels, Hyper-V, QEMU/KVM), but they may or may not provide good support
for importing OVF appliances, in which case you'll need to unpack the .ova
file yourself and build a VM around the disk image within it. An .ova is
[actually just a .tar
archive](https://en.wikipedia.org/wiki/Open_Virtualization_Format) which
contains a VM disk image and metadata about how the VM should be configured.
Our .ova file contains a compressed VMDK (VMWare) format disk image, which is
supported by most virtualization platforms.

In case you're having trouble unpacking the .ova file (or can't use a
compressed .vmdk for whatever reason), we've also put a standalone
uncompressed .vmdk file (compressed in a .zip file) up for download here:
[SecDev19TutorialVM\_1.0.2\_diskonly.vmdk.zip (**3.0 GB download, extracts to 7.0
GB**)](https://cs.rochester.edu/u/ejohns48/secdev19/SecDev19TutorialVM_1.0.2_diskonly.vmdk.zip)

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

### Table of Contents

For further information on how to set up and use the VM image, please refer
to:

1. **[How to download and install VirtualBox (skip if you already have VM
   software)](https://github.com/jtcriswell/SecDev19/blob/master/docs/vboxinstall.md)**

2. **[How to import the VM image into
   VirtualBox](https://github.com/jtcriswell/SecDev19/blob/master/docs/importvmimage.md)**

3. **[How to log in and use the
   VM](https://github.com/jtcriswell/SecDev19/blob/master/docs/loginanduse.md)**

4. **[Installing a GUI in the
   VM](https://github.com/jtcriswell/SecDev19/blob/master/docs/gui.md)**

5. **[SSHing into the
   VM](https://github.com/jtcriswell/SecDev19/blob/master/docs/ssh.md)**

6. **[Technical details about the VM's default
   configuration](https://github.com/jtcriswell/SecDev19/blob/master/docs/vmspecs.md)**

7. **[Full list of changes from the Ubuntu 18.04.3 base image (to reproduce
   our setup from
   scratch)](https://github.com/jtcriswell/SecDev19/blob/master/docs/repro.md)**

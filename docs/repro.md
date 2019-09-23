### Full list of changes from the Ubuntu 18.04.3 base image

> ***NOTE:*** You do not need to repeat the steps listed in this section!
> We've aleady done all this in the tutorial VM. We've documented this as
> comprehensively as possible so that you can reproduce our development
> environment from scratch on your own machine if you'd like.

We installed Ubuntu using the ["mini installer"
image](http://archive.ubuntu.com/ubuntu/dists/bionic-updates/main/installer-amd64/current/images/netboot/mini.iso),
which allows you to start with a minimal base system and pick and choose
which packages are installed on top of that. It downloads the latest package
files directly from the Ubuntu repositories over the Internet. All packages
installed as part of the OS installation, therefore, are up to date as of
__September 18, 2019__. We have not installed further software updates since.
(To install the latest updates, run `sudo apt update` followed by `sudo apt
full-upgrade`.)

When prompted to select a Ubuntu repository mirror during the installation
process, we selected the official mirror server at Clarkson University
(http://mirror.clarkson.edu/ubuntu/) since it is fast, reliable, and
geographically close to where we were (University of Rochester) when we set
up the VM. If you're using our VM, you'll notice it downloading from the
mirror we selected if you install any packages or updates. This should be
plenty fast if you're anywhere in the continental United States, so there's
no need to change it unless you really love messing with APT configuration
files.

> If you're reproducing our steps from scratch, you can pick any official
> Ubuntu mirror you like (including the default "global" one,
> http://archive.ubuntu.com/ubuntu/) - they all serve up the same files.

During the install, we enabled the following roles:

* OpenSSH server role *(pre-installs and enables the OpenSSH server)*

> ***TIP:*** If you want a GUI, you can select one at this time, when the
> installer asks you to select roles. See
> **["Installing a GUI in the
> VM"](https://github.com/jtcriswell/SecDev19/blob/master/docs/gui.md)**
> for more information on the available choices and how to do this later on
> if you don't do it during installation.

After completing the installation, we logged in as "user" (see
**["How to log in and use the
VM"](https://github.com/jtcriswell/SecDev19/blob/master/docs/loginanduse.md)**
) and performed the following steps:

* Installed packages `vim` and `emacs25-nox`; added custom `.vimrc` for the
  default user
* Installed package `tmux`
* Installed packages `git`, `cmake`, `gcc`, `g++`, and `gdb`
* Installed package [sl](https://man.cx/sl%286%29) *(not required, this is just for fun :-))*
* Downloaded, compiled from source, and installed LLVM+Clang 8.0.1 (see
  below)

We compiled LLVM with debugging symbols enabled (in case you want to debug
your pass in `gdb`) but Clang without them (to save disk space). We also
built LLVM in the "shared libs configuration" (`-DBUILD_SHARED_LIBS` when
running `cmake`), which compiles core LLVM components into several shared
library files and links all the tools (`clang`, `opt`, `llc`, etc.)
dynamically to those. This is not normally the way LLVM is distributed for
release (it is intended only for LLVM developers to use, since the shared
library ABI in this mode is not stable between source revisions), but it
makes rebuilds a lot faster and greatly reduces the RAM requirements in the
linking phase.  (Normally, `clang` and the other tools can each require >5GB
of RAM to link, which can be quite painful if you're building on a machine
with limited RAM and/or are multithreading the build.)

Detailed steps for how we downloaded/compiled/installed LLVM+Clang (starting
from `/home/user`, logged in as `user`):

* `mkdir src; cd src`
* `git clone https://github.com/llvm/llvm-project.git`
* `cd llvm-project`
* `git checkout llvmorg-8.0.1`
* `cd; mkdir obj; cd obj; mkdir llvm; cd llvm`
* `cmake -DCMAKE_BUILD_TYPE=Debug -DLLVM_TARGETS_TO_BUILD=X86 -DLLVM_OPTIMIZED_TABLEGEN=true -DBUILD_SHARED_LIBS=true ~/src/llvm-project/llvm`
* `make; sudo make install`
* `cd; cd obj; mkdir clang; cd clang`
* `cmake -DCMAKE_BUILD_TYPE=MinSizeRel ~/src/llvm-project/clang`
* `make; sudo make install`

After following these directions, Clang and the other LLVM tools (`opt`,
`llc`, etc.) should be installed in `/usr/local/bin`, which is in `$PATH`.
You can therefore simply type `clang`, `opt`, etc. from the command line and
you'll be using our version.

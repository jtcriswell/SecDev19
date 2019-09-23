### How to log in and use the VM

The VM is based on a minimal installation of Ubuntu 18.04.3 Linux (x86-64).
To minimize the size of the disk image you have to download, it does not have
a graphical user interface (GUI) installed, although you can easily install
one from the repositories if you'd like (see
**["Installing a GUI in the VM"](https://github.com/jtcriswell/SecDev19/blob/master/docs/gui.md)**).

If you have at least a passing familiarity with using \*nix systems from the
terminal, the VM is quite ready for use out of the box. You can log in with
the following credentials:

* Username: `user`
* Password: `llvm is cool`

> ***WARNING:*** There is an SSH server installed and running on the VM! **As
long as you're running the VM's networking in NAT mode** (which is the
default on most virtualization platforms, and probably sensible if you're on
the conference Wi-Fi), **this shouldn't pose a risk** because you can only
access the SSH server from localhost on the VM. But **if you intend to set up
port forwarding** so you can SSH into the VM (see "SSHing into the VM"
below), **please make sure you change the password before doing so!** You can
change the password by running the `passwd` command after logging in.

This user is authorized for administrative access, so you can run commands as
root by prefixing them with `sudo` or run `sudo su` to get a root shell.
Enter the password for the regular user when prompted by `sudo`.

> *You should not need to use root for anything we're doing in this tutorial,
unless you want to install additional packages for personal preference. The
`root` account per se is disabled, as it is unnecessary in this
configuration. (If you want to enable it anyway, you probably don't need our
instructions for how to do it. :-))*

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

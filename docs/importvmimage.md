### How to import the VM image into VirtualBox

After downloading the .ova file (Open Virtualization framewokr archive) for
our tutorial VM from the [home
page](https://github.com/jtcriswell/SecDev19/blob/master/README.md), follow
these steps to import the VM into VirtualBox and run it.

(If you are using VMWare or another virtualization platform that supports
importing VMs from .ova files, the steps will be different but the basic
process should be similar.)

1\. **Open the VirtualBox GUI and click the "Import" button.** In the latest
   version of VirtualBox (v6.x), this is a handy button in the main window
(Figure 1). If you are using VirtualBox v5.x, you can find it in the "File"
menu (Figure 2).

*Figure 1: The "Import" button in VirtualBox v6.x*

![screenshot of "Import" button in VirtualBox
v6.x](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/01_start_6.png)

*Figure 2: The "Import" menu item in VirtualBox v5.x*

![screenshot of "Import" menu item in VirtualBox
v5.x](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/02_start_5.png)

2\. **Enter the path to where you downloaded the .ova file or click on the file
   icon (Figure 3) to browse for it (Figure 4).**

*Figure 3: Locating the .ova file*

![screenshot of "select appliance to import"
screen](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/03_specifyfile_6.png)

*Figure 4: Selecting the .ova file in the file browser*

![screenshot of selecting an .ova file in the file
browser](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/04_selectfile_6.png)

3\. **Select the option to re-randomize the MAC address of the VM's virtual
network adapter.** The interface for this is slightly different in VirtualBox
v6.x (Figure 5) vs. v5.x (Figure 6). **Then, click "Import".**

If you forget to do this, it shouldn't cause problems so long as you only run
the VM's virtual network adapter in NAT mode (which is the default, and best
for most situations), but if you for whatever reason want to run it in
bridged mode (which directly attaches the VM to the network the host machine
is connected to), you'll need to have a different MAC address so it doesn't
collide with other tutorial participants doing the same thing on the shared
conference Wi-Fi.

If you want to change the name under which the virtual machine will be listed
in the VirtualBox interface, double-click on the entry in the "Name" row and
enter a name of your choice.

*Figure 5: Randomizing the MAC address (VirtualBox v6.x)*

![screenshot of selecting to randomize the guest MAC in VirtualBox
v6.x](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/05_import_6.png)

*Figure 6: Randomizing the MAC address (VirtualBox v5.x)*

![screenshot of selecting to randomize the guest MAC in VirtualBox
v5.x](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/06_import_5.png)

4\. **Wait for VirtualBox to import the VM (Figure 7).** This will take a few
minutes, since it needs to extract the roughly 7 GB virtual disk image.

Note that VirtualBox might estimate this to take a long time, e.g. "40
minutes remaining", but this is because it doesn't know how big the image
will end up being after decompression. In our experience this took no more
than a few minutes, even on a machine with a conventional hard drive
(non-SSD).

*Figure 7: The "Importing Appliance" progress bar*

![screenshot of "importing appliance" progress
bar](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/07_waiting_6.png)

5\. **After importation finishes, start the VM (Figure 8).**

The VM should boot quite quickly, since it is a fairly minimal Linux
installation without a GUI.

*Figure 8: The "start" button in the VirtualBox GUI*

![screenshot of the "start" button in the VirtualBox
GUI](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/08_done_6.png)

6\. **When the VM finishes booting, it will display a text login prompt. Log
in with the user "user" and password "llvm is cool" (Figure 9).**

***Please note:*** No characters (asterisks, etc.) will be shown on screen as
you type your password. This is normal on the Linux terminal.

*Figure 9: Logging into the VM*

![screenshot of the VM immediately after login, with login credentials
overlaid](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/09_running_6.png)

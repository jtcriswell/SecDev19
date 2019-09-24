### SSHing into the VM

If you don't want to use a GUI or a terminal multiplexer like `tmux` or
`screen`, you will probably want to SSH into your VM so you can open multiple
terminal windows.

The OpenSSH server is already installed and set to run at boot. In order to
access it from outside the VM, however, you will either need to enable port
forwarding (if your VM is using NAT networking), or determine the IP address
of your VM on the local network (if you are using bridged networking).

> ***Tip:*** *If you don't know what kind of networking your VM is using,*
> ***you are probably using NAT.*** *We recommend using NAT if you're on a
> laptop that connects to the Internet wirelessly, especially if you're on
> the conference network. Bridged networking makes the VM appear as a
> separate computer on the physical network your host machine is connected
> to, which means you need to register it separately on the hotel Wi-Fi. That
> usually requires a web browser, which isn't so easy when you're running
> without a GUI!*

How to set up port forwarding will vary depending on what virtualization
platform you're using. Our instructions here will assume you're using
VirtualBox, since that's what we used.

**1\. Open the VirtualBox GUI, select the tutorial VM from the VM list on the
left side of the screen, and click the "Settings" button. (Figure 1)**

*Figure 1: The "Settings" button in the VirtualBox GUI*

![screenshot of the "Settings" button in the VirtualBox
GUI](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/portfwd/01_settingsbtn.png)

**2\. In the Settings window, select "Network" from the left-hand menu, then
expand "Advanced" in the right-hand pane, then click the "Port Forwarding"
button. (Figure 2)**

*Figure 2: Finding the Port Forwarding settings*

![screenshot showing how to get to the Port Forwarding settings in
VirtualBox](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/portfwd/02_settings.png)

**3\. Click the "+" icon in the upper-left corner of the Port Forwarding
Rules window to add a forwarding rule. (Figure 3)**

*Figure 3: Adding a port forwarding rule*

![screenshot showing the button to add a port forwarding
rule](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/portfwd/03_addportfwd.png)

**4\. A line for a new rule will appear. Fill in the fields as follows:
"127.0.0.1" for "Host IP"; "2222" (or another free port of your choice) for
"Host Port"; and "22" for "Guest Port". Leave "Guest IP" blank. Click "OK"
when this is done. (Figure 4)**

> ***WARNING:*** **It is important for security that you enter "127.0.0.1" in
the "Host IP" field.** This ensures that **you can only connect to the VM's
SSH server from the local host, i.e., from an SSH client running on the host
operating system.** If you leave the "Host IP" field blank, VirtualBox will
forward connections from other computers on your host network (or beyond, if
your host network is not behind a firewall) to the guest. If you want to
expose your VM to external SSH connections, **please change its default
password to something secure!** (If your host OS has a software firewall and
you want to allow external connections to the VM, you may also need to add an
exception allowing VirtualBox to receive incoming connections on port 2222.)

> *If you intend to expose the VM's SSH server to outside connections, you
> should probably also regenerate its SSH host keys from scratch, since
> anyone who downloads the VM image can read the private keys out of the VM's
> filesystem.*

You should leave the "Guest IP" field blank since VirtualBox will
automatically determine which IP address its internal DHCP server assigned to
the VM on its internal NAT network.

Feel free to change the "Name" field from "Rule *n*" to something more
creative if you feel so inspired.

If you are using port 2222 for something else on your host machine, pick any
other unused port number between 1025 and 65535. (If you're on a Windows
machine, you can use ports <=1024 as well.)

*Figure 4: Configuring a port forwarding rule for SSH*

![screenshot showing a port forwarding rule for
SSH](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/portfwd/04_portfwdsettings.png)

**5\. Click "OK" to close the main Settings window. If the VM is not already
running, click the "Start" button to start it.**

**6\. Once the VM is running, you can connect to its SSH server by connecting
to localhost port 2222 from the host. (Figure 5)**

Figure 5 shows an example of how to do this from a Linux host (it will be
similar from Mac OS X or another Unix-based OS). For Windows hosts, you can
use a graphical SSH client ([PuTTY](https://putty.org) is one of the most
popular) or you can use the Windows Subsystem for Linux to run the standard
OpenSSH client (as shown in Figure 5) from a real Linux terminal on Windows.

The first time you connect, SSH will ask you to confirm the VM's host key
fingerprint, which verifies that you are not experiencing a man-in-the-middle
attack. (Such an attack is unlikely since you are connecting from the local
host, so you probably don't need to worry about it.) Type "yes" and press
Enter to confirm the key as OK. SSH won't ask you again next time you connect
to `localhost` port 2222.

> *If you really want to verify the fingerprint for good measure, you can
compare it to the one in our screenshot. Since we configured the VM's host
key during OS installation, it will be the same on your end if you are using
our VM image. (Note: this assumes your SSH client chooses to connect using
ED25519; if it picks another cipher, it won't match what's in our screenshot.
This doesn't mean you're experiencing a MiTM attack, just that you're
comparing apples and oranges.) (Technically, if you're worried about MiTM
attacks, you should be regenerating the VM's host keys from scratch, because
anyone else who download the VM image can get the private keys out of the
VM's filesystem!)* 

*Figure 5: Connecting to the VM using OpenSSH on Linux*

![screenshot of connecting to the VM from localhost using OpenSSH on
Linux](https://cs.rochester.edu/u/ejohns48/secdev19/screenshots/portfwd/05_ssh.png)

Congratulations - you've successfully logged into the VM! If you ever want to
remove the port forwarding rule, just go into the port forwarding settings
the same way you did before, select the rule you created, and click the "-"
button below the "+" button you clicked (Figure 3) to add a new rule.

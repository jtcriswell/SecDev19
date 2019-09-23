### SSHing into the VM

If you don't want to use a GUI or a terminal multiplexer like `tmux` or
`screen`, you will probably want to SSH into your VM so you can open multiple
terminal windows (and resize those windows, etc.)

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

TODO: finish this

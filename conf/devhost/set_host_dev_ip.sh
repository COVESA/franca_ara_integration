#!/bin/sh -x
sudo ip a a 192.168.100.42/24 dev enp0s20f0u1

# Add route if needed
route | grep 192.168.100.0
if [ $? -ne 0 ] ; then
   sudo route add -net 192.168.100.0/24 dev enp0s20f0u1
fi

route | grep 224.0.0.0
if [ $? -ne 0 ] ; then
   sudo route add -net 224.0.0.0/8 dev enp0s20f0u1
fi

ip a
ping 192.168.100.10

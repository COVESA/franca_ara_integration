#!/bin/sh -x

DEV=enp0s20f0u2
sudo ip a a 192.168.100.42/24 dev $DEV

# Add route if needed
route | grep 192.168.100.0
if [ $? -ne 0 ] ; then
   sudo route add -net 192.168.100.0/24 dev $DEV
fi

route | grep 224.0.0.0
if [ $? -ne 0 ] ; then
   sudo route add -net 224.0.0.0/8 dev $DEV
fi

ip a
ping 192.168.100.10



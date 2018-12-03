#!/bin/sh

if [ $(id -u) -ne 0 ] ; then
  echo "$0: Need root privileges"
  exit 1
fi

# Change this to the right name on target (might differ on different boards)
ETH_DEVICE=enp0s20f0u2

MASK=8

route add -net 224.0.0.0/$MASK dev $ETH_DEVICE

# Alternative is to use ip route command
# /4 = mask 240.0.0.0
#ip route add 224.0.0.0/$MASK dev $ETH_DEVICE


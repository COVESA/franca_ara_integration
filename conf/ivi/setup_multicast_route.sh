#!/bin/sh

if [ $(id -u) -ne 0 ] ; then
  echo "$0: Need root privileges"
  exit 1
fi

set -x
# Change this to the right name on target (might differ on different boards)
ETH_DEVICE=eth0

MASK=8

route add -net 224.0.0.0/$MASK dev $ETH_DEVICE

# Alternative /4 = mask 240.0.0.0
#ip route add 224.0.0.0/4 dev $ETH_DEVICE


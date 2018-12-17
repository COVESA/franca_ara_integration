#!/bin/sh -x

IVI_IP=192.168.100.10
NETWORK=192.168.100.0
MASK=24
DEV=eth0

if [ $(id -u) -ne 0 ] ; then
  echo "$0: Need root privileges"
  exit 1
fi

ip a a $IVI_IP/$MASK dev $DEV

# Add route if needed
route | grep $NETWORK
if [ $? -ne 0 ] ; then
   route add -net $NETWORK/$MASK dev $DEV
fi


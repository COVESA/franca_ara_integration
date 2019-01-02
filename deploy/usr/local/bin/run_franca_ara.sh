#!/bin/sh -x

export VSOMEIP_CONFIGURATION="$(readlink -f /usr/local/share/franca-ara/conf/vsomeip_ecu1.json)"
#export VSOMEIP_CLIENTSIDELOGGING=true

[ -z "$VSOMEIP_CONFIGURATION" ] && { echo "ERROR: Did not find VSOMEIP_CONFIGURATION file as expected!" ; exit 1 ; }

# ---------
# Including the setup IP scripts.
# Just a simple setup for the demo.  Obviously done outside 
# (using root privileges) in a real setup.
IVI_IP=192.168.100.10
NETWORK=192.168.100.0
MASK=24
DEV=eth0
ip a a $IVI_IP/$MASK dev $DEV
# Add route if needed
route | grep -q $NETWORK
if [ $? -ne 0 ] ; then
   route add -net $NETWORK/$MASK dev $DEV
fi
# Multicast route, if needed
MASK=8
MCAST_NETWORK=224.0.0.0
route | grep -q $MCAST_NETWORK
if [ $? -ne 0 ] ; then
  route add -net $MCAST_NETWORK/$MASK dev $DEV
fi
# ---------

# Run vsomeipd if it's not in process list already
ps aux | grep -q [v]someipd 
if [ $? -eq 0 ] ; then
  echo 
  echo VSOMEIPD ALREADY RUNNING -- SKIPPED
  echo
else
  echo -------------------------------
  echo STARTING VSOMEIPD
  echo -------------------------------
  vsomeipd &
fi

  echo -------------------------------
  echo STARTING FRANCA-ARA
  echo -------------------------------

/usr/apps/franca-ara/bin/franca-ara -platform wayland


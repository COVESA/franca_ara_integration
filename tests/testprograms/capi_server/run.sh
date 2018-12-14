#!/bin/bash
cd $(dirname $0)

test_file_exists() {
  [ -f "$1" ] || { echo "Missing file $1 !" ; exit 1 ; }
}

export VSOMEIP_CONFIGURATION="$(readlink -f ./conf/vsomeip_ecu1.json)"
[ -z "$VSOMEIP_CONFIGURATION" ] && echo VSOMEIP_CONFIGURATION is empty!
test_file_exists $VSOMEIP_CONFIGURATION

export VSOMEIP_CLIENTSIDELOGGING=true

# Run vsomeipd if it's not in process list already
ps aux | grep -q [v]someipd 
if [ $? -eq 0 ] ; then
  echo
  echo VSOMEIPD ALREADY RUNNING -- SKIPPED
  echo
else
  echo -------------------------------
  echo "STARTING VSOMEIPD (hit return to continue)"
  echo -------------------------------
  read x
  LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 vsomeipd &
fi

echo -------------------------------
echo "STARTING CAPI_SERVER (hit return to continue"
echo -------------------------------
read x

LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 ./capi_server

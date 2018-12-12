#!/bin/bash -x
cd $(dirname $0)

test_file_exists() {
  [ -f "$1" ] || { echo "Missing file $1 !" ; exit 1 ; }
}

export VSOMEIP_CONFIGURATION="$(readlink -f ./conf/vsomeip.json)"
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
  echo STARTING VSOMEIPD
  echo -------------------------------
  LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 vsomeipd &
fi

echo -------------------------------
echo STARTING CAPI_SERVER
echo -------------------------------

LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 ./capi_server

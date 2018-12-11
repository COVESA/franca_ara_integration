#!/bin/bash
cd $(dirname $0)

test_file_exists() {
  [ -f "$1" ] || echo "Missing file $1 !"
}

export VSOMEIP_CONFIGURATION="$(readlink -f ./conf/vsomeip.json)"
test_file_exists $COMMONAPI_CONFIG
#test_file_exists $COMMONAPI_SOMEIP_CONFIG
test_file_exists $VSOMEIP_CONFIGURATION

export VSOMEIP_CLIENTSIDELOGGING=true

echo Starting simple_capi_server
echo
echo Start vsomeipd and vsomeip/client, but not vsomeip/server

LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 ./simple_capi_server

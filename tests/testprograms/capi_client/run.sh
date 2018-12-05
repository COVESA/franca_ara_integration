#!/bin/bash

export COMMONAPI_CONFIG="$(readlink -f ../../../conf/commonapi.ini)"
export COMMONAPI_SOMEIP_CONFIG="$(readlink -f ../../../conf/commonapi-someip.ini)"
export VSOMEIP_CONFIGURATION="$(readlink -f ../../../conf/vsomeip_ecu1.json)"
export VSOMEIP_CLIENTSIDELOGGING=true

cd $(dirname $0)
LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 ./capi_client

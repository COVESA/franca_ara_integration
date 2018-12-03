#!/bin/bash

cd "$(dirname "$0")"

export VSOMEIP_CONFIGURATION="$(readlink -f ./conf/vsomeip_ecu1.json)"
export VSOMEIP_CLIENTSIDELOGGING=true

LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 ./capi_client

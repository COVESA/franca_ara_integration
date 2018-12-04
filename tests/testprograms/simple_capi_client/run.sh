#!/bin/bash
cd $(dirname $0)
export VSOMEIP_APPLICATION_NAME=FrancaAraSomeIP_instance

#export COMMONAPI_CONFIG="$(readlink -f ../../../conf/commonapi.ini)"
#export COMMONAPI_SOMEIP_CONFIG="$(readlink -f ../../../conf/commonapi-someip.ini)"
#export VSOMEIP_CONFIGURATION="$(readlink -f ../../../conf/vsomeip_ecu1.json)"

export VSOMEIP_CLIENTSIDELOGGING=true

LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64 ./simple_capi_client

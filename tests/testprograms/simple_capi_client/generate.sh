#!/bin/bash

cd "$(dirname "$0")"

export COMMONAPI_CONFIG="$(readlink -f ../../../conf/commonapi.ini)"
export COMMONAPI_SOMEIP_CONFIG="$(readlink -f ../../../conf/commonapi-someip.ini)"
export VSOMEIP_CONFIGURATION="$(readlink -f ../../../conf/vsomeip_ecu1.json)"

CORE_GEN=../../../dependencies/build-common-api-cpp-native/project/cgen/commonapi-generator/commonapi-generator-linux-x86_64
SOMEIP_GEN=../../../dependencies/build-common-api-cpp-native/project/cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64

CORE_GEN="$(readlink -f $CORE_GEN)"
SOMEIP_GEN="$(readlink -f $SOMEIP_GEN)"

echo got: CORE_GEN=$CORE_GEN 
echo got: SOMEIP_GEN=$SOMEIP_GEN 

echo
echo GENERATING CODE
echo

# Note: this generates local fidl files located in simple_capi_client test directory
# These are not the same as for the main program
rm -rf src-gen
$CORE_GEN -sk fidl/vehicles.fidl
$SOMEIP_GEN fidl/vehicles.fdepl

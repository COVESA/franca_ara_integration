#!/bin/bash

cd "$(dirname "$0")"

export COMMONAPI_CONFIG="$(readlink -f ../../../conf/commonapi.ini)"
export COMMONAPI_SOMEIP_CONFIG="$(readlink -f ../../../conf/commonapi-someip.ini)"
export VSOMEIP_CONFIGURATION="$(readlink -f ../../../conf/vsomeip_ecu1.json)"

CORE_GEN=../../../dependencies/build-common-api-cpp-native/project/cgen/commonapi-generator/commonapi-generator-linux-x86_64
SOMEIP_GEN=../../../dependencies/build-common-api-cpp-native/project/cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64

CORE_GEN="$(readlink -f $CORE_GEN)"
SOMEIP_GEN="$(readlink -f $SOMEIP_GEN)"

if [ -z "$CORE_GEN" ]; then
  echo "Can't find code generator at location $CORE_GEN"
  exit 2
fi

if [ -z "$SOMEIP_GEN" ]; then
  echo "Can't find code generator at location $SOMEIP_GEN"
  exit 3
fi

echo Using: CORE_GEN=$CORE_GEN 
echo Using: SOMEIP_GEN=$SOMEIP_GEN 

echo
echo GENERATING CODE
echo

# Note: this generates local fidl files located in simple_capi_client test directory
# These are not the same as for the main program
rm -rf src-gen
$CORE_GEN -sk fidl/vehicles.fidl
$SOMEIP_GEN fidl/vehicles.fdepl

#!/bin/bash

cd "$(dirname "$0")"

CORE_GEN=../dependencies/build-common-api-cpp-native/project/cgen/commonapi-generator/commonapi-generator-linux-x86_64
SOMEIP_GEN=../dependencies/build-common-api-cpp-native/project/cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64

CORE_GEN="$(readlink -f $CORE_GEN)"
SOMEIP_GEN="$(readlink -f $SOMEIP_GEN)"

echo Using: CORE_GEN=$CORE_GEN 
echo Using: SOMEIP_GEN=$SOMEIP_GEN 

echo
echo GENERATING CODE
echo

rm -rf src-gen
$CORE_GEN -sk ../fidl/vehicles.fidl
$SOMEIP_GEN ../fidl/vehicles.fdepl
$CORE_GEN -sk ../fidl/drivingLane.fidl
$SOMEIP_GEN ../fidl/drivingLane.fdepl


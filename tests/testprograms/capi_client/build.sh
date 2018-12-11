#!/bin/sh

cd "$(dirname "$0")"

# This depends on where you installed the files
# but should not matter in the final SDK/Image builds
INCDIR="-I/usr/local/include/CommonAPI-3.1"

# Use the CC variable if it was set in an SDK
if [ -z "$CC" ] ; then
  CC=g++
  BINARY=capi_client
else
  # Assume this means we are building for target
  BINARY=capi_client_gdp
fi

set -x
$CC -o $BINARY -std=c++14 -I src-gen $INCDIR \
  main.cpp \
    src-gen/v1/genivi/aasr/showcase/*.cpp \
    -lCommonAPI-SomeIP  \
    -lCommonAPI \
    -lpthread \
    -lstdc++

#!/bin/sh

cd "$(dirname "$0")"

# Use the CC variable if it was set in an SDK
if [ -z "$CC" ] ; then
  CC=g++
fi

set -x
$CC -o simple_capi_server -std=c++14 -I src-gen -I/usr/local/include/CommonAPI-3.1 \
  main.cpp \
    src-gen/v1/genivi/testexec/*.cpp \
    -lCommonAPI-SomeIP  \
    -lCommonAPI \
    -lpthread


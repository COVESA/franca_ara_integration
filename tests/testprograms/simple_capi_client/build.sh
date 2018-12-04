#!/bin/sh -x

g++ -o simple_capi_client -I src-gen -I/usr/local/include/CommonAPI-3.1 \
  main.cpp \
    src-gen/v1/genivi/testexec/*.cpp \
    -lCommonAPI-SomeIP  \
    -lCommonAPI \
    -lpthread \
    -lstdc++


  #SomeIpNetworkThread.cpp \

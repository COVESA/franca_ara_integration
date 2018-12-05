#!/bin/sh -x

g++ -o capi_client -I src-gen -I/usr/local/include/CommonAPI-3.1 \
  main.cpp \
    src-gen/v1/genivi/aasr/showcase/*.cpp \
    -lCommonAPI-SomeIP  \
    -lCommonAPI \
    -lpthread \
    -lstdc++


  #SomeIpNetworkThread.cpp \

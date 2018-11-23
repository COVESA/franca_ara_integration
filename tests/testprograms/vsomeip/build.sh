#!/bin/bash -xe

cd "$(dirname "$0")"
rm -rf build
mkdir -p build
cd build
cmake ..
make -j8

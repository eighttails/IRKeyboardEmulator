#!/bin/bash
rm -rf build 2> /dev/null
mkdir build
cd build

cmake .. -DIR_STUB=OFF -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc)



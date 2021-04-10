#!/bin/bash
rm -rf build 2> /dev/null
mkdir build
cd build

cmake ../src -DIR_STUB=OFF -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)



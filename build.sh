#!/bin/bash
rm -rf build 2> /dev/null
mkdir build
cd build

cmake ..
make -j$(nproc)



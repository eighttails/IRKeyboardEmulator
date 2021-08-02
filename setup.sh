#!/bin/bash
sudo apt install build-essential pigpio cmake
sudo systemctl enable pigpiod

BUILD_DIR=../build-IRKeyboardEmulator
rm -rf $BUILD_DIR
cmake -S src -DIR_STUB=OFF -DCMAKE_BUILD_TYPE=Release -B $BUILD_DIR
cmake --build $BUILD_DIR
sudo cmake --install $BUILD_DIR

echo "@reboot   /usr/local/bin/IRKeyboardEmulator" | crontab

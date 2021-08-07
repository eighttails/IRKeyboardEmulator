#!/bin/bash
sudo apt update
sudo apt upgrade -y
sudo apt install -y build-essential pigpio cmake
sudo apt autoremove
sudo apt clean
sudo systemctl enable pigpiod

BUILD_DIR=../build-IRKeyboardEmulator
rm -rf $BUILD_DIR
cmake -S src -DIR_STUB=OFF -DCMAKE_BUILD_TYPE=Release -B $BUILD_DIR
cmake --build $BUILD_DIR
sudo cmake --install $BUILD_DIR

sudo raspi-config nonint do_boot_behaviour B2

echo "/usr/local/bin/IRKeyboardEmulator" >> ~/.bashrc


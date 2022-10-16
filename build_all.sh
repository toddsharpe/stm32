#!/bin/bash

echo "Building App"
cd Src/App
make
cd ../../

echo "Building Bootloader"
cd Src/Bootloader
make
cd ../..

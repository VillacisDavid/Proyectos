#!/bin/bash
if [ ! -d "./build" ]; then mkdir build; fi
cd build
cmake ../source
cmake --build .
cd ..
if [ -f "./build/sort" ]; then 
echo "Ejecutable 1"
./build/sort
fi
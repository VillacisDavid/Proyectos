#!/bin/bash
cd build
cmake ../source
cmake --build  .
./step1
cd ..
#!/bin/bash
set -e

cmake -S . -B build
cmake --build build -j4
./build/smart_inventory
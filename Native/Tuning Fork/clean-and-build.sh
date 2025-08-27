#! /bin/sh
set -e

rm -rf build
mkdir build
cd build
cmake ..
cmake --build .

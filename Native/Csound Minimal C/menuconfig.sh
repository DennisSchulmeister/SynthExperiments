#! /bin/sh
set -e

rm -rf build
mkdir build
cd build
ccmake ..
#cmake --build .

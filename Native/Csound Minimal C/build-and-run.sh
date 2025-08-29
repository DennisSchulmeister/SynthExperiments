#! /bin/sh
set -e

cd build
cmake --build .

echo
echo
echo

./csound-minimal-c

echo
echo
echo

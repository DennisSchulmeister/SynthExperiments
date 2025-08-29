#! /bin/sh
set -e

cd build
cmake --build .

echo
echo
echo

./csound-skeleton

echo
echo
echo

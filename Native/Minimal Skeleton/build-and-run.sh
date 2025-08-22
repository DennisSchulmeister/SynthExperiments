#! /bin/sh
set -e

cd build
cmake --build .

echo
echo
echo

./csound_skeleton

echo
echo
echo

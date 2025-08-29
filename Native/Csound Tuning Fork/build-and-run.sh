#! /bin/sh
set -e

cd build
cmake --build .

echo
echo
echo

./csound-tuning-fork

echo
echo
echo

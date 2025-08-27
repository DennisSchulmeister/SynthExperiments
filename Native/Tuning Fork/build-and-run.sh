#! /bin/sh
set -e

cd build
cmake --build .

echo
echo
echo

./tuning-fork

echo
echo
echo

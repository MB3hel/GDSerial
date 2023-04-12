#!/usr/bin/env bash

DIR=$(realpath $(dirname "$0"))

echo ""
echo "Run all builds and copy_to_test.sh first!!!"
echo ""

read -p "Version: " VERSION


cd "$DIR/test/"
zip ../bin/GDSerial-${VERSION}.zip -r GDSerial -x GDSerial/.gitignore

#!/usr/bin/env bash

DIR=$(realpath $(dirname "$0"))
cd "$DIR"
rm -rf test/GDSerial/linux64
rm -rf test/GDSerial/win64
rm -rf test/GDSerial/mac64
if [ -d bin/linux64 ]; then
    cp -r bin/linux64 test/GDSerial
fi
if [ -d bin/win64 ]; then
    cp -r bin/win64 test/GDSerial
fi
if [ -d bin/mac64 ]; then
    cp -r bin/mac64 test/GDSerial
fi

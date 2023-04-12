#!/usr/bin/env bash
set -e

DIR=$(realpath $(dirname "$0"))
cd "$DIR"

# Build libgodot-cpp if it does not already eixst
BUILD_GODOT_CPP=false
if [ ! -f godot-cpp/bin/libgodot-cpp.linux.release.64.a ]; then
    BUILD_GODOT_CPP=true
fi
if [ ! -f godot-cpp/bin/libgodot-cpp.linux.debug.64.a ]; then
    BUILD_GODOT_CPP=true
fi
if [ "$BUILD_GODOT_CPP" == "true" ]; then
    echo "*** BUILDING GODOT-CPP"
    cd godot-cpp
    scons -c
    scons platform=linux generate_bindings=yes target=debug
    scons platform=linux generate_bindings=yes target=release
    cd ..
fi

# Build libserial
BUILD_SERIAL=fasle
if [ ! -f serial/build-debug-linux-64/devel/lib/libserial.a ]; then
    BUILD_SERIAL=true
fi
if [ ! -f serial/build-release-linux-64/devel/lib/libserial.a ]; then
    BUILD_SERIAL=true
fi
if [ "$BUILD_SERIAL" == "true" ]; then
    echo "*** BUILDING SERIAL"
    cd serial
    rm -rf build-debug-linux-64
    rm -rf build-release-linux-64
    mkdir build-debug-linux-64
    cd build-debug-linux-64
    cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON
    cmake --build .
    cd ..
    mkdir build-release-linux-64
    cd build-release-linux-64
    cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON
    cmake --build .
    cd ..
    cd ..
fi


# Build debug libgdserial
CPPFLAGS="-fPIC -std=c++14 -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot-headers -g -O0"
rm -rf bin/libgdseral.linux.debug.64.so
rm -rf bin/obj
mkdir bin/obj
for sfile in src/*.cpp; do
    bname=$(basename "$sfile")
    bname=$(basename "$sfile" .cpp)
    ofile="bin/obj/${bname}.o"
    echo "g++ $CPPFLAGS \"$sfile\" -o \"$ofile\""
    g++ $CPPFLAGS -c "$sfile" -o "$ofile"
done
echo "g++ -shared -o bin/libgdseral.linux.debug.64.so bin/obj/*.o godot-cpp/bin/libgodot-cpp.linux.debug.64.a serial/build-debug-linux-64/devel/lib/libserial.a"
g++ -shared -o bin/libgdseral.linux.debug.64.so bin/obj/*.o godot-cpp/bin/libgodot-cpp.linux.debug.64.a serial/build-debug-linux-64/devel/lib/libserial.a
rm -r bin/obj

# Build release libgdserial
CPPFLAGS="-fPIC -std=c++14 -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot-headers -O3"
rm -rf bin/libgdseral.linux.release.64.so
rm -rf bin/obj
mkdir bin/obj
for sfile in src/*.cpp; do
    bname=$(basename "$sfile")
    bname=$(basename "$sfile" .cpp)
    ofile="bin/obj/${bname}.o"
    echo "g++ $CPPFLAGS \"$sfile\" -o \"$ofile\""
    g++ $CPPFLAGS -c "$sfile" -o "$ofile"
done
echo "g++ -shared -o bin/libgdseral.linux.release.64.so bin/obj/*.o godot-cpp/bin/libgodot-cpp.linux.release.64.a serial/build-release-linux-64/devel/lib/libserial.a"
g++ -shared -o bin/libgdseral.linux.release.64.so bin/obj/*.o godot-cpp/bin/libgodot-cpp.linux.release.64.a serial/build-release-linux-64/devel/lib/libserial.a
rm -r bin/obj
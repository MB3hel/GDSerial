#!/usr/bin/env bash
set -e

DIR=$(realpath $(dirname "$0"))
cd "$DIR"
mkdir -p bin

# Build libgodot-cpp if it does not already eixst
BUILD_GODOT_CPP=false
if [ ! -f godot-cpp/bin/libgodot-cpp.osx.release.x86_64.a ]; then
    BUILD_GODOT_CPP=true
fi
if [ "$BUILD_GODOT_CPP" == "true" ]; then
    echo "*** BUILDING GODOT-CPP"
    cd godot-cpp
    scons platform=osx macos_arch=x86_64 generate_bindings=yes target=release
    cd ..
fi

# Build libserial
BUILD_SERIAL=fasle
if [ ! -f serial/build/mac64/libserial.a ]; then
    BUILD_SERIAL=true
fi
if [ "$BUILD_SERIAL" == "true" ]; then
    echo "*** BUILDING SERIAL"
    cd serial
    rm CMakeLists.txt
    cp ../serial-alt-cmake.txt CMakeLists.txt
    rm -rf build
    mkdir -p build/mac64
    cd build/mac64
    x86_64-apple-darwin20.2-cmake ../.. -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON
    cmake --build .
    cd ../..
    cd ..
fi


# Build release libgdserial
CPPFLAGS="-arch x86_64 -fPIC -std=c++14 -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot-headers -Iinclude -Iserial/include -O3"
rm -rf bin/mac64/
rm -rf bin/obj
mkdir bin/obj
mkdir bin/mac64
for sfile in src/*.cpp; do
    bname=$(basename "$sfile")
    bname=$(basename "$sfile" .cpp)
    ofile="bin/obj/${bname}.o"
    echo "o64-clang++ $CPPFLAGS \"$sfile\" -o \"$ofile\""
    o64-clang++ $CPPFLAGS -c "$sfile" -o "$ofile"
done
echo "o64-clang++ -shared -o bin/mac64/libGDSerial.dylib bin/obj/*.o godot-cpp/bin/libgodot-cpp.osx.release.x86_64.a serial/build/mac64/libserial.a"
o64-clang++ -shared -o bin/mac64/libGDSerial.dylib bin/obj/*.o godot-cpp/bin/libgodot-cpp.osx.release.x86_64.a serial/build/mac64/libserial.a
rm -r bin/obj
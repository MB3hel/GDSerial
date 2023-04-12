#!/usr/bin/env bash
set -e

DIR=$(realpath $(dirname "$0"))
cd "$DIR"
mkdir -p bin

# Build libgodot-cpp if it does not already eixst
BUILD_GODOT_CPP=false
if [ ! -f godot-cpp/bin/libgodot-cpp.windows.release.64.a ]; then
    BUILD_GODOT_CPP=true
fi
if [ "$BUILD_GODOT_CPP" == "true" ]; then
    echo "*** BUILDING GODOT-CPP"
    cd godot-cpp
    scons platform=windows use_mingw=yes generate_bindings=yes target=release
    cd ..
fi

# Build libserial
BUILD_SERIAL=fasle
if [ ! -f serial/build/win64/libserial.a ]; then
    BUILD_SERIAL=true
fi
if [ "$BUILD_SERIAL" == "true" ]; then
    echo "*** BUILDING SERIAL"
    cd serial
    rm CMakeLists.txt
    cp ../serial-alt-cmake.txt CMakeLists.txt
    rm -rf build
    mkdir -p build/win64
    cd build/win64
    cmake ../.. -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake
    cmake --build .
    cd ../..
    cd ..
fi


# Build release libgdserial
CPPFLAGS="-fPIC -std=c++14 -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot-headers -Iinclude -Iserial/include -O3"
rm -rf bin/win64/
rm -rf bin/obj
mkdir bin/obj
mkdir bin/win64
for sfile in src/*.cpp; do
    bname=$(basename "$sfile")
    bname=$(basename "$sfile" .cpp)
    ofile="bin/obj/${bname}.o"
    echo "x86_64-w64-mingw32-g++ $CPPFLAGS \"$sfile\" -o \"$ofile\""
    x86_64-w64-mingw32-g++ $CPPFLAGS -c "$sfile" -o "$ofile"
done
echo "x86_64-w64-mingw32-g++ -shared -o bin/win64/libgdseral.dll bin/obj/*.o godot-cpp/bin/libgodot-cpp.windows.release.64.a serial/build/win64/libserial.a"
x86_64-w64-mingw32-g++ -shared -o bin/win64/libgdseral.dll bin/obj/*.o godot-cpp/bin/libgodot-cpp.windows.release.64.a serial/build/win64/libserial.a
rm -r bin/obj
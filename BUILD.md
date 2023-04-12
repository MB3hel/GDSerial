# Building / Development

## Clone Repo

```
git clone https://github.com/MB3hel/GDSerial.git
cd GDSerial
git submodule update --init --recursive
```

## Build Setup

All builds are tested on Ubuntu 22.04 amd64 host. Other Linux distributions should work too.

### Build Linux AMD64

- Setup Ubuntu bionic chroot (ensures glibc compatibility)
- In chroot
    - Add universe and multiverse to /etc/apt/sources.list
    - Use apt to install python3-pip cmake build-essentials
    - Use pip3 to install scons
    - Run build_linux_amd64.sh


### Build Windows AMD64

- Use apt to install python3-pip cmake mingw-w64
- Run the following to ensure posix thread model is used
    ```
    sudo update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix
    sudo update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix
    ```
- Run build_win_amd64.sh

### Build macOS AMD64

- Use apt to install clang cmake git patch python3 libssl-dev lzma-dev libxml2-dev llvm-dev uuid-dev "libstdc++-*-dev"
- Build and install [osxcross](https://github.com/tpoechtrager/osxcross). Edit profile so it is in your path.
- Edit `godot-cpp/SConstruct` and replace CXX setting on line 232 with the following
```
env["CXX"] = "x86_64-apple-darwin20.2-clang++"
env["AR"] = "x86_64-apple-darwin20.2-ar"
env["RANLIB"] = "x86_64-apple-darwin20.2-ranlib"
env["LINK"] = "x86_64-apple-darwin20.2-clang++"
```
- Run build_mac_amd64.sh (may need to change `-darwin20.2` if not using same SDK when building osxcross)

## Testing

- Build
- Run `copy_to_test.sh`
- Use the `test` project in Godot editor

To test on non-linux system

- Zip test project (after building for target system and copying to test)
- Copy zip to other system
- Test as usual in editor


## Packaging

- Build
- Copy to test
- Run `package.sh`


# GDSerial

Serial library for Godot Engine using [libserial](https://github.com/wjwwood/serial)

## Build Setup

All builds are done on Ubuntu 22.04 amd64 host.

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
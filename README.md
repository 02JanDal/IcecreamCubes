IcecreamCubes
=============

# Building

## Linux

1. Get the dependencies: Git, Qt 5, CMake, Lua 5.1
2. Issue the following commands:

```Shell
git clone https://github.com/02JanDal/JansGameFramework.git
git clone https://github.com/02JanDal/IcecreamCubes.git
cd IcecreamCubes
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<install-path> -DCMAKE_PREFIX_PATH=<path-to-qt>/lib/cmake -DJGF_PATH=$PWD/../JansGameFramework ..
make
make install
```

The \<install-path\> can be left out and will default to /usr/local on linux

## Windows

TODO

## Mac OS X

TODO

## Android/BlackBerry/iOS

TODO

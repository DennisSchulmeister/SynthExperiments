Minimal C/CMake Skeleton
========================

1. [Description](#description)
1. [How to build](#how-to-build)

Description
-----------

This is a most minimal skeleton for using the Csound API in a C program
built with Cmake. Use this as a starting point if you want to write a
program with plain C.

The build system should be fairly cross-platform, but I have in reality
only tried on Linux. All you need to get started:

* A C toolchain (aka `build-essential` on Debian)
* CMake
* Csound
* Csound C headers (aka `libcsound-dev` on Debian)

On Linux you can simply install them with your package manager. On Windows
you are on your own. But you can use the `CSOUND6_DIR` configuration option
or environment variable to point the build system to the Csound headers.

How to build
------------

On Linux you can simply use the shell scripts in this directory. Otherwise,
the basic procedure is:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

The executable will be in the `build` directory. To start over simply delete
the directory.

If you want to use the graphical configuration menu the last but one
command changes to `ccmake ..` to edit the configuration and generate
the build files (see `menuconfig.sh` script):

```sh
mkdir build
cd build
ccmake ..
cmake --build .
```

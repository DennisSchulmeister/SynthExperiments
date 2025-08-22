Minimal C/CMake Skeleton
========================

1. [Description](#description)
1. [How to build](#how-to-build)

Description
-----------

This is a most minimal skeleton for using the Csound API in a C program
built with Cmake. The actual C code is taken almost verbatim from the
Csound API documentation. Use this as a starting point for C or C++,
if all you want is to build a simple command line program.

The build system should be fairly cross-platform, but I have in reality
only tried on Linux. All you need to get started:

* A C/C++ toolchain (aka `build-essential` on Debian)
* CMake
* Csound
* Csound headers

On Linux you can simply install them with your package manager. On Windows
you are on your own. But you can use the `CSOUND_DIR` configuration option
or envirnment variable to point the build system to the Csound headers.

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

Minimal C++/CMake Skeleton
==========================

1. [Description](#description)
1. [How to build](#how-to-build)

Description
-----------

This is a most minimal skeleton for using the Csound API in a C++ program
built with Cmake. Use this as a starting point if you want to write a
program with C++ instead of plain C. This project is mostly identical to
the minimal C skeleton, except for using C++ throughout. And since modern
C++ also includes a cross-platform standard library, there is only very
little platform-dependent code (which is fully optional here).

The build system should be fairly cross-platform, but I have in reality
only tried on Linux. All you need to get started:

* A C++ toolchain (aka `build-essential` on Debian)
* CMake
* Csound
* Csound C++ headers (aka `libcsnd-dev` on Debian)

On Linux you can simply install them with your package manager. On Windows
you are on your own. But you can use the `CSOUND6_CXX_DIR` configuration
option or environment variable to point the build system to the Csound headers.

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

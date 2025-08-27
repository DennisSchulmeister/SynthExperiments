Tuning Fork (Native)
====================

1. [Description](#description)
1. [How to build](#how-to-build)

Description
-----------

This extends the minimal Csound skeleton for native apps with the
following features:

* C++ instead of plain C
* Reading the Csound code from a separate file
* Lightweight user interface courtesy of Dear Im GUI

The UI uses SDL2 for platform-neutral input & output. All in all the
code is still minimalistic to serve as a template for larger projects.

How to build
------------

The build system should be fairly cross-platform, but I have in reality
only tried on Linux. All you need to get started:

* A C/C++ toolchain (aka `build-essential` on Debian)
* CMake
* Csound
* Csound C++ headers (aka `libcsnd-dev` on Debian)

On Linux you can simply install them with your package manager. On Windows
you are on your own. But you can use the `CSOUND_DIR` configuration option
or environment variable to point the build system to the Csound headers.

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

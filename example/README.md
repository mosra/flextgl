flextGL example
===============

This is a small example program that demonstrates how flextGL can be included in your build system.

There are two separate build scripts available:

Make
----

This only works with Linux.

Just call `make` to build the example program.

You can find the build script in `Makefile`.

CMake
-----

This works both with Windows and Linux.

For building under Linux, call:

    mkdir build
    make

This should build the example in the separate build directory and copy all files necessary for execution in there.

For building with Windows and Visual Studio, the easiest way is to use cmake-gui. Select the path of the example
project. Select a build path and click on "Generate". This will let you select the compiler chain. There is currently only support for 32-bit Visual Studio 2008 and 2010.

After doing this, there will be a Visual Studio solution file in the build directory. Open it and build the contained `example` project.

You can find the build script in 'CMakeLists.txt'
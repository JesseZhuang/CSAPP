## Dependencies

This project was built and tested on the Mac OS X platform with the following dependencies:

* CMake = 3.28.6
* Boost = 1.86.0

Clion bundled Cmake and LLDB (debugger). Install boost (unit test) with homebrew (installed
in `/opt/homebrew/Cellar/boost`).

## Instructions

Do as you would any CMake project to compile:

```
cd cmake
cmake ..
make
```

Run application:

```
cd bin
./cmake_boost_demo.o
```

Run unit test suite:

```
cd cmake/test
ctest
```

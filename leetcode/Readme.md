## Dependencies

This project was built and tested on the Mac OS X platform with the following dependencies:

* CMake = 3.28.6
* Boost = 1.86.0

Clion bundled Cmake and LLDB (debugger). Install boost (unit test) with homebrew (installed
in `/opt/homebrew/Cellar/boost`).

## CLion Instructions

Run -> edit configurations -> add new Boot.Test configuration -> select leet_code_unit_test target. Run all tests.

Or

`/Volumes/code/CSAPP/leetcode/cmake-build-debug/test/bin/leet_code_unit_tests --run_test=list_node_test --logger=HRF,all --color_output=false --report_format=HRF --show_progress=no`

To run single test, have to manually type in the test name as pattern in the window UI. Or run one from the demo folder then select others to run.

`/Volumes/code/CSAPP/leetcode/cmake-build-debug/test/bin/leet_code_unit_tests --run_test=foo_suite/constructor_test --logger=HRF,all --color_output=false --report_format=HRF --show_progress=no`

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

## Dependencies

This project was built and tested on the Mac OS X platform with the following dependencies:

* CMake = 3.29.6
* GoogleTest = 1.15.0

Clion bundled Cmake and LLDB (debugger). GoogleTest is downloaded with CMake.

## cpp version

LeetCode notes: Compiled with clang 17 using the latest C++ 23 standard, and libstdc++ provided by GCC 13. Your code is compiled with level two optimization (-O2). AddressSanitizer is also enabled to help detect out-of-bounds and use-after-free bugs. Most standard library headers are already included automatically for your convenience.

Apple clang c++ support: https://developer.apple.com/xcode/cpp/

Clion c++ support: https://www.jetbrains.com/help/clion/c-support.html

```shell
/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/Applications/CLion.app/Contents/bin/ninja/mac/aarch64/ninja -G Ninja -S /Volumes/code/CSAPP/leetcode -B /Volumes/code/CSAPP/leetcode/cmake-build-debug
-- The C compiler identification is AppleClang 15.0.0.15000309
-- The CXX compiler identification is AppleClang 15.0.0.15000309
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Configuring done (1.9s)
-- Generating done (0.0s)
-- Build files have been written to: /Volumes/code/CSAPP/leetcode/cmake-build-debug

[Finished]
```

## CLion Instructions

In project root folder, right click, then and load or reload CmakeLists.txt.

Run -> edit configurations -> should be able to find

LeetCode-src-main

```shell
/Volumes/code/CSAPP/leetcode/cmake-build-debug/LeetCode_src_main
Hello, World!
binary search 2, index: 2
binary search 3, index: -4
negating index -4 gives 3
after insert nums[3] is 3
nums size is 6

Process finished with exit code 0
```

Run -> edit configurations -> + -> Google Test -> change target in the drop down to LeetCode_test

```shell
/Volumes/code/CSAPP/leetcode/cmake-build-debug/test/LeetCode_test --gtest_filter=* --gtest_color=no
Testing started at 11:50 PM ...
Running main() from /Volumes/code/CSAPP/leetcode/cmake-build-debug/_deps/googletest-src/googletest/src/gtest_main.cc
Process finished with exit code 0
```

Can right click a test cpp file and run all tsts in there.

```shell
/Volumes/code/CSAPP/leetcode/cmake-build-debug/test/LeetCode_test --gtest_filter=BisectTestF.bisect_found:BisectTestF/*.bisect_found:BisectTestF.bisect_found/*:*/BisectTestF.bisect_found/*:*/BisectTestF/*.bisect_found:BisectTestF.bisect_not_found:BisectTestF/*.bisect_not_found:BisectTestF.bisect_not_found/*:*/BisectTestF.bisect_not_found/*:*/BisectTestF/*.bisect_not_found:BisectTestF.bisect_not_found_insert:BisectTestF/*.bisect_not_found_insert:BisectTestF.bisect_not_found_insert/*:*/BisectTestF.bisect_not_found_insert/*:*/BisectTestF/*.bisect_not_found_insert --gtest_color=no
Testing started at 11:52 PM ...
Running main() from /Volumes/code/CSAPP/leetcode/cmake-build-debug/_deps/googletest-src/googletest/src/gtest_main.cc
Process finished with exit code 0
```

The run window showed "Tests passed:3 of 3 tests-0ms".

Alternatively, in `test_main.cpp`, click the gutter icon and run `LeetCode_test`, saw colored output.

```shell
/Volumes/code/CSAPP/leetcode/cmake-build-debug/test/LeetCode_test
[==========] Running 4 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from array
[ RUN      ] array.min_cost_unequal_array
[       OK ] array.min_cost_unequal_array (0 ms)
[----------] 1 test from array (0 ms total)

[----------] 3 tests from BisectTestF
[ RUN      ] BisectTestF.bisect_found
[       OK ] BisectTestF.bisect_found (0 ms)
[ RUN      ] BisectTestF.bisect_not_found
[       OK ] BisectTestF.bisect_not_found (0 ms)
[ RUN      ] BisectTestF.bisect_not_found_insert
[       OK ] BisectTestF.bisect_not_found_insert (0 ms)
[----------] 3 tests from BisectTestF (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 4 tests.

Process finished with exit code 0
```
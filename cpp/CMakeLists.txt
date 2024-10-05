cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 23)
set(SRC_EXE ${CMAKE_PROJECT_NAME}_src_main)
add_executable(${SRC_EXE} helloArgs.cpp)

# build leetcode first before this
add_subdirectory(../leetcode/cmake-build-debug/_deps/googletest-src ./google-test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# generate debug information
set(CMAKE_CXX_FLAGS "-g")

include_directories(src)
add_subdirectory(src)

add_subdirectory(test)

target_link_libraries(${SRC_EXE} ${CMAKE_PROJECT_NAME}_lib)

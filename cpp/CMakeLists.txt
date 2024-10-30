cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 23)
set(SRC_EXE ${CMAKE_PROJECT_NAME}_src_main)
add_executable(${SRC_EXE} helloArgs.cpp)

# generate debug information
set(CMAKE_CXX_FLAGS "-g")

include_directories(src)
add_subdirectory(src)

add_subdirectory(test)

# download gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(${SRC_EXE} ${CMAKE_PROJECT_NAME}_lib)

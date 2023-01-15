# https://github.com/MarinaKalashina/DateConverter_withTests
cmake_minimum_required(VERSION 3.5)
project(InCodeCpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES helloworld.cpp)
add_executable(helloworld_exe.o ${SOURCE_FILES})

#include_directories(vector)
# add_subdirectory(vector)

# target_link_libraries(DateConverter_run DateConverter_lib)

add_subdirectory(test)

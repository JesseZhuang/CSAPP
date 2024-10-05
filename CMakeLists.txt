cmake_minimum_required(VERSION 3.0.0)
project(csapp VERSION 0.1.0)
add_definitions(-std=c++17)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} ./cpp/helloArgs.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

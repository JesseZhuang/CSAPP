cmake_minimum_required(VERSION 3.14)

# Definitions
set(PROJECT_NAME_STR leet_code)
# Clion will ignore this and use ./cmake-build-debug
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

# Project title and define versioning
project(${PROJECT_NAME_STR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Build object files for reuse (e.g. in test)
#ADD_LIBRARY(demo_objects OBJECT ${INC_FILES} ${SRC_FILES})

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# unit tests
add_subdirectory(test)

include_directories(${Boost_INCLUDE_DIRS})

# build, if you need an executable
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES})
add_executable(${PROJECT_NAME_STR}.o ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME_STR}.o ${Boost_LIBRARIES})

cmake_minimum_required(VERSION 3.14)

# Clion will ignore this and use ./cmake-build-debug
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(PROJECT_UNIT_TESTS_NAME leet_code_unit_tests)

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Gather the header and source files
#file(GLOB UNIT_TESTS_INC_FILES ${PROJECT_SOURCE_DIR}/test/*/*.hpp)
file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*/*.cpp)

# Include paths
set(UNIT_TESTS_INCLUDES ../src ${Boost_INCLUDE_DIR})

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${UNIT_TESTS_INCLUDES})

# Build unit tests
add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${PROJECT_UNIT_TESTS_NAME} ${SRC_FILES} ${UNIT_TESTS_SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} ${Boost_LIBRARIES})

#enable_testing()
#add_test(DemoTest ${PROJECT_UNIT_TESTS_NAME})
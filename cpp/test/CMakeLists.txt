set(TEST_NAME ${CMAKE_PROJECT_NAME}_test)
project(${TEST_NAME})

file(GLOB_RECURSE SRC_FILES ./*/*.cpp ./test_main.cpp)

add_executable(${TEST_NAME} ${SRC_FILES})

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(${TEST_NAME} ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(${TEST_NAME} gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

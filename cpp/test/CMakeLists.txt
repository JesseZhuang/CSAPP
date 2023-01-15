set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

file(GLOB UNIT_TEST_SOURCES CONFIGURE_DEPENDS "./*.cpp")

add_executable(Boost_Tests_run ${UNIT_TEST_SOURCES})
target_link_libraries(Boost_Tests_run ${Boost_LIBRARIES})
# target_link_libraries (Boost_Tests_run DateConverter_lib)
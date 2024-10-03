#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include "shared/Foo.hpp"


BOOST_AUTO_TEST_SUITE(foo_suite)

    BOOST_AUTO_TEST_CASE(constructor_test)
    {
        Foo foo(3);
        BOOST_CHECK_EQUAL(foo.doubleValue(), 6);
    }

BOOST_AUTO_TEST_SUITE_END()
// with Clion
// /Volumes/workplace/projects/CSAPP/cpp/leetcode/cmake-build-debug/test/leet_code_unit_tests
// --run_test=foo_suite --logger=HRF,all --color_output=false --report_format=HRF --show_progress=no

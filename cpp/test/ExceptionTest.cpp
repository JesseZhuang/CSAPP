#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <string>

const std::string message = "cannot divide by 0";

int divide(int top, int bottom) {
    if (bottom == 0) throw std::runtime_error(message);
    return top / bottom;
}

BOOST_AUTO_TEST_SUITE(exception_tests)

    BOOST_AUTO_TEST_CASE(catch_exception) {
        try {
            divide(10, 0);
        } catch (std::runtime_error e) {
            BOOST_CHECK_EQUAL(message, e.what());
        }
    }

BOOST_AUTO_TEST_SUITE_END()
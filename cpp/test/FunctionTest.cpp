#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <string>

int factorial(int n) {
    int res = 1;
    while (n) res *= n--;
    return res;
}

int reset(int *ip) {
    *ip = 0;
    ip = 0; // local copy set to nullptr
}

using namespace std;

bool isShorter(const string &s1, const string &s2) { // use const if no mutation
    // avoid copy expensive arguments, pass by ref
    return s1.size() < s2.size();
}

BOOST_AUTO_TEST_SUITE(function_tests)

    BOOST_AUTO_TEST_CASE(pass_by_value1) {
        int n = 3;
        BOOST_CHECK_EQUAL(6, factorial(n));
        BOOST_CHECK_EQUAL(3, n); // copied value into function factorial
    }

    BOOST_AUTO_TEST_CASE(pass_by_value2) {
        int i = 23;
        int *ip = &i;
        BOOST_TEST_MESSAGE("pointer address before reset: " << ip);
        reset(ip);
        BOOST_TEST_MESSAGE("pointer address after reset: " << ip); // same to before 0x7ff7b8a9d754
        BOOST_CHECK_EQUAL(0, i);
    }

    BOOST_AUTO_TEST_CASE(pass_by_ref1) {
        BOOST_CHECK(isShorter("ab", "abc"));
    }


BOOST_AUTO_TEST_SUITE_END()

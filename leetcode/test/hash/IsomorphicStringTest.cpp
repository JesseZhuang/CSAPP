#include <boost/test/unit_test.hpp>
#include "hash/IsomorphicString.hpp"

BOOST_AUTO_TEST_SUITE(leetcode)

    BOOST_AUTO_TEST_CASE(isomorphic_string_test) {
        IsomorphicString tbt;
        BOOST_CHECK_EQUAL(true, tbt.isIsomorphicMap("paper", "title"));
        BOOST_CHECK_EQUAL(true, tbt.isIsomorphicArray2("paper", "title"));
    }

BOOST_AUTO_TEST_SUITE_END()

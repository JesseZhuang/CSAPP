#include <boost/test/unit_test.hpp>
#include "string/ValidAnagram.hpp"

// CLion test config: test target leet_code_unit_tests
BOOST_AUTO_TEST_CASE(lc_solution_test) {
    ValidAnagram va;
    BOOST_CHECK_EQUAL(true, va.isAnagram("anagram", "nagaram"));
    BOOST_CHECK_EQUAL(false, va.isAnagram("rat", "car"));
    BOOST_CHECK_EQUAL(false, va.isAnagramArray("rat", "car"));
}

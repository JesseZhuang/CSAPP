#include <boost/test/unit_test.hpp>
#include "hash/IsomorphicString.hpp"

BOOST_AUTO_TEST_CASE(isomorphic_string_test) {
    IsomorphicString tbt;
    BOOST_CHECK_EQUAL(true, tbt.isIsomorphicMap("paper", "title"));
}

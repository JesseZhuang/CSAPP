
#include <boost/test/unit_test.hpp>
#include "string/Manacher.hpp"
#include <iostream>

using namespace std;

BOOST_AUTO_TEST_CASE(manacher) {
    string s = "abba";
    Manacher m(s); // copy string in constructor
    BOOST_CHECK_EQUAL("abba", m.longestPalindromeSubstring());
    BOOST_CHECK_EQUAL(6, m.cntPalindromeSubstrings());
    s[0] = 'b';
    BOOST_CHECK_EQUAL("abba", m.s); // still abba
    BOOST_CHECK_EQUAL("bbba", s); // changed to bbba
}

#include "gtest/gtest.h"
#include "string/Manacher.hpp"

using namespace std;

TEST(string, manacher) {
    string s = "abba";
    Manacher m(s); // copy string in constructor
    ASSERT_EQ(6, m.cntPalindromeSubstrings());
    ASSERT_EQ("abba", m.longestPalindromeSubstring());
    s[0] = 'b';
    ASSERT_EQ("abba", m.s); // still abba
    ASSERT_EQ("bbba", s); // changed to bbba
}

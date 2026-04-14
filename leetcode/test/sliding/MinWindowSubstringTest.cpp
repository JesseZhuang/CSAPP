#include "gtest/gtest.h"
#include "sliding/MinWindowSubstring.hpp"

TEST(sliding, min_window_substring) {
    EXPECT_EQ("BANC", MinWindowSubstring::minWindow("ADOBECODEBANC", "ABC"));
    EXPECT_EQ("a", MinWindowSubstring::minWindow("a", "a"));
    EXPECT_EQ("", MinWindowSubstring::minWindow("a", "aa"));
    EXPECT_EQ("", MinWindowSubstring::minWindow("a", "b"));
    EXPECT_EQ("a", MinWindowSubstring::minWindow("ab", "a"));
    EXPECT_EQ("b", MinWindowSubstring::minWindow("ab", "b"));
    EXPECT_EQ("abc", MinWindowSubstring::minWindow("abc", "ac"));
    EXPECT_EQ("ab", MinWindowSubstring::minWindow("bdab", "ab"));
    EXPECT_EQ("aaa", MinWindowSubstring::minWindow("aaflslflsldkalskaaa", "aaa"));
    EXPECT_EQ("cwae", MinWindowSubstring::minWindow("cabwefgewcwaefgcf", "cae"));
}

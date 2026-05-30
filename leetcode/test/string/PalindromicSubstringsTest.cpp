#include "gtest/gtest.h"
#include "string/PalindromicSubstrings.hpp"

TEST(string, palindromic_substrings_expand) {
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("abc"), 3);
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("aaa"), 6);
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("a"), 1);
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("aa"), 3);
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("racecar"), 10);
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("aaaa"), 10);
    ASSERT_EQ(PalindromicSubstrings::countSubstrings("abba"), 6);
}

TEST(string, palindromic_substrings_manacher) {
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("abc"), 3);
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("aaa"), 6);
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("a"), 1);
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("aa"), 3);
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("racecar"), 10);
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("aaaa"), 10);
    ASSERT_EQ(PalindromicSubstrings::countSubstringsManacher("abba"), 6);
}

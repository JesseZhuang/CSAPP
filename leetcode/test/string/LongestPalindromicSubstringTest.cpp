#include "gtest/gtest.h"
#include "string/LongestPalindromicSubstring.hpp"

TEST(string, longest_palindromic_substring_expand) {
    Solution5 sol;
    string res = sol.longestPalindrome("babad");
    ASSERT_TRUE(res == "bab" || res == "aba");
    ASSERT_EQ(sol.longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(sol.longestPalindrome("a"), "a");
    ASSERT_EQ(sol.longestPalindrome("aa"), "aa");
    ASSERT_EQ(sol.longestPalindrome("racecar"), "racecar");
    ASSERT_EQ(sol.longestPalindrome("xabcbay"), "abcba");
}

TEST(string, longest_palindromic_substring_manacher) {
    Solution5Manacher sol;
    string res = sol.longestPalindrome("babad");
    ASSERT_TRUE(res == "bab" || res == "aba");
    ASSERT_EQ(sol.longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(sol.longestPalindrome("a"), "a");
    ASSERT_EQ(sol.longestPalindrome("aa"), "aa");
    ASSERT_EQ(sol.longestPalindrome("racecar"), "racecar");
    ASSERT_EQ(sol.longestPalindrome("xabcbay"), "abcba");
}

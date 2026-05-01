#include "gtest/gtest.h"
#include "string/ShortestPalindrome.hpp"

TEST(string, shortest_palindrome) {
    Solution214 sol;
    ASSERT_EQ(sol.shortestPalindrome("aacecaaa"), "aaacecaaa");
    ASSERT_EQ(sol.shortestPalindrome("abcd"), "dcbabcd");
    ASSERT_EQ(sol.shortestPalindrome(""), "");
    ASSERT_EQ(sol.shortestPalindrome("a"), "a");
    ASSERT_EQ(sol.shortestPalindrome("aba"), "aba");
    ASSERT_EQ(sol.shortestPalindrome("aaabc"), "cbaaabc");
}

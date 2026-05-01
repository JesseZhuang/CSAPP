#include "gtest/gtest.h"
#include "string/ConstructKPalindromeStrings.hpp"

TEST(string, construct_k_palindrome_strings) {
    ConstructKPalindromeStrings sol;
    ASSERT_TRUE(sol.canConstruct("annabelle", 2));
    ASSERT_FALSE(sol.canConstruct("leetcode", 3));
    ASSERT_TRUE(sol.canConstruct("true", 4));
}

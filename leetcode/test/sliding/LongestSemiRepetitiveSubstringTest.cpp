#include "gtest/gtest.h"
#include "sliding/LongestSemiRepetitiveSubstring.hpp"

TEST(sliding, longest_semi_repetitive_substring) {
    Solution sol;
    EXPECT_EQ(4, sol.longestSemiRepetitiveSubstring("52233"));
    EXPECT_EQ(4, sol.longestSemiRepetitiveSubstring("5494"));
    EXPECT_EQ(6, sol.longestSemiRepetitiveSubstring("123456"));
    EXPECT_EQ(6, sol.longestSemiRepetitiveSubstring("122345"));
    EXPECT_EQ(4, sol.longestSemiRepetitiveSubstring("112233"));
    EXPECT_EQ(5, sol.longestSemiRepetitiveSubstring("1233112"));
    EXPECT_EQ(2, sol.longestSemiRepetitiveSubstring("111111"));
    EXPECT_EQ(6, sol.longestSemiRepetitiveSubstring("1123455"));
    EXPECT_EQ(2, sol.longestSemiRepetitiveSubstring("12"));
    EXPECT_EQ(2, sol.longestSemiRepetitiveSubstring("11"));
    EXPECT_EQ(1, sol.longestSemiRepetitiveSubstring("5"));
}

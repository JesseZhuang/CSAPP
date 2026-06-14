#include "gtest/gtest.h"
#include "dp/DistinctSubsequences.hpp"

TEST(dp, distinct_subsequences_1d) {
    Solution sol;
    ASSERT_EQ(3, sol.numDistinct("rabbbit", "rabbit"));
    ASSERT_EQ(5, sol.numDistinct("babgbag", "bag"));
    ASSERT_EQ(0, sol.numDistinct("abc", "def"));
    ASSERT_EQ(1, sol.numDistinct("abc", ""));
    ASSERT_EQ(0, sol.numDistinct("", "a"));
    ASSERT_EQ(1, sol.numDistinct("", ""));
    ASSERT_EQ(1, sol.numDistinct("abc", "abc"));
    ASSERT_EQ(3, sol.numDistinct("aaa", "a"));
    ASSERT_EQ(0, sol.numDistinct("a", "abc"));
    ASSERT_EQ(10, sol.numDistinct("aaaaa", "aaa"));
}

TEST(dp, distinct_subsequences_2d) {
    Solution2D sol;
    ASSERT_EQ(3, sol.numDistinct("rabbbit", "rabbit"));
    ASSERT_EQ(5, sol.numDistinct("babgbag", "bag"));
    ASSERT_EQ(0, sol.numDistinct("abc", "def"));
    ASSERT_EQ(1, sol.numDistinct("abc", ""));
    ASSERT_EQ(0, sol.numDistinct("", "a"));
    ASSERT_EQ(1, sol.numDistinct("", ""));
    ASSERT_EQ(1, sol.numDistinct("abc", "abc"));
    ASSERT_EQ(3, sol.numDistinct("aaa", "a"));
    ASSERT_EQ(0, sol.numDistinct("a", "abc"));
    ASSERT_EQ(10, sol.numDistinct("aaaaa", "aaa"));
}

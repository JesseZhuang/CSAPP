#include "gtest/gtest.h"
#include "dp/EditDistance.hpp"

TEST(dp, edit_distance_1d) {
    Solution sol;
    ASSERT_EQ(3, sol.minDistance("horse", "ros"));
    ASSERT_EQ(5, sol.minDistance("intention", "execution"));
    ASSERT_EQ(0, sol.minDistance("", ""));
    ASSERT_EQ(3, sol.minDistance("", "abc"));
    ASSERT_EQ(3, sol.minDistance("abc", ""));
    ASSERT_EQ(0, sol.minDistance("abc", "abc"));
    ASSERT_EQ(1, sol.minDistance("a", "b"));
    ASSERT_EQ(3, sol.minDistance("kitten", "sitting"));
    ASSERT_EQ(3, sol.minDistance("sunday", "saturday"));
}

TEST(dp, edit_distance_2d) {
    Solution2D sol;
    ASSERT_EQ(3, sol.minDistance("horse", "ros"));
    ASSERT_EQ(5, sol.minDistance("intention", "execution"));
    ASSERT_EQ(0, sol.minDistance("", ""));
    ASSERT_EQ(3, sol.minDistance("", "abc"));
    ASSERT_EQ(3, sol.minDistance("abc", ""));
    ASSERT_EQ(0, sol.minDistance("abc", "abc"));
    ASSERT_EQ(1, sol.minDistance("a", "b"));
    ASSERT_EQ(3, sol.minDistance("kitten", "sitting"));
    ASSERT_EQ(3, sol.minDistance("sunday", "saturday"));
}

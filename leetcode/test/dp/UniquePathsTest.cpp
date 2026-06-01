#include "gtest/gtest.h"
#include "dp/UniquePaths.hpp"

TEST(dp, unique_paths_dp) {
    EXPECT_EQ(28, UniquePaths::dp(3, 7));
    EXPECT_EQ(3, UniquePaths::dp(3, 2));
    EXPECT_EQ(1, UniquePaths::dp(1, 1));
    EXPECT_EQ(1, UniquePaths::dp(1, 100));
    EXPECT_EQ(1, UniquePaths::dp(100, 1));
    EXPECT_EQ(48620, UniquePaths::dp(10, 10));
}

TEST(dp, unique_paths_combination) {
    EXPECT_EQ(28, UniquePaths::combination(3, 7));
    EXPECT_EQ(3, UniquePaths::combination(3, 2));
    EXPECT_EQ(1, UniquePaths::combination(1, 1));
    EXPECT_EQ(1, UniquePaths::combination(1, 100));
    EXPECT_EQ(1, UniquePaths::combination(100, 1));
    EXPECT_EQ(48620, UniquePaths::combination(10, 10));
}

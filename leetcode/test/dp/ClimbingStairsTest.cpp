#include "gtest/gtest.h"
#include "dp/ClimbingStairs.hpp"

TEST(dp, climbing_stairs) {
    Solution sol;
    EXPECT_EQ(1, sol.climbStairs(1));
    EXPECT_EQ(2, sol.climbStairs(2));
    EXPECT_EQ(3, sol.climbStairs(3));
    EXPECT_EQ(1836311903, sol.climbStairs(45));
}

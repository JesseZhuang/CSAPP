#include "gtest/gtest.h"
#include "array/MinArrowsBurstBalloons.hpp"

TEST(array, min_arrows_burst_balloons) {
    Solution sol;

    // LeetCode example 1
    vector<vector<int>> p1 = {{10,16},{2,8},{1,6},{7,12}};
    EXPECT_EQ(2, sol.findMinArrowShots(p1));

    // LeetCode example 2
    vector<vector<int>> p2 = {{1,2},{3,4},{5,6},{7,8}};
    EXPECT_EQ(4, sol.findMinArrowShots(p2));

    // LeetCode example 3
    vector<vector<int>> p3 = {{1,2},{2,3},{3,4},{4,5}};
    EXPECT_EQ(2, sol.findMinArrowShots(p3));

    // Single balloon
    vector<vector<int>> p4 = {{5,10}};
    EXPECT_EQ(1, sol.findMinArrowShots(p4));

    // All overlapping
    vector<vector<int>> p5 = {{1,10},{2,9},{3,8},{4,7}};
    EXPECT_EQ(1, sol.findMinArrowShots(p5));

    // Touching edges
    vector<vector<int>> p6 = {{1,2},{2,3},{3,4}};
    EXPECT_EQ(2, sol.findMinArrowShots(p6));

    // INT_MIN/INT_MAX range
    vector<vector<int>> p7 = {{INT_MIN,INT_MAX}};
    EXPECT_EQ(1, sol.findMinArrowShots(p7));

    vector<vector<int>> p8 = {{INT_MIN,INT_MIN},{INT_MAX,INT_MAX}};
    EXPECT_EQ(2, sol.findMinArrowShots(p8));
}

TEST(array, min_arrows_burst_balloons2) {
    Solution sol;

    // LeetCode example 1
    vector<vector<int>> p1 = {{10,16},{2,8},{1,6},{7,12}};
    EXPECT_EQ(2, sol.findMinArrowShots2(p1));

    // LeetCode example 2
    vector<vector<int>> p2 = {{1,2},{3,4},{5,6},{7,8}};
    EXPECT_EQ(4, sol.findMinArrowShots2(p2));

    // LeetCode example 3
    vector<vector<int>> p3 = {{1,2},{2,3},{3,4},{4,5}};
    EXPECT_EQ(2, sol.findMinArrowShots2(p3));

    // Single balloon
    vector<vector<int>> p4 = {{5,10}};
    EXPECT_EQ(1, sol.findMinArrowShots2(p4));

    // All overlapping
    vector<vector<int>> p5 = {{1,10},{2,9},{3,8},{4,7}};
    EXPECT_EQ(1, sol.findMinArrowShots2(p5));

    // Touching edges
    vector<vector<int>> p6 = {{1,2},{2,3},{3,4}};
    EXPECT_EQ(2, sol.findMinArrowShots2(p6));

    // INT_MIN/INT_MAX range
    vector<vector<int>> p7 = {{INT_MIN,INT_MAX}};
    EXPECT_EQ(1, sol.findMinArrowShots2(p7));

    vector<vector<int>> p8 = {{INT_MIN,INT_MIN},{INT_MAX,INT_MAX}};
    EXPECT_EQ(2, sol.findMinArrowShots2(p8));
}

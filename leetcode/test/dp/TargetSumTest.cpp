#include "gtest/gtest.h"
#include "dp/TargetSum.hpp"

TEST(dp, target_sum_dp) {
    TargetSumDP sol;
    vector<int> n1 = {1, 1, 1, 1, 1};
    ASSERT_EQ(5, sol.findTargetSumWays(n1, 3));
    vector<int> n2 = {1};
    ASSERT_EQ(1, sol.findTargetSumWays(n2, 1));
    vector<int> n3 = {1, 0};
    ASSERT_EQ(2, sol.findTargetSumWays(n3, 1));
    vector<int> n4 = {0, 0, 0, 0, 0};
    ASSERT_EQ(32, sol.findTargetSumWays(n4, 0));
    vector<int> n5 = {1, 2, 3};
    ASSERT_EQ(0, sol.findTargetSumWays(n5, 7));
    vector<int> n6 = {1, 1, 1, 1, 1};
    ASSERT_EQ(5, sol.findTargetSumWays(n6, -3));
    vector<int> n7 = {0};
    ASSERT_EQ(2, sol.findTargetSumWays(n7, 0));
    vector<int> n8 = {1, 2, 1};
    ASSERT_EQ(2, sol.findTargetSumWays(n8, 0));
}

TEST(dp, target_sum_dfs) {
    TargetSumDFS sol;
    vector<int> n1 = {1, 1, 1, 1, 1};
    ASSERT_EQ(5, sol.findTargetSumWays(n1, 3));
    vector<int> n2 = {1};
    ASSERT_EQ(1, sol.findTargetSumWays(n2, 1));
    vector<int> n3 = {1, 0};
    ASSERT_EQ(2, sol.findTargetSumWays(n3, 1));
    vector<int> n4 = {0, 0, 0, 0, 0};
    ASSERT_EQ(32, sol.findTargetSumWays(n4, 0));
    vector<int> n5 = {1, 2, 3};
    ASSERT_EQ(0, sol.findTargetSumWays(n5, 7));
    vector<int> n6 = {1, 1, 1, 1, 1};
    ASSERT_EQ(5, sol.findTargetSumWays(n6, -3));
    vector<int> n7 = {0};
    ASSERT_EQ(2, sol.findTargetSumWays(n7, 0));
    vector<int> n8 = {1, 2, 1};
    ASSERT_EQ(2, sol.findTargetSumWays(n8, 0));
}

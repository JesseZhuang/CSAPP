#include "gtest/gtest.h"
#include "dp/MinimumPathSum.hpp"

TEST(dp, minimum_path_sum_dp) {
    MinimumPathSumDP sol;

    vector<vector<int>> g1 = {{1,3,1},{1,5,1},{4,2,1}};
    ASSERT_EQ(7, sol.minPathSum(g1));

    vector<vector<int>> g2 = {{5}};
    ASSERT_EQ(5, sol.minPathSum(g2));

    vector<vector<int>> g3 = {{1,2,3}};
    ASSERT_EQ(6, sol.minPathSum(g3));

    vector<vector<int>> g4 = {{1},{2},{3}};
    ASSERT_EQ(6, sol.minPathSum(g4));

    vector<vector<int>> g5 = {{1,2},{1,1}};
    ASSERT_EQ(3, sol.minPathSum(g5));

    vector<vector<int>> g6 = {{0,0},{0,0}};
    ASSERT_EQ(0, sol.minPathSum(g6));

    vector<vector<int>> g7 = {{100,100,100},{100,1,100},{100,1,1}};
    ASSERT_EQ(203, sol.minPathSum(g7));

    vector<vector<int>> g8 = {{1,100},{1,1}};
    ASSERT_EQ(3, sol.minPathSum(g8));
}

TEST(dp, minimum_path_sum_1d) {
    MinimumPathSum1D sol;

    vector<vector<int>> g1 = {{1,3,1},{1,5,1},{4,2,1}};
    ASSERT_EQ(7, sol.minPathSum(g1));

    vector<vector<int>> g2 = {{5}};
    ASSERT_EQ(5, sol.minPathSum(g2));

    vector<vector<int>> g3 = {{1,2,3}};
    ASSERT_EQ(6, sol.minPathSum(g3));

    vector<vector<int>> g4 = {{1},{2},{3}};
    ASSERT_EQ(6, sol.minPathSum(g4));

    vector<vector<int>> g5 = {{1,2},{1,1}};
    ASSERT_EQ(3, sol.minPathSum(g5));

    vector<vector<int>> g6 = {{0,0},{0,0}};
    ASSERT_EQ(0, sol.minPathSum(g6));

    vector<vector<int>> g7 = {{100,100,100},{100,1,100},{100,1,1}};
    ASSERT_EQ(203, sol.minPathSum(g7));

    vector<vector<int>> g8 = {{1,100},{1,1}};
    ASSERT_EQ(3, sol.minPathSum(g8));
}

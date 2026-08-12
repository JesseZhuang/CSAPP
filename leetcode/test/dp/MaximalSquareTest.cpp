#include "gtest/gtest.h"
#include "dp/MaximalSquare.hpp"

TEST(dp, maximal_square) {
    Solution sol;

    // Example 1: answer 4
    vector<vector<char>> m1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    ASSERT_EQ(4, sol.maximalSquare(m1));

    // Example 2: [['0','1'],['1','0']] -> 1
    vector<vector<char>> m2 = {{'0','1'},{'1','0'}};
    ASSERT_EQ(1, sol.maximalSquare(m2));

    // All zeros -> 0
    vector<vector<char>> m3 = {{'0','0'},{'0','0'}};
    ASSERT_EQ(0, sol.maximalSquare(m3));

    // All ones 3x3 -> 9
    vector<vector<char>> m4 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    ASSERT_EQ(9, sol.maximalSquare(m4));

    // Single '1' -> 1
    vector<vector<char>> m5 = {{'1'}};
    ASSERT_EQ(1, sol.maximalSquare(m5));
}

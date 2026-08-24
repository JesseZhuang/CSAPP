#include "gtest/gtest.h"
#include "deque/MaximalRectangle.hpp"

using namespace std;

TEST(deque, maximal_rectangle) {
    Solution tbt;

    // LeetCode example: answer = 6
    vector<vector<char>> m1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    ASSERT_EQ(6, tbt.maximalRectangle(m1));

    // Empty matrix
    vector<vector<char>> m2 = {};
    ASSERT_EQ(0, tbt.maximalRectangle(m2));

    // Single "0"
    vector<vector<char>> m3 = {{'0'}};
    ASSERT_EQ(0, tbt.maximalRectangle(m3));

    // Single "1"
    vector<vector<char>> m4 = {{'1'}};
    ASSERT_EQ(1, tbt.maximalRectangle(m4));

    // All ones 3x3
    vector<vector<char>> m5 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    ASSERT_EQ(9, tbt.maximalRectangle(m5));

    // All zeros 2x3
    vector<vector<char>> m6 = {
        {'0','0','0'},
        {'0','0','0'}
    };
    ASSERT_EQ(0, tbt.maximalRectangle(m6));

    // Single row
    vector<vector<char>> m7 = {{'1','1','0','1','1','1'}};
    ASSERT_EQ(3, tbt.maximalRectangle(m7));

    // Single column
    vector<vector<char>> m8 = {{'1'},{'1'},{'0'},{'1'}};
    ASSERT_EQ(2, tbt.maximalRectangle(m8));
}

TEST(deque, maximal_rectangle_dp) {
    Solution2 tbt;

    // LeetCode example: answer = 6
    vector<vector<char>> m1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    ASSERT_EQ(6, tbt.maximalRectangle(m1));

    // Empty matrix
    vector<vector<char>> m2 = {};
    ASSERT_EQ(0, tbt.maximalRectangle(m2));

    // Single "0"
    vector<vector<char>> m3 = {{'0'}};
    ASSERT_EQ(0, tbt.maximalRectangle(m3));

    // Single "1"
    vector<vector<char>> m4 = {{'1'}};
    ASSERT_EQ(1, tbt.maximalRectangle(m4));

    // All ones 3x3
    vector<vector<char>> m5 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    ASSERT_EQ(9, tbt.maximalRectangle(m5));

    // All zeros 2x3
    vector<vector<char>> m6 = {
        {'0','0','0'},
        {'0','0','0'}
    };
    ASSERT_EQ(0, tbt.maximalRectangle(m6));

    // Single row
    vector<vector<char>> m7 = {{'1','1','0','1','1','1'}};
    ASSERT_EQ(3, tbt.maximalRectangle(m7));

    // Single column
    vector<vector<char>> m8 = {{'1'},{'1'},{'0'},{'1'}};
    ASSERT_EQ(2, tbt.maximalRectangle(m8));
}

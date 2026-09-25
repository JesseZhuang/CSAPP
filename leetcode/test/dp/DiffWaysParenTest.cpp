#include "gtest/gtest.h"
#include "dp/DiffWaysParen.hpp"
#include <algorithm>

TEST(dp, diff_ways_paren_basic_subtract) {
    Solution sol;
    auto res = sol.diffWaysToCompute("2-1-1");
    sort(res.begin(), res.end());
    vector<int> expected = {0, 2};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_mixed_ops) {
    Solution sol;
    auto res = sol.diffWaysToCompute("2*3-4*5");
    sort(res.begin(), res.end());
    vector<int> expected = {-34, -14, -10, -10, 10};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_single_digit) {
    Solution sol;
    auto res = sol.diffWaysToCompute("3");
    vector<int> expected = {3};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_two_digit) {
    Solution sol;
    auto res = sol.diffWaysToCompute("11");
    vector<int> expected = {11};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_single_add) {
    Solution sol;
    auto res = sol.diffWaysToCompute("2+3");
    vector<int> expected = {5};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_single_sub) {
    Solution sol;
    auto res = sol.diffWaysToCompute("5-2");
    vector<int> expected = {3};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_single_mul) {
    Solution sol;
    auto res = sol.diffWaysToCompute("4*3");
    vector<int> expected = {12};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_add_chain) {
    Solution sol;
    auto res = sol.diffWaysToCompute("1+2+3");
    sort(res.begin(), res.end());
    vector<int> expected = {6, 6};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_mul_chain) {
    Solution sol;
    auto res = sol.diffWaysToCompute("2*3*4");
    sort(res.begin(), res.end());
    vector<int> expected = {24, 24};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_add_mul) {
    Solution sol;
    auto res = sol.diffWaysToCompute("1+2*3");
    sort(res.begin(), res.end());
    vector<int> expected = {7, 9};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_two_digit_operands) {
    Solution sol;
    auto res = sol.diffWaysToCompute("10+5");
    vector<int> expected = {15};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_zeros) {
    Solution sol;
    auto res = sol.diffWaysToCompute("0+0");
    vector<int> expected = {0};
    ASSERT_EQ(expected, res);
}

TEST(dp, diff_ways_paren_sub_chain) {
    Solution sol;
    auto res = sol.diffWaysToCompute("1-2-3");
    sort(res.begin(), res.end());
    vector<int> expected = {-4, 2};
    ASSERT_EQ(expected, res);
}

#include "gtest/gtest.h"
#include "array/TwoSumII.hpp"

TEST(array, two_sum_ii_example1) {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    EXPECT_EQ(s.twoSum(nums, 9), (vector<int>{1, 2}));
    EXPECT_EQ(s.twoSumBS(nums, 9), (vector<int>{1, 2}));
}

TEST(array, two_sum_ii_example2) {
    Solution s;
    vector<int> nums = {2, 3, 4};
    EXPECT_EQ(s.twoSum(nums, 6), (vector<int>{1, 3}));
    EXPECT_EQ(s.twoSumBS(nums, 6), (vector<int>{1, 3}));
}

TEST(array, two_sum_ii_example3) {
    Solution s;
    vector<int> nums = {-1, 0};
    EXPECT_EQ(s.twoSum(nums, -1), (vector<int>{1, 2}));
    EXPECT_EQ(s.twoSumBS(nums, -1), (vector<int>{1, 2}));
}

TEST(array, two_sum_ii_negatives) {
    Solution s;
    vector<int> nums = {-10, -5, -3, 0, 7};
    EXPECT_EQ(s.twoSum(nums, -3), (vector<int>{1, 5}));
    EXPECT_EQ(s.twoSumBS(nums, -3), (vector<int>{1, 5}));
}

TEST(array, two_sum_ii_boundary) {
    Solution s;
    vector<int> nums = {-1000, 1000};
    EXPECT_EQ(s.twoSum(nums, 0), (vector<int>{1, 2}));
    EXPECT_EQ(s.twoSumBS(nums, 0), (vector<int>{1, 2}));
}

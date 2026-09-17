#include "gtest/gtest.h"
#include "hash/BinarySubarraysWithSum.hpp"

TEST(hash, binary_subarrays_with_sum_example1) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {1, 0, 1, 0, 1};
    EXPECT_EQ(4, sol1.numSubarraysWithSum(nums, 2));
    EXPECT_EQ(4, sol2.numSubarraysWithSum(nums, 2));
}

TEST(hash, binary_subarrays_with_sum_example2) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {0, 0, 0, 0, 0};
    EXPECT_EQ(15, sol1.numSubarraysWithSum(nums, 0));
    EXPECT_EQ(15, sol2.numSubarraysWithSum(nums, 0));
}

TEST(hash, binary_subarrays_with_sum_single) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {1};
    EXPECT_EQ(1, sol1.numSubarraysWithSum(nums, 1));
    EXPECT_EQ(1, sol2.numSubarraysWithSum(nums, 1));
}

TEST(hash, binary_subarrays_with_sum_all_ones) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(3, sol1.numSubarraysWithSum(nums, 2));
    EXPECT_EQ(3, sol2.numSubarraysWithSum(nums, 2));
}

TEST(hash, binary_subarrays_with_sum_zeros_goal_zero) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {1, 0, 0, 1};
    EXPECT_EQ(3, sol1.numSubarraysWithSum(nums, 0));
    EXPECT_EQ(3, sol2.numSubarraysWithSum(nums, 0));
}

TEST(hash, binary_subarrays_with_sum_leading_trailing) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {0, 0, 1, 0, 0};
    EXPECT_EQ(9, sol1.numSubarraysWithSum(nums, 1));
    EXPECT_EQ(9, sol2.numSubarraysWithSum(nums, 1));
}

TEST(hash, binary_subarrays_with_sum_no_valid) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {0, 0, 0};
    EXPECT_EQ(0, sol1.numSubarraysWithSum(nums, 1));
    EXPECT_EQ(0, sol2.numSubarraysWithSum(nums, 1));
}

TEST(hash, binary_subarrays_with_sum_large_goal) {
    Solution sol1;
    Solution2 sol2;
    vector<int> nums = {1, 0, 1};
    EXPECT_EQ(0, sol1.numSubarraysWithSum(nums, 5));
    EXPECT_EQ(0, sol2.numSubarraysWithSum(nums, 5));
}

#include "gtest/gtest.h"
#include "sliding/KRadiusSubarrayAverages.hpp"
#include <vector>

using namespace std;

TEST(sliding, k_radius_subarray_averages_sample) {
    vector<int> nums{7, 4, 3, 9, 1, 8, 5, 2, 6};
    vector<int> expected{-1, -1, -1, 5, 4, 4, -1, -1, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 3), expected);
}

TEST(sliding, k_radius_subarray_averages_zero_radius) {
    vector<int> nums{100000, 0, -7};
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 0), nums);
}

TEST(sliding, k_radius_subarray_averages_window_too_large) {
    vector<int> nums{8};
    vector<int> expected{-1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 100000), expected);
}

TEST(sliding, k_radius_subarray_averages_first_and_last_valid_windows) {
    vector<int> nums{1, 2, 3, 4, 5};
    vector<int> expected{-1, 2, 3, 4, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 1), expected);
}

TEST(sliding, k_radius_subarray_averages_exact_window) {
    vector<int> nums{1, 2, 3, 4, 5};
    vector<int> expected{-1, -1, 3, -1, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 2), expected);
}

TEST(sliding, k_radius_subarray_averages_negative_truncates_toward_zero) {
    vector<int> nums{-4, -3, -1, -2, -6};
    vector<int> expected{-1, -2, -2, -3, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 1), expected);
}

TEST(sliding, k_radius_subarray_averages_wide_window_sum) {
    vector<int> nums(100001, 100000);
    vector<int> expected(100001, -1);
    expected[50000] = 100000;
    EXPECT_EQ(KRadiusSubarrayAverages::getAverages(nums, 50000), expected);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_sample) {
    vector<int> nums{7, 4, 3, 9, 1, 8, 5, 2, 6};
    vector<int> expected{-1, -1, -1, 5, 4, 4, -1, -1, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 3), expected);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_zero_radius) {
    vector<int> nums{100000, 0, -7};
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 0), nums);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_window_too_large) {
    vector<int> nums{8};
    vector<int> expected{-1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 100000), expected);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_first_and_last_valid_windows) {
    vector<int> nums{1, 2, 3, 4, 5};
    vector<int> expected{-1, 2, 3, 4, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 1), expected);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_exact_window) {
    vector<int> nums{1, 2, 3, 4, 5};
    vector<int> expected{-1, -1, 3, -1, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 2), expected);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_negative_truncates_toward_zero) {
    vector<int> nums{-4, -3, -1, -2, -6};
    vector<int> expected{-1, -2, -2, -3, -1};
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 1), expected);
}

TEST(sliding, k_radius_subarray_averages_prefix_sum_wide_window_sum) {
    vector<int> nums(100001, 100000);
    vector<int> expected(100001, -1);
    expected[50000] = 100000;
    EXPECT_EQ(KRadiusSubarrayAverages::getAveragesByPrefixSum(nums, 50000), expected);
}

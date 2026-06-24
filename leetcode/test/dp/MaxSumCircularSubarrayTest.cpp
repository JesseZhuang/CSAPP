#include "gtest/gtest.h"
#include "dp/MaxSumCircularSubarray.hpp"

TEST(dp, max_sum_circular_subarray) {
    vector<int> nums1 = {1, -2, 3, -2};
    ASSERT_EQ(3, Solution::maxSubarraySumCircular(nums1));

    vector<int> nums2 = {5, -3, 5};
    ASSERT_EQ(10, Solution::maxSubarraySumCircular(nums2));

    vector<int> nums3 = {-3, -2, -3};
    ASSERT_EQ(-2, Solution::maxSubarraySumCircular(nums3));

    vector<int> nums4 = {7};
    ASSERT_EQ(7, Solution::maxSubarraySumCircular(nums4));

    vector<int> nums5 = {-1};
    ASSERT_EQ(-1, Solution::maxSubarraySumCircular(nums5));

    vector<int> nums6 = {-5, -3, -4, -1, -2};
    ASSERT_EQ(-1, Solution::maxSubarraySumCircular(nums6));

    vector<int> nums7 = {3, 1, 2, 4};
    ASSERT_EQ(10, Solution::maxSubarraySumCircular(nums7));

    vector<int> nums8 = {5, -3, -100, 2, 4};
    ASSERT_EQ(11, Solution::maxSubarraySumCircular(nums8));

    vector<int> nums9 = {3, -1};
    ASSERT_EQ(3, Solution::maxSubarraySumCircular(nums9));

    vector<int> nums10 = {8, -1, -1, 8, -7, 4};
    ASSERT_EQ(18, Solution::maxSubarraySumCircular(nums10));
}

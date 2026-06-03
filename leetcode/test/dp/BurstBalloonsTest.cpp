#include "gtest/gtest.h"
#include "dp/BurstBalloons.hpp"

TEST(dp, burst_balloons) {
    Solution sol;

    vector<int> nums1 = {3, 1, 5, 8};
    ASSERT_EQ(167, sol.maxCoins(nums1));

    vector<int> nums2 = {1, 5};
    ASSERT_EQ(10, sol.maxCoins(nums2));

    vector<int> nums3 = {3};
    ASSERT_EQ(3, sol.maxCoins(nums3));

    vector<int> nums4 = {2, 2};
    ASSERT_EQ(6, sol.maxCoins(nums4));

    vector<int> nums5 = {1, 2, 3, 4};
    ASSERT_EQ(40, sol.maxCoins(nums5));
}

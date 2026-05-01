#include "gtest/gtest.h"
#include "array/PowerKSizeSubArraysI.hpp"

TEST(array, power_k_size_subarrays_i) {
    PowerKSizeSubArraysI sol;

    vector<int> nums1 = {1, 2, 3, 4, 3, 2, 5};
    ASSERT_EQ(vector<int>({3, 4, -1, -1, -1}), sol.resultsArray(nums1, 3));

    vector<int> nums2 = {2, 2, 2, 2, 2};
    ASSERT_EQ(vector<int>({-1, -1}), sol.resultsArray(nums2, 4));

    vector<int> nums3 = {3, 2, 3, 2, 3, 2};
    ASSERT_EQ(vector<int>({-1, 3, -1, 3, -1}), sol.resultsArray(nums3, 2));
}

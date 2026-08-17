#include "gtest/gtest.h"
#include "array/MajorityElement.hpp"
#include <vector>

using namespace std;

TEST(array, majority_element) {
    Solution sol;

    // Single element
    {
        vector<int> nums = {1};
        EXPECT_EQ(sol.majorityElement(nums), 1);
        EXPECT_EQ(sol.majorityElementSort(nums), 1);
    }

    // [3,2,3]
    {
        vector<int> nums = {3, 2, 3};
        EXPECT_EQ(sol.majorityElement(nums), 3);
        vector<int> nums2 = {3, 2, 3};
        EXPECT_EQ(sol.majorityElementSort(nums2), 3);
    }

    // [2,2,1,1,1,2,2]
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        EXPECT_EQ(sol.majorityElement(nums), 2);
        vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
        EXPECT_EQ(sol.majorityElementSort(nums2), 2);
    }

    // All same
    {
        vector<int> nums = {5, 5, 5, 5};
        EXPECT_EQ(sol.majorityElement(nums), 5);
        EXPECT_EQ(sol.majorityElementSort(nums), 5);
    }

    // Negative numbers
    {
        vector<int> nums = {-1, -1, -1, 2, 3};
        EXPECT_EQ(sol.majorityElement(nums), -1);
        vector<int> nums2 = {-1, -1, -1, 2, 3};
        EXPECT_EQ(sol.majorityElementSort(nums2), -1);
    }

    // Majority at end
    {
        vector<int> nums = {1, 2, 3, 3, 3};
        EXPECT_EQ(sol.majorityElement(nums), 3);
        vector<int> nums2 = {1, 2, 3, 3, 3};
        EXPECT_EQ(sol.majorityElementSort(nums2), 3);
    }
}

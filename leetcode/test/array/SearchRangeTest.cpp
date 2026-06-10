#include "gtest/gtest.h"
#include "array/SearchRange.hpp"

TEST(array, search_range) {
    SearchRange sol;

    // Example 1: Target found with multiple occurrences
    vector<int> nums1 = {5,7,7,8,8,10};
    int target1 = 8;
    vector<int> expected1 = {3, 4};
    EXPECT_EQ(expected1, sol.searchRange(nums1, target1));

    // Example 2: Target not found
    vector<int> nums2 = {5,7,7,8,8,10};
    int target2 = 6;
    vector<int> expected2 = {-1, -1};
    EXPECT_EQ(expected2, sol.searchRange(nums2, target2));

    // Example 3: Empty array
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> expected3 = {-1, -1};
    EXPECT_EQ(expected3, sol.searchRange(nums3, target3));

    // Single element - match
    vector<int> nums4 = {5};
    int target4 = 5;
    vector<int> expected4 = {0, 0};
    EXPECT_EQ(expected4, sol.searchRange(nums4, target4));

    // Single element - no match
    vector<int> nums5 = {5};
    int target5 = 3;
    vector<int> expected5 = {-1, -1};
    EXPECT_EQ(expected5, sol.searchRange(nums5, target5));

    // All elements are target
    vector<int> nums6 = {7,7,7,7,7};
    int target6 = 7;
    vector<int> expected6 = {0, 4};
    EXPECT_EQ(expected6, sol.searchRange(nums6, target6));

    // Target at beginning
    vector<int> nums7 = {1,1,2,3,4,5};
    int target7 = 1;
    vector<int> expected7 = {0, 1};
    EXPECT_EQ(expected7, sol.searchRange(nums7, target7));

    // Target at end
    vector<int> nums8 = {1,2,3,4,5,5};
    int target8 = 5;
    vector<int> expected8 = {4, 5};
    EXPECT_EQ(expected8, sol.searchRange(nums8, target8));

    // Single occurrence
    vector<int> nums9 = {1,2,3,4,5,6};
    int target9 = 3;
    vector<int> expected9 = {2, 2};
    EXPECT_EQ(expected9, sol.searchRange(nums9, target9));
}

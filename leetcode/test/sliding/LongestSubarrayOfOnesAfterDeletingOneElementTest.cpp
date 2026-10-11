#include "gtest/gtest.h"
#include "sliding/LongestSubarrayOfOnesAfterDeletingOneElement.hpp"

TEST(sliding, longest_subarray_of_ones_after_deleting_one_element) {
    SolutionLongestSubarrayOfOnesAfterDeletingOneElement sol;

    vector<int> nums1 = {1, 1, 0, 1};
    EXPECT_EQ(3, sol.longestSubarray(nums1));

    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    EXPECT_EQ(5, sol.longestSubarray(nums2));

    vector<int> allOnes = {1, 1, 1};
    EXPECT_EQ(2, sol.longestSubarray(allOnes));

    vector<int> allZeros = {0, 0, 0, 0};
    EXPECT_EQ(0, sol.longestSubarray(allZeros));

    vector<int> singletonOne = {1};
    EXPECT_EQ(0, sol.longestSubarray(singletonOne));

    vector<int> singletonZero = {0};
    EXPECT_EQ(0, sol.longestSubarray(singletonZero));

    vector<int> multipleZeros = {1, 1, 0, 0, 1, 1, 1};
    EXPECT_EQ(3, sol.longestSubarray(multipleZeros));
}

TEST(sliding, longest_subarray_of_ones_after_deleting_one_element_prefix_suffix) {
    SolutionLongestSubarrayOfOnesAfterDeletingOneElement2 sol;

    vector<int> nums1 = {1, 1, 0, 1};
    EXPECT_EQ(3, sol.longestSubarray(nums1));

    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    EXPECT_EQ(5, sol.longestSubarray(nums2));

    vector<int> allOnes = {1, 1, 1};
    EXPECT_EQ(2, sol.longestSubarray(allOnes));

    vector<int> allZeros = {0, 0, 0, 0};
    EXPECT_EQ(0, sol.longestSubarray(allZeros));

    vector<int> singletonOne = {1};
    EXPECT_EQ(0, sol.longestSubarray(singletonOne));

    vector<int> singletonZero = {0};
    EXPECT_EQ(0, sol.longestSubarray(singletonZero));

    vector<int> multipleZeros = {1, 1, 0, 0, 1, 1, 1};
    EXPECT_EQ(3, sol.longestSubarray(multipleZeros));
}

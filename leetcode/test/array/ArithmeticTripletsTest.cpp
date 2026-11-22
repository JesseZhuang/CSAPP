#include "array/ArithmeticTriplets.hpp"
#include <gtest/gtest.h>

TEST(array, arithmetic_triplets_official_examples) {
    Solution sol;
    vector<int> nums1 = {0, 1, 4, 6, 7, 10};
    EXPECT_EQ(sol.arithmeticTriplets(nums1, 3), 2);

    vector<int> nums2 = {4, 5, 6, 7, 8, 9};
    EXPECT_EQ(sol.arithmeticTriplets(nums2, 2), 2);
}

TEST(array, arithmetic_triplets_no_triplets) {
    Solution sol;
    vector<int> nums = {0, 1, 4, 6};
    EXPECT_EQ(sol.arithmeticTriplets(nums, 3), 0);
}

TEST(array, arithmetic_triplets_overlapping) {
    Solution sol;
    vector<int> nums = {0, 1, 2, 3, 4};
    EXPECT_EQ(sol.arithmeticTriplets(nums, 1), 3);
}

TEST(array, arithmetic_triplets_minimum_size) {
    Solution sol;
    vector<int> valid = {0, 100, 200};
    EXPECT_EQ(sol.arithmeticTriplets(valid, 100), 1);

    vector<int> invalid = {0, 1, 3};
    EXPECT_EQ(sol.arithmeticTriplets(invalid, 1), 0);
}

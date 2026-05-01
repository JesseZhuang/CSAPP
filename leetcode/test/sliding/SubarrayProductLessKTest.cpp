#include "sliding/SubarrayProductLessK.hpp"
#include <gtest/gtest.h>

TEST(sliding, subarray_product_less_k) {
    SolutionSubarrayProductLessK sol;
    vector<int> v1 = {10, 5, 2, 6};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v1, 100), 8);
    vector<int> v2 = {1, 2, 3};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v2, 0), 0);
    vector<int> v3 = {1, 2, 3};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v3, 7), 6);
    vector<int> v4 = {2, 3, 4};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v4, 7), 4);
    vector<int> v5 = {1, 2, 3};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v5, 4), 4);
    vector<int> v6 = {4, 13, 20, 32, 44, 59, 61, 71, 75, 86, 88};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v6, 567601), 32);
    // single element
    vector<int> v7 = {5};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v7, 6), 1);
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v7, 5), 0);
    // k=1
    vector<int> v8 = {1, 1, 1};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v8, 1), 0);
}

TEST(sliding, subarray_product_less_k_v2) {
    SolutionSubarrayProductLessK2 sol;
    vector<int> v1 = {10, 5, 2, 6};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v1, 100), 8);
    vector<int> v2 = {1, 2, 3};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v2, 0), 0);
    vector<int> v3 = {1, 2, 3};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(v3, 7), 6);
}

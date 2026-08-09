#include <gtest/gtest.h>
#include "binary_search/SplitArrayLargestSum.hpp"

TEST(binary_search, split_array_largest_sum) {
    Solution s;

    vector<int> v1 = {7, 2, 5, 10, 8};
    EXPECT_EQ(18, s.splitArray(v1, 2));

    vector<int> v2 = {1, 2, 3, 4, 5};
    EXPECT_EQ(9, s.splitArray(v2, 2));

    vector<int> v3 = {10};
    EXPECT_EQ(10, s.splitArray(v3, 1));

    vector<int> v4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(5, s.splitArray(v4, 5));

    vector<int> v5 = {1, 2, 3, 4, 5};
    EXPECT_EQ(15, s.splitArray(v5, 1));

    vector<int> v6 = {3, 3, 3, 3};
    EXPECT_EQ(6, s.splitArray(v6, 2));

    vector<int> v7 = {1000000, 1, 1};
    EXPECT_EQ(1000000, s.splitArray(v7, 2));
}

TEST(binary_search, split_array_largest_sum_dp) {
    Solution s;

    vector<int> v1 = {7, 2, 5, 10, 8};
    EXPECT_EQ(18, s.splitArrayDp(v1, 2));

    vector<int> v2 = {1, 2, 3, 4, 5};
    EXPECT_EQ(9, s.splitArrayDp(v2, 2));

    vector<int> v3 = {10};
    EXPECT_EQ(10, s.splitArrayDp(v3, 1));

    vector<int> v4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(5, s.splitArrayDp(v4, 5));

    vector<int> v5 = {1, 2, 3, 4, 5};
    EXPECT_EQ(15, s.splitArrayDp(v5, 1));

    vector<int> v6 = {3, 3, 3, 3};
    EXPECT_EQ(6, s.splitArrayDp(v6, 2));

    vector<int> v7 = {1000000, 1, 1};
    EXPECT_EQ(1000000, s.splitArrayDp(v7, 2));
}

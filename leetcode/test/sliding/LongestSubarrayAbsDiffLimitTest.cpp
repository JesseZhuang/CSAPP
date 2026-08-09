#include "sliding/LongestSubarrayAbsDiffLimit.hpp"
#include <gtest/gtest.h>

TEST(sliding, longest_subarray_abs_diff_limit) {
    SolutionLongestSubarrayAbsDiffLimit sol;

    vector<int> v1 = {8, 2, 4, 7};
    EXPECT_EQ(sol.longestSubarray(v1, 4), 2);

    vector<int> v2 = {10, 1, 2, 4, 7, 2};
    EXPECT_EQ(sol.longestSubarray(v2, 5), 4);

    vector<int> v3 = {4, 2, 2, 2, 4, 4, 2, 2};
    EXPECT_EQ(sol.longestSubarray(v3, 0), 3);

    vector<int> v4 = {5};
    EXPECT_EQ(sol.longestSubarray(v4, 0), 1);

    vector<int> v5 = {3, 3, 3, 3, 3};
    EXPECT_EQ(sol.longestSubarray(v5, 0), 5);

    vector<int> v6 = {1, 2, 1, 2, 1};
    EXPECT_EQ(sol.longestSubarray(v6, 0), 1);

    vector<int> v7 = {1, 5, 9, 2, 7};
    EXPECT_EQ(sol.longestSubarray(v7, 100), 5);

    vector<int> v8 = {9, 8, 7, 6, 5};
    EXPECT_EQ(sol.longestSubarray(v8, 2), 3);

    vector<int> v9 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.longestSubarray(v9, 2), 3);

    vector<int> v10 = {1, 3};
    EXPECT_EQ(sol.longestSubarray(v10, 2), 2);

    vector<int> v11 = {1, 4};
    EXPECT_EQ(sol.longestSubarray(v11, 2), 1);
}

TEST(sliding, longest_subarray_abs_diff_limit_v2) {
    SolutionLongestSubarrayAbsDiffLimit2 sol;

    vector<int> v1 = {8, 2, 4, 7};
    EXPECT_EQ(sol.longestSubarray(v1, 4), 2);

    vector<int> v2 = {10, 1, 2, 4, 7, 2};
    EXPECT_EQ(sol.longestSubarray(v2, 5), 4);

    vector<int> v3 = {4, 2, 2, 2, 4, 4, 2, 2};
    EXPECT_EQ(sol.longestSubarray(v3, 0), 3);

    vector<int> v4 = {5};
    EXPECT_EQ(sol.longestSubarray(v4, 0), 1);

    vector<int> v5 = {3, 3, 3, 3, 3};
    EXPECT_EQ(sol.longestSubarray(v5, 0), 5);

    vector<int> v6 = {1, 2, 1, 2, 1};
    EXPECT_EQ(sol.longestSubarray(v6, 0), 1);

    vector<int> v7 = {1, 5, 9, 2, 7};
    EXPECT_EQ(sol.longestSubarray(v7, 100), 5);

    vector<int> v8 = {9, 8, 7, 6, 5};
    EXPECT_EQ(sol.longestSubarray(v8, 2), 3);

    vector<int> v9 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.longestSubarray(v9, 2), 3);

    vector<int> v10 = {1, 3};
    EXPECT_EQ(sol.longestSubarray(v10, 2), 2);

    vector<int> v11 = {1, 4};
    EXPECT_EQ(sol.longestSubarray(v11, 2), 1);
}

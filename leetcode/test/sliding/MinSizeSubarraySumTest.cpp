#include "sliding/MinSizeSubarraySum.hpp"
#include <gtest/gtest.h>

TEST(sliding, min_size_subarray_sum) {
    SolutionMinSizeSubarraySum sol;

    // Example 1: target=7, nums=[2,3,1,2,4,3] -> 2 (subarray [4,3])
    vector<int> v1 = {2, 3, 1, 2, 4, 3};
    EXPECT_EQ(sol.minSubArrayLen(7, v1), 2);

    // Example 2: target=4, nums=[1,4,4] -> 1 (subarray [4])
    vector<int> v2 = {1, 4, 4};
    EXPECT_EQ(sol.minSubArrayLen(4, v2), 1);

    // Example 3: target=11, nums=[1,1,1,1,1,1,1,1] -> 0 (no subarray)
    vector<int> v3 = {1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(sol.minSubArrayLen(11, v3), 0);

    // target=11, nums=[1,2,3,4,5] -> 3 (subarray [3,4,5] or [2,4,5])
    vector<int> v4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.minSubArrayLen(11, v4), 3);

    // target=15, nums=[1,2,3,4,5] -> 5 (entire array)
    vector<int> v5 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.minSubArrayLen(15, v5), 5);

    // target=3, nums=[1,1] -> 0 (no subarray)
    vector<int> v6 = {1, 1};
    EXPECT_EQ(sol.minSubArrayLen(3, v6), 0);

    // target=5, nums=[5] -> 1 (single element)
    vector<int> v7 = {5};
    EXPECT_EQ(sol.minSubArrayLen(5, v7), 1);

    // target=6, nums=[10,2,3] -> 1 (subarray [10])
    vector<int> v8 = {10, 2, 3};
    EXPECT_EQ(sol.minSubArrayLen(6, v8), 1);
}

TEST(sliding, min_size_subarray_sum_v2) {
    SolutionMinSizeSubarraySum2 sol;

    // Example 1: target=7, nums=[2,3,1,2,4,3] -> 2 (subarray [4,3])
    vector<int> v1 = {2, 3, 1, 2, 4, 3};
    EXPECT_EQ(sol.minSubArrayLen(7, v1), 2);

    // Example 2: target=4, nums=[1,4,4] -> 1 (subarray [4])
    vector<int> v2 = {1, 4, 4};
    EXPECT_EQ(sol.minSubArrayLen(4, v2), 1);

    // Example 3: target=11, nums=[1,1,1,1,1,1,1,1] -> 0 (no subarray)
    vector<int> v3 = {1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(sol.minSubArrayLen(11, v3), 0);

    // target=11, nums=[1,2,3,4,5] -> 3 (subarray [3,4,5] or [2,4,5])
    vector<int> v4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.minSubArrayLen(11, v4), 3);

    // target=15, nums=[1,2,3,4,5] -> 5 (entire array)
    vector<int> v5 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.minSubArrayLen(15, v5), 5);

    // target=3, nums=[1,1] -> 0 (no subarray)
    vector<int> v6 = {1, 1};
    EXPECT_EQ(sol.minSubArrayLen(3, v6), 0);

    // target=5, nums=[5] -> 1 (single element)
    vector<int> v7 = {5};
    EXPECT_EQ(sol.minSubArrayLen(5, v7), 1);

    // target=6, nums=[10,2,3] -> 1 (subarray [10])
    vector<int> v8 = {10, 2, 3};
    EXPECT_EQ(sol.minSubArrayLen(6, v8), 1);
}

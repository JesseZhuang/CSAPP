#include "gtest/gtest.h"
#include "array/XorAfterRangeMultiplicationQueries.hpp"

using namespace std;

TEST(array, xor_after_range_multiplication_queries) {
    Solution sol;

    // Example 1
    vector<int> nums1{1, 1, 1};
    vector<vector<int>> queries1{{0, 2, 1, 4}};
    ASSERT_EQ(4, sol.xorAfterRangeMultiplicationQueries(nums1, queries1));

    // Example 2
    vector<int> nums2{2, 3, 1, 5, 4};
    vector<vector<int>> queries2{{1, 4, 2, 3}, {0, 2, 1, 2}};
    ASSERT_EQ(31, sol.xorAfterRangeMultiplicationQueries(nums2, queries2));

    // Single element
    vector<int> nums3{3};
    vector<vector<int>> queries3{{0, 0, 1, 2}};
    ASSERT_EQ(6, sol.xorAfterRangeMultiplicationQueries(nums3, queries3));

    // Large values mod
    vector<int> nums4{1000000000};
    vector<vector<int>> queries4{{0, 0, 1, 100000}};
    int expected = (int)((1000000000LL * 100000LL) % 1000000007LL);
    ASSERT_EQ(expected, sol.xorAfterRangeMultiplicationQueries(nums4, queries4));
}

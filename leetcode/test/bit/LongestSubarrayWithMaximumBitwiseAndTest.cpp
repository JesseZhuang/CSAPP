#include <climits>
#include <vector>
#include <gtest/gtest.h>
#include "bit/LongestSubarrayWithMaximumBitwiseAnd.hpp"

TEST(bit, longest_subarray_with_maximum_bitwise_and) {
    Solution sol;

    std::vector<int> singleton = {7};
    EXPECT_EQ(1, sol.longestSubarray(singleton));

    std::vector<int> allEqual = {5, 5, 5, 5};
    EXPECT_EQ(4, sol.longestSubarray(allEqual));

    std::vector<int> separatedRuns = {1, 3, 3, 2, 3, 3, 3, 1, 3};
    EXPECT_EQ(3, sol.longestSubarray(separatedRuns));

    std::vector<int> maximumLate = {4, 4, 4, 4, 1, 5, 5};
    EXPECT_EQ(2, sol.longestSubarray(maximumLate));

    std::vector<int> longRun(100000, 1000000);
    EXPECT_EQ(100000, sol.longestSubarray(longRun));

    std::vector<int> extremes = {0, INT_MAX, INT_MAX, 0, INT_MAX};
    EXPECT_EQ(2, sol.longestSubarray(extremes));
}

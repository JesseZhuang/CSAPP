#include "gtest/gtest.h"
#include "dp/LongestIncreasingSubsequence.hpp"

#include <vector>

using namespace std;

TEST(dp, longest_increasing_subsequence) {
    Solution sol;
    SolutionDP solDP;

    vector<int> v1{10, 9, 2, 5, 3, 7, 101, 18};
    ASSERT_EQ(4, sol.lengthOfLIS(v1));
    ASSERT_EQ(4, solDP.lengthOfLIS(v1));

    vector<int> v2{0, 1, 0, 3, 2, 3};
    ASSERT_EQ(4, sol.lengthOfLIS(v2));
    ASSERT_EQ(4, solDP.lengthOfLIS(v2));

    vector<int> v3{7, 7, 7, 7, 7, 7, 7};
    ASSERT_EQ(1, sol.lengthOfLIS(v3));
    ASSERT_EQ(1, solDP.lengthOfLIS(v3));

    vector<int> v4{1};
    ASSERT_EQ(1, sol.lengthOfLIS(v4));
    ASSERT_EQ(1, solDP.lengthOfLIS(v4));

    vector<int> v5{1, 3, 6, 7, 9, 4, 10, 5, 6};
    ASSERT_EQ(6, sol.lengthOfLIS(v5));
    ASSERT_EQ(6, solDP.lengthOfLIS(v5));
}

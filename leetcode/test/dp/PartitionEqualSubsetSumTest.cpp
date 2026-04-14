#include "gtest/gtest.h"
#include "dp/PartitionEqualSubsetSum.hpp"
#include <vector>

using namespace std;

TEST(dp, partition_equal_subset_sum) {
    Solution sol;

    vector<int> v1 = {1, 5, 11, 5};
    EXPECT_TRUE(sol.canPartition(v1));
    EXPECT_TRUE(sol.canPartition2(v1));

    vector<int> v2 = {1, 2, 3, 5};
    EXPECT_FALSE(sol.canPartition(v2));
    EXPECT_FALSE(sol.canPartition2(v2));

    vector<int> v3 = {1, 1};
    EXPECT_TRUE(sol.canPartition(v3));
    EXPECT_TRUE(sol.canPartition2(v3));

    vector<int> v4 = {1, 2, 5};
    EXPECT_FALSE(sol.canPartition(v4));
    EXPECT_FALSE(sol.canPartition2(v4));

    vector<int> v5 = {2, 2, 1, 1};
    EXPECT_TRUE(sol.canPartition(v5));
    EXPECT_TRUE(sol.canPartition2(v5));

    vector<int> v6 = {1};
    EXPECT_FALSE(sol.canPartition(v6));
    EXPECT_FALSE(sol.canPartition2(v6));

    vector<int> v7 = {100};
    EXPECT_FALSE(sol.canPartition(v7));
    EXPECT_FALSE(sol.canPartition2(v7));

    vector<int> v8 = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_TRUE(sol.canPartition(v8));
    EXPECT_TRUE(sol.canPartition2(v8));

    vector<int> v9 = {14, 9, 8, 4, 3, 2};
    EXPECT_TRUE(sol.canPartition(v9));
    EXPECT_TRUE(sol.canPartition2(v9));
}

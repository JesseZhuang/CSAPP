#include "gtest/gtest.h"
#include "array/ThreeSum.hpp"

using namespace std;

static vector<vector<int>> sorted(vector<vector<int>> v) {
    for (auto& triplet : v) sort(triplet.begin(), triplet.end());
    sort(v.begin(), v.end());
    return v;
}

TEST(array, three_sum) {
    Solution sol;

    // Example 1: [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]
    vector<int> n1 = {-1,0,1,2,-1,-4};
    EXPECT_EQ(sorted({{-1,-1,2},{-1,0,1}}), sorted(sol.threeSum(n1)));

    // Example 2: [0,1,1] -> []
    vector<int> n2 = {0,1,1};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n2));

    // Example 3: [0,0,0] -> [[0,0,0]]
    vector<int> n3 = {0,0,0};
    EXPECT_EQ(sorted({{0,0,0}}), sorted(sol.threeSum(n3)));

    // Empty input
    vector<int> n4 = {};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n4));

    // Two elements
    vector<int> n5 = {1,-1};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n5));

    // All zeros
    vector<int> n6 = {0,0,0,0,0};
    EXPECT_EQ(sorted({{0,0,0}}), sorted(sol.threeSum(n6)));

    // No triplet
    vector<int> n7 = {1,2,3,4,5};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n7));

    // All negative
    vector<int> n8 = {-5,-4,-3,-2,-1};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n8));

    // Multiple triplets
    vector<int> n9 = {-2,-1,0,1,2,3};
    EXPECT_EQ(sorted({{-2,-1,3},{-2,0,2},{-1,0,1}}), sorted(sol.threeSum(n9)));

    // Large duplicates
    vector<int> n10 = {-1,-1,-1,0,0,0,1,1,1};
    EXPECT_EQ(sorted({{-1,-1,2},{-1,0,1},{0,0,0}}).empty(), false);
    // Actual check:
    auto r10 = sorted(sol.threeSum(n10));
    EXPECT_EQ(sorted({{-1,0,1},{0,0,0}}), r10);
}

TEST(array, three_sum_hash) {
    Solution2 sol;

    vector<int> n1 = {-1,0,1,2,-1,-4};
    EXPECT_EQ(sorted({{-1,-1,2},{-1,0,1}}), sorted(sol.threeSum(n1)));

    vector<int> n2 = {0,1,1};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n2));

    vector<int> n3 = {0,0,0};
    EXPECT_EQ(sorted({{0,0,0}}), sorted(sol.threeSum(n3)));

    vector<int> n4 = {};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n4));

    vector<int> n5 = {1,-1};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n5));

    vector<int> n6 = {0,0,0,0,0};
    EXPECT_EQ(sorted({{0,0,0}}), sorted(sol.threeSum(n6)));

    vector<int> n7 = {1,2,3,4,5};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n7));

    vector<int> n8 = {-5,-4,-3,-2,-1};
    EXPECT_EQ(vector<vector<int>>{}, sol.threeSum(n8));

    vector<int> n9 = {-2,-1,0,1,2,3};
    EXPECT_EQ(sorted({{-2,-1,3},{-2,0,2},{-1,0,1}}), sorted(sol.threeSum(n9)));

    vector<int> n10 = {-1,-1,-1,0,0,0,1,1,1};
    auto r10 = sorted(sol.threeSum(n10));
    EXPECT_EQ(sorted({{-1,0,1},{0,0,0}}), r10);
}

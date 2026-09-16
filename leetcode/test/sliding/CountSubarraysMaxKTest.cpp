#include "sliding/CountSubarraysMaxK.hpp"
#include <gtest/gtest.h>

TEST(sliding, count_subarrays_max_k) {
    SolutionCountSubarraysMaxK sol;
    vector<int> v1 = {1, 3, 2, 3, 3};
    EXPECT_EQ(sol.countSubarrays(v1, 2), 6);
    vector<int> v2 = {1, 4, 2, 1};
    EXPECT_EQ(sol.countSubarrays(v2, 3), 0);
    vector<int> v3 = {5, 5, 5, 5};
    EXPECT_EQ(sol.countSubarrays(v3, 2), 6);
    vector<int> v4 = {7};
    EXPECT_EQ(sol.countSubarrays(v4, 1), 1);
    vector<int> v5 = {3, 1, 1, 3};
    EXPECT_EQ(sol.countSubarrays(v5, 2), 1);
    vector<int> v6 = {2, 1, 2, 1, 2};
    EXPECT_EQ(sol.countSubarrays(v6, 3), 1);
    vector<int> v7 = {1, 2, 3};
    EXPECT_EQ(sol.countSubarrays(v7, 1), 3);
    vector<int> v8 = {5, 1, 5, 1};
    EXPECT_EQ(sol.countSubarrays(v8, 3), 0);
    vector<int> v9 = {4, 4, 4, 1, 1};
    EXPECT_EQ(sol.countSubarrays(v9, 2), 7);
}

TEST(sliding, count_subarrays_max_k_v2) {
    SolutionCountSubarraysMaxK2 sol;
    vector<int> v1 = {1, 3, 2, 3, 3};
    EXPECT_EQ(sol.countSubarrays(v1, 2), 6);
    vector<int> v2 = {1, 4, 2, 1};
    EXPECT_EQ(sol.countSubarrays(v2, 3), 0);
    vector<int> v3 = {5, 5, 5, 5};
    EXPECT_EQ(sol.countSubarrays(v3, 2), 6);
    vector<int> v4 = {7};
    EXPECT_EQ(sol.countSubarrays(v4, 1), 1);
    vector<int> v5 = {3, 1, 1, 3};
    EXPECT_EQ(sol.countSubarrays(v5, 2), 1);
    vector<int> v6 = {2, 1, 2, 1, 2};
    EXPECT_EQ(sol.countSubarrays(v6, 3), 1);
    vector<int> v7 = {1, 2, 3};
    EXPECT_EQ(sol.countSubarrays(v7, 1), 3);
    vector<int> v8 = {5, 1, 5, 1};
    EXPECT_EQ(sol.countSubarrays(v8, 3), 0);
    vector<int> v9 = {4, 4, 4, 1, 1};
    EXPECT_EQ(sol.countSubarrays(v9, 2), 7);
}

#include "gtest/gtest.h"
#include "hash/SubarraySumsDivisibleByK.hpp"
#include <vector>
using namespace std;

TEST(hash, subarray_sums_divisible_by_k) {
    Solution sol;

    vector<int> v1{4, 5, 0, -2, -3, 1};
    ASSERT_EQ(7, sol.subarraysDivByK(v1, 5));
    ASSERT_EQ(7, sol.subarraysDivByKBrute(v1, 5));

    vector<int> v2{5};
    ASSERT_EQ(0, sol.subarraysDivByK(v2, 9));
    ASSERT_EQ(0, sol.subarraysDivByKBrute(v2, 9));

    vector<int> v3{5, 10, 15};
    ASSERT_EQ(6, sol.subarraysDivByK(v3, 5));
    ASSERT_EQ(6, sol.subarraysDivByKBrute(v3, 5));

    vector<int> v4{0};
    ASSERT_EQ(1, sol.subarraysDivByK(v4, 1));
    ASSERT_EQ(1, sol.subarraysDivByKBrute(v4, 1));

    vector<int> v5{-1, 2, 9};
    ASSERT_EQ(2, sol.subarraysDivByK(v5, 2));
    ASSERT_EQ(2, sol.subarraysDivByKBrute(v5, 2));

    vector<int> v6{0, 0, 0};
    ASSERT_EQ(6, sol.subarraysDivByK(v6, 3));
    ASSERT_EQ(6, sol.subarraysDivByKBrute(v6, 3));

    vector<int> v7{1, 2, 3};
    ASSERT_EQ(0, sol.subarraysDivByK(v7, 100));
    ASSERT_EQ(0, sol.subarraysDivByKBrute(v7, 100));

    vector<int> v8{1, 2, 3};
    ASSERT_EQ(6, sol.subarraysDivByK(v8, 1));
    ASSERT_EQ(6, sol.subarraysDivByKBrute(v8, 1));

    vector<int> v9{-5, 1, 2, -3, 4};
    ASSERT_EQ(3, sol.subarraysDivByK(v9, 5));
    ASSERT_EQ(3, sol.subarraysDivByKBrute(v9, 5));

    vector<int> v10{6};
    ASSERT_EQ(1, sol.subarraysDivByK(v10, 3));
    ASSERT_EQ(1, sol.subarraysDivByKBrute(v10, 3));
}

#include "gtest/gtest.h"
#include "hash/SubarraySumEqualsK.hpp"
#include <vector>
using namespace std;

TEST(hash, subarray_sum_equals_k) {
    Solution sol;

    vector<int> v1{1, 1, 1};
    ASSERT_EQ(2, sol.subarraySum(v1, 2));
    ASSERT_EQ(2, sol.subarraySumBrute(v1, 2));

    vector<int> v2{1, 2, 3};
    ASSERT_EQ(2, sol.subarraySum(v2, 3));
    ASSERT_EQ(2, sol.subarraySumBrute(v2, 3));

    vector<int> v3{1};
    ASSERT_EQ(1, sol.subarraySum(v3, 1));
    ASSERT_EQ(1, sol.subarraySumBrute(v3, 1));

    vector<int> v4{1};
    ASSERT_EQ(0, sol.subarraySum(v4, 0));
    ASSERT_EQ(0, sol.subarraySumBrute(v4, 0));

    vector<int> v5{-1, -1, 1};
    ASSERT_EQ(1, sol.subarraySum(v5, 0));
    ASSERT_EQ(1, sol.subarraySumBrute(v5, 0));

    vector<int> v6{0, 0, 0};
    ASSERT_EQ(6, sol.subarraySum(v6, 0));
    ASSERT_EQ(6, sol.subarraySumBrute(v6, 0));

    vector<int> v7{1, -1, 0};
    ASSERT_EQ(2, sol.subarraySumBrute(v7, -1));
    ASSERT_EQ(2, sol.subarraySum(v7, -1));

    vector<int> v8{1, -1, 1, -1};
    ASSERT_EQ(4, sol.subarraySum(v8, 0));
    ASSERT_EQ(4, sol.subarraySumBrute(v8, 0));

    vector<int> v9{1, 2, 3, 4, 5};
    ASSERT_EQ(1, sol.subarraySum(v9, 15));
    ASSERT_EQ(1, sol.subarraySumBrute(v9, 15));

    vector<int> v10{1, 2, 3};
    ASSERT_EQ(0, sol.subarraySum(v10, 7));
    ASSERT_EQ(0, sol.subarraySumBrute(v10, 7));
}

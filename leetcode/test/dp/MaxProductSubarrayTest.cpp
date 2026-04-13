#include "gtest/gtest.h"
#include "dp/MaxProductSubarray.hpp"

#include <vector>

using namespace std;

TEST(dp, max_product_subarray) {
    Solution sol;

    vector<int> v1{2, 3, -2, 4};
    ASSERT_EQ(6, sol.maxProduct(v1));

    vector<int> v2{-2, 0, -1};
    ASSERT_EQ(0, sol.maxProduct(v2));

    vector<int> v3{-2};
    ASSERT_EQ(-2, sol.maxProduct(v3));

    vector<int> v4{0, 2};
    ASSERT_EQ(2, sol.maxProduct(v4));

    vector<int> v5{-2, 3, -4};
    ASSERT_EQ(24, sol.maxProduct(v5));

    vector<int> v6{2, -5, -2, -4, 3};
    ASSERT_EQ(24, sol.maxProduct(v6));

    vector<int> v7{-1, -2, -3, 0};
    ASSERT_EQ(6, sol.maxProduct(v7));

    vector<int> v8{1, -2, 3, -4, -3, -2, 1};
    ASSERT_EQ(144, sol.maxProduct(v8));
}

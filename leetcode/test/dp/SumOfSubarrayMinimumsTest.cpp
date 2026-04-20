#include "gtest/gtest.h"
#include "dp/SumOfSubarrayMinimums.hpp"

#include <vector>

using namespace std;

TEST(dp, sum_of_subarray_minimums) {
    Solution907 sol;

    vector<int> v1{3, 1, 2, 4};
    ASSERT_EQ(17, sol.sumSubarrayMins(v1));

    vector<int> v2{11, 81, 94, 43, 3};
    ASSERT_EQ(444, sol.sumSubarrayMins(v2));

    vector<int> v3{5};
    ASSERT_EQ(5, sol.sumSubarrayMins(v3));

    vector<int> v4{1, 2};
    ASSERT_EQ(4, sol.sumSubarrayMins(v4));

    vector<int> v5{3, 2, 1};
    ASSERT_EQ(10, sol.sumSubarrayMins(v5));

    vector<int> v6{1, 2, 3};
    ASSERT_EQ(10, sol.sumSubarrayMins(v6));

    vector<int> v7{2, 2, 2};
    ASSERT_EQ(12, sol.sumSubarrayMins(v7));
}

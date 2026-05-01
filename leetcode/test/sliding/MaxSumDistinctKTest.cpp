#include "gtest/gtest.h"
#include "sliding/MaxSumDistinctK.hpp"
#include <vector>

using namespace std;

TEST(sliding, max_sum_distinct_k) {
    vector<int> v1{1, 5, 4, 2, 9, 9, 9};
    EXPECT_EQ(MaxSumDistinctK::maximumSubarraySum(v1, 3), 15);

    vector<int> v2{4, 4, 4};
    EXPECT_EQ(MaxSumDistinctK::maximumSubarraySum(v2, 3), 0);
}

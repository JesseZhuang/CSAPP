#include "sliding/MinimumOperationsToReduceXToZero.hpp"
#include <gtest/gtest.h>

TEST(sliding, minimum_operations_to_reduce_x_to_zero) {
    using Solution = SolutionMinimumOperationsToReduceXToZero;
    EXPECT_EQ(Solution::minOperations({1, 1, 4, 2, 3}, 5), 2);
    EXPECT_EQ(Solution::minOperations({5, 6, 7, 8, 9}, 4), -1);
    EXPECT_EQ(Solution::minOperations({3, 2, 20, 1, 1, 3}, 10), 5);
    EXPECT_EQ(Solution::minOperations({1, 2, 3}, 6), 3);
    EXPECT_EQ(Solution::minOperations({1, 2, 3}, 7), -1);
    EXPECT_EQ(Solution::minOperations({1, 2, 3}, 0), 0);
    EXPECT_EQ(Solution::minOperations({1, 2, 3}, 2), -1);
    EXPECT_EQ(Solution::minOperations({1}, 1), 1);
}

TEST(sliding, minimum_operations_to_reduce_x_to_zero_prefix_sum) {
    using Solution = SolutionMinimumOperationsToReduceXToZero;
    EXPECT_EQ(Solution::minOperationsByPrefixSum({1, 1, 4, 2, 3}, 5), 2);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({5, 6, 7, 8, 9}, 4), -1);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({3, 2, 20, 1, 1, 3}, 10), 5);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({1, 2, 3}, 6), 3);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({1, 2, 3}, 7), -1);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({1, 2, 3}, 0), 0);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({1, 2, 3}, 2), -1);
    EXPECT_EQ(Solution::minOperationsByPrefixSum({1}, 1), 1);
}

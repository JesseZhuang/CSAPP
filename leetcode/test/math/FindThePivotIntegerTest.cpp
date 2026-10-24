#include <gtest/gtest.h>

#include "math/FindThePivotInteger.hpp"

TEST(FindThePivotIntegerTest, MathHandlesKnownCases) {
    Solution solution;
    EXPECT_EQ(1, solution.pivotInteger(1));
    EXPECT_EQ(6, solution.pivotInteger(8));
    EXPECT_EQ(-1, solution.pivotInteger(4));
    EXPECT_EQ(35, solution.pivotInteger(49));
}

TEST(FindThePivotIntegerTest, PrefixSuffixScanHandlesKnownCases) {
    Solution solution;
    EXPECT_EQ(1, solution.pivotIntegerPrefixSum(1));
    EXPECT_EQ(6, solution.pivotIntegerPrefixSum(8));
    EXPECT_EQ(-1, solution.pivotIntegerPrefixSum(4));
    EXPECT_EQ(35, solution.pivotIntegerPrefixSum(49));
}

TEST(FindThePivotIntegerTest, MethodsAgreeForEveryNThroughOneThousand) {
    Solution solution;
    for (int n = 1; n <= 1000; ++n) {
        SCOPED_TRACE(n);
        EXPECT_EQ(solution.pivotInteger(n), solution.pivotIntegerPrefixSum(n));
    }
}

#include <gtest/gtest.h>
#include "math/Pow.hpp"
#include <climits>

struct PowCase {
    double x;
    int n;
    double expected;
};

class PowIterativeTest : public ::testing::TestWithParam<PowCase> {};
class PowRecursiveTest : public ::testing::TestWithParam<PowCase> {};

static const PowCase cases[] = {
    {2.0, 10, 1024.0},
    {2.1, 3, 9.261},
    {2.0, -2, 0.25},
    {2.0, 0, 1.0},
    {-2.0, 4, 16.0},
    {-2.0, 3, -8.0},
    {0.5, 3, 0.125},
    {1.0, INT_MIN, 1.0},
    {1.0, INT_MAX, 1.0},
};

INSTANTIATE_TEST_SUITE_P(math, PowIterativeTest, ::testing::ValuesIn(cases));
INSTANTIATE_TEST_SUITE_P(math, PowRecursiveTest, ::testing::ValuesIn(cases));

TEST_P(PowIterativeTest, powIterative) {
    auto [x, n, expected] = GetParam();
    Solution50 sol;
    ASSERT_NEAR(expected, sol.myPow(x, n), 1e-5);
}

TEST_P(PowRecursiveTest, powRecursive) {
    auto [x, n, expected] = GetParam();
    Solution50 sol;
    ASSERT_NEAR(expected, sol.myPowRecursive(x, n), 1e-5);
}

#include <gtest/gtest.h>
#include "bit/CountingBits.hpp"

using V = vector<int>;

// Expected popcount arrays for each test case
static V expected0 = {0};
static V expected1 = {0, 1};
static V expected2 = {0, 1, 1};
static V expected5 = {0, 1, 1, 2, 1, 2};
static V expected8 = {0, 1, 1, 2, 1, 2, 2, 3, 1};
static V expected15 = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

static V buildExpected(int n) {
    V ans(n + 1);
    for (int i = 0; i <= n; i++)
        ans[i] = __builtin_popcount(i);
    return ans;
}

TEST(bit, counting_bits) {
    Solution338 sol;
    EXPECT_EQ(expected0, sol.countBits(0));
    EXPECT_EQ(expected1, sol.countBits(1));
    EXPECT_EQ(expected2, sol.countBits(2));
    EXPECT_EQ(expected5, sol.countBits(5));
    EXPECT_EQ(expected8, sol.countBits(8));
    EXPECT_EQ(expected15, sol.countBits(15));
    EXPECT_EQ(buildExpected(100000), sol.countBits(100000));
}

TEST(bit, counting_bits2) {
    Solution338 sol;
    EXPECT_EQ(expected0, sol.countBits2(0));
    EXPECT_EQ(expected1, sol.countBits2(1));
    EXPECT_EQ(expected2, sol.countBits2(2));
    EXPECT_EQ(expected5, sol.countBits2(5));
    EXPECT_EQ(expected8, sol.countBits2(8));
    EXPECT_EQ(expected15, sol.countBits2(15));
    EXPECT_EQ(buildExpected(100000), sol.countBits2(100000));
}

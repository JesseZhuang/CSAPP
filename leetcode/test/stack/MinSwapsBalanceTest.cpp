#include "stack/MinSwapsBalance.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(stack, min_swaps_balance) {
    MinSwapsBalance::Solution solution;

    EXPECT_EQ(0, solution.minSwaps("[]"));
    EXPECT_EQ(1, solution.minSwaps("]["));
    EXPECT_EQ(1, solution.minSwaps("][]["));
    EXPECT_EQ(2, solution.minSwaps("]]][[["));
    EXPECT_EQ(3, solution.minSwaps("]]]]][[[[["));
    EXPECT_EQ(0, solution.minSwaps("[[[]]]"));
    EXPECT_EQ(0, solution.minSwaps("[[]][]"));
    EXPECT_EQ(0, solution.minSwaps(std::string(500000, '[') + std::string(500000, ']')));
    EXPECT_EQ(250000, solution.minSwaps(std::string(500000, ']') + std::string(500000, '[')));
}

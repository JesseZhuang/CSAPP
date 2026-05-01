#include "gtest/gtest.h"
#include "dp/CountWaysGoodStrings.hpp"

TEST(dp, count_ways_good_strings) {
    CountWaysGoodStrings sol;
    ASSERT_EQ(8, sol.countGoodStrings(3, 3, 1, 1));
    ASSERT_EQ(5, sol.countGoodStrings(2, 3, 1, 2));
}

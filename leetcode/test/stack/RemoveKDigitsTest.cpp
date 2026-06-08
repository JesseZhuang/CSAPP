#include "stack/RemoveKDigits.hpp"
#include <gtest/gtest.h>

TEST(stack, remove_k_digits) {
    RemoveKDigits::Solution sol;
    EXPECT_EQ(sol.removeKdigits("1432219", 3), "1219");
    EXPECT_EQ(sol.removeKdigits("10200", 1), "200");
    EXPECT_EQ(sol.removeKdigits("10", 2), "0");
    EXPECT_EQ(sol.removeKdigits("9", 1), "0");
    EXPECT_EQ(sol.removeKdigits("123", 0), "123");
    EXPECT_EQ(sol.removeKdigits("9876", 2), "76");
    EXPECT_EQ(sol.removeKdigits("10001", 1), "1");
    EXPECT_EQ(sol.removeKdigits("1234", 2), "12");
}

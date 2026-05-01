#include "gtest/gtest.h"
#include "string/BetterCompression.hpp"

TEST(string, better_compression) {
    Solution3167 sol;
    ASSERT_EQ(sol.betterCompression("a3c9b2c1"), "a3b2c10");
    ASSERT_EQ(sol.betterCompression("a12b56c1"), "a12b56c1");
    ASSERT_EQ(sol.betterCompression("a12c56a1b5"), "a13b5c56");
    ASSERT_EQ(sol.betterCompression("c2b3a1"), "a1b3c2");
    ASSERT_EQ(sol.betterCompression("a2b4c1"), "a2b4c1");
}

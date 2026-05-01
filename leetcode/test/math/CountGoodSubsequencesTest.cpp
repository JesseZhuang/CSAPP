#include "gtest/gtest.h"
#include "math/CountGoodSubsequences.hpp"

TEST(math, count_good_subsequences_example1) {
    Solution2539 sol;
    ASSERT_EQ(11, sol.countGoodSubsequences("aabb"));
}

TEST(math, count_good_subsequences_example2) {
    Solution2539 sol;
    ASSERT_EQ(12, sol.countGoodSubsequences("leet"));
}

TEST(math, count_good_subsequences_example3) {
    Solution2539 sol;
    ASSERT_EQ(15, sol.countGoodSubsequences("abcd"));
}

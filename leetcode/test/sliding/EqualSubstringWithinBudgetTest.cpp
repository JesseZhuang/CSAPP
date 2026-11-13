#include "gtest/gtest.h"
#include "sliding/EqualSubstringWithinBudget.hpp"

TEST(sliding, equal_substring_within_budget) {
    SolutionEqualSubstringWithinBudget sol;

    EXPECT_EQ(3, sol.equalSubstring("abcd", "bcdf", 3));
    EXPECT_EQ(1, sol.equalSubstring("abcd", "cdef", 3));
    EXPECT_EQ(1, sol.equalSubstring("abcd", "acde", 0));

    // An expensive character forces the window to shrink past both endpoints.
    EXPECT_EQ(2, sol.equalSubstring("abcd", "azcd", 1));
    EXPECT_EQ(3, sol.equalSubstring("abcdxyz", "bcdezzz", 3));
    EXPECT_EQ(2, sol.equalSubstring("abcde", "abzde", 0));
    EXPECT_EQ(4, sol.equalSubstring("same", "same", 0));
    EXPECT_EQ(1, sol.equalSubstring("a", "b", 1));
    EXPECT_EQ(0, sol.equalSubstring("a", "b", 0));
}

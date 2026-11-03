#include "gtest/gtest.h"
#include "string/LargestSubstringBetweenEqualCharacters.hpp"

TEST(string, largest_substring_between_equal_characters) {
    Solution1624 solution;

    // Replacing the first occurrence with a later one would incorrectly return 0.
    EXPECT_EQ(4, solution.maxLengthBetweenEqualCharacters("cabbac"));
    EXPECT_EQ(0, solution.maxLengthBetweenEqualCharacters("aa"));
    EXPECT_EQ(-1, solution.maxLengthBetweenEqualCharacters("abcdef"));
}

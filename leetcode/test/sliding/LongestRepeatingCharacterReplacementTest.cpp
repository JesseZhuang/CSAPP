#include "gtest/gtest.h"
#include "sliding/LongestRepeatingCharacterReplacement.hpp"

TEST(sliding, longest_repeating_character_replacement) {
    SolutionLongestRepeatingCharacterReplacement sol;
    EXPECT_EQ(4, sol.characterReplacement("ABAB", 2));
    EXPECT_EQ(4, sol.characterReplacement("AABABBA", 1));
    EXPECT_EQ(1, sol.characterReplacement("A", 0));
    EXPECT_EQ(4, sol.characterReplacement("AAAA", 2));
    EXPECT_EQ(2, sol.characterReplacement("AABBC", 0));
    EXPECT_EQ(5, sol.characterReplacement("ABCDE", 4));
    EXPECT_EQ(5, sol.characterReplacement("ABABAB", 2));
    EXPECT_EQ(5, sol.characterReplacement("ABCAA", 2));
}

TEST(sliding, longest_repeating_character_replacement_binary_search) {
    SolutionLongestRepeatingCharacterReplacement2 sol;
    EXPECT_EQ(4, sol.characterReplacement("ABAB", 2));
    EXPECT_EQ(4, sol.characterReplacement("AABABBA", 1));
    EXPECT_EQ(1, sol.characterReplacement("A", 0));
    EXPECT_EQ(4, sol.characterReplacement("AAAA", 2));
    EXPECT_EQ(2, sol.characterReplacement("AABBC", 0));
    EXPECT_EQ(5, sol.characterReplacement("ABCDE", 4));
    EXPECT_EQ(5, sol.characterReplacement("ABABAB", 2));
    EXPECT_EQ(5, sol.characterReplacement("ABCAA", 2));
}

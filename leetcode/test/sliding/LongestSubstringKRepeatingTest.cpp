#include "gtest/gtest.h"
#include "sliding/LongestSubstringKRepeating.hpp"

TEST(sliding, longest_substring_k_repeating) {
    EXPECT_EQ(3, LongestSubstringKRepeating::longestSubstring("aaabb", 3));
    EXPECT_EQ(5, LongestSubstringKRepeating::longestSubstring("ababbc", 2));
    EXPECT_EQ(1, LongestSubstringKRepeating::longestSubstring("a", 1));
    EXPECT_EQ(0, LongestSubstringKRepeating::longestSubstring("abc", 4));
    EXPECT_EQ(5, LongestSubstringKRepeating::longestSubstring("aaaaa", 2));
    EXPECT_EQ(0, LongestSubstringKRepeating::longestSubstring("abcdef", 2));
    EXPECT_EQ(6, LongestSubstringKRepeating::longestSubstring("aabbcc", 2));
    EXPECT_EQ(6, LongestSubstringKRepeating::longestSubstring("aaabbbdcccc", 2));
    EXPECT_EQ(7, LongestSubstringKRepeating::longestSubstring("abcdefg", 1));
    EXPECT_EQ(3, LongestSubstringKRepeating::longestSubstring("cbcbbaaa", 3));
}

TEST(sliding, longest_substring_k_repeating2) {
    EXPECT_EQ(3, LongestSubstringKRepeating::longestSubstring2("aaabb", 3));
    EXPECT_EQ(5, LongestSubstringKRepeating::longestSubstring2("ababbc", 2));
    EXPECT_EQ(1, LongestSubstringKRepeating::longestSubstring2("a", 1));
    EXPECT_EQ(0, LongestSubstringKRepeating::longestSubstring2("abc", 4));
    EXPECT_EQ(5, LongestSubstringKRepeating::longestSubstring2("aaaaa", 2));
    EXPECT_EQ(0, LongestSubstringKRepeating::longestSubstring2("abcdef", 2));
    EXPECT_EQ(6, LongestSubstringKRepeating::longestSubstring2("aabbcc", 2));
    EXPECT_EQ(6, LongestSubstringKRepeating::longestSubstring2("aaabbbdcccc", 2));
    EXPECT_EQ(7, LongestSubstringKRepeating::longestSubstring2("abcdefg", 1));
    EXPECT_EQ(3, LongestSubstringKRepeating::longestSubstring2("cbcbbaaa", 3));
}

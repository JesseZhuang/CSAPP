#include "gtest/gtest.h"
#include "sliding/LongestSubstringWithoutRepeating.hpp"

TEST(sliding, longest_substring_without_repeating) {
    // Method 1: sliding window with hash map
    EXPECT_EQ(3, LongestSubstringWithoutRepeating::lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, LongestSubstringWithoutRepeating::lengthOfLongestSubstring("bbbbb"));
    EXPECT_EQ(3, LongestSubstringWithoutRepeating::lengthOfLongestSubstring("pwwkew"));
    EXPECT_EQ(0, LongestSubstringWithoutRepeating::lengthOfLongestSubstring(""));
    EXPECT_EQ(1, LongestSubstringWithoutRepeating::lengthOfLongestSubstring("a"));
    EXPECT_EQ(5, LongestSubstringWithoutRepeating::lengthOfLongestSubstring("abcde"));
    EXPECT_EQ(3, LongestSubstringWithoutRepeating::lengthOfLongestSubstring("abca"));

    // Method 2: sliding window with hash set
    EXPECT_EQ(3, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2("abcabcbb"));
    EXPECT_EQ(1, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2("bbbbb"));
    EXPECT_EQ(3, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2("pwwkew"));
    EXPECT_EQ(0, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2(""));
    EXPECT_EQ(1, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2("a"));
    EXPECT_EQ(5, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2("abcde"));
    EXPECT_EQ(3, LongestSubstringWithoutRepeating::lengthOfLongestSubstring2("abca"));
}

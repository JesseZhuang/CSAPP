#include "gtest/gtest.h"
#include "dp/LongestPalindromicSubsequence.hpp"

TEST(dp, longest_palindromic_subsequence) {
    EXPECT_EQ(4, LongestPalindromicSubsequence::longestPalindromeSubseq("bbbab"));
    EXPECT_EQ(2, LongestPalindromicSubsequence::longestPalindromeSubseq("cbbd"));
    EXPECT_EQ(1, LongestPalindromicSubsequence::longestPalindromeSubseq("a"));
    EXPECT_EQ(4, LongestPalindromicSubsequence::longestPalindromeSubseq("aaaa"));
    EXPECT_EQ(7, LongestPalindromicSubsequence::longestPalindromeSubseq("racecar"));
    EXPECT_EQ(1, LongestPalindromicSubsequence::longestPalindromeSubseq("abcde"));
    EXPECT_EQ(2, LongestPalindromicSubsequence::longestPalindromeSubseq("aa"));
    EXPECT_EQ(1, LongestPalindromicSubsequence::longestPalindromeSubseq("ab"));
    EXPECT_EQ(5, LongestPalindromicSubsequence::longestPalindromeSubseq("character"));
}

TEST(dp, longest_palindromic_subsequence_optimized) {
    EXPECT_EQ(4, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("bbbab"));
    EXPECT_EQ(2, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("cbbd"));
    EXPECT_EQ(1, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("a"));
    EXPECT_EQ(4, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("aaaa"));
    EXPECT_EQ(7, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("racecar"));
    EXPECT_EQ(1, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("abcde"));
    EXPECT_EQ(2, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("aa"));
    EXPECT_EQ(1, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("ab"));
    EXPECT_EQ(5, LongestPalindromicSubsequence::longestPalindromeSubseqOptimized("character"));
}

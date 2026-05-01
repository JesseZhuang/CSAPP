#include "gtest/gtest.h"
#include "hash/UniqL3PalindromeSubsequence.hpp"

using namespace std;

TEST(hash, uniq_l3_palindrome_subsequence) {
    SolutionUniqL3Palindrome sol;
    ASSERT_EQ(3, sol.countPalindromicSubsequence("aabca"));
    ASSERT_EQ(0, sol.countPalindromicSubsequence("adc"));
    ASSERT_EQ(4, sol.countPalindromicSubsequence("bbcbaba"));
}

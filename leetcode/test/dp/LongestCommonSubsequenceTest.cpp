#include "gtest/gtest.h"
#include "dp/LongestCommonSubsequence.hpp"

TEST(dp, longest_common_subsequence_1d) {
    Solution sol;
    ASSERT_EQ(3, sol.longestCommonSubsequence("abcde", "ace"));
    ASSERT_EQ(3, sol.longestCommonSubsequence("abc", "abc"));
    ASSERT_EQ(0, sol.longestCommonSubsequence("abc", "def"));
    ASSERT_EQ(1, sol.longestCommonSubsequence("bsbininm", "jmjkbkjkv"));
    ASSERT_EQ(1, sol.longestCommonSubsequence("a", "a"));
    ASSERT_EQ(0, sol.longestCommonSubsequence("a", "b"));
    ASSERT_EQ(2, sol.longestCommonSubsequence("oxcpqrsvwf", "shmtulqrypy"));
    ASSERT_EQ(5, sol.longestCommonSubsequence("abcba", "abcbcba"));
}

TEST(dp, longest_common_subsequence_2d) {
    Solution2D sol;
    ASSERT_EQ(3, sol.longestCommonSubsequence("abcde", "ace"));
    ASSERT_EQ(3, sol.longestCommonSubsequence("abc", "abc"));
    ASSERT_EQ(0, sol.longestCommonSubsequence("abc", "def"));
    ASSERT_EQ(1, sol.longestCommonSubsequence("bsbininm", "jmjkbkjkv"));
    ASSERT_EQ(5, sol.longestCommonSubsequence("abcba", "abcbcba"));
}

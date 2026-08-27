#include "gtest/gtest.h"
#include "dp/InterleavingString.hpp"

TEST(dp, interleaving_string) {
    InterleavingSolution sol;
    ASSERT_TRUE(sol.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    ASSERT_FALSE(sol.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    ASSERT_TRUE(sol.isInterleave("", "", ""));
    ASSERT_FALSE(sol.isInterleave("", "", "a"));
    ASSERT_TRUE(sol.isInterleave("a", "", "a"));
    ASSERT_TRUE(sol.isInterleave("a", "b", "ab"));
    ASSERT_TRUE(sol.isInterleave("a", "b", "ba"));
    ASSERT_TRUE(sol.isInterleave("abc", "def", "adbcef"));
    ASSERT_TRUE(sol.isInterleave("aaaa", "aaaa", "aaaaaaaa"));
    ASSERT_TRUE(sol.isInterleave("ab", "cd", "cadb"));
    ASSERT_FALSE(sol.isInterleave("ab", "cd", "cdba"));
}

TEST(dp, interleaving_string_2d) {
    InterleavingSolution2D sol;
    ASSERT_TRUE(sol.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    ASSERT_FALSE(sol.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    ASSERT_TRUE(sol.isInterleave("", "", ""));
    ASSERT_FALSE(sol.isInterleave("", "", "a"));
    ASSERT_TRUE(sol.isInterleave("a", "", "a"));
    ASSERT_TRUE(sol.isInterleave("a", "b", "ab"));
    ASSERT_TRUE(sol.isInterleave("a", "b", "ba"));
    ASSERT_TRUE(sol.isInterleave("abc", "def", "adbcef"));
    ASSERT_TRUE(sol.isInterleave("aaaa", "aaaa", "aaaaaaaa"));
    ASSERT_TRUE(sol.isInterleave("ab", "cd", "cadb"));
    ASSERT_FALSE(sol.isInterleave("ab", "cd", "cdba"));
}

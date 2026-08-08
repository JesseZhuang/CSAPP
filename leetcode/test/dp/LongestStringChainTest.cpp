#include "gtest/gtest.h"
#include "dp/LongestStringChain.hpp"

TEST(dp, longest_string_chain) {
    Solution sol;
    // Example 1: "a" -> "ba" -> "bca" -> "bda" -> "bdca"
    vector<string> w1 = {"a", "b", "ba", "bca", "bda", "bdca"};
    ASSERT_EQ(4, sol.longestStrChain(w1));
    // Example 2
    vector<string> w2 = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    ASSERT_EQ(5, sol.longestStrChain(w2));
    // Example 3: no chain possible
    vector<string> w3 = {"abcd", "dbqca"};
    ASSERT_EQ(1, sol.longestStrChain(w3));
    // Single word
    vector<string> w4 = {"a"};
    ASSERT_EQ(1, sol.longestStrChain(w4));
    // Longer chain
    vector<string> w5 = {"a", "ab", "abc", "abcd", "abcde"};
    ASSERT_EQ(5, sol.longestStrChain(w5));
}

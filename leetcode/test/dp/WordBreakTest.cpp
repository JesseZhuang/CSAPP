#include "gtest/gtest.h"
#include "dp/WordBreak.hpp"

TEST(dp, word_break_dp) {
    WordBreakDP sol;
    vector<string> d1 = {"leet", "code"};
    ASSERT_TRUE(sol.wordBreak("leetcode", d1));
    vector<string> d2 = {"apple", "pen"};
    ASSERT_TRUE(sol.wordBreak("applepenapple", d2));
    vector<string> d3 = {"cats", "dog", "sand", "and", "cat"};
    ASSERT_FALSE(sol.wordBreak("catsandog", d3));
    vector<string> d4 = {"a"};
    ASSERT_TRUE(sol.wordBreak("a", d4));
    vector<string> d5 = {"a"};
    ASSERT_FALSE(sol.wordBreak("b", d5));
    vector<string> d6 = {"a", "aa"};
    ASSERT_TRUE(sol.wordBreak("aaaa", d6));
    vector<string> d7 = {"a", "aa", "aaa"};
    ASSERT_FALSE(sol.wordBreak("aaaaaab", d7));
    vector<string> d8 = {"cats", "dog", "sand", "and", "cat"};
    ASSERT_TRUE(sol.wordBreak("catsanddog", d8));
}

TEST(dp, word_break_bfs) {
    WordBreakBFS sol;
    vector<string> d1 = {"leet", "code"};
    ASSERT_TRUE(sol.wordBreak("leetcode", d1));
    vector<string> d2 = {"apple", "pen"};
    ASSERT_TRUE(sol.wordBreak("applepenapple", d2));
    vector<string> d3 = {"cats", "dog", "sand", "and", "cat"};
    ASSERT_FALSE(sol.wordBreak("catsandog", d3));
    vector<string> d4 = {"a"};
    ASSERT_TRUE(sol.wordBreak("a", d4));
    vector<string> d5 = {"a"};
    ASSERT_FALSE(sol.wordBreak("b", d5));
    vector<string> d6 = {"a", "aa"};
    ASSERT_TRUE(sol.wordBreak("aaaa", d6));
    vector<string> d7 = {"a", "aa", "aaa"};
    ASSERT_FALSE(sol.wordBreak("aaaaaab", d7));
    vector<string> d8 = {"cats", "dog", "sand", "and", "cat"};
    ASSERT_TRUE(sol.wordBreak("catsanddog", d8));
}

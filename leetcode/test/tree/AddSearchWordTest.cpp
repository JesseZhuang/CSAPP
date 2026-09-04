#include <gtest/gtest.h>
#include "tree/AddSearchWord.hpp"

TEST(tree, add_search_word) {
    // Basic example from LeetCode
    {
        WordDictionary wd;
        wd.addWord("bad");
        wd.addWord("dad");
        wd.addWord("mad");
        EXPECT_FALSE(wd.search("pad"));
        EXPECT_TRUE(wd.search("bad"));
        EXPECT_TRUE(wd.search(".ad"));
        EXPECT_TRUE(wd.search("b.."));
    }

    // Empty dictionary
    {
        WordDictionary wd;
        EXPECT_FALSE(wd.search("a"));
        EXPECT_FALSE(wd.search("."));
        EXPECT_FALSE(wd.search(""));
    }

    // Single character words
    {
        WordDictionary wd;
        wd.addWord("a");
        wd.addWord("b");
        EXPECT_TRUE(wd.search("a"));
        EXPECT_TRUE(wd.search("b"));
        EXPECT_FALSE(wd.search("c"));
        EXPECT_TRUE(wd.search("."));
        EXPECT_FALSE(wd.search(".."));
    }

    // All dots
    {
        WordDictionary wd;
        wd.addWord("abc");
        wd.addWord("de");
        EXPECT_TRUE(wd.search("..."));
        EXPECT_TRUE(wd.search(".."));
        EXPECT_FALSE(wd.search("."));
        EXPECT_FALSE(wd.search("...."));
    }

    // Prefix is not a word
    {
        WordDictionary wd;
        wd.addWord("apple");
        EXPECT_FALSE(wd.search("app"));
        EXPECT_FALSE(wd.search("ap"));
        EXPECT_TRUE(wd.search("apple"));
        EXPECT_TRUE(wd.search("appl."));
        EXPECT_TRUE(wd.search("a..le"));
    }

    // Dot in the middle
    {
        WordDictionary wd;
        wd.addWord("cat");
        wd.addWord("car");
        wd.addWord("cap");
        EXPECT_TRUE(wd.search("c.t"));
        EXPECT_TRUE(wd.search("c.r"));
        EXPECT_TRUE(wd.search("c.p"));
        EXPECT_TRUE(wd.search("ca."));
        EXPECT_FALSE(wd.search("c.x"));  // no "cax" etc.
    }
}

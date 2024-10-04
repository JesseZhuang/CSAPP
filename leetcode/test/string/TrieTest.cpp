#include "gtest/gtest.h"
#include "string/Trie.hpp"
#include "string/TrieP.hpp"

TEST(string, trie_test) {
    Trie tbt;
    tbt.insert("hello");
    tbt.insert("happy");
    tbt.insert("henry");
    ASSERT_TRUE(tbt.search("hello"));
    ASSERT_TRUE(tbt.search("happy"));
    ASSERT_TRUE(tbt.search("henry"));
    ASSERT_FALSE(tbt.search("hap"));
    ASSERT_TRUE(tbt.startsWith("hap"));
    ASSERT_TRUE(tbt.startsWith("he"));
}

TEST(string, triep_test) {
    TrieP tbt;
    tbt.insert("hello");
    tbt.insert("henry");
    ASSERT_TRUE(tbt.search("hello"));
    ASSERT_TRUE(tbt.search("henry"));
    ASSERT_FALSE(tbt.search("happy"));
    ASSERT_TRUE(tbt.startsWith("he"));
}

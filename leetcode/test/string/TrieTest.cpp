#include "gtest/gtest.h"
#include "string/Trie.hpp"

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

#include "gtest/gtest.h"
#include "string/TrieII.hpp"

TEST(string, trie_ii) {
    TrieII trie;
    trie.insert("apple");
    trie.insert("apple");
    ASSERT_EQ(2, trie.countWordsEqualTo("apple"));
    ASSERT_EQ(2, trie.countWordsStartingWith("app"));
    trie.erase("apple");
    ASSERT_EQ(1, trie.countWordsEqualTo("apple"));
    ASSERT_EQ(1, trie.countWordsStartingWith("app"));
    trie.erase("apple");
    ASSERT_EQ(0, trie.countWordsStartingWith("app"));
}

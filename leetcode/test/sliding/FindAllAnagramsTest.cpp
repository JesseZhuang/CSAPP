#include "gtest/gtest.h"
#include "sliding/FindAllAnagrams.hpp"

TEST(sliding, find_all_anagrams) {
    using V = vector<int>;
    // basic examples
    EXPECT_EQ((V{0, 6}), FindAllAnagrams::findAnagrams("cbaebabacd", "abc"));
    EXPECT_EQ((V{0, 1, 2}), FindAllAnagrams::findAnagrams("abab", "ab"));
    // no match
    EXPECT_EQ(V{}, FindAllAnagrams::findAnagrams("abcdef", "gh"));
    // p longer than s
    EXPECT_EQ(V{}, FindAllAnagrams::findAnagrams("ab", "abc"));
    // single char
    EXPECT_EQ((V{0, 2}), FindAllAnagrams::findAnagrams("aba", "a"));
    // entire string
    EXPECT_EQ((V{0}), FindAllAnagrams::findAnagrams("abc", "cba"));
    // repeated pattern
    EXPECT_EQ((V{0, 1, 3, 4, 5}), FindAllAnagrams::findAnagrams("aababaab", "aab"));
    // empty s
    EXPECT_EQ(V{}, FindAllAnagrams::findAnagrams("", "a"));
}

TEST(sliding, find_all_anagrams2) {
    using V = vector<int>;
    EXPECT_EQ((V{0, 6}), FindAllAnagrams::findAnagrams2("cbaebabacd", "abc"));
    EXPECT_EQ((V{0, 1, 2}), FindAllAnagrams::findAnagrams2("abab", "ab"));
    EXPECT_EQ(V{}, FindAllAnagrams::findAnagrams2("abcdef", "gh"));
    EXPECT_EQ(V{}, FindAllAnagrams::findAnagrams2("ab", "abc"));
    EXPECT_EQ((V{0, 2}), FindAllAnagrams::findAnagrams2("aba", "a"));
    EXPECT_EQ((V{0}), FindAllAnagrams::findAnagrams2("abc", "cba"));
    EXPECT_EQ((V{0, 1, 3, 4, 5}), FindAllAnagrams::findAnagrams2("aababaab", "aab"));
    EXPECT_EQ(V{}, FindAllAnagrams::findAnagrams2("", "a"));
}

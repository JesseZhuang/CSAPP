#include "gtest/gtest.h"
#include "string/WordsWithinTwoEdits.hpp"

TEST(string, words_within_two_edits_brute_force) {
    Solution2452 tbt;

    // Example 1
    vector<string> q1 = {"word", "note", "ants", "wood"};
    vector<string> d1 = {"wood", "joke", "moat"};
    ASSERT_EQ(tbt.twoEditWords(q1, d1), vector<string>({"word", "note", "wood"}));

    // Example 2
    vector<string> q2 = {"yes"};
    vector<string> d2 = {"not"};
    ASSERT_EQ(tbt.twoEditWords(q2, d2), vector<string>({}));

    // Exact match
    vector<string> q3 = {"abc"};
    vector<string> d3 = {"abc"};
    ASSERT_EQ(tbt.twoEditWords(q3, d3), vector<string>({"abc"}));

    // One edit
    vector<string> q4 = {"abc"};
    vector<string> d4 = {"axc"};
    ASSERT_EQ(tbt.twoEditWords(q4, d4), vector<string>({"abc"}));

    // Two edits boundary
    vector<string> q5 = {"abc"};
    vector<string> d5 = {"axx"};
    ASSERT_EQ(tbt.twoEditWords(q5, d5), vector<string>({"abc"}));

    // Three edits rejected
    vector<string> q6 = {"abc"};
    vector<string> d6 = {"xyz"};
    ASSERT_EQ(tbt.twoEditWords(q6, d6), vector<string>({}));

    // Single char
    vector<string> q7 = {"a", "b"};
    vector<string> d7 = {"a"};
    ASSERT_EQ(tbt.twoEditWords(q7, d7), vector<string>({"a", "b"}));
}

TEST(string, words_within_two_edits_trie) {
    Solution2452V2 tbt;

    // Example 1
    vector<string> q1 = {"word", "note", "ants", "wood"};
    vector<string> d1 = {"wood", "joke", "moat"};
    ASSERT_EQ(tbt.twoEditWords(q1, d1), vector<string>({"word", "note", "wood"}));

    // Example 2
    vector<string> q2 = {"yes"};
    vector<string> d2 = {"not"};
    ASSERT_EQ(tbt.twoEditWords(q2, d2), vector<string>({}));

    // Exact match
    vector<string> q3 = {"abc"};
    vector<string> d3 = {"abc"};
    ASSERT_EQ(tbt.twoEditWords(q3, d3), vector<string>({"abc"}));

    // One edit
    vector<string> q4 = {"abc"};
    vector<string> d4 = {"axc"};
    ASSERT_EQ(tbt.twoEditWords(q4, d4), vector<string>({"abc"}));

    // Two edits boundary
    vector<string> q5 = {"abc"};
    vector<string> d5 = {"axx"};
    ASSERT_EQ(tbt.twoEditWords(q5, d5), vector<string>({"abc"}));

    // Three edits rejected
    vector<string> q6 = {"abc"};
    vector<string> d6 = {"xyz"};
    ASSERT_EQ(tbt.twoEditWords(q6, d6), vector<string>({}));

    // Single char
    vector<string> q7 = {"a", "b"};
    vector<string> d7 = {"a"};
    ASSERT_EQ(tbt.twoEditWords(q7, d7), vector<string>({"a", "b"}));
}

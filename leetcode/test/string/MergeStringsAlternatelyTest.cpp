#include "gtest/gtest.h"
#include "string/MergeStringsAlternately.hpp"

TEST(string, merge_strings_alternately_equal_lengths) {
    Solution1768 solution;
    EXPECT_EQ("apbqcr", solution.mergeAlternately("abc", "pqr"));
    EXPECT_EQ("az", solution.mergeAlternately("a", "z"));
}

TEST(string, merge_strings_alternately_first_shorter) {
    Solution1768 solution;
    EXPECT_EQ("apbqrs", solution.mergeAlternately("ab", "pqrs"));
}

TEST(string, merge_strings_alternately_second_shorter) {
    Solution1768 solution;
    EXPECT_EQ("apbqcd", solution.mergeAlternately("abcd", "pq"));
}

TEST(string, merge_strings_alternately_empty_strings) {
    Solution1768 solution;
    EXPECT_EQ("abc", solution.mergeAlternately("abc", ""));
    EXPECT_EQ("pqr", solution.mergeAlternately("", "pqr"));
    EXPECT_EQ("", solution.mergeAlternately("", ""));
}

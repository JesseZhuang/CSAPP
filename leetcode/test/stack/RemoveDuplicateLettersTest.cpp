#include "stack/RemoveDuplicateLetters.hpp"
#include <gtest/gtest.h>

TEST(stack, remove_duplicate_letters) {
    RemoveDuplicateLetters::Solution sol;
    EXPECT_EQ(sol.removeDuplicateLetters("bcabc"), "abc");
    EXPECT_EQ(sol.removeDuplicateLetters("cbacdcbc"), "acdb");
    EXPECT_EQ(sol.removeDuplicateLetters("a"), "a");
    EXPECT_EQ(sol.removeDuplicateLetters("abacb"), "abc");
    EXPECT_EQ(sol.removeDuplicateLetters("bbcaac"), "bac");
}

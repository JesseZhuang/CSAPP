#include "stack/CheckIfWordIsValidAfterSubstitutions.hpp"
#include <gtest/gtest.h>

TEST(stack, check_if_word_is_valid_after_substitutions_valid) {
    CheckIfWordIsValidAfterSubstitutions::Solution sol;
    EXPECT_TRUE(sol.isValid("abc"));
    EXPECT_TRUE(sol.isValid("aabcbc"));
    EXPECT_TRUE(sol.isValid("abcabcababcc"));
    EXPECT_TRUE(sol.isValid("aaabcbcbc"));
}

TEST(stack, check_if_word_is_valid_after_substitutions_invalid_order) {
    CheckIfWordIsValidAfterSubstitutions::Solution sol;
    EXPECT_FALSE(sol.isValid("abccba"));
    EXPECT_FALSE(sol.isValid("cababc"));
    EXPECT_FALSE(sol.isValid("acb"));
    EXPECT_FALSE(sol.isValid("bac"));
}

TEST(stack, check_if_word_is_valid_after_substitutions_leftover_characters) {
    CheckIfWordIsValidAfterSubstitutions::Solution sol;
    EXPECT_FALSE(sol.isValid("a"));
    EXPECT_FALSE(sol.isValid("ab"));
    EXPECT_FALSE(sol.isValid("abcab"));
    EXPECT_FALSE(sol.isValid("aabcc"));
    EXPECT_FALSE(sol.isValid("aabbcc"));
}

TEST(stack, check_if_word_is_valid_after_substitutions_deep_nesting) {
    CheckIfWordIsValidAfterSubstitutions::Solution sol;
    std::string input(6666, 'a');
    for (int i = 0; i < 6666; ++i) input += "bc";
    EXPECT_TRUE(sol.isValid(input));
}

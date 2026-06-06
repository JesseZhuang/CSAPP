#include "gtest/gtest.h"
#include "stack/MinimumRemoveToMakeValidParentheses.hpp"

// Tests for stack-based approach
TEST(stack, minimum_remove_to_make_valid_parentheses_basic) {
    Solution sol;
    ASSERT_EQ("lee(t(c)o)de", sol.minRemoveToMakeValid("lee(t(c)o)de)"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_mixed) {
    Solution sol;
    ASSERT_EQ("ab(c)d", sol.minRemoveToMakeValid("a)b(c)d"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_only_parens) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValid("))(("));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_empty) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValid(""));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_all_valid) {
    Solution sol;
    ASSERT_EQ("(a(bc)d)", sol.minRemoveToMakeValid("(a(bc)d)"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_only_open) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValid("((("));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_only_close) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValid(")))"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_nested) {
    Solution sol;
    ASSERT_EQ("a(b(c)d)e", sol.minRemoveToMakeValid("a(b(c)d)e"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_mixed_invalid) {
    Solution sol;
    ASSERT_EQ("(a)", sol.minRemoveToMakeValid(")(a)("));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_no_letters) {
    Solution sol;
    ASSERT_EQ("()()()", sol.minRemoveToMakeValid("()()))(()"));
}

// Tests for two-pass approach
TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_basic) {
    Solution sol;
    ASSERT_EQ("lee(t(c)o)de", sol.minRemoveToMakeValidTwoPass("lee(t(c)o)de)"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_mixed) {
    Solution sol;
    ASSERT_EQ("ab(c)d", sol.minRemoveToMakeValidTwoPass("a)b(c)d"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_only_parens) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValidTwoPass("))(("));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_empty) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValidTwoPass(""));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_all_valid) {
    Solution sol;
    ASSERT_EQ("(a(bc)d)", sol.minRemoveToMakeValidTwoPass("(a(bc)d)"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_only_open) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValidTwoPass("((("));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_only_close) {
    Solution sol;
    ASSERT_EQ("", sol.minRemoveToMakeValidTwoPass(")))"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_nested) {
    Solution sol;
    ASSERT_EQ("a(b(c)d)e", sol.minRemoveToMakeValidTwoPass("a(b(c)d)e"));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_mixed_invalid) {
    Solution sol;
    ASSERT_EQ("(a)", sol.minRemoveToMakeValidTwoPass(")(a)("));
}

TEST(stack, minimum_remove_to_make_valid_parentheses_two_pass_no_letters) {
    Solution sol;
    ASSERT_EQ("()()()", sol.minRemoveToMakeValidTwoPass("()()))(()"));
}

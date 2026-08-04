#include "stack/ValidParenthesisString.hpp"
#include <gtest/gtest.h>

TEST(stack, valid_parenthesis_string_basic) { EXPECT_TRUE(ValidParenthesisString::checkValidString("()")); }
TEST(stack, valid_parenthesis_string_star_as_close) { EXPECT_TRUE(ValidParenthesisString::checkValidString("(*)")); }
TEST(stack, valid_parenthesis_string_star_paren) { EXPECT_TRUE(ValidParenthesisString::checkValidString("(*))")); }
TEST(stack, valid_parenthesis_string_empty) { EXPECT_TRUE(ValidParenthesisString::checkValidString("")); }
TEST(stack, valid_parenthesis_string_single_star) { EXPECT_TRUE(ValidParenthesisString::checkValidString("*")); }
TEST(stack, valid_parenthesis_string_invalid) { EXPECT_FALSE(ValidParenthesisString::checkValidString("((")); }
TEST(stack, valid_parenthesis_string_close_first) { EXPECT_FALSE(ValidParenthesisString::checkValidString(")(")); }
TEST(stack, valid_parenthesis_string_all_stars) { EXPECT_TRUE(ValidParenthesisString::checkValidString("***")); }
TEST(stack, valid_parenthesis_string_complex) { EXPECT_TRUE(ValidParenthesisString::checkValidString("((*)(*)(*")); }

TEST(stack, valid_parenthesis_string_two_pass_basic) { EXPECT_TRUE(ValidParenthesisString::checkValidStringTwoPass("()")); }
TEST(stack, valid_parenthesis_string_two_pass_star) { EXPECT_TRUE(ValidParenthesisString::checkValidStringTwoPass("(*)")); }
TEST(stack, valid_parenthesis_string_two_pass_star_paren) { EXPECT_TRUE(ValidParenthesisString::checkValidStringTwoPass("(*))")); }
TEST(stack, valid_parenthesis_string_two_pass_empty) { EXPECT_TRUE(ValidParenthesisString::checkValidStringTwoPass("")); }
TEST(stack, valid_parenthesis_string_two_pass_invalid) { EXPECT_FALSE(ValidParenthesisString::checkValidStringTwoPass("((")); }
TEST(stack, valid_parenthesis_string_two_pass_close_first) { EXPECT_FALSE(ValidParenthesisString::checkValidStringTwoPass(")(")); }
TEST(stack, valid_parenthesis_string_two_pass_all_stars) { EXPECT_TRUE(ValidParenthesisString::checkValidStringTwoPass("***")); }

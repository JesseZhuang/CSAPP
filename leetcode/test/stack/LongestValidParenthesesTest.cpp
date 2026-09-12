#include "stack/LongestValidParentheses.hpp"
#include <gtest/gtest.h>

TEST(stack, longest_valid_parentheses_stack_example1) { EXPECT_EQ(2, Solution32::longestValidParenthesesStack("(()")); }
TEST(stack, longest_valid_parentheses_stack_example2) { EXPECT_EQ(4, Solution32::longestValidParenthesesStack(")()())")); }
TEST(stack, longest_valid_parentheses_stack_empty) { EXPECT_EQ(0, Solution32::longestValidParenthesesStack("")); }
TEST(stack, longest_valid_parentheses_stack_single_open) { EXPECT_EQ(0, Solution32::longestValidParenthesesStack("(")); }
TEST(stack, longest_valid_parentheses_stack_single_close) { EXPECT_EQ(0, Solution32::longestValidParenthesesStack(")")); }
TEST(stack, longest_valid_parentheses_stack_all_open) { EXPECT_EQ(0, Solution32::longestValidParenthesesStack("((((")); }
TEST(stack, longest_valid_parentheses_stack_two_pairs) { EXPECT_EQ(4, Solution32::longestValidParenthesesStack("()()")); }
TEST(stack, longest_valid_parentheses_stack_three_pairs) { EXPECT_EQ(6, Solution32::longestValidParenthesesStack("()()()")); }
TEST(stack, longest_valid_parentheses_stack_nested) { EXPECT_EQ(6, Solution32::longestValidParenthesesStack("((()))")); }
TEST(stack, longest_valid_parentheses_stack_mixed) { EXPECT_EQ(6, Solution32::longestValidParenthesesStack("()(())")); }
TEST(stack, longest_valid_parentheses_stack_complex) { EXPECT_EQ(10, Solution32::longestValidParenthesesStack(")(())()(()))("));}
TEST(stack, longest_valid_parentheses_stack_trailing) { EXPECT_EQ(6, Solution32::longestValidParenthesesStack("()()()("));}

TEST(stack, longest_valid_parentheses_two_pass_example1) { EXPECT_EQ(2, Solution32::longestValidParenthesesTwoPass("(()")); }
TEST(stack, longest_valid_parentheses_two_pass_example2) { EXPECT_EQ(4, Solution32::longestValidParenthesesTwoPass(")()())")); }
TEST(stack, longest_valid_parentheses_two_pass_empty) { EXPECT_EQ(0, Solution32::longestValidParenthesesTwoPass("")); }
TEST(stack, longest_valid_parentheses_two_pass_single_open) { EXPECT_EQ(0, Solution32::longestValidParenthesesTwoPass("(")); }
TEST(stack, longest_valid_parentheses_two_pass_single_close) { EXPECT_EQ(0, Solution32::longestValidParenthesesTwoPass(")")); }
TEST(stack, longest_valid_parentheses_two_pass_all_open) { EXPECT_EQ(0, Solution32::longestValidParenthesesTwoPass("((((")); }
TEST(stack, longest_valid_parentheses_two_pass_two_pairs) { EXPECT_EQ(4, Solution32::longestValidParenthesesTwoPass("()()")); }
TEST(stack, longest_valid_parentheses_two_pass_three_pairs) { EXPECT_EQ(6, Solution32::longestValidParenthesesTwoPass("()()()")); }
TEST(stack, longest_valid_parentheses_two_pass_nested) { EXPECT_EQ(6, Solution32::longestValidParenthesesTwoPass("((()))")); }
TEST(stack, longest_valid_parentheses_two_pass_mixed) { EXPECT_EQ(6, Solution32::longestValidParenthesesTwoPass("()(())")); }
TEST(stack, longest_valid_parentheses_two_pass_complex) { EXPECT_EQ(10, Solution32::longestValidParenthesesTwoPass(")(())()(()))("));}
TEST(stack, longest_valid_parentheses_two_pass_trailing) { EXPECT_EQ(6, Solution32::longestValidParenthesesTwoPass("()()()("));}

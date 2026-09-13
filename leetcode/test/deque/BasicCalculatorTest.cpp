#include "deque/BasicCalculator.hpp"
#include "gtest/gtest.h"

TEST(deque, basic_calculator) {
    Solution224 sol;
    // basic examples
    EXPECT_EQ(2, sol.calculate("1 + 1"));
    EXPECT_EQ(3, sol.calculate(" 2-1 + 2 "));
    EXPECT_EQ(23, sol.calculate("(1+(4+5+2)-3)+(6+8)"));
    // edge: single number
    EXPECT_EQ(0, sol.calculate("0"));
    EXPECT_EQ(2147483647, sol.calculate("2147483647"));
    // unary minus
    EXPECT_EQ(-1, sol.calculate("-1"));
    EXPECT_EQ(-5, sol.calculate("-(3+2)"));
    // nested / redundant parens
    EXPECT_EQ(3, sol.calculate("((1+2))"));
    EXPECT_EQ(11, sol.calculate("(7)-(0)+(4)"));
    // left-to-right associativity
    EXPECT_EQ(1, sol.calculate("1-1+1"));
    EXPECT_EQ(2, sol.calculate("10-5-3"));
}

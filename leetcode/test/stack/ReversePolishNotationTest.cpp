#include "gtest/gtest.h"
#include "../../src/stack/ReversePolishNotation.hpp"

TEST(stack, reverse_polish_notation) {
    ReversePolishNotation sol;

    // Example 1: ["2","1","+","3","*"] -> 9
    vector<string> t1 = {"2", "1", "+", "3", "*"};
    EXPECT_EQ(sol.evalRPN(t1), 9);

    // Example 2: ["4","13","5","/","+"] -> 6
    vector<string> t2 = {"4", "13", "5", "/", "+"};
    EXPECT_EQ(sol.evalRPN(t2), 6);

    // Example 3: ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] -> 22
    vector<string> t3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    EXPECT_EQ(sol.evalRPN(t3), 22);

    // Single number
    vector<string> t4 = {"42"};
    EXPECT_EQ(sol.evalRPN(t4), 42);

    // Negative result
    vector<string> t5 = {"3", "5", "-"};
    EXPECT_EQ(sol.evalRPN(t5), -2);

    // Division truncation toward zero: -7/2 = -3 (not -4)
    vector<string> t6 = {"7", "2", "-", "2", "/"};
    // (7-2)/2 = 5/2 = 2... let's use a clearer case
    vector<string> t7 = {"-7", "2", "/"};
    EXPECT_EQ(sol.evalRPN(t7), -3);
}

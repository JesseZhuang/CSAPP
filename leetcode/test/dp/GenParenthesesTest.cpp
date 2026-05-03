#include "gtest/gtest.h"
#include "dp/GenParentheses.hpp"

TEST(dp, gen_parentheses_bt) {
    GenParenthesesBT sol;

    vector<string> r1 = sol.generateParenthesis(1);
    sort(r1.begin(), r1.end());
    ASSERT_EQ(r1, vector<string>({"()"}));

    vector<string> r2 = sol.generateParenthesis(2);
    sort(r2.begin(), r2.end());
    vector<string> e2 = {"(())", "()()"};
    ASSERT_EQ(r2, e2);

    vector<string> r3 = sol.generateParenthesis(3);
    sort(r3.begin(), r3.end());
    vector<string> e3 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    ASSERT_EQ(r3, e3);

    vector<string> r4 = sol.generateParenthesis(4);
    ASSERT_EQ((int)r4.size(), 14);
}

TEST(dp, gen_parentheses_dp) {
    GenParenthesesDP sol;

    vector<string> r1 = sol.generateParenthesis(1);
    sort(r1.begin(), r1.end());
    ASSERT_EQ(r1, vector<string>({"()"}));

    vector<string> r2 = sol.generateParenthesis(2);
    sort(r2.begin(), r2.end());
    vector<string> e2 = {"(())", "()()"};
    ASSERT_EQ(r2, e2);

    vector<string> r3 = sol.generateParenthesis(3);
    sort(r3.begin(), r3.end());
    vector<string> e3 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    ASSERT_EQ(r3, e3);

    vector<string> r4 = sol.generateParenthesis(4);
    ASSERT_EQ((int)r4.size(), 14);
}

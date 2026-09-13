#ifndef LEETCODE_BASICCALCULATOR_HPP
#define LEETCODE_BASICCALCULATOR_HPP

#include <string>
#include <stack>

using namespace std;

class Solution224 {
public:
    // O(n) time — single pass through the string
    // O(n) space — stack depth proportional to nesting depth
    int calculate(const string &s) {
        stack<int> stk; // stores outer result and sign on '('
        int res = 0, num = 0, sign = 1;
        for (auto &c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // O(1) per digit
            } else if (c == '+') {
                res += sign * num; // accumulate previous number
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(res);  // push current result to stack
                stk.push(sign); // push current sign to stack
                res = 0;        // reset for sub-expression
                sign = 1;
            } else if (c == ')') {
                res += sign * num; // finalize sub-expression
                num = 0;
                res *= stk.top(); stk.pop(); // multiply by sign before '('
                res += stk.top(); stk.pop(); // add result before '('
            }
            // spaces are implicitly skipped
        }
        return res + sign * num; // handle trailing number
    }
};

#endif //LEETCODE_BASICCALCULATOR_HPP

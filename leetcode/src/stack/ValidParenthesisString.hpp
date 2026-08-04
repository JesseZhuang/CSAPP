#ifndef VALID_PARENTHESIS_STRING_HPP
#define VALID_PARENTHESIS_STRING_HPP

#include <string>
#include <algorithm>

using namespace std;

// LeetCode 678, medium, tags: string, stack, greedy, dynamic programming.
class ValidParenthesisString {
public:
    // Greedy min/max approach. O(n) time, O(1) space.
    static bool checkValidString(const string &s) {
        int lo = 0, hi = 0;
        for (char c : s) {
            if (c == '(') { lo++; hi++; }
            else if (c == ')') { lo--; hi--; }
            else { lo--; hi++; }
            if (hi < 0) return false;
            lo = max(lo, 0);
        }
        return lo == 0;
    }

    // Two-pass greedy approach. O(n) time, O(1) space.
    static bool checkValidStringTwoPass(const string &s) {
        int balance = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(' || s[i] == '*') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        balance = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return true;
    }
};

#endif

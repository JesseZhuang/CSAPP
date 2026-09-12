#ifndef LONGEST_VALID_PARENTHESES_HPP
#define LONGEST_VALID_PARENTHESES_HPP

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// LeetCode 32, hard, tags: string, stack, dynamic programming.
class Solution32 {
public:
    // Stack approach. O(n) time, O(n) space.
    static int longestValidParenthesesStack(const string &s) {
        stack<int> st;
        st.push(-1); // base index
        int maxLen = 0;
        for (int i = 0; i < (int)s.size(); i++) { // O(n), each index pushed/popped once, O(n) total
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // new base
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }

    // Two-pass greedy approach. O(n) time, O(1) space.
    static int longestValidParenthesesTwoPass(const string &s) {
        int n = (int)s.size();
        int open = 0, close = 0, maxLen = 0;
        for (int i = 0; i < n; i++) { // O(n)
            if (s[i] == '(') open++;
            else close++;
            if (open == close) maxLen = max(maxLen, 2 * close);
            else if (close > open) { open = 0; close = 0; }
        }
        open = 0; close = 0;
        for (int i = n - 1; i >= 0; i--) { // O(n)
            if (s[i] == '(') open++;
            else close++;
            if (open == close) maxLen = max(maxLen, 2 * open);
            else if (open > close) { open = 0; close = 0; }
        }
        return maxLen;
    }
};

#endif

#ifndef MINIMUMREMOVETOMAKEVALIDPARENTHESES_HPP
#define MINIMUMREMOVETOMAKEVALIDPARENTHESES_HPP

#include <string>
#include <stack>
#include <unordered_set>

// LeetCode 1249

using namespace std;

class Solution {
public:
    // Stack approach: track indices of unmatched parens
    // O(n) time, O(n) space
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> toRemove;

        // Pass 1: find all indices of unmatched parentheses
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    // Unmatched closing paren
                    toRemove.insert(i);
                }
            }
        }

        // Any remaining opening parens in stack are unmatched
        while (!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }

        // Pass 2: rebuild string skipping indices in toRemove
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (toRemove.find(i) == toRemove.end()) {
                result += s[i];
            }
        }

        return result;
    }

    // Two-pass approach: remove excess ')' left-to-right, then excess '(' right-to-left
    // O(n) time, O(n) space
    string minRemoveToMakeValidTwoPass(string s) {
        // Pass 1: left to right - remove excess ')'
        string leftToRight;
        int openCount = 0;
        for (char c : s) {
            if (c == '(') {
                openCount++;
                leftToRight += c;
            } else if (c == ')') {
                if (openCount > 0) {
                    openCount--;
                    leftToRight += c;
                }
                // Skip this ')' if no matching '('
            } else {
                leftToRight += c;
            }
        }

        // Pass 2: right to left - remove excess '('
        string result;
        int closeCount = 0;
        for (int i = leftToRight.length() - 1; i >= 0; i--) {
            char c = leftToRight[i];
            if (c == ')') {
                closeCount++;
                result += c;
            } else if (c == '(') {
                if (closeCount > 0) {
                    closeCount--;
                    result += c;
                }
                // Skip this '(' if no matching ')'
            } else {
                result += c;
            }
        }

        // Reverse result since we built it right-to-left
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif //MINIMUMREMOVETOMAKEVALIDPARENTHESES_HPP

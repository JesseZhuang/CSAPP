#ifndef VALIDPAREN_HPP
#define VALIDPAREN_HPP

#include <deque>
#include <string>

// LeetCode 20

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        deque<char> st;
        for (char c: s) {
            if (c == '(') st.push_back(')');
            else if (c == '[') st.push_back(']');
            else if (c == '{') st.push_back('}');
            else if (!st.empty() && st.back() == c) st.pop_back();
            else return false;
        }
        return st.empty();
    }
};

#endif //VALIDPAREN_HPP

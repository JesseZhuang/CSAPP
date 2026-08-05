#pragma once
#include <string>

using namespace std;

namespace RemoveDuplicateLetters {

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastIdx[26] = {};
        bool inStack[26] = {};
        for (int i = 0; i < (int)s.size(); i++)
            lastIdx[s[i] - 'a'] = i;

        string stack;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (inStack[c]) continue;
            while (!stack.empty() && stack.back() > s[i] && lastIdx[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(s[i]);
            inStack[c] = true;
        }
        return stack;
    }
};

} // namespace RemoveDuplicateLetters

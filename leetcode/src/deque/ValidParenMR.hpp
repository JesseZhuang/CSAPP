#ifndef LEETCODE_VALIDPARENMR_HPP
#define LEETCODE_VALIDPARENMR_HPP

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0, r = 0;
        vector<char> res;
        for (auto &c: s)
            if (c == ')') r++;
        for (auto &c: s) {
            if (c == '(') {
                if (l == r) continue;
                l++;
            } else if (c == ')') {
                r--;
                if (l == 0) continue;
                l--;
            }
            res.emplace_back(c);
        }
        return {res.begin(), res.end()};
    }
};

#endif //LEETCODE_VALIDPARENMR_HPP

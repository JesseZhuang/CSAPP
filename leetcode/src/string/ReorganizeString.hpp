#ifndef LEETCODE_REORGANIZESTRING_HPP
#define LEETCODE_REORGANIZESTRING_HPP

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 767

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        char mC = 0;
        int maxCnt = 0;
        for (auto &c: s) {
            counts[c] += 1;
            if (counts[c] > maxCnt)
                maxCnt = counts[c], mC = c;
        }
        if (maxCnt > (s.size() + 1) / 2) return "";
        int i = 0;
        vector<char> res(s.size());
        while (counts[mC]-- > 0) {
            res[i] = mC;
            i += 2;
        }
        for (auto &p: counts) {
            while (p.second > 0) {
                if (i > s.size() - 1) i = 1;
                res[i] = p.first;
                i += 2;
                p.second--;
            }
        }
        return {res.begin(), res.end()};
    }
};

#endif //LEETCODE_REORGANIZESTRING_HPP

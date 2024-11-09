#ifndef LEETCODE_TEXTJUSTIFY_HPP
#define LEETCODE_TEXTJUSTIFY_HPP

#include <string>
#include <vector>
#include <iomanip>
#include "util/cph.hpp"

using namespace std;

// LeetCode 68
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res, cur;
        size_t nLetters = 0;
        for (auto &w: words) {
            if (nLetters + w.size() + cur.size() > maxWidth) {
                for (int i = 0; i < maxWidth - nLetters; i++) {
                    if (cur.size() == 1) cur[0] += " ";
                    else cur[i % (cur.size() - 1)] += " ";
                }
                res.push_back(string_join(cur, ""));
                cur.clear();
                nLetters = 0;
            }
            nLetters += w.size();
            cur.push_back(w);
        }
        stringstream ss; // or add space until maxWidth
        ss << left << setfill(' ') << setw(maxWidth) << string_join(cur, " ");
        res.push_back(ss.str());
        return res;
    }
};

#endif //LEETCODE_TEXTJUSTIFY_HPP

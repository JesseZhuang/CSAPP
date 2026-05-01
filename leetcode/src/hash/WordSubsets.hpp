#ifndef LEETCODE_WORDSUBSETS_HPP
#define LEETCODE_WORDSUBSETS_HPP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// leet 916
class Solution916 {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        int maxCnt[26] = {};
        for (auto &b : words2) {
            int cnt[26] = {};
            for (char c : b) cnt[c - 'a']++;
            for (int i = 0; i < 26; i++) maxCnt[i] = max(maxCnt[i], cnt[i]);
        }
        vector<string> res;
        for (auto &a : words1) {
            int cnt[26] = {};
            for (char c : a) cnt[c - 'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++)
                if (cnt[i] < maxCnt[i]) { ok = false; break; }
            if (ok) res.push_back(a);
        }
        return res;
    }
};

#endif //LEETCODE_WORDSUBSETS_HPP

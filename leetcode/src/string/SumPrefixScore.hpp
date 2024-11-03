#ifndef SUMPREFIXSCORE_HPP
#define SUMPREFIXSCORE_HPP

#include <vector>
#include "struct/TrieNode.hpp"

using namespace std;

// LeetCode 2416
class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        auto root = make_unique<TrieNode>(); // note no *
        for (string &w: words) root->insert(w);

        vector<int> res;
        for (string &w: words) {
            int sum = 0;
            auto cur = root.get(); // note star * is optional ...
            for (auto &c: w) {
                int id = c - 'a';
                cur = cur->next[id].get();
                sum += cur->cnt;
            }
            res.push_back(sum);
        }
        return res;
    }
};

#endif //SUMPREFIXSCORE_HPP

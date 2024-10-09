#ifndef SUMPREFIXSCORE_HPP
#define SUMPREFIXSCORE_HPP

#include <vector>
#include "struct/TrieNode.hpp"

using namespace std;

// LeetCode 2416
class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        unique_ptr<TrieNode> root = make_unique<TrieNode>();
        for (string &w: words) root->insert(w);

        vector<int> res;
        for (string &w: words) {
            int sum = 0;
            TrieNode *cur = root.get();
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

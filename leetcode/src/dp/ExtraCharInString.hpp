#ifndef LEETCODE_EXTRACHARINSTRING_HPP
#define LEETCODE_EXTRACHARINSTRING_HPP

#include <string>
#include <vector>
#include "struct//TrieNode.hpp"

using namespace std;

// LeetCode 2707
class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        size_t n = s.size();
        vector<int> dp(n + 1);
        auto root = make_unique<TrieNode>();
        for (string &w: dictionary) root->insert(w);
        for (size_t l = n - 1; l != size_t(-1); l--) { // note !=
            dp[l] = dp[l + 1] + 1;
            auto cur = root.get(); // auto *cur or auto cur both ok
            for (size_t r = l; r < n; r++) {
                if (!cur->next.count(s[r])) break;
                cur = cur->next[s[r]].get();
                if (cur->end) dp[l] = min(dp[l], dp[r + 1]);
            }
        }
        return dp[0];
    }
};

#endif //LEETCODE_EXTRACHARINSTRING_HPP

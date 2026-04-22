#ifndef LEETCODE_WORDSWITHINTWOEDITS_HPP
#define LEETCODE_WORDSWITHINTWOEDITS_HPP

#include <string>
#include <vector>
#include <array>
#include <memory>

using namespace std;

// LeetCode 2452

// Solution 1: Brute Force
// Time: O(q * d * m), Space: O(1) extra
class Solution2452 {
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
        vector<string> res;
        for (auto &q : queries) {
            for (auto &d : dictionary) {
                int diff = 0;
                for (int i = 0; i < (int)q.size() && diff <= 2; i++) {
                    if (q[i] != d[i]) diff++;
                }
                if (diff <= 2) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};

// Solution 2: Trie with DFS allowing up to 2 mismatches
// Time: O(d * m) build + O(q * 26^2 * m) worst-case query, Space: O(d * m) for trie
class Solution2452V2 {
    struct TrieNode {
        array<unique_ptr<TrieNode>, 26> children{};
        bool isEnd = false;
    };

    unique_ptr<TrieNode> root;

    void insert(const string &word) {
        TrieNode *cur = root.get();
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = make_unique<TrieNode>();
            }
            cur = cur->children[idx].get();
        }
        cur->isEnd = true;
    }

    // DFS: try to match word[pos..] from node, allowing up to `edits` mismatches
    bool dfs(TrieNode *node, const string &word, int pos, int edits) {
        if (edits > 2) return false;
        if (pos == (int)word.size()) return node->isEnd;
        for (int c = 0; c < 26; c++) {
            if (!node->children[c]) continue;
            int cost = (c != word[pos] - 'a') ? 1 : 0;
            if (dfs(node->children[c].get(), word, pos + 1, edits + cost))
                return true;
        }
        return false;
    }

public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
        root = make_unique<TrieNode>();
        for (auto &w : dictionary) insert(w);
        vector<string> res;
        for (auto &q : queries) {
            if (dfs(root.get(), q, 0, 0))
                res.push_back(q);
        }
        return res;
    }
};

#endif //LEETCODE_WORDSWITHINTWOEDITS_HPP

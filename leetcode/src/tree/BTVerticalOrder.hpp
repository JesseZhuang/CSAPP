#ifndef BTVERTICALORDER_HPP
#define BTVERTICALORDER_HPP

#include <deque>
#include <vector>
#include <unordered_map>
#include "struct/TreeNode.hpp"
#include <ranges>

using namespace std;

// LintCode 651, LeetCode 314, 20 ms, 2.82 mb
class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int> > verticalOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == nullptr) return res;
        unordered_map<int, vector<int> > colV; // col:vals
        deque<pair<TreeNode *, int> > q;
        int minC = 0, maxC = 0;
        q.emplace_back(root, 0);
        while (!q.empty()) {
            auto [n, c] = q.front();
            q.pop_front();
            colV[c].emplace_back(n->val);
            minC = min(minC, c);
            maxC = max(maxC, c);
            if (n->left) q.emplace_back(n->left, c - 1);
            if (n->right) q.emplace_back(n->right, c + 1);
        }
        for (int i = minC; i <= maxC; ++i) res.emplace_back(colV[i]);
        return res;
//        auto vals = views::values(colV); // LintCode does not support cpp 20
//        return vector<vector<int> >{vals.begin(), vals.end()};
    }
};

#endif //BTVERTICALORDER_HPP

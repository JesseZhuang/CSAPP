#ifndef BTVERTICALORDER_HPP
#define BTVERTICALORDER_HPP

#include <deque>
#include <vector>
#include <unordered_map>
#include "struct/TreeNode.hpp"

using namespace std;

// LintCode 651, LeetCode 314
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
            auto [n,c] = q.front();
            q.pop_front();
            colV[c].push_back(n->val);
            minC = min(minC, c);
            maxC = max(maxC, c);
            if (n->left) q.emplace_back(n->left, c - 1);
            if (n->right) q.emplace_back(n->right, c + 1);
        }
        for (int i = minC; i <= maxC; ++i) res.push_back(colV[i]);
        return res;
        // auto vals = views::values(colV);
        // return vector<vector<int> >{vals.begin(), vals.end()};
    }
};
#endif //BTVERTICALORDER_HPP

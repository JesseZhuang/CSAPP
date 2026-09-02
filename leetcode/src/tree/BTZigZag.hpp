#ifndef BTZIGZAG_HPP
#define BTZIGZAG_HPP
#include <algorithm>
#include <deque>
#include <vector>

#include "struct/TreeNode.hpp"

using namespace std;

// LeetCode 103

class Solution103 {
public:
    // BFS with deque, reversing direction each level.
    // Time: O(n)  Space: O(w) where w = max width of the tree
    vector<vector<int>> zigzagLevelOrderBfs(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        deque<TreeNode *> q;
        q.push_back(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop_front();
                int idx = leftToRight ? i : size - 1 - i;
                level[idx] = cur->val;
                if (cur->left) q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }

    // DFS recursive: build levels then reverse odd-indexed ones.
    // Time: O(n)  Space: O(h) where h = height of the tree (recursion stack)
    vector<vector<int>> zigzagLevelOrderDfs(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        for (int i = 1; i < (int)res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }

private:
    void dfs(TreeNode *node, int depth, vector<vector<int>> &res) {
        if (node == nullptr) return;
        if (depth == (int)res.size()) res.emplace_back();
        res[depth].push_back(node->val);
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
};

#endif //BTZIGZAG_HPP

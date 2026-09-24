#ifndef LEETCODE_COUNTGOODNODEBT_HPP
#define LEETCODE_COUNTGOODNODEBT_HPP

#include "struct/TreeNode.hpp"
#include <algorithm>
#include <queue>
#include <utility>

// LeetCode 1448 - Count Good Nodes in Binary Tree
// A node X is "good" if no node on the path from root to X has value > X.

class Solution {
public:
    // DFS recursive — O(n) time, O(h) space
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    // BFS iterative — O(n) time, O(w) space
    int goodNodesBfs(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            auto [node, maxSoFar] = q.front();
            q.pop();
            if (node->val >= maxSoFar) count++;
            int newMax = std::max(maxSoFar, node->val);
            if (node->left) q.push({node->left, newMax});
            if (node->right) q.push({node->right, newMax});
        }
        return count;
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        int count = (node->val >= maxSoFar) ? 1 : 0;
        int newMax = std::max(maxSoFar, node->val);
        return count + dfs(node->left, newMax) + dfs(node->right, newMax);
    }
};

#endif //LEETCODE_COUNTGOODNODEBT_HPP

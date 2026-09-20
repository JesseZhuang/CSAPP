#ifndef LEETCODE_INVERTBT_HPP
#define LEETCODE_INVERTBT_HPP

#include "struct/TreeNode.hpp"
#include <queue>
#include <algorithm>

// LeetCode 226 - Invert Binary Tree

class InvertBT {
public:
    // Recursive DFS
    // Time:  O(n) — visit each node once
    // Space: O(h) — recursion stack depth (h = tree height)
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // Iterative BFS with queue
    // Time:  O(n) — visit each node once
    // Space: O(n) — queue holds up to n/2 nodes at widest level
    TreeNode* invertTreeBFS(TreeNode* root) {
        if (!root) return nullptr;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            std::swap(node->left, node->right);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};

#endif //LEETCODE_INVERTBT_HPP

#ifndef LEETCODE_HOUSEROBBERIII_HPP
#define LEETCODE_HOUSEROBBERIII_HPP

#include "struct/TreeNode.hpp"
#include <algorithm>
#include <utility>

// LeetCode 337 - House Robber III
// Time:  O(n) — visit each node once
// Space: O(h) — recursion stack depth

class Solution {
public:
    int rob(TreeNode* root) {
        auto [rob_root, skip_root] = dfs(root);
        return std::max(rob_root, skip_root);
    }

private:
    // Returns {rob_this, skip_this}
    std::pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [rob_left, skip_left] = dfs(node->left);
        auto [rob_right, skip_right] = dfs(node->right);
        int rob_this = node->val + skip_left + skip_right;
        int skip_this = std::max(rob_left, skip_left) + std::max(rob_right, skip_right);
        return {rob_this, skip_this};
    }
};

#endif //LEETCODE_HOUSEROBBERIII_HPP

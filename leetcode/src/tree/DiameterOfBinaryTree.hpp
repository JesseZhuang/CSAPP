#ifndef LEETCODE_DIAMETEROFBINARYTREE_HPP
#define LEETCODE_DIAMETEROFBINARYTREE_HPP

#include "struct/TreeNode.hpp"
#include <algorithm>

// LeetCode 543 - Diameter of Binary Tree
// Time:  O(n) — visit each node once
// Space: O(h) — recursion stack depth

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        depth(root, result);
        return result;
    }

private:
    int depth(TreeNode* node, int& result) {
        if (!node) return 0;
        int left = depth(node->left, result);
        int right = depth(node->right, result);
        result = std::max(result, left + right);
        return std::max(left, right) + 1;
    }
};

#endif //LEETCODE_DIAMETEROFBINARYTREE_HPP

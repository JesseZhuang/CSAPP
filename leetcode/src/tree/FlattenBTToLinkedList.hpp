#ifndef FLATTENBTTOLINKEDLIST_HPP
#define FLATTENBTTOLINKEDLIST_HPP

#include "struct/TreeNode.hpp"

// LeetCode 114 - Flatten Binary Tree to Linked List
// Solution 1: Iterative Morris-traversal style.
// For each node with a left child, find the rightmost node of the left subtree,
// link current's right subtree to that rightmost node, then move left to right.
// Time: O(n), Space: O(1)
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                // Find rightmost node of left subtree
                TreeNode *rightmost = cur->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                // Link current's right subtree to rightmost
                rightmost->right = cur->right;
                // Move left subtree to right
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

// Solution 2: Recursive reverse postorder (right, left, root) with prev pointer.
// Time: O(n), Space: O(h) where h = tree height (recursion stack)
class Solution2 {
public:
    void flatten(TreeNode *root) {
        prev = nullptr;
        helper(root);
    }

private:
    TreeNode *prev = nullptr;

    void helper(TreeNode *node) {
        if (!node) return;
        helper(node->right);
        helper(node->left);
        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
};

#endif //FLATTENBTTOLINKEDLIST_HPP

#ifndef VALIDATEBST_HPP
#define VALIDATEBST_HPP

#include "struct/TreeNode.hpp"
#include <climits>
#include <stack>

class ValidateBST {
public:
    // Approach 1: Recursive with bounds
    // Time: O(n), Space: O(h) where h is tree height
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    // Approach 2: Iterative inorder traversal with stack
    // Time: O(n), Space: O(h) where h is tree height
    bool isValidBSTInorder(TreeNode* root) {
        std::stack<TreeNode*> stk;
        long prev = LONG_MIN;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (curr->val <= prev) return false;
            prev = curr->val;
            curr = curr->right;
        }
        return true;
    }

private:
    bool validate(TreeNode* node, long low, long high) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;
        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }
};

#endif //VALIDATEBST_HPP

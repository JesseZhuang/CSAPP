#ifndef KTHSMALLESTBST_HPP
#define KTHSMALLESTBST_HPP

#include <stack>
#include "struct/TreeNode.hpp"

// LeetCode 230
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        std::stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (--k == 0) return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};

#endif //KTHSMALLESTBST_HPP

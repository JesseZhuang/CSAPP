#ifndef SAMETREE_HPP
#define SAMETREE_HPP

#include "struct/TreeNode.hpp";

// LeetCode 100
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr || q==nullptr) return p==q;
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

#endif //SAMETREE_HPP

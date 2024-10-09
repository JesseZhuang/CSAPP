#ifndef MAXDEPTHBT_HPP
#define MAXDEPTHBT_HPP

#include <algorithm>
#include "struct/TreeNode.hpp"

// LeetCode 104
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

#endif //MAXDEPTHBT_HPP

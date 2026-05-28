#ifndef MAXPATHSUMBT_HPP
#define MAXPATHSUMBT_HPP

#include <algorithm>
#include <climits>
#include "struct/TreeNode.hpp"

// LeetCode 124 - Binary Tree Maximum Path Sum
// DFS post-order: at each node, compute max gain from left/right subtrees (clamped to 0),
// update global max with path through current node.
// Time: O(n), Space: O(h) where h = tree height (recursion stack)
class Solution124 {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxGain(root, res);
        return res;
    }

private:
    int maxGain(TreeNode *node, int &res) {
        if (!node) return 0;
        int left = std::max(0, maxGain(node->left, res));   // O(left subtree)
        int right = std::max(0, maxGain(node->right, res)); // O(right subtree)
        res = std::max(res, left + right + node->val);      // path through node
        return std::max(left, right) + node->val;           // max single-branch gain
    }
};

#endif //MAXPATHSUMBT_HPP

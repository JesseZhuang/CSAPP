#ifndef LEETCODE_LOWESTCOMMONANCESTORBT_HPP
#define LEETCODE_LOWESTCOMMONANCESTORBT_HPP

// leet 236

#include "struct/TreeNode.hpp"
#include <unordered_map>
#include <unordered_set>

class SolutionLCA {
public:
    // Recursive DFS: O(n) time, O(h) space
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    // Iterative with parent map: O(n) time, O(n) space
    TreeNode *lowestCommonAncestorIterative(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return nullptr;
        std::unordered_map<TreeNode *, TreeNode *> parent;
        parent[root] = nullptr;
        std::vector<TreeNode *> stack = {root};
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode *node = stack.back();
            stack.pop_back();
            if (node->left) {
                parent[node->left] = node;
                stack.push_back(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                stack.push_back(node->right);
            }
        }
        std::unordered_set<TreeNode *> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }
        return q;
    }
};

#endif //LEETCODE_LOWESTCOMMONANCESTORBT_HPP

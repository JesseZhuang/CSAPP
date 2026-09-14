#ifndef LEETCODE_SUBTREEOFANOTHERTREE_HPP
#define LEETCODE_SUBTREEOFANOTHERTREE_HPP

#include "struct/TreeNode.hpp"
#include <string>

// LeetCode 572 - Subtree of Another Tree

// Solution 1: Recursive DFS
// Time:  O(m*n) — for each node in root, compare entire subRoot
// Space: O(m)   — recursion stack depth of root tree

class SubtreeSolution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return !subRoot;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

// Solution 2: Serialization
// Time:  O(m+n) — serialize both trees, then string find
// Space: O(m+n) — serialized strings

class SubtreeSerialSolution {
public:
    bool isSubtreeSerial(TreeNode* root, TreeNode* subRoot) {
        std::string s = serialize(root);
        std::string t = serialize(subRoot);
        return s.find(t) != std::string::npos;
    }

private:
    // Use delimiters to avoid prefix ambiguity: e.g. [12] vs [2]
    // Format: ,val(left)(right) with # for null
    void serialize(TreeNode* node, std::string& out) {
        if (!node) {
            out += ",#";
            return;
        }
        out += "," + std::to_string(node->val);
        serialize(node->left, out);
        serialize(node->right, out);
    }

    std::string serialize(TreeNode* node) {
        std::string out;
        serialize(node, out);
        return out;
    }
};

#endif //LEETCODE_SUBTREEOFANOTHERTREE_HPP

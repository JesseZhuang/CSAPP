#ifndef BTFROMPREORDERINORDER_HPP
#define BTFROMPREORDERINORDER_HPP

#include "struct/TreeNode.hpp"
#include <vector>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

// LeetCode 105 — Construct Binary Tree from Preorder and Inorder Traversal

// Recursive DFS with HashMap — O(n) time, O(n) space
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap; // val -> index in inorder
        for (int i = 0; i < (int)inorder.size(); ++i)
            inMap[inorder[i]] = i;
        int preIdx = 0;
        return build(preorder, preIdx, inMap, 0, (int)inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int& preIdx,
                    unordered_map<int, int>& inMap, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int inIdx = inMap[rootVal]; // O(1) lookup
        root->left = build(preorder, preIdx, inMap, inLeft, inIdx - 1);
        root->right = build(preorder, preIdx, inMap, inIdx + 1, inRight);
        return root;
    }
};

// Iterative with stack — O(n) time, O(n) space
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inIdx = 0;
        for (int i = 1; i < (int)preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            if (stk.top()->val != inorder[inIdx]) {
                // node is left child of stack top
                stk.top()->left = node;
            } else {
                // pop until top != inorder[inIdx], node is right child of last popped
                TreeNode* parent = nullptr;
                while (!stk.empty() && stk.top()->val == inorder[inIdx]) {
                    parent = stk.top();
                    stk.pop();
                    ++inIdx;
                }
                parent->right = node;
            }
            stk.push(node);
        }
        return root;
    }
};

#endif //BTFROMPREORDERINORDER_HPP

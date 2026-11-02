#ifndef BINARYTREEINORDERTRAVERSAL_HPP
#define BINARYTREEINORDERTRAVERSAL_HPP

#include <stack>
#include <vector>

#include "struct/TreeNode.hpp"

using namespace std;

// LeetCode 94

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> traversal;
        stack<TreeNode *> pending;
        TreeNode *current = root;

        // Each node is pushed, popped, and visited once: O(n) time.
        // The explicit stack holds at most the tree height: O(h) space.
        while (current != nullptr || !pending.empty()) {
            while (current != nullptr) {
                pending.push(current);
                current = current->left;
            }

            current = pending.top();
            pending.pop();
            traversal.push_back(current->val);
            current = current->right;
        }

        return traversal;
    }
};

#endif // BINARYTREEINORDERTRAVERSAL_HPP

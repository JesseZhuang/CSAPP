#ifndef LEETCODE_BINARYTREERIGHTSIDEVIEW_HPP
#define LEETCODE_BINARYTREERIGHTSIDEVIEW_HPP

#include <vector>
#include <deque>
#include <functional>
#include "struct/TreeNode.hpp"

using namespace std;

// LeetCode 199 - Binary Tree Right Side View

// BFS level-order traversal: take last node of each level.
// Time O(n), Space O(w) where w is max width.
class SolutionBFS {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto cur = q.front();
                q.pop_front();
                if (size == 0) res.push_back(cur->val);
                if (cur->left) q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);
            }
        }
        return res;
    }
};

// DFS preorder (root -> right -> left): first node at each new depth.
// Time O(n), Space O(h).
class SolutionDFS {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        function<void(TreeNode *, int)> dfs = [&](TreeNode *n, int depth) {
            if (!n) return;
            if (depth == (int)res.size()) res.push_back(n->val);
            dfs(n->right, depth + 1);
            dfs(n->left, depth + 1);
        };
        dfs(root, 0);
        return res;
    }
};

#endif //LEETCODE_BINARYTREERIGHTSIDEVIEW_HPP

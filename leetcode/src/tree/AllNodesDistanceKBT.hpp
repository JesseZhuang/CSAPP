#ifndef LEETCODE_ALLNODESDISTANCEKBT_HPP
#define LEETCODE_ALLNODESDISTANCEKBT_HPP

#include "struct/TreeNode.hpp"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// LeetCode 863 - All Nodes Distance K in Binary Tree
// Given a binary tree, a target node, and integer k, return values of all
// nodes at distance k from target.

class Solution {
public:
    // Approach 1: BFS with parent map
    // Time O(n), Space O(n)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Build parent pointers
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, nullptr, parent);

        // BFS from target
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            if (dist == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }
        return {};
    }

    // Approach 2: Pure DFS
    // Time O(n), Space O(n)
    vector<int> distanceKDFS(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        dfs(root, target, k, result);
        return result;
    }

private:
    void buildParent(TreeNode* node, TreeNode* par,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        parent[node] = par;
        buildParent(node->left, node, parent);
        buildParent(node->right, node, parent);
    }

    // Returns distance from node to target, or -1 if target not in subtree
    int dfs(TreeNode* node, TreeNode* target, int k, vector<int>& result) {
        if (!node) return -1;
        if (node == target) {
            collectSubtree(node, k, result);
            return 0;
        }
        int left = dfs(node->left, target, k, result);
        if (left >= 0) {
            // target is in left subtree, distance from node to target is left+1
            if (left + 1 == k) {
                result.push_back(node->val);
            } else {
                collectSubtree(node->right, k - left - 2, result);
            }
            return left + 1;
        }
        int right = dfs(node->right, target, k, result);
        if (right >= 0) {
            if (right + 1 == k) {
                result.push_back(node->val);
            } else {
                collectSubtree(node->left, k - right - 2, result);
            }
            return right + 1;
        }
        return -1;
    }

    void collectSubtree(TreeNode* node, int dist, vector<int>& result) {
        if (!node || dist < 0) return;
        if (dist == 0) {
            result.push_back(node->val);
            return;
        }
        collectSubtree(node->left, dist - 1, result);
        collectSubtree(node->right, dist - 1, result);
    }
};

#endif //LEETCODE_ALLNODESDISTANCEKBT_HPP

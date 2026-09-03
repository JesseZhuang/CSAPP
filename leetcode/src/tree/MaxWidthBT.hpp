#ifndef MAXWIDTHBT_HPP
#define MAXWIDTHBT_HPP

#include <algorithm>
#include <queue>
#include <unordered_map>

#include "struct/TreeNode.hpp"

using namespace std;

// LeetCode 662 - Maximum Width of Binary Tree

// BFS approach: level-order traversal tracking positions
class Solution662BFS {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        int maxWidth = 0;
        // queue of (node, position index) — O(n) space
        queue<pair<TreeNode *, unsigned long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();                          // nodes at current level
            unsigned long left = q.front().second;        // leftmost position
            unsigned long right = left;                   // will become rightmost
            while (size-- > 0) {
                auto [node, pos] = q.front();
                q.pop();
                right = pos;
                // Subtract left to keep positions small, avoiding overflow
                unsigned long offset = pos - left;        // O(1) normalization
                if (node->left)
                    q.push({node->left, 2 * offset});     // left child position
                if (node->right)
                    q.push({node->right, 2 * offset + 1}); // right child position
            }
            maxWidth = max(maxWidth, (int)(right - left + 1)); // O(1) width calc
        }
        return maxWidth;
    }
};

// DFS approach: track first position seen at each depth
class Solution662DFS {
public:
    int widthOfBinaryTree(TreeNode *root) {
        unordered_map<int, unsigned long> firstPos; // depth -> first position seen
        int maxWidth = 0;
        dfs(root, 0, 0, firstPos, maxWidth);
        return maxWidth;
    }

private:
    void dfs(TreeNode *node, int depth, unsigned long pos,
             unordered_map<int, unsigned long> &firstPos, int &maxWidth) {
        if (!node) return;
        if (firstPos.find(depth) == firstPos.end()) {
            firstPos[depth] = pos;                        // record first node at this depth
        }
        unsigned long width = pos - firstPos[depth] + 1;  // O(1) width at this depth
        maxWidth = max(maxWidth, (int)width);
        // Normalize position relative to first at this depth to avoid overflow
        unsigned long offset = pos - firstPos[depth];
        dfs(node->left, depth + 1, 2 * offset, firstPos, maxWidth);      // O(h) recursion depth
        dfs(node->right, depth + 1, 2 * offset + 1, firstPos, maxWidth);
    }
};

#endif //MAXWIDTHBT_HPP

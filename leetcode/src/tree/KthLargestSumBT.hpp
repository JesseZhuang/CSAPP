#ifndef KTHLARGESTSUMBT_HPP
#define KTHLARGESTSUMBT_HPP

#include <algorithm>
#include <queue>
#include <vector>
#include "struct/TreeNode.hpp"

// LeetCode 2583 - Kth Largest Sum in a Binary Tree

// BFS + sort
// Time: O(n + L log L) where n = nodes, L = levels
// Space: O(n)
class Solution {
public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        if (!root) return -1;
        std::vector<long long> sums;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            long long levelSum = 0;
            for (int i = 0; i < sz; ++i) {
                auto *node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            sums.push_back(levelSum);
        }
        if (k > (int)sums.size()) return -1;
        std::sort(sums.begin(), sums.end(), std::greater<>());
        return sums[k - 1];
    }
};

// BFS + min-heap of size k
// Time: O(n + L log k) where n = nodes, L = levels
// Space: O(n)
class Solution2 {
public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        if (!root) return -1;
        std::priority_queue<long long, std::vector<long long>, std::greater<>> minHeap;
        std::queue<TreeNode *> q;
        q.push(root);
        int levels = 0;
        while (!q.empty()) {
            int sz = q.size();
            long long levelSum = 0;
            for (int i = 0; i < sz; ++i) {
                auto *node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++levels;
            minHeap.push(levelSum);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        if (k > levels) return -1;
        return minHeap.top();
    }
};

#endif //KTHLARGESTSUMBT_HPP

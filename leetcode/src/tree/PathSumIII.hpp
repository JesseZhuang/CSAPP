#ifndef PATHSUMIII_HPP
#define PATHSUMIII_HPP

#include <unordered_map>
#include "struct/TreeNode.hpp"

// LeetCode 437 - Path Sum III
// DFS + prefix sum HashMap approach.
// Time: O(n), Space: O(n)
class Solution437 {
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long long, int> prefixCount;
        prefixCount[0] = 1; // empty prefix
        int count = 0;
        dfs(root, 0LL, static_cast<long long>(targetSum), prefixCount, count);
        return count;
    }

private:
    void dfs(TreeNode* node, long long currSum, long long target,
             std::unordered_map<long long, int>& prefixCount, int& count) {
        if (!node) return;
        currSum += node->val;
        // Check if there's a prefix whose removal yields target sum
        auto it = prefixCount.find(currSum - target);
        if (it != prefixCount.end()) {
            count += it->second;
        }
        prefixCount[currSum]++;
        dfs(node->left, currSum, target, prefixCount, count);
        dfs(node->right, currSum, target, prefixCount, count);
        prefixCount[currSum]--; // backtrack
    }
};

// LeetCode 437 - Path Sum III (Brute Force)
// Double DFS: for each node, try all downward paths starting from it.
// Time: O(n^2), Space: O(n) (recursion stack)
class Solution437_BruteForce {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        // Count paths starting from root + paths in left/right subtrees
        return countFrom(root, static_cast<long long>(targetSum)) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }

private:
    int countFrom(TreeNode* node, long long remaining) {
        if (!node) return 0;
        int count = (node->val == remaining) ? 1 : 0;
        count += countFrom(node->left, remaining - node->val);
        count += countFrom(node->right, remaining - node->val);
        return count;
    }
};

#endif //PATHSUMIII_HPP

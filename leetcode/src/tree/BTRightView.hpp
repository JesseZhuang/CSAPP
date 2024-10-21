#ifndef LEETCODE_BTRIGHTVIEW_HPP
#define LEETCODE_BTRIGHTVIEW_HPP

#include <vector>
#include <functional>
#include "struct/TreeNode.hpp"

using namespace std;

// LeetCode 199
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        function<void(TreeNode *, int)> dfs = [&](TreeNode *n, int depth) {
            if (n == nullptr) return;
            if (depth == res.size()) res.emplace_back(n->val);
            dfs(n->right, depth + 1);
            dfs(n->left, depth + 1);
        };
        dfs(root, 0);
        return res;
    }
};

#endif //LEETCODE_BTRIGHTVIEW_HPP

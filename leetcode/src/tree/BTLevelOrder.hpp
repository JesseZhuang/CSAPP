#ifndef BTLEVELORDER_HPP
#define BTLEVELORDER_HPP
#include <deque>
#include <vector>

#include "struct/TreeNode.hpp"

using namespace std;

// LeetCode 102

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == nullptr) return res;
        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty()) {
            res.emplace_back(); // appends an empty vector
            int size = q.size();
            while (size-- > 0) {
                auto cur = q.front();
                q.pop_front();
                res.back().push_back(cur->val);
                if (cur->left) q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);
            }
        }
        return res;
    }
};

#endif //BTLEVELORDER_HPP

#include "gtest/gtest.h"
#include "tree/ReverseOddLevelsBT.hpp"
#include <vector>
#include <queue>

using namespace std;

// Helper to build a perfect binary tree from level order
static TreeNode2415 *buildTree(const vector<int> &vals) {
    if (vals.empty()) return nullptr;
    TreeNode2415 *root = new TreeNode2415(vals[0]);
    queue<TreeNode2415 *> q;
    q.push(root);
    int i = 1;
    while (i < (int) vals.size()) {
        TreeNode2415 *node = q.front();
        q.pop();
        if (i < (int) vals.size()) {
            node->left = new TreeNode2415(vals[i++]);
            q.push(node->left);
        }
        if (i < (int) vals.size()) {
            node->right = new TreeNode2415(vals[i++]);
            q.push(node->right);
        }
    }
    return root;
}

// Helper to get level order traversal
static vector<int> levelOrder(TreeNode2415 *root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode2415 *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode2415 *node = q.front();
        q.pop();
        res.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return res;
}

TEST(tree, reverse_odd_levels_bt_example1) {
    Solution2415 sol;
    auto root = buildTree({2, 3, 5, 8, 13, 21, 34});
    auto result = sol.reverseOddLevels(root);
    vector<int> expected = {2, 5, 3, 8, 13, 21, 34};
    ASSERT_EQ(levelOrder(result), expected);
}

TEST(tree, reverse_odd_levels_bt_example2) {
    Solution2415 sol;
    auto root = buildTree({7, 13, 11});
    auto result = sol.reverseOddLevels(root);
    vector<int> expected = {7, 11, 13};
    ASSERT_EQ(levelOrder(result), expected);
}

TEST(tree, reverse_odd_levels_bt_example3) {
    Solution2415 sol;
    auto root = buildTree({0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2});
    auto result = sol.reverseOddLevels(root);
    vector<int> expected = {0, 2, 1, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1};
    ASSERT_EQ(levelOrder(result), expected);
}

#include "gtest/gtest.h"
#include "tree/FlattenBTToLinkedList.hpp"
#include <vector>

namespace {

// Helper: collect flattened list values (all left pointers should be null)
std::vector<int> toList(TreeNode *root) {
    std::vector<int> res;
    while (root) {
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

} // namespace

TEST(tree, flatten_bt_iterative) {
    Solution sol;

    // Example 1: [1,2,5,3,4,null,6] -> [1,2,3,4,5,6]
    auto *t1 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(5, nullptr, new TreeNode(6)));
    sol.flatten(t1);
    ASSERT_EQ((std::vector<int>{1, 2, 3, 4, 5, 6}), toList(t1));

    // Empty tree
    sol.flatten(nullptr);

    // Single node
    auto *t2 = new TreeNode(0);
    sol.flatten(t2);
    ASSERT_EQ((std::vector<int>{0}), toList(t2));

    // Left-skewed
    auto *t3 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    sol.flatten(t3);
    ASSERT_EQ((std::vector<int>{1, 2, 3}), toList(t3));

    // Right-skewed (already flat)
    auto *t4 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    sol.flatten(t4);
    ASSERT_EQ((std::vector<int>{1, 2, 3}), toList(t4));
}

TEST(tree, flatten_bt_recursive) {
    Solution2 sol;

    // Example 1: [1,2,5,3,4,null,6] -> [1,2,3,4,5,6]
    auto *t1 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(5, nullptr, new TreeNode(6)));
    sol.flatten(t1);
    ASSERT_EQ((std::vector<int>{1, 2, 3, 4, 5, 6}), toList(t1));

    // Empty tree
    sol.flatten(nullptr);

    // Single node
    auto *t2 = new TreeNode(0);
    sol.flatten(t2);
    ASSERT_EQ((std::vector<int>{0}), toList(t2));

    // Left-skewed
    auto *t3 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    sol.flatten(t3);
    ASSERT_EQ((std::vector<int>{1, 2, 3}), toList(t3));

    // Right-skewed (already flat)
    auto *t4 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    sol.flatten(t4);
    ASSERT_EQ((std::vector<int>{1, 2, 3}), toList(t4));
}

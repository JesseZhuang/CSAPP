#include "gtest/gtest.h"
#include "tree/BinaryTreeRightSideView.hpp"

TEST(tree, binary_tree_right_side_view_bfs) {
    SolutionBFS sol;

    // Example 1: [1,2,3,null,5,null,4] -> [1,3,4]
    auto *t1 = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(5)),
        new TreeNode(3, nullptr, new TreeNode(4)));
    ASSERT_EQ(vector<int>({1, 3, 4}), sol.rightSideView(t1));

    // Example 2: [1,null,3] -> [1,3]
    auto *t2 = new TreeNode(1, nullptr, new TreeNode(3));
    ASSERT_EQ(vector<int>({1, 3}), sol.rightSideView(t2));

    // Example 3: empty tree -> []
    ASSERT_EQ(vector<int>({}), sol.rightSideView(nullptr));

    // Single node
    auto *t4 = new TreeNode(42);
    ASSERT_EQ(vector<int>({42}), sol.rightSideView(t4));

    // Left-skewed tree: [1,2,null,3] -> [1,2,3]
    auto *t5 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), nullptr),
        nullptr);
    ASSERT_EQ(vector<int>({1, 2, 3}), sol.rightSideView(t5));

    // Left subtree deeper than right
    // [1,2,3,4] -> [1,3,4]
    auto *t6 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), nullptr),
        new TreeNode(3));
    ASSERT_EQ(vector<int>({1, 3, 4}), sol.rightSideView(t6));
}

TEST(tree, binary_tree_right_side_view_dfs) {
    SolutionDFS sol;

    // Example 1: [1,2,3,null,5,null,4] -> [1,3,4]
    auto *t1 = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(5)),
        new TreeNode(3, nullptr, new TreeNode(4)));
    ASSERT_EQ(vector<int>({1, 3, 4}), sol.rightSideView(t1));

    // Example 2: [1,null,3] -> [1,3]
    auto *t2 = new TreeNode(1, nullptr, new TreeNode(3));
    ASSERT_EQ(vector<int>({1, 3}), sol.rightSideView(t2));

    // Example 3: empty tree -> []
    ASSERT_EQ(vector<int>({}), sol.rightSideView(nullptr));

    // Single node
    auto *t4 = new TreeNode(42);
    ASSERT_EQ(vector<int>({42}), sol.rightSideView(t4));

    // Left-skewed tree: [1,2,null,3] -> [1,2,3]
    auto *t5 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), nullptr),
        nullptr);
    ASSERT_EQ(vector<int>({1, 2, 3}), sol.rightSideView(t5));

    // Left subtree deeper than right
    // [1,2,3,4] -> [1,3,4]
    auto *t6 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), nullptr),
        new TreeNode(3));
    ASSERT_EQ(vector<int>({1, 3, 4}), sol.rightSideView(t6));
}

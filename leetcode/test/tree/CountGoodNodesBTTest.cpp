#include <gtest/gtest.h>
#include "tree/CountGoodNodesBT.hpp"

TEST(tree, count_good_nodes_bt) {
    Solution s;

    // [3,1,4,3,null,1,5] → 4
    //       3
    //      / \
    //     1   4
    //    /   / \
    //   3   1   5
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->left->left = new TreeNode(3);
        root->right->left = new TreeNode(1);
        root->right->right = new TreeNode(5);
        EXPECT_EQ(4, s.goodNodes(root));
        EXPECT_EQ(4, s.goodNodesBfs(root));
    }

    // [3,3,null,4,2] → 3
    //     3
    //    /
    //   3
    //  / \
    // 4   2
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(2);
        EXPECT_EQ(3, s.goodNodes(root));
        EXPECT_EQ(3, s.goodNodesBfs(root));
    }

    // single node [1] → 1
    {
        auto* root = new TreeNode(1);
        EXPECT_EQ(1, s.goodNodes(root));
        EXPECT_EQ(1, s.goodNodesBfs(root));
    }

    // all same [5,5,5] → 3
    {
        auto* root = new TreeNode(5);
        root->left = new TreeNode(5);
        root->right = new TreeNode(5);
        EXPECT_EQ(3, s.goodNodes(root));
        EXPECT_EQ(3, s.goodNodesBfs(root));
    }

    // decreasing 10→5→3→1 (left chain) → 1
    {
        auto* root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->left->left = new TreeNode(3);
        root->left->left->left = new TreeNode(1);
        EXPECT_EQ(1, s.goodNodes(root));
        EXPECT_EQ(1, s.goodNodesBfs(root));
    }

    // increasing 1→2→3→4 (right chain) → 4
    {
        auto* root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(3);
        root->right->right->right = new TreeNode(4);
        EXPECT_EQ(4, s.goodNodes(root));
        EXPECT_EQ(4, s.goodNodesBfs(root));
    }

    // negative [-1,-2,-3] → 1
    //    -1
    //   /  \
    // -2   -3
    {
        auto* root = new TreeNode(-1);
        root->left = new TreeNode(-2);
        root->right = new TreeNode(-3);
        EXPECT_EQ(1, s.goodNodes(root));
        EXPECT_EQ(1, s.goodNodesBfs(root));
    }

    // negative good [-10,-5,-10] → 2 (root + left child -5 >= -10)
    //     -10
    //    /   \
    //  -5   -10
    {
        auto* root = new TreeNode(-10);
        root->left = new TreeNode(-5);
        root->right = new TreeNode(-10);
        EXPECT_EQ(3, s.goodNodes(root));
        EXPECT_EQ(3, s.goodNodesBfs(root));
    }
}

#include <gtest/gtest.h>
#include "tree/DiameterOfBinaryTree.hpp"

TEST(tree, diameter_of_binary_tree) {
    Solution s;

    // nullptr
    EXPECT_EQ(0, s.diameterOfBinaryTree(nullptr));

    // single node
    {
        auto* root = new TreeNode(1);
        EXPECT_EQ(0, s.diameterOfBinaryTree(root));
    }

    // example2: [1,2] → 1
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        EXPECT_EQ(1, s.diameterOfBinaryTree(root));
    }

    // example1: [1,2,3,4,5] → 3
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        EXPECT_EQ(3, s.diameterOfBinaryTree(root));
    }

    // linear: 1-2-3-4 → diameter 3
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->left->left = new TreeNode(4);
        EXPECT_EQ(3, s.diameterOfBinaryTree(root));
    }

    // diameter not through root → 4
    //        1
    //       /
    //      2
    //     / \
    //    3   4
    //   /     \
    //  5       6
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->left->left->left = new TreeNode(5);
        root->left->right->right = new TreeNode(6);
        EXPECT_EQ(4, s.diameterOfBinaryTree(root));
    }

    // balanced tree depth 3 → diameter 4
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        EXPECT_EQ(4, s.diameterOfBinaryTree(root));
    }
}

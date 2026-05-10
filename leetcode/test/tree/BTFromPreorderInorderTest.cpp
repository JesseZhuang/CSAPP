#include "gtest/gtest.h"
#include "tree/BTFromPreorderInorder.hpp"

TEST(tree, bt_from_preorder_inorder) {
    Solution sol;

    // Example 1: preorder={3,9,20,15,7}, inorder={9,3,15,20,7}
    {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 3);
        EXPECT_EQ(root->left->val, 9);
        EXPECT_EQ(root->left->left, nullptr);
        EXPECT_EQ(root->left->right, nullptr);
        EXPECT_EQ(root->right->val, 20);
        EXPECT_EQ(root->right->left->val, 15);
        EXPECT_EQ(root->right->right->val, 7);
    }

    // Single node
    {
        vector<int> preorder = {1};
        vector<int> inorder = {1};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 1);
        EXPECT_EQ(root->left, nullptr);
        EXPECT_EQ(root->right, nullptr);
    }

    // Left-skewed: 3 -> 2 -> 1
    {
        vector<int> preorder = {3, 2, 1};
        vector<int> inorder = {1, 2, 3};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 3);
        EXPECT_EQ(root->left->val, 2);
        EXPECT_EQ(root->left->left->val, 1);
        EXPECT_EQ(root->right, nullptr);
    }

    // Right-skewed: 1 -> 2 -> 3
    {
        vector<int> preorder = {1, 2, 3};
        vector<int> inorder = {1, 2, 3};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 1);
        EXPECT_EQ(root->left, nullptr);
        EXPECT_EQ(root->right->val, 2);
        EXPECT_EQ(root->right->right->val, 3);
    }
}

TEST(tree, bt_from_preorder_inorder_2) {
    Solution2 sol;

    // Example 1: preorder={3,9,20,15,7}, inorder={9,3,15,20,7}
    {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 3);
        EXPECT_EQ(root->left->val, 9);
        EXPECT_EQ(root->left->left, nullptr);
        EXPECT_EQ(root->left->right, nullptr);
        EXPECT_EQ(root->right->val, 20);
        EXPECT_EQ(root->right->left->val, 15);
        EXPECT_EQ(root->right->right->val, 7);
    }

    // Single node
    {
        vector<int> preorder = {1};
        vector<int> inorder = {1};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 1);
        EXPECT_EQ(root->left, nullptr);
        EXPECT_EQ(root->right, nullptr);
    }

    // Left-skewed: 3 -> 2 -> 1
    {
        vector<int> preorder = {3, 2, 1};
        vector<int> inorder = {1, 2, 3};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 3);
        EXPECT_EQ(root->left->val, 2);
        EXPECT_EQ(root->left->left->val, 1);
        EXPECT_EQ(root->right, nullptr);
    }

    // Right-skewed: 1 -> 2 -> 3
    {
        vector<int> preorder = {1, 2, 3};
        vector<int> inorder = {1, 2, 3};
        TreeNode* root = sol.buildTree(preorder, inorder);
        EXPECT_EQ(root->val, 1);
        EXPECT_EQ(root->left, nullptr);
        EXPECT_EQ(root->right->val, 2);
        EXPECT_EQ(root->right->right->val, 3);
    }
}

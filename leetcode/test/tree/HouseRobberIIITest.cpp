#include <gtest/gtest.h>
#include "tree/HouseRobberIII.hpp"

TEST(tree, house_robber_iii) {
    Solution s;

    // nullptr
    EXPECT_EQ(0, s.rob(nullptr));

    // single node [5] -> 5
    {
        auto* root = new TreeNode(5);
        EXPECT_EQ(5, s.rob(root));
    }

    // [3,2,3,null,3,null,1] -> 7
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(1);
        EXPECT_EQ(7, s.rob(root));
    }

    // [3,4,5,1,3,null,1] -> 9
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(1);
        EXPECT_EQ(9, s.rob(root));
    }

    // left skew [4,1,null,null,2] -> 6
    {
        auto* root = new TreeNode(4);
        root->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        EXPECT_EQ(6, s.rob(root));
    }
}

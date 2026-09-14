#include <gtest/gtest.h>
#include "tree/SubtreeOfAnotherTree.hpp"

TEST(tree, subtree_of_another_tree) {
    SubtreeSolution s;

    // Example 1: root=[3,4,5,1,2], subRoot=[4,1,2] → true
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);

        auto* sub = new TreeNode(4);
        sub->left = new TreeNode(1);
        sub->right = new TreeNode(2);

        EXPECT_TRUE(s.isSubtree(root, sub));
    }

    // Example 2: root=[3,4,5,1,2,null,null,null,null,0], subRoot=[4,1,2] → false
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(0);

        auto* sub = new TreeNode(4);
        sub->left = new TreeNode(1);
        sub->right = new TreeNode(2);

        EXPECT_FALSE(s.isSubtree(root, sub));
    }

    // Single node match
    {
        auto* root = new TreeNode(1);
        auto* sub = new TreeNode(1);
        EXPECT_TRUE(s.isSubtree(root, sub));
    }

    // Single node no match
    {
        auto* root = new TreeNode(1);
        auto* sub = new TreeNode(2);
        EXPECT_FALSE(s.isSubtree(root, sub));
    }

    // root == sub (identical trees)
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        auto* sub = new TreeNode(1);
        sub->left = new TreeNode(2);
        sub->right = new TreeNode(3);

        EXPECT_TRUE(s.isSubtree(root, sub));
    }

    // null root, non-null sub → false
    {
        auto* sub = new TreeNode(1);
        EXPECT_FALSE(s.isSubtree(nullptr, sub));
    }

    // Value prefix: root has [12], sub is [2] — must not match
    {
        auto* root = new TreeNode(12);
        auto* sub = new TreeNode(2);
        EXPECT_FALSE(s.isSubtree(root, sub));
    }

    // Negative values
    {
        auto* root = new TreeNode(-1);
        root->left = new TreeNode(-2);
        auto* sub = new TreeNode(-2);
        EXPECT_TRUE(s.isSubtree(root, sub));
    }

    // Deep right chain: sub is leaf at end
    {
        auto* root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(3);
        root->right->right->right = new TreeNode(4);

        auto* sub = new TreeNode(4);
        EXPECT_TRUE(s.isSubtree(root, sub));
    }
}

TEST(tree, subtree_of_another_tree_serial) {
    SubtreeSerialSolution s;

    // Example 1: true
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);

        auto* sub = new TreeNode(4);
        sub->left = new TreeNode(1);
        sub->right = new TreeNode(2);

        EXPECT_TRUE(s.isSubtreeSerial(root, sub));
    }

    // Example 2: false
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(0);

        auto* sub = new TreeNode(4);
        sub->left = new TreeNode(1);
        sub->right = new TreeNode(2);

        EXPECT_FALSE(s.isSubtreeSerial(root, sub));
    }

    // Single node match
    {
        auto* root = new TreeNode(1);
        auto* sub = new TreeNode(1);
        EXPECT_TRUE(s.isSubtreeSerial(root, sub));
    }

    // Single node no match
    {
        auto* root = new TreeNode(1);
        auto* sub = new TreeNode(2);
        EXPECT_FALSE(s.isSubtreeSerial(root, sub));
    }

    // root == sub
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        auto* sub = new TreeNode(1);
        sub->left = new TreeNode(2);
        sub->right = new TreeNode(3);

        EXPECT_TRUE(s.isSubtreeSerial(root, sub));
    }

    // null root
    {
        auto* sub = new TreeNode(1);
        EXPECT_FALSE(s.isSubtreeSerial(nullptr, sub));
    }

    // Value prefix: [12] vs [2]
    {
        auto* root = new TreeNode(12);
        auto* sub = new TreeNode(2);
        EXPECT_FALSE(s.isSubtreeSerial(root, sub));
    }

    // Negative values
    {
        auto* root = new TreeNode(-1);
        root->left = new TreeNode(-2);
        auto* sub = new TreeNode(-2);
        EXPECT_TRUE(s.isSubtreeSerial(root, sub));
    }

    // Deep right chain
    {
        auto* root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(3);
        root->right->right->right = new TreeNode(4);

        auto* sub = new TreeNode(4);
        EXPECT_TRUE(s.isSubtreeSerial(root, sub));
    }
}

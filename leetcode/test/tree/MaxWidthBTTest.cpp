#include "gtest/gtest.h"
#include "tree/MaxWidthBT.hpp"

TEST(tree, max_width_bt_bfs) {
    Solution662BFS sol;

    // [1,3,2,5,3,null,9] -> 4
    {
        TreeNode n5(5), n3b(3), n9(9);
        TreeNode n3(3, &n5, &n3b), n2(2, nullptr, &n9);
        TreeNode root(1, &n3, &n2);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 4);
    }

    // [1,3,2,5,null,null,9,6,null,7] -> 7
    // 7 is LEFT child of 9
    {
        TreeNode n6(6), n7(7);
        TreeNode n5(5, &n6, nullptr);
        TreeNode n9(9, &n7, nullptr);
        TreeNode n3(3, &n5, nullptr), n2(2, nullptr, &n9);
        TreeNode root(1, &n3, &n2);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 7);
    }

    // [1,3,2,5] -> 2
    {
        TreeNode n5(5);
        TreeNode n3(3, &n5, nullptr), n2(2);
        TreeNode root(1, &n3, &n2);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 2);
    }

    // Single node -> 1
    {
        TreeNode root(1);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 1);
    }

    // Left skewed 1->2->3 -> 1
    {
        TreeNode n3(3);
        TreeNode n2(2, &n3, nullptr);
        TreeNode root(1, &n2, nullptr);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 1);
    }

    // Complete tree [1,2,3,4,5,6,7] -> 4
    {
        TreeNode n4(4), n5(5), n6(6), n7(7);
        TreeNode n2(2, &n4, &n5), n3(3, &n6, &n7);
        TreeNode root(1, &n2, &n3);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 4);
    }

    // Wide gap [1,2,3,4,null,null,5] -> 4
    {
        TreeNode n4(4), n5(5);
        TreeNode n2(2, &n4, nullptr), n3(3, nullptr, &n5);
        TreeNode root(1, &n2, &n3);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 4);
    }
}

TEST(tree, max_width_bt_dfs) {
    Solution662DFS sol;

    // [1,3,2,5,3,null,9] -> 4
    {
        TreeNode n5(5), n3b(3), n9(9);
        TreeNode n3(3, &n5, &n3b), n2(2, nullptr, &n9);
        TreeNode root(1, &n3, &n2);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 4);
    }

    // [1,3,2,5,null,null,9,6,null,7] -> 7
    {
        TreeNode n6(6), n7(7);
        TreeNode n5(5, &n6, nullptr);
        TreeNode n9(9, &n7, nullptr);
        TreeNode n3(3, &n5, nullptr), n2(2, nullptr, &n9);
        TreeNode root(1, &n3, &n2);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 7);
    }

    // [1,3,2,5] -> 2
    {
        TreeNode n5(5);
        TreeNode n3(3, &n5, nullptr), n2(2);
        TreeNode root(1, &n3, &n2);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 2);
    }

    // Single node -> 1
    {
        TreeNode root(1);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 1);
    }

    // Left skewed 1->2->3 -> 1
    {
        TreeNode n3(3);
        TreeNode n2(2, &n3, nullptr);
        TreeNode root(1, &n2, nullptr);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 1);
    }

    // Complete tree [1,2,3,4,5,6,7] -> 4
    {
        TreeNode n4(4), n5(5), n6(6), n7(7);
        TreeNode n2(2, &n4, &n5), n3(3, &n6, &n7);
        TreeNode root(1, &n2, &n3);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 4);
    }

    // Wide gap [1,2,3,4,null,null,5] -> 4
    {
        TreeNode n4(4), n5(5);
        TreeNode n2(2, &n4, nullptr), n3(3, nullptr, &n5);
        TreeNode root(1, &n2, &n3);
        EXPECT_EQ(sol.widthOfBinaryTree(&root), 4);
    }
}

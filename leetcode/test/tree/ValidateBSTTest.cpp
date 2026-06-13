#include "gtest/gtest.h"
#include "tree/ValidateBST.hpp"
#include <climits>

TEST(tree, validate_bst) {
    ValidateBST sol;

    // [2,1,3] -> true
    {
        TreeNode n1(1), n3(3);
        TreeNode root(2, &n1, &n3);
        EXPECT_TRUE(sol.isValidBST(&root));
        EXPECT_TRUE(sol.isValidBSTInorder(&root));
    }

    // [5,1,4,null,null,3,6] -> false
    {
        TreeNode n3(3), n6(6);
        TreeNode n4(4, &n3, &n6);
        TreeNode n1(1);
        TreeNode root(5, &n1, &n4);
        EXPECT_FALSE(sol.isValidBST(&root));
        EXPECT_FALSE(sol.isValidBSTInorder(&root));
    }

    // single node -> true
    {
        TreeNode root(1);
        EXPECT_TRUE(sol.isValidBST(&root));
        EXPECT_TRUE(sol.isValidBSTInorder(&root));
    }

    // equal values [2,2,2] -> false
    {
        TreeNode l(2), r(2);
        TreeNode root(2, &l, &r);
        EXPECT_FALSE(sol.isValidBST(&root));
        EXPECT_FALSE(sol.isValidBSTInorder(&root));
    }

    // [5,4,6,null,null,3,7] -> false (3 < 5 but in right subtree)
    {
        TreeNode n3(3), n7(7);
        TreeNode n6(6, &n3, &n7);
        TreeNode n4(4);
        TreeNode root(5, &n4, &n6);
        EXPECT_FALSE(sol.isValidBST(&root));
        EXPECT_FALSE(sol.isValidBSTInorder(&root));
    }

    // INT_MAX single node -> true
    {
        TreeNode root(INT_MAX);
        EXPECT_TRUE(sol.isValidBST(&root));
        EXPECT_TRUE(sol.isValidBSTInorder(&root));
    }

    // left skewed 3->2->1 -> true
    {
        TreeNode n1(1);
        TreeNode n2(2, &n1, nullptr);
        TreeNode root(3, &n2, nullptr);
        EXPECT_TRUE(sol.isValidBST(&root));
        EXPECT_TRUE(sol.isValidBSTInorder(&root));
    }
}

#include "gtest/gtest.h"
#include "tree/BTLevelOrder.hpp"

TEST(tree, bt_level_order) {
    Solution sol;

    // [3,9,20,null,null,15,7] -> {{3},{9,20},{15,7}}
    {
        TreeNode n15(15), n7(7);
        TreeNode n9(9), n20(20, &n15, &n7);
        TreeNode root(3, &n9, &n20);
        vector<vector<int>> expected = {{3}, {9, 20}, {15, 7}};
        EXPECT_EQ(sol.levelOrder(&root), expected);
    }

    // [1] -> {{1}}
    {
        TreeNode root(1);
        vector<vector<int>> expected = {{1}};
        EXPECT_EQ(sol.levelOrder(&root), expected);
    }

    // nullptr -> {}
    {
        vector<vector<int>> expected = {};
        EXPECT_EQ(sol.levelOrder(nullptr), expected);
    }

    // Complete tree [1,2,3,4,5,6,7] -> {{1},{2,3},{4,5,6,7}}
    {
        TreeNode n4(4), n5(5), n6(6), n7(7);
        TreeNode n2(2, &n4, &n5), n3(3, &n6, &n7);
        TreeNode root(1, &n2, &n3);
        vector<vector<int>> expected = {{1}, {2, 3}, {4, 5, 6, 7}};
        EXPECT_EQ(sol.levelOrder(&root), expected);
    }
}

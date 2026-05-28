#include "gtest/gtest.h"
#include "tree/MaxPathSumBT.hpp"

TEST(tree, max_path_sum_bt) {
    Solution124 sol;

    // Example 1: [1,2,3] -> 6
    auto *t1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    ASSERT_EQ(6, sol.maxPathSum(t1));

    // Example 2: [-10,9,20,null,null,15,7] -> 42
    auto *t2 = new TreeNode(-10,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    ASSERT_EQ(42, sol.maxPathSum(t2));

    // Single node
    auto *t3 = new TreeNode(1);
    ASSERT_EQ(1, sol.maxPathSum(t3));

    // Single negative node
    auto *t4 = new TreeNode(-3);
    ASSERT_EQ(-3, sol.maxPathSum(t4));

    // All negative: pick the least negative
    auto *t5 = new TreeNode(-1, new TreeNode(-2), new TreeNode(-3));
    ASSERT_EQ(-1, sol.maxPathSum(t5));

    // Path not through root: 3-2-4 = 9
    //       1
    //      /
    //     2
    //    / \
    //   3   4
    auto *t6 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        nullptr);
    ASSERT_EQ(9, sol.maxPathSum(t6));

    // Left skewed: -2 -> 1, answer is 1
    auto *t7 = new TreeNode(-2, new TreeNode(1), nullptr);
    ASSERT_EQ(1, sol.maxPathSum(t7));

    // Boundary values
    auto *t8 = new TreeNode(1000, new TreeNode(-1000), new TreeNode(1000));
    ASSERT_EQ(2000, sol.maxPathSum(t8));
}

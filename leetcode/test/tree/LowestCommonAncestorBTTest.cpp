#include "gtest/gtest.h"
#include "tree/LowestCommonAncestorBT.hpp"

//        3
//       / \
//      5   1
//     / \ / \
//    6  2 0  8
//      / \
//     7   4

static TreeNode *buildTree(TreeNode nodes[]) {
    nodes[0] = TreeNode(3);
    nodes[1] = TreeNode(5);
    nodes[2] = TreeNode(1);
    nodes[3] = TreeNode(6);
    nodes[4] = TreeNode(2);
    nodes[5] = TreeNode(0);
    nodes[6] = TreeNode(8);
    nodes[7] = TreeNode(7);
    nodes[8] = TreeNode(4);
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];
    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];
    nodes[4].left = &nodes[7];
    nodes[4].right = &nodes[8];
    return &nodes[0];
}

TEST(tree, lowest_common_ancestor_bt) {
    SolutionLCA sol;
    TreeNode nodes[9];
    TreeNode *root = buildTree(nodes);

    // p=5, q=1, expected=3
    ASSERT_EQ(root, sol.lowestCommonAncestor(root, &nodes[1], &nodes[2]));
    // p=5, q=4, expected=5
    ASSERT_EQ(&nodes[1], sol.lowestCommonAncestor(root, &nodes[1], &nodes[8]));
    // p=6, q=4, expected=5
    ASSERT_EQ(&nodes[1], sol.lowestCommonAncestor(root, &nodes[3], &nodes[8]));
    // p=7, q=8, expected=3
    ASSERT_EQ(root, sol.lowestCommonAncestor(root, &nodes[7], &nodes[6]));
}

TEST(tree, lowest_common_ancestor_bt_iterative) {
    SolutionLCA sol;
    TreeNode nodes[9];
    TreeNode *root = buildTree(nodes);

    // p=5, q=1, expected=3
    ASSERT_EQ(root, sol.lowestCommonAncestorIterative(root, &nodes[1], &nodes[2]));
    // p=5, q=4, expected=5
    ASSERT_EQ(&nodes[1], sol.lowestCommonAncestorIterative(root, &nodes[1], &nodes[8]));
    // p=6, q=4, expected=5
    ASSERT_EQ(&nodes[1], sol.lowestCommonAncestorIterative(root, &nodes[3], &nodes[8]));
    // p=7, q=8, expected=3
    ASSERT_EQ(root, sol.lowestCommonAncestorIterative(root, &nodes[7], &nodes[6]));
}

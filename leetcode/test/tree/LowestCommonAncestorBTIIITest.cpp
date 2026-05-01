#include "gtest/gtest.h"
#include "tree/LowestCommonAncestorBTIII.hpp"

TEST(tree, lca_bt_iii) {
    SolutionLCAIII sol;
    // {4,3,7,#,#,5,6}, p=3, q=5, expected=4
    auto root = new ParentNode(4);
    auto n3 = new ParentNode(3);
    auto n7 = new ParentNode(7);
    auto n5 = new ParentNode(5);
    auto n6 = new ParentNode(6);
    root->left = n3;
    root->right = n7;
    n3->parent = root;
    n7->parent = root;
    n7->left = n5;
    n7->right = n6;
    n5->parent = n7;
    n6->parent = n7;

    ASSERT_EQ(root, sol.lowestCommonAncestor(n3, n5));
    ASSERT_EQ(n7, sol.lowestCommonAncestor(n5, n6));

    delete root;
    delete n3;
    delete n7;
    delete n5;
    delete n6;
}

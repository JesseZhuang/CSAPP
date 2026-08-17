#include <gtest/gtest.h>
#include "tree/AmountOfTimeInfected.hpp"

TEST(tree, amount_of_time_infected_example) {
    // Tree: root=1, left=5(left=4(left=9,right=2)), right=3(left=10,right=6)
    auto* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(9);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    Solution s;
    EXPECT_EQ(s.amountOfTime(root, 3), 4);

    Solution2 s2;
    EXPECT_EQ(s2.amountOfTime(root, 3), 4);
}

TEST(tree, amount_of_time_infected_single) {
    auto* root = new TreeNode(1);

    Solution s;
    EXPECT_EQ(s.amountOfTime(root, 1), 0);

    Solution2 s2;
    EXPECT_EQ(s2.amountOfTime(root, 1), 0);
}

TEST(tree, amount_of_time_infected_start_at_root) {
    // 1->2,3; 2->4
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution s;
    EXPECT_EQ(s.amountOfTime(root, 1), 2);

    Solution2 s2;
    EXPECT_EQ(s2.amountOfTime(root, 1), 2);
}

TEST(tree, amount_of_time_infected_start_at_leaf) {
    // 1->2,3; 2->4,5
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    EXPECT_EQ(s.amountOfTime(root, 4), 3);

    Solution2 s2;
    EXPECT_EQ(s2.amountOfTime(root, 4), 3);
}

TEST(tree, amount_of_time_infected_linear) {
    // 1->2->3->4 all left children
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);

    Solution s;
    EXPECT_EQ(s.amountOfTime(root, 2), 2);

    Solution2 s2;
    EXPECT_EQ(s2.amountOfTime(root, 2), 2);
}

TEST(tree, amount_of_time_infected_deep_right) {
    // 1->2,3; 3->null,4; 4->null,5
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);

    Solution s;
    EXPECT_EQ(s.amountOfTime(root, 1), 3);

    Solution2 s2;
    EXPECT_EQ(s2.amountOfTime(root, 1), 3);
}

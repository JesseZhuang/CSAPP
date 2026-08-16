#include <gtest/gtest.h>
#include <algorithm>
#include "tree/AllNodesDistanceKBT.hpp"

TEST(tree, all_nodes_distance_k_bt) {
    Solution s;

    // Example 1: [3,5,1,6,2,0,8,null,null,7,4], target=5, k=2 -> [7,4,1]
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);

        TreeNode* target = root->left; // node 5
        auto result = s.distanceK(root, target, 2);
        std::sort(result.begin(), result.end());
        EXPECT_EQ(result, (vector<int>{1, 4, 7}));
    }

    // Example 2: single node, k=0 -> [1]
    {
        auto* root = new TreeNode(1);
        auto result = s.distanceK(root, root, 0);
        EXPECT_EQ(result, (vector<int>{1}));
    }

    // k larger than tree depth -> empty
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        auto result = s.distanceK(root, root, 5);
        EXPECT_TRUE(result.empty());
    }

    // Target is root, k=1
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        auto result = s.distanceK(root, root, 1);
        std::sort(result.begin(), result.end());
        EXPECT_EQ(result, (vector<int>{2, 3}));
    }

    // Target is leaf, k=1 -> parent
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        TreeNode* target = root->left; // node 2
        auto result = s.distanceK(root, target, 1);
        EXPECT_EQ(result, (vector<int>{1}));
    }
}

TEST(tree, all_nodes_distance_k_bt_dfs) {
    Solution s;

    // Example 1: [3,5,1,6,2,0,8,null,null,7,4], target=5, k=2 -> [7,4,1]
    {
        auto* root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);

        TreeNode* target = root->left; // node 5
        auto result = s.distanceKDFS(root, target, 2);
        std::sort(result.begin(), result.end());
        EXPECT_EQ(result, (vector<int>{1, 4, 7}));
    }

    // Single node, k=0
    {
        auto* root = new TreeNode(1);
        auto result = s.distanceKDFS(root, root, 0);
        EXPECT_EQ(result, (vector<int>{1}));
    }

    // k larger than tree depth -> empty
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        auto result = s.distanceKDFS(root, root, 5);
        EXPECT_TRUE(result.empty());
    }

    // Target is root, k=1
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        auto result = s.distanceKDFS(root, root, 1);
        std::sort(result.begin(), result.end());
        EXPECT_EQ(result, (vector<int>{2, 3}));
    }

    // Target is leaf, k goes up to parent then across
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        TreeNode* target = root->left; // node 2
        auto result = s.distanceKDFS(root, target, 2);
        std::sort(result.begin(), result.end());
        EXPECT_EQ(result, (vector<int>{3}));
    }
}

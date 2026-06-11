#include <gtest/gtest.h>
#include "../src/tree/SerializeBT.hpp"
#include "../src/struct/TreeNode.hpp"

namespace {

bool treesEqual(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val &&
           treesEqual(a->left, b->left) &&
           treesEqual(a->right, b->right);
}

// [1,2,3,null,null,4,5]
TreeNode* buildExample() {
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    return root;
}

// left-skewed: 1->2->3
TreeNode* buildLeftSkewed() {
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    return root;
}

// right-skewed: 1->2->3
TreeNode* buildRightSkewed() {
    auto* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    return root;
}

// negative values
TreeNode* buildNegative() {
    auto* root = new TreeNode(-1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    return root;
}

} // namespace

TEST(tree, serialize_bt_dfs) {
    SerializeBT sol;

    // Example tree [1,2,3,null,null,4,5]
    {
        TreeNode* root = buildExample();
        std::string s = sol.serialize_dfs(root);
        TreeNode* res = sol.deserialize_dfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Empty tree
    {
        std::string s = sol.serialize_dfs(nullptr);
        TreeNode* res = sol.deserialize_dfs(s);
        EXPECT_EQ(res, nullptr);
    }

    // Single node
    {
        TreeNode* root = new TreeNode(42);
        std::string s = sol.serialize_dfs(root);
        TreeNode* res = sol.deserialize_dfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Left-skewed
    {
        TreeNode* root = buildLeftSkewed();
        std::string s = sol.serialize_dfs(root);
        TreeNode* res = sol.deserialize_dfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Right-skewed
    {
        TreeNode* root = buildRightSkewed();
        std::string s = sol.serialize_dfs(root);
        TreeNode* res = sol.deserialize_dfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Negative values
    {
        TreeNode* root = buildNegative();
        std::string s = sol.serialize_dfs(root);
        TreeNode* res = sol.deserialize_dfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }
}

TEST(tree, serialize_bt_bfs) {
    SerializeBT sol;

    // Example tree [1,2,3,null,null,4,5]
    {
        TreeNode* root = buildExample();
        std::string s = sol.serialize_bfs(root);
        TreeNode* res = sol.deserialize_bfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Empty tree
    {
        std::string s = sol.serialize_bfs(nullptr);
        TreeNode* res = sol.deserialize_bfs(s);
        EXPECT_EQ(res, nullptr);
    }

    // Single node
    {
        TreeNode* root = new TreeNode(42);
        std::string s = sol.serialize_bfs(root);
        TreeNode* res = sol.deserialize_bfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Left-skewed
    {
        TreeNode* root = buildLeftSkewed();
        std::string s = sol.serialize_bfs(root);
        TreeNode* res = sol.deserialize_bfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Right-skewed
    {
        TreeNode* root = buildRightSkewed();
        std::string s = sol.serialize_bfs(root);
        TreeNode* res = sol.deserialize_bfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }

    // Negative values
    {
        TreeNode* root = buildNegative();
        std::string s = sol.serialize_bfs(root);
        TreeNode* res = sol.deserialize_bfs(s);
        EXPECT_TRUE(treesEqual(root, res));
    }
}

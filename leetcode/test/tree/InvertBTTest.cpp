#include <gtest/gtest.h>
#include "tree/InvertBT.hpp"

TEST(tree, invert_bt) {
    InvertBT s;

    // helper: compare two trees for structural + value equality
    std::function<bool(TreeNode*, TreeNode*)> treesEqual =
        [&](TreeNode* a, TreeNode* b) -> bool {
            if (!a && !b) return true;
            if (!a || !b) return false;
            return a->val == b->val
                && treesEqual(a->left, b->left)
                && treesEqual(a->right, b->right);
        };

    // helper: deep-copy a tree so we can test both methods independently
    std::function<TreeNode*(TreeNode*)> copyTree =
        [&](TreeNode* node) -> TreeNode* {
            if (!node) return nullptr;
            auto* copy = new TreeNode(node->val);
            copy->left = copyTree(node->left);
            copy->right = copyTree(node->right);
            return copy;
        };

    // 1. [4,2,7,1,3,6,9] → [4,7,2,9,6,3,1]
    {
        auto* root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(7);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(9);

        auto* expected = new TreeNode(4);
        expected->left = new TreeNode(7);
        expected->right = new TreeNode(2);
        expected->left->left = new TreeNode(9);
        expected->left->right = new TreeNode(6);
        expected->right->left = new TreeNode(3);
        expected->right->right = new TreeNode(1);

        auto* rootCopy = copyTree(root);
        EXPECT_TRUE(treesEqual(expected, s.invertTree(root)));
        EXPECT_TRUE(treesEqual(expected, s.invertTreeBFS(rootCopy)));
    }

    // 2. [2,1,3] → [2,3,1]
    {
        auto* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);

        auto* expected = new TreeNode(2);
        expected->left = new TreeNode(3);
        expected->right = new TreeNode(1);

        auto* rootCopy = copyTree(root);
        EXPECT_TRUE(treesEqual(expected, s.invertTree(root)));
        EXPECT_TRUE(treesEqual(expected, s.invertTreeBFS(rootCopy)));
    }

    // 3. nullptr → nullptr
    {
        EXPECT_EQ(nullptr, s.invertTree(nullptr));
        EXPECT_EQ(nullptr, s.invertTreeBFS(nullptr));
    }

    // 4. Single node
    {
        auto* root = new TreeNode(42);
        auto* rootCopy = copyTree(root);
        auto* result1 = s.invertTree(root);
        auto* result2 = s.invertTreeBFS(rootCopy);
        EXPECT_EQ(42, result1->val);
        EXPECT_EQ(nullptr, result1->left);
        EXPECT_EQ(nullptr, result1->right);
        EXPECT_EQ(42, result2->val);
        EXPECT_EQ(nullptr, result2->left);
        EXPECT_EQ(nullptr, result2->right);
    }

    // 5. Left-only chain: 1→2→3 becomes right-only chain
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);

        auto* expected = new TreeNode(1);
        expected->right = new TreeNode(2);
        expected->right->right = new TreeNode(3);

        auto* rootCopy = copyTree(root);
        EXPECT_TRUE(treesEqual(expected, s.invertTree(root)));
        EXPECT_TRUE(treesEqual(expected, s.invertTreeBFS(rootCopy)));
    }

    // 6. Asymmetric tree
    //        1
    //       / \
    //      2   3
    //     /     \
    //    4       5
    // Expected:
    //        1
    //       / \
    //      3   2
    //     /     \
    //    5       4
    {
        auto* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->right->right = new TreeNode(5);

        auto* expected = new TreeNode(1);
        expected->left = new TreeNode(3);
        expected->right = new TreeNode(2);
        expected->left->left = new TreeNode(5);
        expected->right->right = new TreeNode(4);

        auto* rootCopy = copyTree(root);
        EXPECT_TRUE(treesEqual(expected, s.invertTree(root)));
        EXPECT_TRUE(treesEqual(expected, s.invertTreeBFS(rootCopy)));
    }
}

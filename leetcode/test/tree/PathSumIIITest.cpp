#include <gtest/gtest.h>
#include "tree/PathSumIII.hpp"

namespace {

// Helper to build trees from level-order with nullopt for null nodes
TreeNode* buildTree(const std::vector<std::optional<int>>& vals) {
    if (vals.empty() || !vals[0].has_value()) return nullptr;
    std::vector<TreeNode*> nodes;
    nodes.push_back(new TreeNode(vals[0].value()));
    size_t i = 1;
    for (size_t parent = 0; parent < nodes.size() && i < vals.size(); parent++) {
        if (nodes[parent] == nullptr) continue;
        // left child
        if (i < vals.size()) {
            if (vals[i].has_value()) {
                nodes[parent]->left = new TreeNode(vals[i].value());
                nodes.push_back(nodes[parent]->left);
            } else {
                nodes.push_back(nullptr);
            }
            i++;
        }
        // right child
        if (i < vals.size()) {
            if (vals[i].has_value()) {
                nodes[parent]->right = new TreeNode(vals[i].value());
                nodes.push_back(nodes[parent]->right);
            } else {
                nodes.push_back(nullptr);
            }
            i++;
        }
    }
    return nodes[0];
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

using O = std::optional<int>;

} // namespace

TEST(tree, path_sum_iii) {
    Solution437 sol;

    // Example 1: [10,5,-3,3,2,null,11,3,-2,null,1] target=8 → 3
    {
        auto root = buildTree({O(10), O(5), O(-3), O(3), O(2), std::nullopt, O(11),
                               O(3), O(-2), std::nullopt, O(1)});
        EXPECT_EQ(sol.pathSum(root, 8), 3);
        deleteTree(root);
    }

    // Example 2: [5,4,8,11,null,13,4,7,2,null,null,5,1] target=22 → 3
    {
        auto root = buildTree({O(5), O(4), O(8), O(11), std::nullopt, O(13), O(4),
                               O(7), O(2), std::nullopt, std::nullopt, O(5), O(1)});
        EXPECT_EQ(sol.pathSum(root, 22), 3);
        deleteTree(root);
    }

    // Empty tree → 0
    EXPECT_EQ(sol.pathSum(nullptr, 0), 0);

    // Single node match
    {
        TreeNode node(5);
        EXPECT_EQ(sol.pathSum(&node, 5), 1);
    }

    // Single node no match
    {
        TreeNode node(5);
        EXPECT_EQ(sol.pathSum(&node, 3), 0);
    }

    // Negative values: [-2, null, -3] target=-5 → 1
    {
        auto root = buildTree({O(-2), std::nullopt, O(-3)});
        EXPECT_EQ(sol.pathSum(root, -5), 1);
        deleteTree(root);
    }

    // Multiple paths: [1,1,1] target=2 → 2 (root->left, root->right)
    {
        auto root = buildTree({O(1), O(1), O(1)});
        EXPECT_EQ(sol.pathSum(root, 2), 2);
        deleteTree(root);
    }

    // Zero target all zeros: [0,0,0] target=0 → 5
    // Paths: 3 single nodes + 2 two-node paths (root->left, root->right)
    {
        auto root = buildTree({O(0), O(0), O(0)});
        EXPECT_EQ(sol.pathSum(root, 0), 5);
        deleteTree(root);
    }
}

TEST(tree, path_sum_iii_brute) {
    Solution437_BruteForce sol;

    // Example 1
    {
        auto root = buildTree({O(10), O(5), O(-3), O(3), O(2), std::nullopt, O(11),
                               O(3), O(-2), std::nullopt, O(1)});
        EXPECT_EQ(sol.pathSum(root, 8), 3);
        deleteTree(root);
    }

    // Example 2
    {
        auto root = buildTree({O(5), O(4), O(8), O(11), std::nullopt, O(13), O(4),
                               O(7), O(2), std::nullopt, std::nullopt, O(5), O(1)});
        EXPECT_EQ(sol.pathSum(root, 22), 3);
        deleteTree(root);
    }

    // Empty tree
    EXPECT_EQ(sol.pathSum(nullptr, 0), 0);

    // Single node match
    {
        TreeNode node(5);
        EXPECT_EQ(sol.pathSum(&node, 5), 1);
    }

    // Single node no match
    {
        TreeNode node(5);
        EXPECT_EQ(sol.pathSum(&node, 3), 0);
    }

    // Negative values
    {
        auto root = buildTree({O(-2), std::nullopt, O(-3)});
        EXPECT_EQ(sol.pathSum(root, -5), 1);
        deleteTree(root);
    }

    // Multiple paths
    {
        auto root = buildTree({O(1), O(1), O(1)});
        EXPECT_EQ(sol.pathSum(root, 2), 2);
        deleteTree(root);
    }

    // Zero target all zeros
    {
        auto root = buildTree({O(0), O(0), O(0)});
        EXPECT_EQ(sol.pathSum(root, 0), 5);
        deleteTree(root);
    }
}

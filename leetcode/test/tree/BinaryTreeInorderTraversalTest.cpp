#include "gtest/gtest.h"
#include "tree/BinaryTreeInorderTraversal.hpp"

TEST(tree, binary_tree_inorder_traversal) {
    Solution solution;

    // Empty tree.
    EXPECT_EQ(solution.inorderTraversal(nullptr), std::vector<int>({}));

    // Singleton tree.
    TreeNode singleton(1);
    EXPECT_EQ(solution.inorderTraversal(&singleton), std::vector<int>({1}));

    // Balanced tree: [4, 2, 6, 1, 3, 5, 7] -> [1, 2, 3, 4, 5, 6, 7].
    TreeNode n1(1), n3(3), n5(5), n7(7);
    TreeNode n2(2, &n1, &n3), n6(6, &n5, &n7);
    TreeNode balanced_root(4, &n2, &n6);
    EXPECT_EQ(solution.inorderTraversal(&balanced_root),
              std::vector<int>({1, 2, 3, 4, 5, 6, 7}));

    // Unbalanced tree: [1, null, 2, 3] -> [1, 3, 2].
    TreeNode n3_unbalanced(3);
    TreeNode n2_unbalanced(2, &n3_unbalanced, nullptr);
    TreeNode unbalanced_root(1, nullptr, &n2_unbalanced);
    EXPECT_EQ(solution.inorderTraversal(&unbalanced_root), std::vector<int>({1, 3, 2}));
}

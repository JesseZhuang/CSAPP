#include "gtest/gtest.h"
#include "tree/KthSmallestBST.hpp"

TEST(tree, kth_smallest_bst) {
    Solution sol;

    // [3,1,4,null,2] k=1 -> 1
    auto *t1 = new TreeNode(3,
        new TreeNode(1, nullptr, new TreeNode(2)),
        new TreeNode(4));
    ASSERT_EQ(1, sol.kthSmallest(t1, 1));

    // [5,3,6,2,4,null,null,1] k=3 -> 3
    auto *t2 = new TreeNode(5,
        new TreeNode(3,
            new TreeNode(2, new TreeNode(1), nullptr),
            new TreeNode(4)),
        new TreeNode(6));
    ASSERT_EQ(3, sol.kthSmallest(t2, 3));

    // single node k=1
    auto *t3 = new TreeNode(42);
    ASSERT_EQ(42, sol.kthSmallest(t3, 1));
}

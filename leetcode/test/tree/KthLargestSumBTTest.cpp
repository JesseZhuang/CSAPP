#include "gtest/gtest.h"
#include "tree/KthLargestSumBT.hpp"

TEST(tree, kth_largest_sum_bt) {
    Solution sol;

    // Example 1: [5,8,9,2,1,3,7,4] k=2 -> 13
    // Level 0: 5, Level 1: 8+9=17, Level 2: 2+1+3+7=13, Level 3: 4
    auto *t1 = new TreeNode(5,
        new TreeNode(8,
            new TreeNode(2, new TreeNode(4), nullptr),
            new TreeNode(1)),
        new TreeNode(9,
            new TreeNode(3),
            new TreeNode(7)));
    ASSERT_EQ(13, sol.kthLargestLevelSum(t1, 2));

    // Example 2: [1,2,null,3] k=1 -> 3
    auto *t2 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), nullptr),
        nullptr);
    ASSERT_EQ(3, sol.kthLargestLevelSum(t2, 1));

    // k exceeds depth -> -1
    auto *t3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    ASSERT_EQ(-1, sol.kthLargestLevelSum(t3, 5));

    // Single node
    auto *t4 = new TreeNode(42);
    ASSERT_EQ(42, sol.kthLargestLevelSum(t4, 1));

    // Negative values
    auto *t5 = new TreeNode(-1,
        new TreeNode(-2),
        new TreeNode(-3));
    // Level 0: -1, Level 1: -5. k=1 -> -1
    ASSERT_EQ(-1, sol.kthLargestLevelSum(t5, 1));
    ASSERT_EQ(-5, sol.kthLargestLevelSum(t5, 2));
}

TEST(tree, kth_largest_sum_bt_heap) {
    Solution2 sol;

    // Example 1: [5,8,9,2,1,3,7,4] k=2 -> 13
    auto *t1 = new TreeNode(5,
        new TreeNode(8,
            new TreeNode(2, new TreeNode(4), nullptr),
            new TreeNode(1)),
        new TreeNode(9,
            new TreeNode(3),
            new TreeNode(7)));
    ASSERT_EQ(13, sol.kthLargestLevelSum(t1, 2));

    // Example 2: [1,2,null,3] k=1 -> 3
    auto *t2 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), nullptr),
        nullptr);
    ASSERT_EQ(3, sol.kthLargestLevelSum(t2, 1));

    // k exceeds depth -> -1
    auto *t3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    ASSERT_EQ(-1, sol.kthLargestLevelSum(t3, 5));

    // Single node
    auto *t4 = new TreeNode(42);
    ASSERT_EQ(42, sol.kthLargestLevelSum(t4, 1));

    // Negative values
    auto *t5 = new TreeNode(-1,
        new TreeNode(-2),
        new TreeNode(-3));
    ASSERT_EQ(-1, sol.kthLargestLevelSum(t5, 1));
    ASSERT_EQ(-5, sol.kthLargestLevelSum(t5, 2));
}

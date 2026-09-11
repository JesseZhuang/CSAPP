#include "gtest/gtest.h"
#include "dp/UniqueBST.hpp"

TEST(dp, unique_bst_dp) {
    UniqueBSTDP sol;
    ASSERT_EQ(1, sol.numTrees(0));
    ASSERT_EQ(1, sol.numTrees(1));
    ASSERT_EQ(2, sol.numTrees(2));
    ASSERT_EQ(5, sol.numTrees(3));
    ASSERT_EQ(14, sol.numTrees(4));
    ASSERT_EQ(42, sol.numTrees(5));
    ASSERT_EQ(1767263190, sol.numTrees(19));
}

TEST(dp, unique_bst_catalan) {
    UniqueBSTCatalan sol;
    ASSERT_EQ(1, sol.numTrees(0));
    ASSERT_EQ(1, sol.numTrees(1));
    ASSERT_EQ(2, sol.numTrees(2));
    ASSERT_EQ(5, sol.numTrees(3));
    ASSERT_EQ(14, sol.numTrees(4));
    ASSERT_EQ(42, sol.numTrees(5));
    ASSERT_EQ(1767263190, sol.numTrees(19));
}

#include "gtest/gtest.h"
#include "array/MinIncrementUnique.hpp"

TEST(array, min_increment_unique) {
    MinIncrementUnique sol;

    // Example 1: [1,2,2] -> [1,2,3], moves = 1
    vector<int> t1 = {1, 2, 2};
    EXPECT_EQ(1, sol.minIncrementForUnique(t1));

    // Example 2: [3,2,1,2,1,7] -> [1,2,3,4,5,7], moves = 6
    vector<int> t2 = {3, 2, 1, 2, 1, 7};
    EXPECT_EQ(6, sol.minIncrementForUnique(t2));

    // Single element
    vector<int> t3 = {5};
    EXPECT_EQ(0, sol.minIncrementForUnique(t3));

    // Already unique
    vector<int> t4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(0, sol.minIncrementForUnique(t4));

    // All same
    vector<int> t5 = {0, 0, 0, 0};
    EXPECT_EQ(6, sol.minIncrementForUnique(t5)); // 0+1+2+3 = 6

    // Two elements equal
    vector<int> t6 = {2, 2};
    EXPECT_EQ(1, sol.minIncrementForUnique(t6));

    // Larger gap already
    vector<int> t7 = {1, 1, 1, 1, 1};
    EXPECT_EQ(10, sol.minIncrementForUnique(t7)); // 0+1+2+3+4 = 10

    // Zeros
    vector<int> t8 = {0};
    EXPECT_EQ(0, sol.minIncrementForUnique(t8));

    // Reverse sorted with dups
    vector<int> t9 = {5, 5, 3, 3, 1};
    EXPECT_EQ(2, sol.minIncrementForUnique(t9)); // sorted [1,3,3,5,5]->[1,3,4,5,6] cost=1+1=2
}

TEST(array, min_increment_unique2) {
    MinIncrementUnique sol;

    vector<int> t1 = {1, 2, 2};
    EXPECT_EQ(1, sol.minIncrementForUnique2(t1));

    vector<int> t2 = {3, 2, 1, 2, 1, 7};
    EXPECT_EQ(6, sol.minIncrementForUnique2(t2));

    vector<int> t3 = {5};
    EXPECT_EQ(0, sol.minIncrementForUnique2(t3));

    vector<int> t4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(0, sol.minIncrementForUnique2(t4));

    vector<int> t5 = {0, 0, 0, 0};
    EXPECT_EQ(6, sol.minIncrementForUnique2(t5));

    vector<int> t6 = {2, 2};
    EXPECT_EQ(1, sol.minIncrementForUnique2(t6));

    vector<int> t7 = {1, 1, 1, 1, 1};
    EXPECT_EQ(10, sol.minIncrementForUnique2(t7));

    vector<int> t8 = {0};
    EXPECT_EQ(0, sol.minIncrementForUnique2(t8));

    vector<int> t9 = {5, 5, 3, 3, 1};
    EXPECT_EQ(2, sol.minIncrementForUnique2(t9));
}

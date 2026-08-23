#include "gtest/gtest.h"
#include "dp/DeleteAndEarn.hpp"

TEST(dp, delete_and_earn) {
    DeleteAndEarn sol;
    vector<int> n1 = {3, 4, 2};
    ASSERT_EQ(6, sol.deleteAndEarn(n1));
    vector<int> n2 = {2, 2, 3, 3, 3, 4};
    ASSERT_EQ(9, sol.deleteAndEarn(n2));
    vector<int> n3 = {1};
    ASSERT_EQ(1, sol.deleteAndEarn(n3));
    vector<int> n4 = {3, 3, 3};
    ASSERT_EQ(9, sol.deleteAndEarn(n4));
    vector<int> n5 = {1, 1, 1, 5, 5, 5};
    ASSERT_EQ(18, sol.deleteAndEarn(n5));
    vector<int> n6 = {1, 2};
    ASSERT_EQ(2, sol.deleteAndEarn(n6));
    vector<int> n7 = {1, 2, 3, 4};
    ASSERT_EQ(6, sol.deleteAndEarn(n7));
    vector<int> n8 = {3, 3, 3, 4};
    ASSERT_EQ(9, sol.deleteAndEarn(n8));
    vector<int> n9 = {10000};
    ASSERT_EQ(10000, sol.deleteAndEarn(n9));
    vector<int> n10 = {1, 1, 1, 1, 2, 3, 3, 3, 3};
    ASSERT_EQ(16, sol.deleteAndEarn(n10));
}

TEST(dp, delete_and_earn_sort) {
    DeleteAndEarnSort sol;
    vector<int> n1 = {3, 4, 2};
    ASSERT_EQ(6, sol.deleteAndEarn(n1));
    vector<int> n2 = {2, 2, 3, 3, 3, 4};
    ASSERT_EQ(9, sol.deleteAndEarn(n2));
    vector<int> n3 = {1};
    ASSERT_EQ(1, sol.deleteAndEarn(n3));
    vector<int> n4 = {3, 3, 3};
    ASSERT_EQ(9, sol.deleteAndEarn(n4));
    vector<int> n5 = {1, 1, 1, 5, 5, 5};
    ASSERT_EQ(18, sol.deleteAndEarn(n5));
    vector<int> n6 = {1, 2};
    ASSERT_EQ(2, sol.deleteAndEarn(n6));
    vector<int> n7 = {1, 2, 3, 4};
    ASSERT_EQ(6, sol.deleteAndEarn(n7));
    vector<int> n8 = {3, 3, 3, 4};
    ASSERT_EQ(9, sol.deleteAndEarn(n8));
    vector<int> n9 = {10000};
    ASSERT_EQ(10000, sol.deleteAndEarn(n9));
    vector<int> n10 = {1, 1, 1, 1, 2, 3, 3, 3, 3};
    ASSERT_EQ(16, sol.deleteAndEarn(n10));
}

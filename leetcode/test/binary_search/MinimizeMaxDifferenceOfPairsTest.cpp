#include <gtest/gtest.h>
#include "binary_search/MinimizeMaxDifferenceOfPairs.hpp"

TEST(binary_search, minimize_max_difference_of_pairs) {
    Solution s;

    vector<int> v1 = {10, 1, 2, 7, 1, 3};
    EXPECT_EQ(1, s.minimizeMax(v1, 2));

    vector<int> v2 = {4, 2, 1, 2};
    EXPECT_EQ(0, s.minimizeMax(v2, 1));

    vector<int> v3 = {5, 3, 1};
    EXPECT_EQ(0, s.minimizeMax(v3, 0));

    vector<int> v4 = {1, 5};
    EXPECT_EQ(4, s.minimizeMax(v4, 1));

    vector<int> v5 = {3, 3, 3, 3};
    EXPECT_EQ(0, s.minimizeMax(v5, 2));

    vector<int> v6 = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(1, s.minimizeMax(v6, 3));

    vector<int> v7 = {0, 0};
    EXPECT_EQ(0, s.minimizeMax(v7, 1));
}

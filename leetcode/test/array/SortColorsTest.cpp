#include "gtest/gtest.h"
#include "array/SortColors.hpp"

TEST(array, sort_colors) {
    SortColors sol;

    // Example 1
    vector<int> v1 = {2,0,2,1,1,0};
    sol.sortColors(v1);
    EXPECT_EQ(vector<int>({0,0,1,1,2,2}), v1);

    // Example 2
    vector<int> v2 = {2,0,1};
    sol.sortColors(v2);
    EXPECT_EQ(vector<int>({0,1,2}), v2);

    // Single element
    vector<int> v3 = {0};
    sol.sortColors(v3);
    EXPECT_EQ(vector<int>({0}), v3);

    // All same
    vector<int> v4 = {1,1,1};
    sol.sortColors(v4);
    EXPECT_EQ(vector<int>({1,1,1}), v4);

    // Already sorted
    vector<int> v5 = {0,0,1,1,2,2};
    sol.sortColors(v5);
    EXPECT_EQ(vector<int>({0,0,1,1,2,2}), v5);

    // Reverse sorted
    vector<int> v6 = {2,2,1,1,0,0};
    sol.sortColors(v6);
    EXPECT_EQ(vector<int>({0,0,1,1,2,2}), v6);

    // Two elements
    vector<int> v7 = {1,0};
    sol.sortColors(v7);
    EXPECT_EQ(vector<int>({0,1}), v7);

    // Missing colors (only 0s and 2s)
    vector<int> v8 = {2,0,2,0};
    sol.sortColors(v8);
    EXPECT_EQ(vector<int>({0,0,2,2}), v8);
}

TEST(array, sort_colors_counting) {
    SortColors sol;

    vector<int> v1 = {2,0,2,1,1,0};
    sol.sortColors2(v1);
    EXPECT_EQ(vector<int>({0,0,1,1,2,2}), v1);

    vector<int> v2 = {2,0,1};
    sol.sortColors2(v2);
    EXPECT_EQ(vector<int>({0,1,2}), v2);

    vector<int> v3 = {0};
    sol.sortColors2(v3);
    EXPECT_EQ(vector<int>({0}), v3);

    vector<int> v4 = {1,1,1};
    sol.sortColors2(v4);
    EXPECT_EQ(vector<int>({1,1,1}), v4);

    vector<int> v5 = {0,0,1,1,2,2};
    sol.sortColors2(v5);
    EXPECT_EQ(vector<int>({0,0,1,1,2,2}), v5);

    vector<int> v6 = {2,2,1,1,0,0};
    sol.sortColors2(v6);
    EXPECT_EQ(vector<int>({0,0,1,1,2,2}), v6);

    vector<int> v7 = {1,0};
    sol.sortColors2(v7);
    EXPECT_EQ(vector<int>({0,1}), v7);

    vector<int> v8 = {2,0,2,0};
    sol.sortColors2(v8);
    EXPECT_EQ(vector<int>({0,0,2,2}), v8);
}

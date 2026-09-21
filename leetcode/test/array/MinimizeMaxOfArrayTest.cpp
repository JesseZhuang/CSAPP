#include "gtest/gtest.h"
#include "array/MinimizeMaxOfArray.hpp"

TEST(array, minimize_max_of_array) {
    Solution s;
    vector<int> v1 = {3, 7, 1, 6};
    EXPECT_EQ(5, s.minimizeArrayValue(v1));
    vector<int> v2 = {10, 1};
    EXPECT_EQ(10, s.minimizeArrayValue(v2));
    vector<int> v3 = {5};
    EXPECT_EQ(5, s.minimizeArrayValue(v3));
    vector<int> v4 = {4, 4, 4, 4};
    EXPECT_EQ(4, s.minimizeArrayValue(v4));
    vector<int> v5 = {10, 5, 1};
    EXPECT_EQ(10, s.minimizeArrayValue(v5));
    vector<int> v6 = {1, 5, 10};
    EXPECT_EQ(6, s.minimizeArrayValue(v6));
    vector<int> v7 = {0, 0, 0};
    EXPECT_EQ(0, s.minimizeArrayValue(v7));
    vector<int> v8 = {0, 0, 0, 0, 100};
    EXPECT_EQ(20, s.minimizeArrayValue(v8));
    vector<int> v9 = {1, 9};
    EXPECT_EQ(5, s.minimizeArrayValue(v9));
    vector<int> v10 = {1, 10};
    EXPECT_EQ(6, s.minimizeArrayValue(v10));
}

TEST(array, minimize_max_of_array_bs) {
    Solution2 s;
    vector<int> v1 = {3, 7, 1, 6};
    EXPECT_EQ(5, s.minimizeArrayValue(v1));
    vector<int> v2 = {10, 1};
    EXPECT_EQ(10, s.minimizeArrayValue(v2));
    vector<int> v3 = {5};
    EXPECT_EQ(5, s.minimizeArrayValue(v3));
    vector<int> v4 = {4, 4, 4, 4};
    EXPECT_EQ(4, s.minimizeArrayValue(v4));
    vector<int> v5 = {10, 5, 1};
    EXPECT_EQ(10, s.minimizeArrayValue(v5));
    vector<int> v6 = {1, 5, 10};
    EXPECT_EQ(6, s.minimizeArrayValue(v6));
    vector<int> v7 = {0, 0, 0};
    EXPECT_EQ(0, s.minimizeArrayValue(v7));
    vector<int> v8 = {0, 0, 0, 0, 100};
    EXPECT_EQ(20, s.minimizeArrayValue(v8));
    vector<int> v9 = {1, 9};
    EXPECT_EQ(5, s.minimizeArrayValue(v9));
    vector<int> v10 = {1, 10};
    EXPECT_EQ(6, s.minimizeArrayValue(v10));
}

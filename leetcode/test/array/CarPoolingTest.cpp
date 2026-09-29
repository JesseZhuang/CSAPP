#include "gtest/gtest.h"
#include "array/CarPooling.hpp"

TEST(array, car_pooling) {
    CarPooling sol;

    vector<vector<int>> t1 = {{2,1,5},{3,3,7}};
    EXPECT_FALSE(sol.carPooling(t1, 4));

    vector<vector<int>> t2 = {{2,1,5},{3,3,7}};
    EXPECT_TRUE(sol.carPooling(t2, 5));

    vector<vector<int>> t3 = {{2,1,5},{3,5,7}};
    EXPECT_TRUE(sol.carPooling(t3, 3));

    vector<vector<int>> t4 = {{3,2,7}};
    EXPECT_TRUE(sol.carPooling(t4, 3));

    vector<vector<int>> t5 = {{3,2,7}};
    EXPECT_FALSE(sol.carPooling(t5, 2));

    vector<vector<int>> t6 = {{5,0,3},{5,3,6}};
    EXPECT_TRUE(sol.carPooling(t6, 5));

    vector<vector<int>> t7 = {{2,0,5},{3,0,5}};
    EXPECT_TRUE(sol.carPooling(t7, 5));

    vector<vector<int>> t8 = {{2,0,5},{3,0,5}};
    EXPECT_FALSE(sol.carPooling(t8, 4));

    vector<vector<int>> t9 = {{3,0,2},{3,2,4}};
    EXPECT_TRUE(sol.carPooling(t9, 3));

    vector<vector<int>> t10 = {};
    EXPECT_TRUE(sol.carPooling(t10, 1));
}

TEST(array, car_pooling2) {
    CarPooling sol;

    vector<vector<int>> t1 = {{2,1,5},{3,3,7}};
    EXPECT_FALSE(sol.carPooling2(t1, 4));

    vector<vector<int>> t2 = {{2,1,5},{3,3,7}};
    EXPECT_TRUE(sol.carPooling2(t2, 5));

    vector<vector<int>> t3 = {{2,1,5},{3,5,7}};
    EXPECT_TRUE(sol.carPooling2(t3, 3));

    vector<vector<int>> t4 = {{3,2,7}};
    EXPECT_TRUE(sol.carPooling2(t4, 3));

    vector<vector<int>> t5 = {{3,2,7}};
    EXPECT_FALSE(sol.carPooling2(t5, 2));

    vector<vector<int>> t6 = {{5,0,3},{5,3,6}};
    EXPECT_TRUE(sol.carPooling2(t6, 5));

    vector<vector<int>> t7 = {{2,0,5},{3,0,5}};
    EXPECT_TRUE(sol.carPooling2(t7, 5));

    vector<vector<int>> t8 = {{2,0,5},{3,0,5}};
    EXPECT_FALSE(sol.carPooling2(t8, 4));

    vector<vector<int>> t9 = {{3,0,2},{3,2,4}};
    EXPECT_TRUE(sol.carPooling2(t9, 3));

    vector<vector<int>> t10 = {};
    EXPECT_TRUE(sol.carPooling2(t10, 1));
}

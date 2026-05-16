#include "gtest/gtest.h"
#include "array/SpiralMatrix.hpp"

TEST(array, spiral_matrix_3x3) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> expected = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

TEST(array, spiral_matrix_3x4) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> expected = {1,2,3,4,8,12,11,10,9,5,6,7};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

TEST(array, spiral_matrix_single_row) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{1,2,3,4}};
    vector<int> expected = {1,2,3,4};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

TEST(array, spiral_matrix_single_col) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{1},{2},{3}};
    vector<int> expected = {1,2,3};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

TEST(array, spiral_matrix_single_element) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{7}};
    vector<int> expected = {7};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

TEST(array, spiral_matrix_2x2) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{1,2},{3,4}};
    vector<int> expected = {1,2,4,3};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

TEST(array, spiral_matrix_4x3) {
    SpiralMatrix sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    vector<int> expected = {1,2,3,6,9,12,11,10,7,4,5,8};
    EXPECT_EQ(sol.spiralOrder(matrix), expected);
}

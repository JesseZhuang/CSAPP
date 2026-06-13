#include "gtest/gtest.h"
#include "array/SetMatrixZeroes.hpp"

// Example 1: 3x3 matrix with one zero
TEST(array, set_matrix_zeroes_example1) {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{1,0,1},{0,0,0},{1,0,1}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_example1) {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{1,0,1},{0,0,0},{1,0,1}};
    EXPECT_EQ(expected, matrix);
}

// Example 2: 3x4 matrix with multiple zeros
TEST(array, set_matrix_zeroes_example2) {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_example2) {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    EXPECT_EQ(expected, matrix);
}

// No zeroes - matrix should remain unchanged
TEST(array, set_matrix_zeroes_no_zeroes) {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{1,2,3},{4,5,6},{7,8,9}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_no_zeroes) {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{1,2,3},{4,5,6},{7,8,9}};
    EXPECT_EQ(expected, matrix);
}

// Single element - zero
TEST(array, set_matrix_zeroes_single_zero) {
    vector<vector<int>> matrix = {{0}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_single_zero) {
    vector<vector<int>> matrix = {{0}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0}};
    EXPECT_EQ(expected, matrix);
}

// Single element - non-zero
TEST(array, set_matrix_zeroes_single_nonzero) {
    vector<vector<int>> matrix = {{5}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{5}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_single_nonzero) {
    vector<vector<int>> matrix = {{5}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{5}};
    EXPECT_EQ(expected, matrix);
}

// First row has zero
TEST(array, set_matrix_zeroes_first_row_zero) {
    vector<vector<int>> matrix = {{0,1,2},{3,4,5},{6,7,8}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0,0,0},{0,4,5},{0,7,8}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_first_row_zero) {
    vector<vector<int>> matrix = {{0,1,2},{3,4,5},{6,7,8}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0,0,0},{0,4,5},{0,7,8}};
    EXPECT_EQ(expected, matrix);
}

// First column has zero
TEST(array, set_matrix_zeroes_first_col_zero) {
    vector<vector<int>> matrix = {{1,2,3},{0,5,6},{7,8,9}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0,2,3},{0,0,0},{0,8,9}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_first_col_zero) {
    vector<vector<int>> matrix = {{1,2,3},{0,5,6},{7,8,9}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0,2,3},{0,0,0},{0,8,9}};
    EXPECT_EQ(expected, matrix);
}

// Negative values
TEST(array, set_matrix_zeroes_negative_values) {
    vector<vector<int>> matrix = {{-1,-2,-3},{-4,0,-6},{-7,-8,-9}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{-1,0,-3},{0,0,0},{-7,0,-9}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_negative_values) {
    vector<vector<int>> matrix = {{-1,-2,-3},{-4,0,-6},{-7,-8,-9}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{-1,0,-3},{0,0,0},{-7,0,-9}};
    EXPECT_EQ(expected, matrix);
}

// All zeros
TEST(array, set_matrix_zeroes_all_zeros) {
    vector<vector<int>> matrix = {{0,0},{0,0}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0,0},{0,0}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_all_zeros) {
    vector<vector<int>> matrix = {{0,0},{0,0}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0,0},{0,0}};
    EXPECT_EQ(expected, matrix);
}

// Single row with zero
TEST(array, set_matrix_zeroes_single_row) {
    vector<vector<int>> matrix = {{1,0,3,4}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0,0,0,0}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_single_row) {
    vector<vector<int>> matrix = {{1,0,3,4}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0,0,0,0}};
    EXPECT_EQ(expected, matrix);
}

// Single column with zero
TEST(array, set_matrix_zeroes_single_col) {
    vector<vector<int>> matrix = {{1},{0},{3}};
    SetMatrixZeroes::setZeroes(matrix);
    vector<vector<int>> expected = {{0},{0},{0}};
    EXPECT_EQ(expected, matrix);
}

TEST(array, set_matrix_zeroes_v2_single_col) {
    vector<vector<int>> matrix = {{1},{0},{3}};
    SetMatrixZeroes::setZeroesV2(matrix);
    vector<vector<int>> expected = {{0},{0},{0}};
    EXPECT_EQ(expected, matrix);
}

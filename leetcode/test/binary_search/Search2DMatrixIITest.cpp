#include "gtest/gtest.h"
#include "binary_search/Search2DMatrixII.hpp"

TEST(binary_search, search_2d_matrix_ii) {
    Search2DMatrixII sol;

    // Standard 5x5 matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    EXPECT_TRUE(sol.searchMatrix(matrix, 5));
    EXPECT_FALSE(sol.searchMatrix(matrix, 20));
    EXPECT_TRUE(sol.searchMatrix2(matrix, 5));
    EXPECT_FALSE(sol.searchMatrix2(matrix, 20));

    // Single element - found
    vector<vector<int>> single = {{5}};
    EXPECT_TRUE(sol.searchMatrix(single, 5));
    EXPECT_TRUE(sol.searchMatrix2(single, 5));

    // Single element - not found
    EXPECT_FALSE(sol.searchMatrix(single, 3));
    EXPECT_FALSE(sol.searchMatrix2(single, 3));

    // Negative numbers
    vector<vector<int>> neg = {{-5, -3}, {-1, 2}};
    EXPECT_TRUE(sol.searchMatrix(neg, -3));
    EXPECT_TRUE(sol.searchMatrix2(neg, -3));
    EXPECT_FALSE(sol.searchMatrix(neg, 0));
    EXPECT_FALSE(sol.searchMatrix2(neg, 0));

    // Single row
    vector<vector<int>> singleRow = {{1, 3, 5, 7, 9}};
    EXPECT_TRUE(sol.searchMatrix(singleRow, 7));
    EXPECT_TRUE(sol.searchMatrix2(singleRow, 7));
    EXPECT_FALSE(sol.searchMatrix(singleRow, 4));
    EXPECT_FALSE(sol.searchMatrix2(singleRow, 4));

    // Single column
    vector<vector<int>> singleCol = {{2}, {4}, {6}, {8}};
    EXPECT_TRUE(sol.searchMatrix(singleCol, 6));
    EXPECT_TRUE(sol.searchMatrix2(singleCol, 6));
    EXPECT_FALSE(sol.searchMatrix(singleCol, 5));
    EXPECT_FALSE(sol.searchMatrix2(singleCol, 5));
}

#include "gtest/gtest.h"
#include "array/EqualRowAndColumnPairs.hpp"

using namespace std;

TEST(array, equal_row_and_column_pairs_official_examples) {
    SolutionEqualRowAndColumnPairs solution;

    vector<vector<int>> grid1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    EXPECT_EQ(solution.equalPairs(grid1), 1);
    EXPECT_EQ(solution.equalPairsBruteForce(grid1), 1);

    vector<vector<int>> grid2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    EXPECT_EQ(solution.equalPairs(grid2), 3);
    EXPECT_EQ(solution.equalPairsBruteForce(grid2), 3);
}

TEST(array, equal_row_and_column_pairs_single_cell) {
    SolutionEqualRowAndColumnPairs solution;
    vector<vector<int>> grid = {{42}};

    EXPECT_EQ(solution.equalPairs(grid), 1);
    EXPECT_EQ(solution.equalPairsBruteForce(grid), 1);
}

TEST(array, equal_row_and_column_pairs_counts_duplicate_rows_and_columns) {
    SolutionEqualRowAndColumnPairs solution;
    vector<vector<int>> grid = {{5, 5}, {5, 5}};

    EXPECT_EQ(solution.equalPairs(grid), 4);
    EXPECT_EQ(solution.equalPairsBruteForce(grid), 4);
}

TEST(array, equal_row_and_column_pairs_returns_zero_when_no_pairs_match) {
    SolutionEqualRowAndColumnPairs solution;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};

    EXPECT_EQ(solution.equalPairs(grid), 0);
    EXPECT_EQ(solution.equalPairsBruteForce(grid), 0);
}

#include "gtest/gtest.h"
#include "graph/ColoringABorder.hpp"

TEST(graph, coloring_a_border_example) {
    ColoringABorder solution;
    vector<vector<int>> grid = {{1, 1}, {1, 2}};
    vector<vector<int>> expected = {{3, 3}, {3, 2}};

    EXPECT_EQ(solution.colorBorder(grid, 0, 0, 3), expected);
    EXPECT_EQ(grid, expected);
}

TEST(graph, coloring_a_border_keeps_interior) {
    ColoringABorder solution;
    vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<vector<int>> expected = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};

    EXPECT_EQ(solution.colorBorder(grid, 1, 1, 2), expected);
}

TEST(graph, coloring_a_border_same_color) {
    ColoringABorder solution;
    vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<vector<int>> expected = grid;

    EXPECT_EQ(solution.colorBorder(grid, 1, 1, 1), expected);
}

TEST(graph, coloring_a_border_disconnected_component) {
    ColoringABorder solution;
    vector<vector<int>> grid = {{1, 2, 1}, {2, 2, 2}, {1, 2, 1}};
    vector<vector<int>> expected = {{3, 2, 1}, {2, 2, 2}, {1, 2, 1}};

    EXPECT_EQ(solution.colorBorder(grid, 0, 0, 3), expected);
}

TEST(graph, coloring_a_border_single_cell) {
    ColoringABorder solution;
    vector<vector<int>> grid = {{1}};
    vector<vector<int>> expected = {{2}};

    EXPECT_EQ(solution.colorBorder(grid, 0, 0, 2), expected);
}

TEST(graph, coloring_a_border_adjacent_different_color) {
    ColoringABorder solution;
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    vector<vector<int>> expected = {
        {3, 3, 3, 3, 3},
        {3, 1, 3, 1, 3},
        {3, 3, 2, 3, 3},
        {3, 1, 3, 1, 3},
        {3, 3, 3, 3, 3}
    };

    EXPECT_EQ(solution.colorBorder(grid, 1, 1, 3), expected);
}

TEST(graph, coloring_a_border_fifty_by_fifty) {
    ColoringABorder solution;
    vector<vector<int>> grid(50, vector<int>(50, 1));
    vector<vector<int>> expected = grid;
    for (int index = 0; index < 50; index++) {
        expected[0][index] = 2;
        expected[49][index] = 2;
        expected[index][0] = 2;
        expected[index][49] = 2;
    }

    EXPECT_EQ(solution.colorBorder(grid, 25, 25, 2), expected);
}

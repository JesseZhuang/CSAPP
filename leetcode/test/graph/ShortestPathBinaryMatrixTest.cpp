#include <gtest/gtest.h>
#include "graph/ShortestPathBinaryMatrix.hpp"

TEST(graph, shortest_path_binary_matrix_bfs) {
    {
        vector<vector<int>> grid = {{0,1},{1,0}};
        EXPECT_EQ(Solution1091::bfs(grid), 2);
    }
    {
        vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
        EXPECT_EQ(Solution1091::bfs(grid), 4);
    }
    {
        vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,0}};
        EXPECT_EQ(Solution1091::bfs(grid), -1);
    }
    {
        vector<vector<int>> grid = {{0}};
        EXPECT_EQ(Solution1091::bfs(grid), 1);
    }
    {
        vector<vector<int>> grid = {{0,0},{0,1}};
        EXPECT_EQ(Solution1091::bfs(grid), -1);
    }
    {
        vector<vector<int>> grid = {{0,1,1},{1,0,1},{1,1,0}};
        EXPECT_EQ(Solution1091::bfs(grid), 3);
    }
}

TEST(graph, shortest_path_binary_matrix_a_star) {
    {
        vector<vector<int>> grid = {{0,1},{1,0}};
        EXPECT_EQ(Solution1091::aStar(grid), 2);
    }
    {
        vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
        EXPECT_EQ(Solution1091::aStar(grid), 4);
    }
    {
        vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,0}};
        EXPECT_EQ(Solution1091::aStar(grid), -1);
    }
    {
        vector<vector<int>> grid = {{0}};
        EXPECT_EQ(Solution1091::aStar(grid), 1);
    }
    {
        vector<vector<int>> grid = {{0,0},{0,1}};
        EXPECT_EQ(Solution1091::aStar(grid), -1);
    }
    {
        vector<vector<int>> grid = {{0,1,1},{1,0,1},{1,1,0}};
        EXPECT_EQ(Solution1091::aStar(grid), 3);
    }
}

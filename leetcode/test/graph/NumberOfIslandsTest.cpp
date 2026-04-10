#include "gtest/gtest.h"
#include "graph/NumberOfIslands.hpp"

using namespace std;

TEST(graph, number_of_islands_dfs) {
    Solution tbt;

    // Example 1: 1 island
    vector<vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    ASSERT_EQ(1, tbt.numIslandsDFS(g1));

    // Example 2: 3 islands
    vector<vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    ASSERT_EQ(3, tbt.numIslandsDFS(g2));

    // Single '1': 1 island
    vector<vector<char>> g3 = {{'1'}};
    ASSERT_EQ(1, tbt.numIslandsDFS(g3));

    // Single '0': 0 islands
    vector<vector<char>> g4 = {{'0'}};
    ASSERT_EQ(0, tbt.numIslandsDFS(g4));

    // All land 2x2: 1 island
    vector<vector<char>> g5 = {{'1','1'},{'1','1'}};
    ASSERT_EQ(1, tbt.numIslandsDFS(g5));

    // Diagonal: 2 islands (diagonal cells are not connected)
    vector<vector<char>> g6 = {{'1','0'},{'0','1'}};
    ASSERT_EQ(2, tbt.numIslandsDFS(g6));
}

TEST(graph, number_of_islands_bfs) {
    Solution tbt;

    // Example 1: 1 island
    vector<vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    ASSERT_EQ(1, tbt.numIslandsBFS(g1));

    // Example 2: 3 islands
    vector<vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    ASSERT_EQ(3, tbt.numIslandsBFS(g2));

    // Single '1': 1 island
    vector<vector<char>> g3 = {{'1'}};
    ASSERT_EQ(1, tbt.numIslandsBFS(g3));

    // Single '0': 0 islands
    vector<vector<char>> g4 = {{'0'}};
    ASSERT_EQ(0, tbt.numIslandsBFS(g4));

    // All land 2x2: 1 island
    vector<vector<char>> g5 = {{'1','1'},{'1','1'}};
    ASSERT_EQ(1, tbt.numIslandsBFS(g5));

    // Diagonal: 2 islands (diagonal cells are not connected)
    vector<vector<char>> g6 = {{'1','0'},{'0','1'}};
    ASSERT_EQ(2, tbt.numIslandsBFS(g6));
}

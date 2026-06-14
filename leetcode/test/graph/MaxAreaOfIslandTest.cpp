#include "gtest/gtest.h"
#include "graph/MaxAreaOfIsland.hpp"

using namespace std;

TEST(graph, max_area_of_island_dfs) {
    MaxAreaOfIslandSolution tbt;

    vector<vector<int>> g1 = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    ASSERT_EQ(6, tbt.maxAreaOfIslandDFS(g1));

    vector<vector<int>> g2 = {{0,0,0,0,0,0,0,0}};
    ASSERT_EQ(0, tbt.maxAreaOfIslandDFS(g2));

    vector<vector<int>> g3 = {{1}};
    ASSERT_EQ(1, tbt.maxAreaOfIslandDFS(g3));

    vector<vector<int>> g4 = {{1,1},{1,1}};
    ASSERT_EQ(4, tbt.maxAreaOfIslandDFS(g4));

    vector<vector<int>> g5 = {{1,0},{0,1}};
    ASSERT_EQ(1, tbt.maxAreaOfIslandDFS(g5));
}

TEST(graph, max_area_of_island_bfs) {
    MaxAreaOfIslandSolution tbt;

    vector<vector<int>> g1 = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    ASSERT_EQ(6, tbt.maxAreaOfIslandBFS(g1));

    vector<vector<int>> g2 = {{0,0,0,0,0,0,0,0}};
    ASSERT_EQ(0, tbt.maxAreaOfIslandBFS(g2));

    vector<vector<int>> g3 = {{1}};
    ASSERT_EQ(1, tbt.maxAreaOfIslandBFS(g3));

    vector<vector<int>> g4 = {{1,1},{1,1}};
    ASSERT_EQ(4, tbt.maxAreaOfIslandBFS(g4));

    vector<vector<int>> g5 = {{1,0},{0,1}};
    ASSERT_EQ(1, tbt.maxAreaOfIslandBFS(g5));
}

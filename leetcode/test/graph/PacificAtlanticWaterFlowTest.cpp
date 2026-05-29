#include "gtest/gtest.h"
#include "graph/PacificAtlanticWaterFlow.hpp"

using namespace std;

static vector<vector<int>> sorted(vector<vector<int>> v) {
    sort(v.begin(), v.end());
    return v;
}

TEST(graph, pacific_atlantic_water_flow_dfs) {
    PacificAtlanticWaterFlow tbt;

    // Example 1
    vector<vector<int>> h1 = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    vector<vector<int>> expected1 = {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
    ASSERT_EQ(sorted(expected1), sorted(tbt.pacificAtlanticDFS(h1)));

    // Single cell
    vector<vector<int>> h2 = {{1}};
    vector<vector<int>> expected2 = {{0,0}};
    ASSERT_EQ(sorted(expected2), sorted(tbt.pacificAtlanticDFS(h2)));

    // Flat grid: all cells can reach both oceans
    vector<vector<int>> h3 = {{1,1},{1,1}};
    vector<vector<int>> expected3 = {{0,0},{0,1},{1,0},{1,1}};
    ASSERT_EQ(sorted(expected3), sorted(tbt.pacificAtlanticDFS(h3)));
}

TEST(graph, pacific_atlantic_water_flow_bfs) {
    PacificAtlanticWaterFlow tbt;

    // Example 1
    vector<vector<int>> h1 = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    vector<vector<int>> expected1 = {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
    ASSERT_EQ(sorted(expected1), sorted(tbt.pacificAtlanticBFS(h1)));

    // Single cell
    vector<vector<int>> h2 = {{1}};
    vector<vector<int>> expected2 = {{0,0}};
    ASSERT_EQ(sorted(expected2), sorted(tbt.pacificAtlanticBFS(h2)));

    // Flat grid: all cells can reach both oceans
    vector<vector<int>> h3 = {{1,1},{1,1}};
    vector<vector<int>> expected3 = {{0,0},{0,1},{1,0},{1,1}};
    ASSERT_EQ(sorted(expected3), sorted(tbt.pacificAtlanticBFS(h3)));
}

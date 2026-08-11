#include "gtest/gtest.h"
#include "graph/ShortestBridge.hpp"

TEST(graph, shortest_bridge) {
    ShortestBridge sol;

    vector<vector<int>> g1 = {{0,1},{1,0}};
    EXPECT_EQ(sol.shortestBridge(g1), 1);

    vector<vector<int>> g2 = {{0,1,0},{0,0,0},{0,0,1}};
    EXPECT_EQ(sol.shortestBridge(g2), 2);

    vector<vector<int>> g3 = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    EXPECT_EQ(sol.shortestBridge(g3), 1);
}

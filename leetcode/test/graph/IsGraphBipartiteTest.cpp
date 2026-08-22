#include "gtest/gtest.h"
#include "graph/IsGraphBipartite.hpp"

TEST(graph, is_graph_bipartite_bfs) {
    IsGraphBipartiteSolution sol;

    vector<vector<int>> g1 = {{1,3},{0,2},{1,3},{0,2}};
    EXPECT_TRUE(sol.isBipartiteBFS(g1));

    vector<vector<int>> g2 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    EXPECT_FALSE(sol.isBipartiteBFS(g2));

    vector<vector<int>> g3 = {{}};
    EXPECT_TRUE(sol.isBipartiteBFS(g3));

    vector<vector<int>> g4 = {{1},{0},{3},{2}};
    EXPECT_TRUE(sol.isBipartiteBFS(g4));

    vector<vector<int>> g5 = {{1},{0},{3,4},{2,4},{2,3}};
    EXPECT_FALSE(sol.isBipartiteBFS(g5));

    vector<vector<int>> g6 = {{},{},{}};
    EXPECT_TRUE(sol.isBipartiteBFS(g6));

    vector<vector<int>> g7 = {{1,2},{0,2},{0,1}};
    EXPECT_FALSE(sol.isBipartiteBFS(g7));

    vector<vector<int>> g8 = {{3,4,5},{3,4,5},{3,4,5},{0,1,2},{0,1,2},{0,1,2}};
    EXPECT_TRUE(sol.isBipartiteBFS(g8));
}

TEST(graph, is_graph_bipartite_uf) {
    IsGraphBipartiteSolution sol;

    vector<vector<int>> g1 = {{1,3},{0,2},{1,3},{0,2}};
    EXPECT_TRUE(sol.isBipartiteUF(g1));

    vector<vector<int>> g2 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    EXPECT_FALSE(sol.isBipartiteUF(g2));

    vector<vector<int>> g3 = {{}};
    EXPECT_TRUE(sol.isBipartiteUF(g3));

    vector<vector<int>> g4 = {{1},{0},{3},{2}};
    EXPECT_TRUE(sol.isBipartiteUF(g4));

    vector<vector<int>> g5 = {{1},{0},{3,4},{2,4},{2,3}};
    EXPECT_FALSE(sol.isBipartiteUF(g5));

    vector<vector<int>> g6 = {{},{},{}};
    EXPECT_TRUE(sol.isBipartiteUF(g6));

    vector<vector<int>> g7 = {{1,2},{0,2},{0,1}};
    EXPECT_FALSE(sol.isBipartiteUF(g7));

    vector<vector<int>> g8 = {{3,4,5},{3,4,5},{3,4,5},{0,1,2},{0,1,2},{0,1,2}};
    EXPECT_TRUE(sol.isBipartiteUF(g8));
}

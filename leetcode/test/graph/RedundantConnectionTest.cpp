#include "gtest/gtest.h"
#include "graph/RedundantConnection.hpp"

TEST(graph, redundant_connection_uf) {
    RedundantConnectionSolution sol;
    vector<vector<int>> e1 = {{1, 2}, {1, 3}, {2, 3}};
    EXPECT_EQ((vector<int>{2, 3}), sol.findRedundantConnectionUF(e1));

    vector<vector<int>> e2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    EXPECT_EQ((vector<int>{1, 4}), sol.findRedundantConnectionUF(e2));

    vector<vector<int>> e3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}};
    EXPECT_EQ((vector<int>{5, 1}), sol.findRedundantConnectionUF(e3));
}

TEST(graph, redundant_connection_dfs) {
    RedundantConnectionSolution sol;
    vector<vector<int>> e1 = {{1, 2}, {1, 3}, {2, 3}};
    EXPECT_EQ((vector<int>{2, 3}), sol.findRedundantConnectionDFS(e1));

    vector<vector<int>> e2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    EXPECT_EQ((vector<int>{1, 4}), sol.findRedundantConnectionDFS(e2));

    vector<vector<int>> e3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}};
    EXPECT_EQ((vector<int>{5, 1}), sol.findRedundantConnectionDFS(e3));
}

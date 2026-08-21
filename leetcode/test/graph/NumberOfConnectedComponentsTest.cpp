#include "gtest/gtest.h"
#include "graph/NumberOfConnectedComponents.hpp"

using namespace std;

TEST(graph, number_of_connected_components_uf) {
    // Example 1: n=5, edges={{0,1},{1,2},{3,4}} -> 2 components
    vector<vector<int>> e1 = {{0,1},{1,2},{3,4}};
    ASSERT_EQ(2, Solution::countComponentsUF(5, e1));

    // Example 2: all connected -> 1 component
    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{3,4}};
    ASSERT_EQ(1, Solution::countComponentsUF(5, e2));

    // No edges: each node is its own component -> 4
    vector<vector<int>> e3 = {};
    ASSERT_EQ(4, Solution::countComponentsUF(4, e3));

    // Single node -> 1
    vector<vector<int>> e4 = {};
    ASSERT_EQ(1, Solution::countComponentsUF(1, e4));

    // Cycle: 0-1-2-0 -> 1 component
    vector<vector<int>> e5 = {{0,1},{1,2},{0,2}};
    ASSERT_EQ(1, Solution::countComponentsUF(3, e5));

    // Three components: {0,1}, {2,3}, {4,5}
    vector<vector<int>> e6 = {{0,1},{2,3},{4,5}};
    ASSERT_EQ(3, Solution::countComponentsUF(6, e6));
}

TEST(graph, number_of_connected_components_dfs) {
    // Example 1: n=5, edges={{0,1},{1,2},{3,4}} -> 2 components
    vector<vector<int>> e1 = {{0,1},{1,2},{3,4}};
    ASSERT_EQ(2, Solution::countComponentsDFS(5, e1));

    // Example 2: all connected -> 1 component
    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{3,4}};
    ASSERT_EQ(1, Solution::countComponentsDFS(5, e2));

    // No edges: each node is its own component -> 4
    vector<vector<int>> e3 = {};
    ASSERT_EQ(4, Solution::countComponentsDFS(4, e3));

    // Single node -> 1
    vector<vector<int>> e4 = {};
    ASSERT_EQ(1, Solution::countComponentsDFS(1, e4));

    // Cycle: 0-1-2-0 -> 1 component
    vector<vector<int>> e5 = {{0,1},{1,2},{0,2}};
    ASSERT_EQ(1, Solution::countComponentsDFS(3, e5));

    // Three components: {0,1}, {2,3}, {4,5}
    vector<vector<int>> e6 = {{0,1},{2,3},{4,5}};
    ASSERT_EQ(3, Solution::countComponentsDFS(6, e6));
}

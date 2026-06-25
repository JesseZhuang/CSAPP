#include "gtest/gtest.h"
#include "graph/NumberOfProvinces.hpp"

using namespace std;

TEST(graph, number_of_provinces_dfs) {
    // Example 1: 2 provinces — {0,1} and {2}
    vector<vector<int>> g1 = {{1,1,0},{1,1,0},{0,0,1}};
    ASSERT_EQ(2, Solution::findCircleNumDFS(g1));

    // Example 2: 3 provinces — each city is isolated
    vector<vector<int>> g2 = {{1,0,0},{0,1,0},{0,0,1}};
    ASSERT_EQ(3, Solution::findCircleNumDFS(g2));

    // All connected: 1 province
    vector<vector<int>> g3 = {{1,1,1},{1,1,1},{1,1,1}};
    ASSERT_EQ(1, Solution::findCircleNumDFS(g3));

    // Single city: 1 province
    vector<vector<int>> g4 = {{1}};
    ASSERT_EQ(1, Solution::findCircleNumDFS(g4));

    // Two pairs: {0,1} and {2,3} — 2 provinces
    vector<vector<int>> g5 = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,1,1}
    };
    ASSERT_EQ(2, Solution::findCircleNumDFS(g5));
}

TEST(graph, number_of_provinces_uf) {
    // Example 1: 2 provinces — {0,1} and {2}
    vector<vector<int>> g1 = {{1,1,0},{1,1,0},{0,0,1}};
    ASSERT_EQ(2, Solution::findCircleNumUF(g1));

    // Example 2: 3 provinces — each city is isolated
    vector<vector<int>> g2 = {{1,0,0},{0,1,0},{0,0,1}};
    ASSERT_EQ(3, Solution::findCircleNumUF(g2));

    // All connected: 1 province
    vector<vector<int>> g3 = {{1,1,1},{1,1,1},{1,1,1}};
    ASSERT_EQ(1, Solution::findCircleNumUF(g3));

    // Single city: 1 province
    vector<vector<int>> g4 = {{1}};
    ASSERT_EQ(1, Solution::findCircleNumUF(g4));

    // Two pairs: {0,1} and {2,3} — 2 provinces
    vector<vector<int>> g5 = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,1,1}
    };
    ASSERT_EQ(2, Solution::findCircleNumUF(g5));
}

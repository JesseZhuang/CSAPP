#include <gtest/gtest.h>
#include "graph/DetonateMaximumBombs.hpp"

TEST(graph, detonate_maximum_bombs_bfs) {
    // Example 1: both bombs detonate each other
    vector<vector<int>> bombs1 = {{2,1,3},{6,1,4}};
    EXPECT_EQ(2, DetonateMaximumBombs::maximumDetonationBFS(bombs1));

    // Example 2: bombs too far apart
    vector<vector<int>> bombs2 = {{1,1,5},{10,10,5}};
    EXPECT_EQ(1, DetonateMaximumBombs::maximumDetonationBFS(bombs2));

    // Example 3: chain reaction detonates all
    vector<vector<int>> bombs3 = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    EXPECT_EQ(5, DetonateMaximumBombs::maximumDetonationBFS(bombs3));

    // Single bomb
    vector<vector<int>> bombs4 = {{0,0,1}};
    EXPECT_EQ(1, DetonateMaximumBombs::maximumDetonationBFS(bombs4));

    // No chain: all isolated
    vector<vector<int>> bombs5 = {{0,0,1},{100,100,1},{200,200,1}};
    EXPECT_EQ(1, DetonateMaximumBombs::maximumDetonationBFS(bombs5));

    // One directional: bomb 0 reaches bomb 1, but not vice versa
    vector<vector<int>> bombs6 = {{0,0,10},{5,0,1}};
    EXPECT_EQ(2, DetonateMaximumBombs::maximumDetonationBFS(bombs6));

    // Exact boundary: distance == radius
    vector<vector<int>> bombs7 = {{0,0,5},{3,4,5}};
    EXPECT_EQ(2, DetonateMaximumBombs::maximumDetonationBFS(bombs7));

    // Chain of 3: 0->1->2 but not 0->2 directly
    vector<vector<int>> bombs8 = {{0,0,3},{2,0,3},{4,0,3}};
    EXPECT_EQ(3, DetonateMaximumBombs::maximumDetonationBFS(bombs8));
}

TEST(graph, detonate_maximum_bombs_dfs) {
    vector<vector<int>> bombs1 = {{2,1,3},{6,1,4}};
    EXPECT_EQ(2, DetonateMaximumBombs::maximumDetonationDFS(bombs1));

    vector<vector<int>> bombs2 = {{1,1,5},{10,10,5}};
    EXPECT_EQ(1, DetonateMaximumBombs::maximumDetonationDFS(bombs2));

    vector<vector<int>> bombs3 = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    EXPECT_EQ(5, DetonateMaximumBombs::maximumDetonationDFS(bombs3));

    vector<vector<int>> bombs4 = {{0,0,1}};
    EXPECT_EQ(1, DetonateMaximumBombs::maximumDetonationDFS(bombs4));

    vector<vector<int>> bombs5 = {{0,0,1},{100,100,1},{200,200,1}};
    EXPECT_EQ(1, DetonateMaximumBombs::maximumDetonationDFS(bombs5));

    vector<vector<int>> bombs6 = {{0,0,10},{5,0,1}};
    EXPECT_EQ(2, DetonateMaximumBombs::maximumDetonationDFS(bombs6));

    vector<vector<int>> bombs7 = {{0,0,5},{3,4,5}};
    EXPECT_EQ(2, DetonateMaximumBombs::maximumDetonationDFS(bombs7));

    vector<vector<int>> bombs8 = {{0,0,3},{2,0,3},{4,0,3}};
    EXPECT_EQ(3, DetonateMaximumBombs::maximumDetonationDFS(bombs8));
}

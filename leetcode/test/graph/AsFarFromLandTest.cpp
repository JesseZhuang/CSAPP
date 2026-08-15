#include "gtest/gtest.h"
#include "graph/AsFarFromLand.hpp"

using namespace std;

// --- BFS solution tests ---

TEST(graph, as_far_from_land_bfs_example1) {
    Solution1162BFS sol;
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    ASSERT_EQ(sol.maxDistance(grid), 2);
}

TEST(graph, as_far_from_land_bfs_example2) {
    Solution1162BFS sol;
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,0}};
    ASSERT_EQ(sol.maxDistance(grid), 4);
}

TEST(graph, as_far_from_land_bfs_all_land) {
    Solution1162BFS sol;
    vector<vector<int>> grid = {{1,1},{1,1}};
    ASSERT_EQ(sol.maxDistance(grid), -1);
}

TEST(graph, as_far_from_land_bfs_all_water) {
    Solution1162BFS sol;
    vector<vector<int>> grid = {{0,0},{0,0}};
    ASSERT_EQ(sol.maxDistance(grid), -1);
}

TEST(graph, as_far_from_land_bfs_land_center) {
    Solution1162BFS sol;
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    ASSERT_EQ(sol.maxDistance(grid), 2);
}

// --- DP solution tests ---

TEST(graph, as_far_from_land_dp_example1) {
    Solution1162 sol;
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    ASSERT_EQ(sol.maxDistance(grid), 2);
}

TEST(graph, as_far_from_land_dp_example2) {
    Solution1162 sol;
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,0}};
    ASSERT_EQ(sol.maxDistance(grid), 4);
}

TEST(graph, as_far_from_land_dp_all_land) {
    Solution1162 sol;
    vector<vector<int>> grid = {{1,1},{1,1}};
    ASSERT_EQ(sol.maxDistance(grid), -1);
}

TEST(graph, as_far_from_land_dp_all_water) {
    Solution1162 sol;
    vector<vector<int>> grid = {{0,0},{0,0}};
    ASSERT_EQ(sol.maxDistance(grid), -1);
}

TEST(graph, as_far_from_land_dp_land_center) {
    Solution1162 sol;
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    ASSERT_EQ(sol.maxDistance(grid), 2);
}

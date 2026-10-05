#include "gtest/gtest.h"
#include "graph/ShortestPathAlternatingColors.hpp"

using namespace std;

TEST(graph, shortest_path_alternating_colors_examples) {
    Solution1129 sol;
    {
        vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
        vector<vector<int>> blueEdges = {};
        vector<int> expected = {0, 1, -1};
        ASSERT_EQ(sol.shortestAlternatingPaths(3, redEdges, blueEdges), expected);
    }
    {
        vector<vector<int>> redEdges = {{0, 1}};
        vector<vector<int>> blueEdges = {{2, 1}};
        vector<int> expected = {0, 1, -1};
        ASSERT_EQ(sol.shortestAlternatingPaths(3, redEdges, blueEdges), expected);
    }
}

TEST(graph, shortest_path_alternating_colors_single_node) {
    Solution1129 sol;
    vector<vector<int>> redEdges = {};
    vector<vector<int>> blueEdges = {};
    vector<int> expected = {0};
    ASSERT_EQ(sol.shortestAlternatingPaths(1, redEdges, blueEdges), expected);
}

TEST(graph, shortest_path_alternating_colors_continues_alternating_edges) {
    Solution1129 sol;
    vector<vector<int>> redEdges = {{0, 1}, {2, 3}};
    vector<vector<int>> blueEdges = {{1, 2}, {3, 4}};
    vector<int> expected = {0, 1, 2, 3, 4};
    ASSERT_EQ(sol.shortestAlternatingPaths(5, redEdges, blueEdges), expected);

    vector<vector<int>> redEdgesStartingBlue = {{1, 2}};
    vector<vector<int>> blueEdgesStartingBlue = {{0, 1}};
    vector<int> expectedStartingBlue = {0, 1, 2};
    ASSERT_EQ(sol.shortestAlternatingPaths(3, redEdgesStartingBlue, blueEdgesStartingBlue), expectedStartingBlue);
}

TEST(graph, shortest_path_alternating_colors_tracks_each_incoming_color) {
    Solution1129 sol;
    vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
    vector<vector<int>> blueEdges = {{0, 1}, {1, 3}};
    vector<int> expected = {0, 1, 2, 2};
    ASSERT_EQ(sol.shortestAlternatingPaths(4, redEdges, blueEdges), expected);
}

TEST(graph, shortest_path_alternating_colors_handles_cycles_duplicates_and_unreachable) {
    Solution1129 sol;
    vector<vector<int>> redEdges = {{0, 1}, {0, 1}, {2, 1}, {2, 3}, {3, 4}};
    vector<vector<int>> blueEdges = {{1, 2}, {2, 0}, {2, 3}};
    vector<int> expected = {0, 1, 2, 3, -1};
    ASSERT_EQ(sol.shortestAlternatingPaths(5, redEdges, blueEdges), expected);
}

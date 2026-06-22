#include "gtest/gtest.h"
#include "graph/PathWithMinimumEffort.hpp"

using namespace std;

// --- Dijkstra tests ---

TEST(graph, path_with_minimum_effort_dijkstra_example1) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,2,2},{3,8,2},{5,3,5}};
    ASSERT_EQ(2, sol.dijkstra(heights));
}

TEST(graph, path_with_minimum_effort_dijkstra_example2) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,2,3},{3,8,4},{5,3,5}};
    ASSERT_EQ(1, sol.dijkstra(heights));
}

TEST(graph, path_with_minimum_effort_dijkstra_example3) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    ASSERT_EQ(0, sol.dijkstra(heights));
}

TEST(graph, path_with_minimum_effort_dijkstra_single_cell) {
    Solution1631 sol;
    vector<vector<int>> heights{{5}};
    ASSERT_EQ(0, sol.dijkstra(heights));
}

TEST(graph, path_with_minimum_effort_dijkstra_single_row) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,10,6,7,9,10,4,9}};
    ASSERT_EQ(9, sol.dijkstra(heights));
}

TEST(graph, path_with_minimum_effort_dijkstra_single_col) {
    Solution1631 sol;
    vector<vector<int>> heights{{1},{10},{6},{7}};
    ASSERT_EQ(9, sol.dijkstra(heights));
}

TEST(graph, path_with_minimum_effort_dijkstra_large_jump) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,100},{100,1}};
    ASSERT_EQ(99, sol.dijkstra(heights));
}

// --- Binary Search + BFS tests ---

TEST(graph, path_with_minimum_effort_binary_search_example1) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,2,2},{3,8,2},{5,3,5}};
    ASSERT_EQ(2, sol.binarySearch(heights));
}

TEST(graph, path_with_minimum_effort_binary_search_example2) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,2,3},{3,8,4},{5,3,5}};
    ASSERT_EQ(1, sol.binarySearch(heights));
}

TEST(graph, path_with_minimum_effort_binary_search_example3) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    ASSERT_EQ(0, sol.binarySearch(heights));
}

TEST(graph, path_with_minimum_effort_binary_search_single_cell) {
    Solution1631 sol;
    vector<vector<int>> heights{{5}};
    ASSERT_EQ(0, sol.binarySearch(heights));
}

TEST(graph, path_with_minimum_effort_binary_search_single_row) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,10,6,7,9,10,4,9}};
    ASSERT_EQ(9, sol.binarySearch(heights));
}

TEST(graph, path_with_minimum_effort_binary_search_single_col) {
    Solution1631 sol;
    vector<vector<int>> heights{{1},{10},{6},{7}};
    ASSERT_EQ(9, sol.binarySearch(heights));
}

TEST(graph, path_with_minimum_effort_binary_search_large_jump) {
    Solution1631 sol;
    vector<vector<int>> heights{{1,100},{100,1}};
    ASSERT_EQ(99, sol.binarySearch(heights));
}

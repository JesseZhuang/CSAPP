#include "gtest/gtest.h"
#include "graph/EventualSafeStates.hpp"

using namespace std;

// --- DFS tests ---

TEST(graph, eventual_safe_states_example1) {
    Solution802 sol;
    vector<vector<int>> g{{1,2},{2,3},{5},{0},{5},{},{}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({2,4,5,6}));
}

TEST(graph, eventual_safe_states_example2) {
    Solution802 sol;
    vector<vector<int>> g{{1,2,3,4},{1,2},{3,4},{0,4},{}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({4}));
}

TEST(graph, eventual_safe_states_all_terminal) {
    Solution802 sol;
    vector<vector<int>> g{{},{},{}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({0,1,2}));
}

TEST(graph, eventual_safe_states_single_node) {
    Solution802 sol;
    vector<vector<int>> g{{}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({0}));
}

TEST(graph, eventual_safe_states_self_loop) {
    Solution802 sol;
    vector<vector<int>> g{{0}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({}));
}

TEST(graph, eventual_safe_states_two_node_cycle) {
    Solution802 sol;
    vector<vector<int>> g{{1},{0}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({}));
}

TEST(graph, eventual_safe_states_chain) {
    Solution802 sol;
    vector<vector<int>> g{{1},{2},{}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({0,1,2}));
}

TEST(graph, eventual_safe_states_mixed) {
    Solution802 sol;
    vector<vector<int>> g{{1},{2},{0},{4},{}};
    ASSERT_EQ(sol.eventualSafeNodes(g), vector<int>({3,4}));
}

// --- BFS tests ---

TEST(graph, eventual_safe_states_bfs_example1) {
    Solution802 sol;
    vector<vector<int>> g{{1,2},{2,3},{5},{0},{5},{},{}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({2,4,5,6}));
}

TEST(graph, eventual_safe_states_bfs_example2) {
    Solution802 sol;
    vector<vector<int>> g{{1,2,3,4},{1,2},{3,4},{0,4},{}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({4}));
}

TEST(graph, eventual_safe_states_bfs_all_terminal) {
    Solution802 sol;
    vector<vector<int>> g{{},{},{}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({0,1,2}));
}

TEST(graph, eventual_safe_states_bfs_single_node) {
    Solution802 sol;
    vector<vector<int>> g{{}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({0}));
}

TEST(graph, eventual_safe_states_bfs_self_loop) {
    Solution802 sol;
    vector<vector<int>> g{{0}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({}));
}

TEST(graph, eventual_safe_states_bfs_two_node_cycle) {
    Solution802 sol;
    vector<vector<int>> g{{1},{0}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({}));
}

TEST(graph, eventual_safe_states_bfs_chain) {
    Solution802 sol;
    vector<vector<int>> g{{1},{2},{}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({0,1,2}));
}

TEST(graph, eventual_safe_states_bfs_mixed) {
    Solution802 sol;
    vector<vector<int>> g{{1},{2},{0},{4},{}};
    ASSERT_EQ(sol.eventualSafeNodesBFS(g), vector<int>({3,4}));
}

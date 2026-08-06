#include "gtest/gtest.h"
#include "graph/PathWithMaxProbability.hpp"

using namespace std;

// Helper to run both solutions and verify they agree
static void verify(int n, vector<vector<int>> edges, vector<double> succProb,
                   int start, int end, double expected) {
    Solution1514 sol1;
    Solution1514BF sol2;
    EXPECT_NEAR(expected, sol1.maxProbability(n, edges, succProb, start, end), 1e-5);
    EXPECT_NEAR(expected, sol2.maxProbability(n, edges, succProb, start, end), 1e-5);
}

TEST(graph, path_with_max_probability_lc_example1) {
    // LC Example 1: 3 nodes, path 0->1->2 has prob 0.5*0.5=0.25 vs 0->2 has 0.2
    verify(3, {{0,1},{1,2},{0,2}}, {0.5, 0.5, 0.2}, 0, 2, 0.25);
}

TEST(graph, path_with_max_probability_lc_example2) {
    // LC Example 2: 3 nodes, path 0->1->2 has prob 0.5*0.5=0.25 vs 0->2 has 0.3
    verify(3, {{0,1},{1,2},{0,2}}, {0.5, 0.5, 0.3}, 0, 2, 0.30);
}

TEST(graph, path_with_max_probability_no_path) {
    // LC Example 3: no path from 0 to 2
    verify(3, {{0,1}}, {0.5}, 0, 2, 0.0);
}

TEST(graph, path_with_max_probability_single_node) {
    // Single node: start == end
    verify(1, {}, {}, 0, 0, 1.0);
}

TEST(graph, path_with_max_probability_direct_edge) {
    // Direct edge is the best path
    verify(2, {{0,1}}, {0.9}, 0, 1, 0.9);
}

TEST(graph, path_with_max_probability_longer_path_better) {
    // Longer path (0->1->2->3) = 0.9*0.9*0.9 = 0.729 > direct (0->3) = 0.1
    verify(4, {{0,1},{1,2},{2,3},{0,3}}, {0.9, 0.9, 0.9, 0.1}, 0, 3, 0.729);
}

TEST(graph, path_with_max_probability_disconnected) {
    // Disconnected components: 0-1 and 2-3, no path from 0 to 3
    verify(4, {{0,1},{2,3}}, {0.5, 0.8}, 0, 3, 0.0);
}

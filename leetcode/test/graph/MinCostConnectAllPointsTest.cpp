#include "gtest/gtest.h"
#include "graph/MinCostConnectAllPoints.hpp"

using namespace std;

TEST(graph, min_cost_connect_all_points_prim) {
    lc1584::Solution sol;

    // Test 1: example from problem
    vector<vector<int>> p1{{0,0},{2,2},{3,10},{5,2},{7,0}};
    ASSERT_EQ(20, sol.minCostConnectPoints(p1));

    // Test 2: triangle
    vector<vector<int>> p2{{3,12},{-2,5},{-4,1}};
    ASSERT_EQ(18, sol.minCostConnectPoints(p2));

    // Test 3: single point
    vector<vector<int>> p3{{0,0}};
    ASSERT_EQ(0, sol.minCostConnectPoints(p3));

    // Test 4: two points
    vector<vector<int>> p4{{0,0},{1,1}};
    ASSERT_EQ(2, sol.minCostConnectPoints(p4));

    // Test 5: collinear points
    vector<vector<int>> p5{{0,0},{1,0},{2,0},{3,0}};
    ASSERT_EQ(3, sol.minCostConnectPoints(p5));
}

TEST(graph, min_cost_connect_all_points_kruskal) {
    lc1584::Solution2 sol;

    // Test 1: example from problem
    vector<vector<int>> p1{{0,0},{2,2},{3,10},{5,2},{7,0}};
    ASSERT_EQ(20, sol.minCostConnectPoints(p1));

    // Test 2: triangle
    vector<vector<int>> p2{{3,12},{-2,5},{-4,1}};
    ASSERT_EQ(18, sol.minCostConnectPoints(p2));

    // Test 3: single point
    vector<vector<int>> p3{{0,0}};
    ASSERT_EQ(0, sol.minCostConnectPoints(p3));

    // Test 4: two points
    vector<vector<int>> p4{{0,0},{1,1}};
    ASSERT_EQ(2, sol.minCostConnectPoints(p4));

    // Test 5: collinear points
    vector<vector<int>> p5{{0,0},{1,0},{2,0},{3,0}};
    ASSERT_EQ(3, sol.minCostConnectPoints(p5));
}

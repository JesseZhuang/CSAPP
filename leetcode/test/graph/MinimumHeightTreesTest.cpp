#include "gtest/gtest.h"
#include <algorithm>
#include "graph/MinimumHeightTrees.hpp"

TEST(graph, minimum_height_trees) {
    MinimumHeightTreesSolution sol;

    // n=1, no edges
    vector<vector<int>> e1 = {};
    EXPECT_EQ((vector<int>{0}), sol.findMinHeightTrees(1, e1));

    // n=2, single edge
    vector<vector<int>> e2 = {{0, 1}};
    EXPECT_EQ((vector<int>{0, 1}), sol.findMinHeightTrees(2, e2));

    // n=4, star graph
    vector<vector<int>> e3 = {{1, 0}, {1, 2}, {1, 3}};
    EXPECT_EQ((vector<int>{1}), sol.findMinHeightTrees(4, e3));

    // n=6
    vector<vector<int>> e4 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> r4 = sol.findMinHeightTrees(6, e4);
    sort(r4.begin(), r4.end());
    EXPECT_EQ((vector<int>{3, 4}), r4);

    // n=5, path graph
    vector<vector<int>> e5 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    EXPECT_EQ((vector<int>{2}), sol.findMinHeightTrees(5, e5));

    // n=4, path graph
    vector<vector<int>> e6 = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> r6 = sol.findMinHeightTrees(4, e6);
    sort(r6.begin(), r6.end());
    EXPECT_EQ((vector<int>{1, 2}), r6);
}

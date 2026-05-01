#include "gtest/gtest.h"
#include "graph/CountUnguardedCells.hpp"
#include <vector>

using namespace std;

TEST(graph, count_unguarded_cells) {
    vector<vector<int>> g1{{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> w1{{0, 1}, {2, 2}, {1, 4}};
    EXPECT_EQ(CountUnguardedCells::countUnguarded(4, 6, g1, w1), 7);

    vector<vector<int>> g2{{1, 1}};
    vector<vector<int>> w2{{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    EXPECT_EQ(CountUnguardedCells::countUnguarded(3, 3, g2, w2), 4);
}

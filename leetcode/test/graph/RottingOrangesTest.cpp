#include "gtest/gtest.h"
#include "graph/RottingOranges.hpp"

using namespace std;

TEST(graph, rotting_oranges_example1) {
    Solution994 sol;
    vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    ASSERT_EQ(4, sol.orangesRotting(grid));
}

TEST(graph, rotting_oranges_example2) {
    Solution994 sol;
    vector<vector<int>> grid{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    ASSERT_EQ(-1, sol.orangesRotting(grid));
}

TEST(graph, rotting_oranges_example3) {
    Solution994 sol;
    vector<vector<int>> grid{{0, 2}};
    ASSERT_EQ(0, sol.orangesRotting(grid));
}

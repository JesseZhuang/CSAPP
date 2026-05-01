#include "gtest/gtest.h"
#include "graph/ZeroOneMatrix.hpp"

using namespace std;

TEST(graph, zero_one_matrix_example1) {
    Solution542 sol;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> expected = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    ASSERT_EQ(sol.updateMatrix(mat), expected);
}

TEST(graph, zero_one_matrix_example2) {
    Solution542 sol;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> expected = {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
    ASSERT_EQ(sol.updateMatrix(mat), expected);
}

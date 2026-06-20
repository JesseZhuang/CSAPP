#include "gtest/gtest.h"
#include "graph/LongestIncreasingPath.hpp"

class LongestIncreasingPathTest : public ::testing::Test {
protected:
    LongestIncreasingPathSolution sol;
};

TEST(graph, longest_increasing_path_dfs_basic) {
    LongestIncreasingPathSolution sol;
    vector<vector<int>> m1 = {{9,9,4},{6,6,8},{2,1,1}};
    EXPECT_EQ(sol.longestIncreasingPathDFS(m1), 4);

    vector<vector<int>> m2 = {{3,4,5},{3,2,6},{2,2,1}};
    EXPECT_EQ(sol.longestIncreasingPathDFS(m2), 4);

    vector<vector<int>> m3 = {{1}};
    EXPECT_EQ(sol.longestIncreasingPathDFS(m3), 1);

    vector<vector<int>> m4 = {{1,2}};
    EXPECT_EQ(sol.longestIncreasingPathDFS(m4), 2);

    vector<vector<int>> m5 = {{7,8,9},{9,7,6},{7,2,3}};
    EXPECT_EQ(sol.longestIncreasingPathDFS(m5), 6);

    vector<vector<int>> m6 = {{1,1},{1,1}};
    EXPECT_EQ(sol.longestIncreasingPathDFS(m6), 1);
}

TEST(graph, longest_increasing_path_bfs_basic) {
    LongestIncreasingPathSolution sol;
    vector<vector<int>> m1 = {{9,9,4},{6,6,8},{2,1,1}};
    EXPECT_EQ(sol.longestIncreasingPathBFS(m1), 4);

    vector<vector<int>> m2 = {{3,4,5},{3,2,6},{2,2,1}};
    EXPECT_EQ(sol.longestIncreasingPathBFS(m2), 4);

    vector<vector<int>> m3 = {{1}};
    EXPECT_EQ(sol.longestIncreasingPathBFS(m3), 1);

    vector<vector<int>> m4 = {{1,2}};
    EXPECT_EQ(sol.longestIncreasingPathBFS(m4), 2);

    vector<vector<int>> m5 = {{7,8,9},{9,7,6},{7,2,3}};
    EXPECT_EQ(sol.longestIncreasingPathBFS(m5), 6);

    vector<vector<int>> m6 = {{1,1},{1,1}};
    EXPECT_EQ(sol.longestIncreasingPathBFS(m6), 1);
}

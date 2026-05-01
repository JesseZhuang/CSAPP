#include "gtest/gtest.h"
#include "dp/GridGame.hpp"

using namespace std;

TEST(dp, grid_game_example1) {
    Solution2017 sol;
    vector<vector<int>> grid{{2, 5, 4}, {1, 5, 1}};
    ASSERT_EQ(4, sol.gridGame(grid));
}

TEST(dp, grid_game_example2) {
    Solution2017 sol;
    vector<vector<int>> grid{{3, 3, 1}, {8, 5, 2}};
    ASSERT_EQ(4, sol.gridGame(grid));
}

TEST(dp, grid_game_example3) {
    Solution2017 sol;
    vector<vector<int>> grid{{1, 3, 1, 15}, {1, 3, 3, 1}};
    ASSERT_EQ(7, sol.gridGame(grid));
}

#include "gtest/gtest.h"
#include "array/GameOfLife.hpp"

using namespace std;

TEST(array, game_of_life) {
    Solution sol;

    // Example 1
    vector<vector<int>> b1 = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    sol.gameOfLife(b1);
    EXPECT_EQ(b1, (vector<vector<int>>{{0,0,0},{1,0,1},{0,1,1},{0,1,0}}));

    // Example 2
    vector<vector<int>> b2 = {{1,1},{1,0}};
    sol.gameOfLife(b2);
    EXPECT_EQ(b2, (vector<vector<int>>{{1,1},{1,1}}));

    // Single cell alive — dies (no neighbors)
    vector<vector<int>> b3 = {{1}};
    sol.gameOfLife(b3);
    EXPECT_EQ(b3, (vector<vector<int>>{{0}}));

    // Single cell dead — stays dead
    vector<vector<int>> b4 = {{0}};
    sol.gameOfLife(b4);
    EXPECT_EQ(b4, (vector<vector<int>>{{0}}));

    // All alive 2x2 — each cell has 3 neighbors, all survive
    vector<vector<int>> b5 = {{1,1},{1,1}};
    sol.gameOfLife(b5);
    EXPECT_EQ(b5, (vector<vector<int>>{{1,1},{1,1}}));

    // Blinker oscillator: vertical → horizontal
    vector<vector<int>> b6 = {{0,1,0},{0,1,0},{0,1,0}};
    sol.gameOfLife(b6);
    EXPECT_EQ(b6, (vector<vector<int>>{{0,0,0},{1,1,1},{0,0,0}}));
}

TEST(array, game_of_life_copy) {
    Solution2 sol;

    // Example 1
    vector<vector<int>> b1 = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    sol.gameOfLife(b1);
    EXPECT_EQ(b1, (vector<vector<int>>{{0,0,0},{1,0,1},{0,1,1},{0,1,0}}));

    // Example 2
    vector<vector<int>> b2 = {{1,1},{1,0}};
    sol.gameOfLife(b2);
    EXPECT_EQ(b2, (vector<vector<int>>{{1,1},{1,1}}));

    // Blinker oscillator: vertical → horizontal
    vector<vector<int>> b6 = {{0,1,0},{0,1,0},{0,1,0}};
    sol.gameOfLife(b6);
    EXPECT_EQ(b6, (vector<vector<int>>{{0,0,0},{1,1,1},{0,0,0}}));
}

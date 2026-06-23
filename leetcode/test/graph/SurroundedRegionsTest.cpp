#include "gtest/gtest.h"
#include "graph/SurroundedRegions.hpp"

using namespace std;

TEST(graph, surrounded_regions_bfs) {
    Solution tbt;

    // Example 1: 4x4 board
    vector<vector<char>> b1 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    vector<vector<char>> e1 = {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','O','X','X'}
    };
    tbt.solveBfs(b1);
    ASSERT_EQ(e1, b1);

    // Single cell 'O' — on border, should stay
    vector<vector<char>> b2 = {{'O'}};
    vector<vector<char>> e2 = {{'O'}};
    tbt.solveBfs(b2);
    ASSERT_EQ(e2, b2);

    // 2x2 all O — all on border, no capture
    vector<vector<char>> b3 = {{'O','O'},{'O','O'}};
    vector<vector<char>> e3 = {{'O','O'},{'O','O'}};
    tbt.solveBfs(b3);
    ASSERT_EQ(e3, b3);

    // 3x3 inner surrounded
    vector<vector<char>> b4 = {
        {'X','X','X'},
        {'X','O','X'},
        {'X','X','X'}
    };
    vector<vector<char>> e4 = {
        {'X','X','X'},
        {'X','X','X'},
        {'X','X','X'}
    };
    tbt.solveBfs(b4);
    ASSERT_EQ(e4, b4);

    // Single row — all on border
    vector<vector<char>> b5 = {{'X','O','X','O','X'}};
    vector<vector<char>> e5 = {{'X','O','X','O','X'}};
    tbt.solveBfs(b5);
    ASSERT_EQ(e5, b5);

    // Connected to border — should not be captured
    vector<vector<char>> b6 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','O','X','X'}
    };
    vector<vector<char>> e6 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','O','X','X'}
    };
    tbt.solveBfs(b6);
    ASSERT_EQ(e6, b6);
}

TEST(graph, surrounded_regions_uf) {
    Solution tbt;

    // Example 1: 4x4 board
    vector<vector<char>> b1 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    vector<vector<char>> e1 = {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','O','X','X'}
    };
    tbt.solveUF(b1);
    ASSERT_EQ(e1, b1);

    // Single cell 'O' — on border, should stay
    vector<vector<char>> b2 = {{'O'}};
    vector<vector<char>> e2 = {{'O'}};
    tbt.solveUF(b2);
    ASSERT_EQ(e2, b2);

    // 2x2 all O — all on border, no capture
    vector<vector<char>> b3 = {{'O','O'},{'O','O'}};
    vector<vector<char>> e3 = {{'O','O'},{'O','O'}};
    tbt.solveUF(b3);
    ASSERT_EQ(e3, b3);

    // 3x3 inner surrounded
    vector<vector<char>> b4 = {
        {'X','X','X'},
        {'X','O','X'},
        {'X','X','X'}
    };
    vector<vector<char>> e4 = {
        {'X','X','X'},
        {'X','X','X'},
        {'X','X','X'}
    };
    tbt.solveUF(b4);
    ASSERT_EQ(e4, b4);

    // Single row — all on border
    vector<vector<char>> b5 = {{'X','O','X','O','X'}};
    vector<vector<char>> e5 = {{'X','O','X','O','X'}};
    tbt.solveUF(b5);
    ASSERT_EQ(e5, b5);

    // Connected to border — should not be captured
    vector<vector<char>> b6 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','O','X','X'}
    };
    vector<vector<char>> e6 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','O','X','X'}
    };
    tbt.solveUF(b6);
    ASSERT_EQ(e6, b6);
}

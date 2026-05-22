#include "gtest/gtest.h"
#include "graph/WordSearch.hpp"

TEST(graph, word_search) {
    WordSearch sol;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    auto b1 = board;
    EXPECT_TRUE(sol.exist(b1, "ABCCED"));

    auto b2 = board;
    EXPECT_TRUE(sol.exist(b2, "SEE"));

    auto b3 = board;
    EXPECT_FALSE(sol.exist(b3, "ABCB"));
}

TEST(graph, word_search_single_cell) {
    WordSearch sol;
    vector<vector<char>> board = {{'A'}};

    auto b1 = board;
    EXPECT_TRUE(sol.exist(b1, "A"));

    auto b2 = board;
    EXPECT_FALSE(sol.exist(b2, "B"));
}

TEST(graph, word_search_full_board) {
    WordSearch sol;
    vector<vector<char>> board = {{'A', 'B'}, {'C', 'D'}};

    auto b1 = board;
    EXPECT_TRUE(sol.exist(b1, "ABDC"));

    auto b2 = board;
    EXPECT_FALSE(sol.exist(b2, "ABCDE"));
}

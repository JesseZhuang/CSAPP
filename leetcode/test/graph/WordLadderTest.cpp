#include "gtest/gtest.h"
#include "graph/WordLadder.hpp"

// Example 1: "hit" -> "cog" with full list = 5
TEST(graph, word_ladder_bfs_example1) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(5, sol.ladderLengthBFS("hit", "cog", wordList));
}

// End word not in list = 0
TEST(graph, word_ladder_bfs_end_not_in_list) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    EXPECT_EQ(0, sol.ladderLengthBFS("hit", "cog", wordList));
}

// Single char words
TEST(graph, word_ladder_bfs_single_char) {
    WordLadderSolution sol;
    vector<string> wordList = {"a", "b", "c"};
    EXPECT_EQ(2, sol.ladderLengthBFS("a", "c", wordList));
}

// No path = 0
TEST(graph, word_ladder_bfs_no_path) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot", "dot", "dog"};
    EXPECT_EQ(0, sol.ladderLengthBFS("hit", "cog", wordList));
}

// Direct neighbor = 2
TEST(graph, word_ladder_bfs_direct_neighbor) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot"};
    EXPECT_EQ(2, sol.ladderLengthBFS("hit", "hot", wordList));
}

// Bidirectional BFS tests
TEST(graph, word_ladder_bidirectional_example1) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(5, sol.ladderLengthBidirectional("hit", "cog", wordList));
}

TEST(graph, word_ladder_bidirectional_end_not_in_list) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    EXPECT_EQ(0, sol.ladderLengthBidirectional("hit", "cog", wordList));
}

TEST(graph, word_ladder_bidirectional_single_char) {
    WordLadderSolution sol;
    vector<string> wordList = {"a", "b", "c"};
    EXPECT_EQ(2, sol.ladderLengthBidirectional("a", "c", wordList));
}

TEST(graph, word_ladder_bidirectional_no_path) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot", "dot", "dog"};
    EXPECT_EQ(0, sol.ladderLengthBidirectional("hit", "cog", wordList));
}

TEST(graph, word_ladder_bidirectional_direct_neighbor) {
    WordLadderSolution sol;
    vector<string> wordList = {"hot"};
    EXPECT_EQ(2, sol.ladderLengthBidirectional("hit", "hot", wordList));
}

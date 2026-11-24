#include "gtest/gtest.h"
#include "graph/JumpGameIII.hpp"

namespace {

void expectCanReach(std::vector<int> arr, int start, bool expected) {
    auto dfsArr = arr;
    EXPECT_EQ(expected, Solution1306BFS().canReach(arr, start)) << "BFS";
    EXPECT_EQ(expected, Solution1306DFS().canReach(dfsArr, start)) << "DFS";
}

}  // namespace

TEST(graph, jump_game_iii_example1) {
    expectCanReach({4, 2, 3, 0, 3, 1, 2}, 5, true);
}

TEST(graph, jump_game_iii_example2) {
    expectCanReach({4, 2, 3, 0, 3, 1, 2}, 0, true);
}

TEST(graph, jump_game_iii_unreachable_zero) {
    expectCanReach({3, 0, 2, 1, 2}, 2, false);
}

TEST(graph, jump_game_iii_start_is_zero) {
    expectCanReach({0}, 0, true);
}

TEST(graph, jump_game_iii_right_jump) {
    expectCanReach({2, 1, 0}, 0, true);
}

TEST(graph, jump_game_iii_left_jump) {
    expectCanReach({1, 0, 2}, 2, true);
}

TEST(graph, jump_game_iii_both_jumps_out_of_bounds) {
    expectCanReach({2, 2, 2}, 1, false);
}

TEST(graph, jump_game_iii_cycle_without_zero) {
    expectCanReach({1, 1}, 0, false);
}

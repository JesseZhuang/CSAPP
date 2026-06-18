#include "gtest/gtest.h"
#include "dp/JumpGame.hpp"

TEST(dp, jump_game_forward) {
    JumpGame sol;
    vector<int> v1 = {2, 3, 1, 1, 4};
    EXPECT_TRUE(sol.canJumpForward(v1));

    vector<int> v2 = {3, 2, 1, 0, 4};
    EXPECT_FALSE(sol.canJumpForward(v2));

    vector<int> v3 = {0};
    EXPECT_TRUE(sol.canJumpForward(v3));

    vector<int> v4 = {1, 0};
    EXPECT_TRUE(sol.canJumpForward(v4));

    vector<int> v5 = {0, 1};
    EXPECT_FALSE(sol.canJumpForward(v5));

    vector<int> v6 = {1, 0, 0, 1};
    EXPECT_FALSE(sol.canJumpForward(v6));
}

TEST(dp, jump_game_backward) {
    JumpGame sol;
    vector<int> v1 = {2, 3, 1, 1, 4};
    EXPECT_TRUE(sol.canJumpBackward(v1));

    vector<int> v2 = {3, 2, 1, 0, 4};
    EXPECT_FALSE(sol.canJumpBackward(v2));

    vector<int> v3 = {0};
    EXPECT_TRUE(sol.canJumpBackward(v3));

    vector<int> v4 = {1, 0};
    EXPECT_TRUE(sol.canJumpBackward(v4));

    vector<int> v5 = {0, 1};
    EXPECT_FALSE(sol.canJumpBackward(v5));

    vector<int> v6 = {1, 0, 0, 1};
    EXPECT_FALSE(sol.canJumpBackward(v6));
}

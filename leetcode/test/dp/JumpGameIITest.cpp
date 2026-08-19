#include "dp/JumpGameII.hpp"
#include <gtest/gtest.h>

TEST(dp, jump_game_ii) {
    JumpGameII sol;
    vector<int> v1 = {2,3,1,1,4};
    EXPECT_EQ(2, sol.jump(v1));
    EXPECT_EQ(2, sol.jumpBFS(v1));

    vector<int> v2 = {2,3,0,1,4};
    EXPECT_EQ(2, sol.jump(v2));
    EXPECT_EQ(2, sol.jumpBFS(v2));

    vector<int> v3 = {0};
    EXPECT_EQ(0, sol.jump(v3));
    EXPECT_EQ(0, sol.jumpBFS(v3));

    vector<int> v4 = {1,2};
    EXPECT_EQ(1, sol.jump(v4));
    EXPECT_EQ(1, sol.jumpBFS(v4));

    vector<int> v5 = {3,2,1};
    EXPECT_EQ(1, sol.jump(v5));
    EXPECT_EQ(1, sol.jumpBFS(v5));

    vector<int> v6 = {1,1,1,1,1};
    EXPECT_EQ(4, sol.jump(v6));
    EXPECT_EQ(4, sol.jumpBFS(v6));

    vector<int> v7 = {10,0,0,0,0};
    EXPECT_EQ(1, sol.jump(v7));
    EXPECT_EQ(1, sol.jumpBFS(v7));

    vector<int> v8 = {2,3,0,0,4};
    EXPECT_EQ(2, sol.jump(v8));
    EXPECT_EQ(2, sol.jumpBFS(v8));

    vector<int> v9 = {1,2,1,1,1};
    EXPECT_EQ(3, sol.jump(v9));
    EXPECT_EQ(3, sol.jumpBFS(v9));
}

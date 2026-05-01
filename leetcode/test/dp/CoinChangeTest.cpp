#include "gtest/gtest.h"
#include "dp/CoinChange.hpp"

TEST(dp, coin_change_dp) {
    CoinChangeDP sol;
    vector<int> c1 = {1, 2, 5};
    ASSERT_EQ(3, sol.coinChange(c1, 11));
    vector<int> c2 = {2};
    ASSERT_EQ(-1, sol.coinChange(c2, 3));
    vector<int> c3 = {1};
    ASSERT_EQ(0, sol.coinChange(c3, 0));
    vector<int> c4 = {3};
    ASSERT_EQ(2, sol.coinChange(c4, 6));
    vector<int> c5 = {3};
    ASSERT_EQ(-1, sol.coinChange(c5, 7));
    vector<int> c6 = {1, 5, 10, 25};
    ASSERT_EQ(2, sol.coinChange(c6, 30));
    vector<int> c7 = {1, 5, 6};
    ASSERT_EQ(3, sol.coinChange(c7, 15));
    vector<int> c8 = {5, 10};
    ASSERT_EQ(-1, sol.coinChange(c8, 3));
}

TEST(dp, coin_change_bfs) {
    CoinChangeBFS sol;
    vector<int> c1 = {1, 2, 5};
    ASSERT_EQ(3, sol.coinChange(c1, 11));
    vector<int> c2 = {2};
    ASSERT_EQ(-1, sol.coinChange(c2, 3));
    vector<int> c3 = {1};
    ASSERT_EQ(0, sol.coinChange(c3, 0));
    vector<int> c4 = {3};
    ASSERT_EQ(2, sol.coinChange(c4, 6));
    vector<int> c5 = {3};
    ASSERT_EQ(-1, sol.coinChange(c5, 7));
    vector<int> c6 = {1, 5, 10, 25};
    ASSERT_EQ(2, sol.coinChange(c6, 30));
    vector<int> c7 = {1, 5, 6};
    ASSERT_EQ(3, sol.coinChange(c7, 15));
    vector<int> c8 = {5, 10};
    ASSERT_EQ(-1, sol.coinChange(c8, 3));
}

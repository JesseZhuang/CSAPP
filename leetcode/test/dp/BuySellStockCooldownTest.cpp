#include "gtest/gtest.h"
#include "dp/BuySellStockCooldown.hpp"
#include <vector>

using namespace std;

namespace {
void verify(const vector<int>& prices, int expected) {
    ASSERT_EQ(expected, SolutionBuySellStockCooldown::maxProfitStateMachine(prices)) << "StateMachine";
    ASSERT_EQ(expected, SolutionBuySellStockCooldown::maxProfitDPArray(prices)) << "DPArray";
}
}

TEST(dp, buy_sell_stock_cooldown_state_machine) {
    verify({1, 2, 3, 0, 2}, 3);
    verify({1}, 0);
    verify({1, 2}, 1);
    verify({2, 1}, 0);
    verify({5, 4, 3, 2, 1}, 0);
    verify({3, 3, 3, 3}, 0);
    verify({1, 2, 3, 4}, 3);
    verify({1, 2, 3, 0, 2, 4, 0, 3}, 6);
    verify({1, 4, 2, 7}, 6);
    verify({0, 1000}, 1000);
}

TEST(dp, buy_sell_stock_cooldown_dp_array) {
    verify({1, 2, 3, 0, 2}, 3);
    verify({1}, 0);
    verify({1, 2}, 1);
    verify({2, 1}, 0);
    verify({5, 4, 3, 2, 1}, 0);
    verify({3, 3, 3, 3}, 0);
    verify({1, 2, 3, 4}, 3);
    verify({1, 2, 3, 0, 2, 4, 0, 3}, 6);
    verify({1, 4, 2, 7}, 6);
    verify({0, 1000}, 1000);
}

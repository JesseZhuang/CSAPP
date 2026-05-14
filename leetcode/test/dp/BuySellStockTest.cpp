#include "gtest/gtest.h"
#include "dp/BuySellStock.hpp"
#include <vector>

using namespace std;

namespace {
void verify(const vector<int>& prices, int expected) {
    SolutionBuySellStock sol;
    ASSERT_EQ(expected, sol.maxProfitMinPrice(prices)) << "MinPrice";
    ASSERT_EQ(expected, sol.maxProfitKadane(prices)) << "Kadane";
}
}

TEST(dp, buy_sell_stock_example1) { verify({7, 1, 5, 3, 6, 4}, 5); }
TEST(dp, buy_sell_stock_decreasing) { verify({7, 6, 4, 3, 1}, 0); }
TEST(dp, buy_sell_stock_single) { verify({5}, 0); }
TEST(dp, buy_sell_stock_two_up) { verify({1, 2}, 1); }
TEST(dp, buy_sell_stock_two_down) { verify({2, 1}, 0); }
TEST(dp, buy_sell_stock_flat) { verify({3, 3, 3, 3}, 0); }
TEST(dp, buy_sell_stock_large_gap) { verify({0, 10000}, 10000); }
TEST(dp, buy_sell_stock_valley) { verify({3, 8, 1, 9, 2}, 8); }
TEST(dp, buy_sell_stock_zigzag) { verify({1, 2, 1, 2, 1, 2}, 1); }

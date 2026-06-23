#include "gtest/gtest.h"
#include "dp/CoinChangeII.hpp"

TEST(dp, coin_change_ii) {
    CoinChangeII sol;
    vector<int> c1 = {1, 2, 5};
    ASSERT_EQ(4, sol.change(5, c1));
    vector<int> c2 = {2};
    ASSERT_EQ(0, sol.change(3, c2));
    vector<int> c3 = {10};
    ASSERT_EQ(1, sol.change(10, c3));
    vector<int> c4 = {1, 2, 5};
    ASSERT_EQ(1, sol.change(0, c4));
    vector<int> c5 = {7};
    ASSERT_EQ(1, sol.change(7, c5));
    vector<int> c6 = {3};
    ASSERT_EQ(0, sol.change(7, c6));
    vector<int> c7 = {1, 5, 10, 25};
    ASSERT_EQ(242, sol.change(100, c7));
}

TEST(dp, coin_change_ii_2d) {
    CoinChangeII2D sol;
    vector<int> c1 = {1, 2, 5};
    ASSERT_EQ(4, sol.change(5, c1));
    vector<int> c2 = {2};
    ASSERT_EQ(0, sol.change(3, c2));
    vector<int> c3 = {10};
    ASSERT_EQ(1, sol.change(10, c3));
    vector<int> c4 = {1, 2, 5};
    ASSERT_EQ(1, sol.change(0, c4));
    vector<int> c5 = {7};
    ASSERT_EQ(1, sol.change(7, c5));
    vector<int> c6 = {3};
    ASSERT_EQ(0, sol.change(7, c6));
    vector<int> c7 = {1, 5, 10, 25};
    ASSERT_EQ(242, sol.change(100, c7));
}

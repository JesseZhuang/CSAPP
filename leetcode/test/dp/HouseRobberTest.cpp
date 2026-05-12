#include "gtest/gtest.h"
#include "dp/HouseRobber.hpp"

TEST(dp, house_robber) {
    HouseRobber sol;
    vector<int> n1 = {1, 2, 3, 1};
    ASSERT_EQ(4, sol.rob(n1));
    vector<int> n2 = {2, 7, 9, 3, 1};
    ASSERT_EQ(12, sol.rob(n2));
    vector<int> n3 = {5};
    ASSERT_EQ(5, sol.rob(n3));
    vector<int> n4 = {1, 2};
    ASSERT_EQ(2, sol.rob(n4));
    vector<int> n5 = {3, 3, 3, 3};
    ASSERT_EQ(6, sol.rob(n5));
    vector<int> n6 = {100, 1, 100, 1, 100};
    ASSERT_EQ(300, sol.rob(n6));
    vector<int> n7 = {};
    ASSERT_EQ(0, sol.rob(n7));
}

TEST(dp, house_robber_dp_array) {
    HouseRobberDP sol;
    vector<int> n1 = {1, 2, 3, 1};
    ASSERT_EQ(4, sol.rob(n1));
    vector<int> n2 = {2, 7, 9, 3, 1};
    ASSERT_EQ(12, sol.rob(n2));
    vector<int> n3 = {5};
    ASSERT_EQ(5, sol.rob(n3));
    vector<int> n4 = {1, 2};
    ASSERT_EQ(2, sol.rob(n4));
    vector<int> n5 = {3, 3, 3, 3};
    ASSERT_EQ(6, sol.rob(n5));
    vector<int> n6 = {100, 1, 100, 1, 100};
    ASSERT_EQ(300, sol.rob(n6));
    vector<int> n7 = {};
    ASSERT_EQ(0, sol.rob(n7));
}

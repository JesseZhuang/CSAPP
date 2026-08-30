#include "gtest/gtest.h"
#include "dp/HouseRobberII.hpp"

TEST(dp, house_robber_ii) {
    HouseRobberII sol;
    vector<int> n1 = {2, 3, 2};
    ASSERT_EQ(3, sol.rob(n1));
    vector<int> n2 = {1, 2, 3, 1};
    ASSERT_EQ(4, sol.rob(n2));
    vector<int> n3 = {1, 2, 3};
    ASSERT_EQ(3, sol.rob(n3));
    vector<int> n4 = {5};
    ASSERT_EQ(5, sol.rob(n4));
    vector<int> n5 = {1, 2};
    ASSERT_EQ(2, sol.rob(n5));
    vector<int> n6 = {3, 3};
    ASSERT_EQ(3, sol.rob(n6));
    vector<int> n7 = {3, 3, 3, 3};
    ASSERT_EQ(6, sol.rob(n7));
    vector<int> n8 = {1000, 1, 1000, 1};
    ASSERT_EQ(2000, sol.rob(n8)); // circular: pick 1000+1000 from [1,n)
    vector<int> n9 = {0, 0, 0, 0};
    ASSERT_EQ(0, sol.rob(n9));
    vector<int> n10 = {1, 2, 3, 4, 5};
    ASSERT_EQ(8, sol.rob(n10)); // 3+5=8 from [1,n)
}

#include "gtest/gtest.h"
#include "array/TrappingRainWater.hpp"

using namespace std;

TEST(array, trapping_rain_water) {
    Solution sol;

    vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    EXPECT_EQ(6, sol.trap(h1));

    vector<int> h2 = {4,2,0,3,2,5};
    EXPECT_EQ(9, sol.trap(h2));

    vector<int> h3 = {};
    EXPECT_EQ(0, sol.trap(h3));

    vector<int> h4 = {5};
    EXPECT_EQ(0, sol.trap(h4));

    vector<int> h5 = {3,0,3};
    EXPECT_EQ(3, sol.trap(h5));

    vector<int> h6 = {5,4,3,2,1};
    EXPECT_EQ(0, sol.trap(h6));

    vector<int> h7 = {1,2,3,4,5};
    EXPECT_EQ(0, sol.trap(h7));

    vector<int> h8 = {2,2,2,2};
    EXPECT_EQ(0, sol.trap(h8));

    vector<int> h9 = {5,0,0,0,5};
    EXPECT_EQ(15, sol.trap(h9));

    vector<int> h10 = {3,0,2,0,4};
    EXPECT_EQ(7, sol.trap(h10));
}

TEST(array, trapping_rain_water_stack) {
    Solution2 sol;

    vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    EXPECT_EQ(6, sol.trap(h1));

    vector<int> h2 = {4,2,0,3,2,5};
    EXPECT_EQ(9, sol.trap(h2));

    vector<int> h3 = {};
    EXPECT_EQ(0, sol.trap(h3));

    vector<int> h4 = {5};
    EXPECT_EQ(0, sol.trap(h4));

    vector<int> h5 = {3,0,3};
    EXPECT_EQ(3, sol.trap(h5));

    vector<int> h6 = {5,4,3,2,1};
    EXPECT_EQ(0, sol.trap(h6));

    vector<int> h7 = {1,2,3,4,5};
    EXPECT_EQ(0, sol.trap(h7));

    vector<int> h8 = {2,2,2,2};
    EXPECT_EQ(0, sol.trap(h8));

    vector<int> h9 = {5,0,0,0,5};
    EXPECT_EQ(15, sol.trap(h9));

    vector<int> h10 = {3,0,2,0,4};
    EXPECT_EQ(7, sol.trap(h10));
}

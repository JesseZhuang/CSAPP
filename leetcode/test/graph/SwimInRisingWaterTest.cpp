#include "gtest/gtest.h"
#include "graph/SwimInRisingWater.hpp"

using namespace std;

TEST(graph, swim_in_rising_water) {
    Solution778Heap sol;

    vector<vector<int>> g1{{0, 2}, {1, 3}};
    ASSERT_EQ(3, sol.swimInWater(g1));

    vector<vector<int>> g2{
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    ASSERT_EQ(16, sol.swimInWater(g2));

    vector<vector<int>> g3{{0}};
    ASSERT_EQ(0, sol.swimInWater(g3));

    vector<vector<int>> g4{{0, 1}, {3, 2}};
    ASSERT_EQ(2, sol.swimInWater(g4));

    vector<vector<int>> g5{{3, 2}, {0, 1}};
    ASSERT_EQ(3, sol.swimInWater(g5));
}

TEST(graph, swim_in_rising_water_bs) {
    Solution778BS sol;

    vector<vector<int>> g1{{0, 2}, {1, 3}};
    ASSERT_EQ(3, sol.swimInWaterBS(g1));

    vector<vector<int>> g2{
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    ASSERT_EQ(16, sol.swimInWaterBS(g2));

    vector<vector<int>> g3{{0}};
    ASSERT_EQ(0, sol.swimInWaterBS(g3));

    vector<vector<int>> g4{{0, 1}, {3, 2}};
    ASSERT_EQ(2, sol.swimInWaterBS(g4));

    vector<vector<int>> g5{{3, 2}, {0, 1}};
    ASSERT_EQ(3, sol.swimInWaterBS(g5));
}

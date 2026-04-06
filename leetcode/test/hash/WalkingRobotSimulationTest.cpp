#include "gtest/gtest.h"
#include "hash/WalkingRobotSimulation.hpp"

TEST(hash, walking_robot_simulation) {
    Solution tbt;

    vector<int> c1 = {4, -1, 3};
    vector<vector<int>> o1 = {};
    ASSERT_EQ(25, tbt.robotSim(c1, o1));

    vector<int> c2 = {4, -1, 4, -2, 4};
    vector<vector<int>> o2 = {{2, 4}};
    ASSERT_EQ(65, tbt.robotSim(c2, o2));

    vector<int> c3 = {6, -1, -1, 6};
    vector<vector<int>> o3 = {{0, 0}};
    ASSERT_EQ(36, tbt.robotSim(c3, o3));

    vector<int> c4 = {-2, -1, -2, -1};
    vector<vector<int>> o4 = {};
    ASSERT_EQ(0, tbt.robotSim(c4, o4));

    vector<int> c5 = {1};
    vector<vector<int>> o5 = {};
    ASSERT_EQ(1, tbt.robotSim(c5, o5));

    vector<int> c6 = {4};
    vector<vector<int>> o6 = {{0, 1}};
    ASSERT_EQ(0, tbt.robotSim(c6, o6));

    vector<int> c7 = {4, -1, 3, -1, 2, -1, 1};
    vector<vector<int>> o7 = {};
    ASSERT_EQ(25, tbt.robotSim(c7, o7));

    vector<int> c8 = {-2, 3};
    vector<vector<int>> o8 = {};
    ASSERT_EQ(9, tbt.robotSim(c8, o8));

    vector<int> c9 = {9, -1, 9};
    vector<vector<int>> o9 = {{0, 3}, {3, 2}};
    ASSERT_EQ(8, tbt.robotSim(c9, o9));
}

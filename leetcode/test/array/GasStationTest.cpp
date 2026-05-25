#include "gtest/gtest.h"
#include "array/GasStation.hpp"

using namespace std;

TEST(array, gas_station) {
    Solution sol;

    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    EXPECT_EQ(3, sol.canCompleteCircuit(gas1, cost1));

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    EXPECT_EQ(-1, sol.canCompleteCircuit(gas2, cost2));

    vector<int> gas3 = {5};
    vector<int> cost3 = {3};
    EXPECT_EQ(0, sol.canCompleteCircuit(gas3, cost3));

    vector<int> gas4 = {3};
    vector<int> cost4 = {5};
    EXPECT_EQ(-1, sol.canCompleteCircuit(gas4, cost4));

    vector<int> gas5 = {4};
    vector<int> cost5 = {4};
    EXPECT_EQ(0, sol.canCompleteCircuit(gas5, cost5));

    vector<int> gas6 = {0,0,0};
    vector<int> cost6 = {0,0,0};
    EXPECT_EQ(0, sol.canCompleteCircuit(gas6, cost6));

    vector<int> gas7 = {10000,0,0,0};
    vector<int> cost7 = {0,5000,3000,2000};
    EXPECT_EQ(0, sol.canCompleteCircuit(gas7, cost7));
}

TEST(array, gas_station_brute) {
    Solution2 sol;

    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    EXPECT_EQ(3, sol.canCompleteCircuitBrute(gas1, cost1));

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    EXPECT_EQ(-1, sol.canCompleteCircuitBrute(gas2, cost2));

    vector<int> gas3 = {5};
    vector<int> cost3 = {3};
    EXPECT_EQ(0, sol.canCompleteCircuitBrute(gas3, cost3));

    vector<int> gas4 = {3};
    vector<int> cost4 = {5};
    EXPECT_EQ(-1, sol.canCompleteCircuitBrute(gas4, cost4));

    vector<int> gas5 = {4};
    vector<int> cost5 = {4};
    EXPECT_EQ(0, sol.canCompleteCircuitBrute(gas5, cost5));

    vector<int> gas6 = {0,0,0};
    vector<int> cost6 = {0,0,0};
    EXPECT_EQ(0, sol.canCompleteCircuitBrute(gas6, cost6));

    vector<int> gas7 = {10000,0,0,0};
    vector<int> cost7 = {0,5000,3000,2000};
    EXPECT_EQ(0, sol.canCompleteCircuitBrute(gas7, cost7));
}

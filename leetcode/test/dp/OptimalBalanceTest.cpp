#include "gtest/gtest.h"
#include "dp/OptimalBalance.hpp"

#include <vector>

using namespace std;

TEST(dp, optimal_balance) {
    Solution tbt;
    Solution2 tbt2;
    vector<vector<vector<int>>> cases = {
            {{0, 1, 10},  {1, 2, 15},  {2, 3, 10}},
            {{0, 1, 100}, {0, 2, 100}, {1, 2, 1}, {1, 3, 100}, {2, 3, 100}},
            {{0, 1, 10},  {2, 0, 5}},
            {{0, 1, 10},  {1, 0, 1},   {1, 2, 5}, {2, 0, 5}}
    };
    vector<int> exp = {
            2,
            2,
            2,
            1
    };
    for (int i = 0; i < cases.size(); i++) {
        ASSERT_EQ(tbt.minTransfers(cases[i]), exp[i]);
        ASSERT_EQ(tbt2.minTransfers(cases[i]), exp[i]);
    }
}

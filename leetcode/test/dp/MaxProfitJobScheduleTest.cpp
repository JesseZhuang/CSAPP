#include "gtest/gtest.h"
#include "dp/MaxProfitJobSchedule.hpp"

#include <vector>

using namespace std;

TEST(dp, max_profit_job_schedule) {
    Solution tbt;
    Solution2 tbt2;
    vector<vector<vector<int>>> cases = {
            {{1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}},
            {{1, 2, 3, 4, 6}, {3, 5, 10, 6, 9}, {20, 20, 100, 70, 60}},
            {{1, 1, 1}, {2, 3, 4}, {5, 6, 4}},
            {{1}, {2}, {50}},
            {{1, 3, 5}, {2, 4, 6}, {10, 20, 30}},
            {{1, 1, 1}, {10, 10, 10}, {5, 6, 4}},
            {{1, 2, 3}, {2, 3, 4}, {10, 20, 30}},
            {{1, 2, 4}, {3, 5, 6}, {60, 10, 70}},
            {{1, 1000000000}, {1000000000, 1000000001}, {100, 200}},
    };
    vector<int> exp = {120, 150, 6, 50, 60, 6, 60, 130, 300};
    for (size_t i = 0; i < cases.size(); i++) {
        vector<int> st = cases[i][0];
        vector<int> en = cases[i][1];
        vector<int> pr = cases[i][2];
        ASSERT_EQ(tbt.jobScheduling(st, en, pr), exp[i]);
        ASSERT_EQ(tbt2.jobScheduling(st, en, pr), exp[i]);
    }
}

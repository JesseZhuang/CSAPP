#include "stack/DailyTemperatures.hpp"
#include <gtest/gtest.h>

TEST(stack, daily_temperatures) {
    DailyTemperatures::Solution sol;
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    EXPECT_EQ(sol.dailyTemperatures(t1), vector<int>({1, 1, 4, 2, 1, 1, 0, 0}));

    vector<int> t2 = {30, 40, 50, 60};
    EXPECT_EQ(sol.dailyTemperatures(t2), vector<int>({1, 1, 1, 0}));

    vector<int> t3 = {30, 60, 90};
    EXPECT_EQ(sol.dailyTemperatures(t3), vector<int>({1, 1, 0}));

    vector<int> t4 = {50};
    EXPECT_EQ(sol.dailyTemperatures(t4), vector<int>({0}));

    vector<int> t5 = {90, 80, 70, 60};
    EXPECT_EQ(sol.dailyTemperatures(t5), vector<int>({0, 0, 0, 0}));

    vector<int> t6 = {70, 70, 70};
    EXPECT_EQ(sol.dailyTemperatures(t6), vector<int>({0, 0, 0}));

    vector<int> t7 = {30, 30, 30, 30, 31};
    EXPECT_EQ(sol.dailyTemperatures(t7), vector<int>({4, 3, 2, 1, 0}));
}

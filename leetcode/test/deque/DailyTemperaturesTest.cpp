#include "gtest/gtest.h"
#include "deque/DailyTemperatures.hpp"

using namespace std;

TEST(deque, daily_temperatures) {
    Solution739 tbt;
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    ASSERT_EQ(vector<int>({1, 1, 4, 2, 1, 1, 0, 0}), tbt.dailyTemperatures(t1));

    vector<int> t2 = {30, 40, 50, 60};
    ASSERT_EQ(vector<int>({1, 1, 1, 0}), tbt.dailyTemperatures(t2));

    vector<int> t3 = {30, 60, 90};
    ASSERT_EQ(vector<int>({1, 1, 0}), tbt.dailyTemperatures(t3));

    vector<int> t4 = {50};
    ASSERT_EQ(vector<int>({0}), tbt.dailyTemperatures(t4));

    vector<int> t5 = {90, 80, 70, 60};
    ASSERT_EQ(vector<int>({0, 0, 0, 0}), tbt.dailyTemperatures(t5));

    vector<int> t6 = {70, 70, 70};
    ASSERT_EQ(vector<int>({0, 0, 0}), tbt.dailyTemperatures(t6));
}

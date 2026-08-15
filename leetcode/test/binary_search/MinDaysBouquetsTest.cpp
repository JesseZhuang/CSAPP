#include <gtest/gtest.h>
#include "binary_search/MinDaysBouquets.hpp"

TEST(binary_search, min_days_bouquets) {
    Solution s;

    vector<int> v1 = {1, 10, 3, 10, 2};
    EXPECT_EQ(3, s.minDays(v1, 3, 1));

    vector<int> v2 = {1, 10, 3, 10, 2};
    EXPECT_EQ(-1, s.minDays(v2, 3, 2));

    vector<int> v3 = {7, 7, 7, 7, 12, 7, 7};
    EXPECT_EQ(12, s.minDays(v3, 2, 3));

    vector<int> v4 = {5, 5, 5, 5};
    EXPECT_EQ(5, s.minDays(v4, 2, 2));

    vector<int> v5 = {1};
    EXPECT_EQ(1, s.minDays(v5, 1, 1));

    vector<int> v6 = {1, 2, 3};
    EXPECT_EQ(-1, s.minDays(v6, 2, 2));

    vector<int> v7 = {1000000000, 1000000000};
    EXPECT_EQ(1000000000, s.minDays(v7, 1, 2));

    vector<int> v8 = {1, 1, 1, 1};
    EXPECT_EQ(1, s.minDays(v8, 2, 2));
}

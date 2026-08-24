#include <gtest/gtest.h>
#include "binary_search/CapacityShipPackages.hpp"

TEST(binary_search, capacity_ship_packages) {
    Solution s;

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(15, s.shipWithinDays(v1, 5));

    vector<int> v2 = {3, 2, 2, 4, 1, 4};
    EXPECT_EQ(6, s.shipWithinDays(v2, 3));

    vector<int> v3 = {1, 2, 3, 1, 1};
    EXPECT_EQ(3, s.shipWithinDays(v3, 4));

    vector<int> v4 = {5};
    EXPECT_EQ(5, s.shipWithinDays(v4, 1));

    vector<int> v5 = {1, 2, 3, 4, 5};
    EXPECT_EQ(15, s.shipWithinDays(v5, 1));

    vector<int> v6 = {3, 3, 3, 3, 3, 3};
    EXPECT_EQ(6, s.shipWithinDays(v6, 3));

    vector<int> v7 = {1, 1, 1, 500};
    EXPECT_EQ(500, s.shipWithinDays(v7, 2));
}

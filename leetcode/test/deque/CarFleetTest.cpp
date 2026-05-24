#include "gtest/gtest.h"
#include "deque/CarFleet.hpp"

using namespace std;

TEST(deque, car_fleet) {
    Solution853 tbt;

    vector<int> p1 = {10, 8, 0, 5, 3}, s1 = {2, 4, 1, 1, 3};
    ASSERT_EQ(3, tbt.carFleet(12, p1, s1));

    vector<int> p2 = {3}, s2 = {3};
    ASSERT_EQ(1, tbt.carFleet(10, p2, s2));

    vector<int> p3 = {0, 2, 4}, s3 = {4, 2, 1};
    ASSERT_EQ(1, tbt.carFleet(100, p3, s3));

    vector<int> p4 = {1, 4, 7}, s4 = {2, 2, 2};
    ASSERT_EQ(3, tbt.carFleet(10, p4, s4));

    vector<int> p5 = {50}, s5 = {10};
    ASSERT_EQ(1, tbt.carFleet(100, p5, s5));
}

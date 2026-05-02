#include "gtest/gtest.h"
#include "deque/AsteroidCollision.hpp"

using namespace std;

TEST(deque, asteroid_collision) {
    Solution735 tbt;

    vector<int> t1 = {5, 10, -5};
    ASSERT_EQ(vector<int>({5, 10}), tbt.asteroidCollision(t1));

    vector<int> t2 = {8, -8};
    ASSERT_EQ(vector<int>({}), tbt.asteroidCollision(t2));

    vector<int> t3 = {10, 2, -5};
    ASSERT_EQ(vector<int>({10}), tbt.asteroidCollision(t3));

    vector<int> t4 = {1, 2, 3, 4};
    ASSERT_EQ(vector<int>({1, 2, 3, 4}), tbt.asteroidCollision(t4));

    vector<int> t5 = {-4, -3, -2, -1};
    ASSERT_EQ(vector<int>({-4, -3, -2, -1}), tbt.asteroidCollision(t5));

    vector<int> t6 = {1};
    ASSERT_EQ(vector<int>({1}), tbt.asteroidCollision(t6));

    vector<int> t7 = {1, 2, 3, -10};
    ASSERT_EQ(vector<int>({-10}), tbt.asteroidCollision(t7));

    vector<int> t8 = {-2, -1, 1, 2};
    ASSERT_EQ(vector<int>({-2, -1, 1, 2}), tbt.asteroidCollision(t8));

    vector<int> t9 = {10, -5, -10};
    ASSERT_EQ(vector<int>({}), tbt.asteroidCollision(t9));

    vector<int> t10 = {1, -1, 2, -2};
    ASSERT_EQ(vector<int>({}), tbt.asteroidCollision(t10));

    vector<int> t11 = {-2, 1, -1, 2};
    ASSERT_EQ(vector<int>({-2, 2}), tbt.asteroidCollision(t11));
}

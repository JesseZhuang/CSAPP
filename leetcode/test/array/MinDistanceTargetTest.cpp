#include "gtest/gtest.h"
#include "array/MinDistanceTarget.hpp"

using namespace std;

TEST(array, min_distance_target) {
    Solution sol;

    vector<int> v1 = {1, 2, 3, 4, 5};
    ASSERT_EQ(1, sol.getMinDistance(v1, 5, 3));

    vector<int> v2 = {1};
    ASSERT_EQ(0, sol.getMinDistance(v2, 1, 0));

    vector<int> v3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_EQ(0, sol.getMinDistance(v3, 1, 0));

    vector<int> v4 = {5, 1, 2, 3, 4};
    ASSERT_EQ(0, sol.getMinDistance(v4, 5, 0));

    vector<int> v5 = {1, 2, 3, 4, 5};
    ASSERT_EQ(4, sol.getMinDistance(v5, 5, 0));

    vector<int> v6 = {1, 2, 3, 2, 1};
    ASSERT_EQ(1, sol.getMinDistance(v6, 2, 2));

    vector<int> v7 = {3, 1, 1, 1, 3};
    ASSERT_EQ(2, sol.getMinDistance(v7, 3, 2));

    vector<int> v8 = {7, 7, 7};
    ASSERT_EQ(0, sol.getMinDistance(v8, 7, 1));
}

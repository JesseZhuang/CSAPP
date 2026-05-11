#include "gtest/gtest.h"
#include "heap/KClosestPointsToOrigin.hpp"

#include <algorithm>

using namespace std;

static void sortPoints(vector<vector<int>> &pts) {
    sort(pts.begin(), pts.end());
}

TEST(heap, k_closest_points_to_origin) {
    Solution sol;

    vector<vector<int>> p1 = {{1,3},{-2,2}};
    auto r1 = sol.kClosest(p1, 1);
    sortPoints(r1);
    ASSERT_EQ(r1, (vector<vector<int>>{{-2,2}}));

    vector<vector<int>> p2 = {{3,3},{5,-1},{-2,4}};
    auto r2 = sol.kClosest(p2, 2);
    sortPoints(r2);
    ASSERT_EQ(r2, (vector<vector<int>>{{-2,4},{3,3}}));

    vector<vector<int>> p3 = {{0,1},{1,0}};
    auto r3 = sol.kClosest(p3, 2);
    sortPoints(r3);
    ASSERT_EQ(r3, (vector<vector<int>>{{0,1},{1,0}}));
}

TEST(heap, k_closest_points_to_origin_quickselect) {
    Solution2 sol;

    vector<vector<int>> p1 = {{1,3},{-2,2}};
    auto r1 = sol.kClosest(p1, 1);
    sortPoints(r1);
    ASSERT_EQ(r1, (vector<vector<int>>{{-2,2}}));

    vector<vector<int>> p2 = {{3,3},{5,-1},{-2,4}};
    auto r2 = sol.kClosest(p2, 2);
    sortPoints(r2);
    ASSERT_EQ(r2, (vector<vector<int>>{{-2,4},{3,3}}));

    vector<vector<int>> p3 = {{0,1},{1,0}};
    auto r3 = sol.kClosest(p3, 2);
    sortPoints(r3);
    ASSERT_EQ(r3, (vector<vector<int>>{{0,1},{1,0}}));
}

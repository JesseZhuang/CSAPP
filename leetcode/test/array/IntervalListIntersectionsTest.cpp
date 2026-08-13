#include "gtest/gtest.h"
#include "array/IntervalListIntersections.hpp"

TEST(array, interval_list_intersections) {
    IntervalListIntersections sol;

    // LeetCode example 1
    {
        vector<vector<int>> first = {{0,2},{5,10},{13,23},{24,25}};
        vector<vector<int>> second = {{1,5},{8,12},{15,24},{25,26}};
        vector<vector<int>> expected = {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}};
        EXPECT_EQ(sol.intervalIntersection(first, second), expected);
    }

    // LeetCode example 2 - empty list
    {
        vector<vector<int>> first = {{1,3},{5,9}};
        vector<vector<int>> second = {};
        vector<vector<int>> expected = {};
        EXPECT_EQ(sol.intervalIntersection(first, second), expected);
    }

    // No intersection
    {
        vector<vector<int>> first = {{1,2},{5,6}};
        vector<vector<int>> second = {{3,4},{7,8}};
        vector<vector<int>> expected = {};
        EXPECT_EQ(sol.intervalIntersection(first, second), expected);
    }

    // Full overlap
    {
        vector<vector<int>> first = {{1,5}};
        vector<vector<int>> second = {{1,5}};
        vector<vector<int>> expected = {{1,5}};
        EXPECT_EQ(sol.intervalIntersection(first, second), expected);
    }

    // One contains other
    {
        vector<vector<int>> first = {{0,10}};
        vector<vector<int>> second = {{2,5}};
        vector<vector<int>> expected = {{2,5}};
        EXPECT_EQ(sol.intervalIntersection(first, second), expected);
    }

    // Touching endpoints
    {
        vector<vector<int>> first = {{1,3}};
        vector<vector<int>> second = {{3,5}};
        vector<vector<int>> expected = {{3,3}};
        EXPECT_EQ(sol.intervalIntersection(first, second), expected);
    }
}

#include "gtest/gtest.h"
#include "array/NonOverlapIntervals.hpp"

TEST(array, non_overlap_intervals) {
    vector<vector<int>> v1 = {{1,2},{2,3},{3,4},{1,3}};
    EXPECT_EQ(1, NonOverlapIntervals::eraseOverlapIntervals(v1));

    vector<vector<int>> v2 = {{1,2},{1,2},{1,2}};
    EXPECT_EQ(2, NonOverlapIntervals::eraseOverlapIntervals(v2));

    vector<vector<int>> v3 = {{1,2},{2,3}};
    EXPECT_EQ(0, NonOverlapIntervals::eraseOverlapIntervals(v3));

    vector<vector<int>> v4 = {{1,5}};
    EXPECT_EQ(0, NonOverlapIntervals::eraseOverlapIntervals(v4));

    vector<vector<int>> v5 = {{1,4},{2,5},{3,6}};
    EXPECT_EQ(2, NonOverlapIntervals::eraseOverlapIntervals(v5));

    vector<vector<int>> v6 = {{1,10},{2,3},{4,5},{6,7}};
    EXPECT_EQ(1, NonOverlapIntervals::eraseOverlapIntervals(v6));

    vector<vector<int>> v7 = {{-5,-3},{-4,-1},{0,2}};
    EXPECT_EQ(1, NonOverlapIntervals::eraseOverlapIntervals(v7));
}

TEST(array, non_overlap_intervals2) {
    vector<vector<int>> v1 = {{1,2},{2,3},{3,4},{1,3}};
    EXPECT_EQ(1, NonOverlapIntervals::eraseOverlapIntervals2(v1));

    vector<vector<int>> v2 = {{1,2},{1,2},{1,2}};
    EXPECT_EQ(2, NonOverlapIntervals::eraseOverlapIntervals2(v2));

    vector<vector<int>> v3 = {{1,2},{2,3}};
    EXPECT_EQ(0, NonOverlapIntervals::eraseOverlapIntervals2(v3));

    vector<vector<int>> v4 = {{1,5}};
    EXPECT_EQ(0, NonOverlapIntervals::eraseOverlapIntervals2(v4));

    vector<vector<int>> v5 = {{1,4},{2,5},{3,6}};
    EXPECT_EQ(2, NonOverlapIntervals::eraseOverlapIntervals2(v5));

    vector<vector<int>> v6 = {{1,10},{2,3},{4,5},{6,7}};
    EXPECT_EQ(1, NonOverlapIntervals::eraseOverlapIntervals2(v6));

    vector<vector<int>> v7 = {{-5,-3},{-4,-1},{0,2}};
    EXPECT_EQ(1, NonOverlapIntervals::eraseOverlapIntervals2(v7));
}

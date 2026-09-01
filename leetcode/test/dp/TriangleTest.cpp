#include "gtest/gtest.h"
#include "dp/Triangle.hpp"

TEST(dp, triangle_dp) {
    TriangleDP sol;
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    ASSERT_EQ(11, sol.minimumTotal(t1));
    vector<vector<int>> t2 = {{-10}};
    ASSERT_EQ(-10, sol.minimumTotal(t2));
    vector<vector<int>> t3 = {{1}, {2, 3}};
    ASSERT_EQ(3, sol.minimumTotal(t3));
    vector<vector<int>> t4 = {{-1}, {2, 3}, {1, -1, -3}};
    ASSERT_EQ(-1, sol.minimumTotal(t4));
    vector<vector<int>> t5 = {{0}, {0, 0}, {0, 0, 0}};
    ASSERT_EQ(0, sol.minimumTotal(t5));
    vector<vector<int>> t6 = {{100}, {-200, 300}, {400, -500, 600}};
    ASSERT_EQ(-600, sol.minimumTotal(t6));
    vector<vector<int>> t7 = {{1}, {2, 3}, {4, 3, 1}};
    ASSERT_EQ(5, sol.minimumTotal(t7));
}

TEST(dp, triangle_in_place) {
    TriangleInPlace sol;
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    ASSERT_EQ(11, sol.minimumTotal(t1));
    vector<vector<int>> t2 = {{-10}};
    ASSERT_EQ(-10, sol.minimumTotal(t2));
    vector<vector<int>> t3 = {{1}, {2, 3}};
    ASSERT_EQ(3, sol.minimumTotal(t3));
    vector<vector<int>> t4 = {{-1}, {2, 3}, {1, -1, -3}};
    ASSERT_EQ(-1, sol.minimumTotal(t4));
    vector<vector<int>> t5 = {{0}, {0, 0}, {0, 0, 0}};
    ASSERT_EQ(0, sol.minimumTotal(t5));
    vector<vector<int>> t6 = {{100}, {-200, 300}, {400, -500, 600}};
    ASSERT_EQ(-600, sol.minimumTotal(t6));
    vector<vector<int>> t7 = {{1}, {2, 3}, {4, 3, 1}};
    ASSERT_EQ(5, sol.minimumTotal(t7));
}

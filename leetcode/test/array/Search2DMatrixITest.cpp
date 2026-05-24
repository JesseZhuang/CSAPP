#include "gtest/gtest.h"
#include "array/Search2DMatrixI.hpp"
#include <vector>

using namespace std;

TEST(array, search_2d_matrix_i_flattened) {
    Solution sol;
    vector<vector<int>> m1{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    ASSERT_TRUE(sol.searchMatrix1(m1, 3));
    ASSERT_FALSE(sol.searchMatrix1(m1, 13));
    ASSERT_TRUE(sol.searchMatrix1(m1, 1));   // first element
    ASSERT_TRUE(sol.searchMatrix1(m1, 60));  // last element
    ASSERT_FALSE(sol.searchMatrix1(m1, -1)); // smaller than all
    ASSERT_FALSE(sol.searchMatrix1(m1, 100));// larger than all

    vector<vector<int>> m2{{1}};
    ASSERT_TRUE(sol.searchMatrix1(m2, 1));
    ASSERT_FALSE(sol.searchMatrix1(m2, 0));
}

TEST(array, search_2d_matrix_i_two_binary) {
    Solution sol;
    vector<vector<int>> m1{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    ASSERT_TRUE(sol.searchMatrix2(m1, 3));
    ASSERT_FALSE(sol.searchMatrix2(m1, 13));
    ASSERT_TRUE(sol.searchMatrix2(m1, 1));   // first element
    ASSERT_TRUE(sol.searchMatrix2(m1, 60));  // last element
    ASSERT_FALSE(sol.searchMatrix2(m1, -1)); // smaller than all
    ASSERT_FALSE(sol.searchMatrix2(m1, 100));// larger than all

    vector<vector<int>> m2{{1}};
    ASSERT_TRUE(sol.searchMatrix2(m2, 1));
    ASSERT_FALSE(sol.searchMatrix2(m2, 0));
}

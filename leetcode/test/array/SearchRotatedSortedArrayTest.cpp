#include "gtest/gtest.h"
#include "array/SearchRotatedSortedArray.hpp"

using namespace std;

TEST(array, search_rotated_sorted_array) {
    Solution sol;
    vector<int> v1{4, 5, 6, 7, 0, 1, 2};
    ASSERT_EQ(4, sol.search(v1, 0));
    ASSERT_EQ(-1, sol.search(v1, 3));
    vector<int> v2{1};
    ASSERT_EQ(-1, sol.search(v2, 0));
    ASSERT_EQ(0, sol.search(v2, 1));
    vector<int> v3{3, 1};
    ASSERT_EQ(1, sol.search(v3, 1));
    ASSERT_EQ(0, sol.search(v3, 3));
    vector<int> v4{5, 1, 3};
    ASSERT_EQ(0, sol.search(v4, 5));
    vector<int> v5{2, 3, 4, 5, 1};
    ASSERT_EQ(4, sol.search(v5, 1));
    vector<int> v6{1, 2, 3, 4, 5};
    ASSERT_EQ(2, sol.search(v6, 3));
    vector<int> v7{4, 5, 6, 7, 8, 1, 2, 3};
    ASSERT_EQ(4, sol.search(v7, 8));
}

TEST(array, search_rotated_sorted_array_two_pass) {
    Solution2 sol;
    vector<int> v1{4, 5, 6, 7, 0, 1, 2};
    ASSERT_EQ(4, sol.search(v1, 0));
    ASSERT_EQ(-1, sol.search(v1, 3));
    vector<int> v2{1};
    ASSERT_EQ(-1, sol.search(v2, 0));
    ASSERT_EQ(0, sol.search(v2, 1));
    vector<int> v3{3, 1};
    ASSERT_EQ(1, sol.search(v3, 1));
    ASSERT_EQ(0, sol.search(v3, 3));
    vector<int> v4{5, 1, 3};
    ASSERT_EQ(0, sol.search(v4, 5));
    vector<int> v5{2, 3, 4, 5, 1};
    ASSERT_EQ(4, sol.search(v5, 1));
    vector<int> v6{1, 2, 3, 4, 5};
    ASSERT_EQ(2, sol.search(v6, 3));
    vector<int> v7{4, 5, 6, 7, 8, 1, 2, 3};
    ASSERT_EQ(4, sol.search(v7, 8));
}

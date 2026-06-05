#include "gtest/gtest.h"
#include "array/FindMinRotatedSortedArray.hpp"

TEST(array, find_min_rotated_sorted_array) {
    FindMinRotatedSortedArray::Solution1 s1;
    FindMinRotatedSortedArray::Solution2 s2;

    vector<int> t1 = {3, 4, 5, 1, 2};
    EXPECT_EQ(s1.findMin(t1), 1);
    EXPECT_EQ(s2.findMin(t1), 1);

    vector<int> t2 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(s1.findMin(t2), 0);
    EXPECT_EQ(s2.findMin(t2), 0);

    vector<int> t3 = {11, 13, 15, 17};
    EXPECT_EQ(s1.findMin(t3), 11);
    EXPECT_EQ(s2.findMin(t3), 11);

    vector<int> t4 = {1};
    EXPECT_EQ(s1.findMin(t4), 1);
    EXPECT_EQ(s2.findMin(t4), 1);

    vector<int> t5 = {2, 1};
    EXPECT_EQ(s1.findMin(t5), 1);
    EXPECT_EQ(s2.findMin(t5), 1);

    vector<int> t6 = {1, 2};
    EXPECT_EQ(s1.findMin(t6), 1);
    EXPECT_EQ(s2.findMin(t6), 1);

    vector<int> t7 = {7, 1, 2, 3, 4, 5, 6};
    EXPECT_EQ(s1.findMin(t7), 1);
    EXPECT_EQ(s2.findMin(t7), 1);

    vector<int> t8 = {1, 2, 3, -5, -4, -3, -2, -1, 0};
    EXPECT_EQ(s1.findMin(t8), -5);
    EXPECT_EQ(s2.findMin(t8), -5);
}

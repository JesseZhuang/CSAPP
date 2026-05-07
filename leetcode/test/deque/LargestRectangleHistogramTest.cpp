#include "gtest/gtest.h"
#include "deque/LargestRectangleHistogram.hpp"

using namespace std;

TEST(deque, largest_rectangle_histogram_stack) {
    Solution84 tbt;
    vector<int> t1 = {2, 1, 5, 6, 2, 3};
    ASSERT_EQ(10, tbt.largestRectangleAreaStack(t1));

    vector<int> t2 = {2, 4};
    ASSERT_EQ(4, tbt.largestRectangleAreaStack(t2));

    vector<int> t3 = {5};
    ASSERT_EQ(5, tbt.largestRectangleAreaStack(t3));

    vector<int> t4 = {1, 2, 3, 4, 5};
    ASSERT_EQ(9, tbt.largestRectangleAreaStack(t4));

    vector<int> t5 = {5, 4, 3, 2, 1};
    ASSERT_EQ(9, tbt.largestRectangleAreaStack(t5));

    vector<int> t6 = {3, 3, 3, 3};
    ASSERT_EQ(12, tbt.largestRectangleAreaStack(t6));
}

TEST(deque, largest_rectangle_histogram_array) {
    Solution84 tbt;
    vector<int> t1 = {2, 1, 5, 6, 2, 3};
    ASSERT_EQ(10, tbt.largestRectangleAreaArray(t1));

    vector<int> t2 = {2, 4};
    ASSERT_EQ(4, tbt.largestRectangleAreaArray(t2));

    vector<int> t3 = {5};
    ASSERT_EQ(5, tbt.largestRectangleAreaArray(t3));

    vector<int> t4 = {1, 2, 3, 4, 5};
    ASSERT_EQ(9, tbt.largestRectangleAreaArray(t4));

    vector<int> t5 = {5, 4, 3, 2, 1};
    ASSERT_EQ(9, tbt.largestRectangleAreaArray(t5));

    vector<int> t6 = {3, 3, 3, 3};
    ASSERT_EQ(12, tbt.largestRectangleAreaArray(t6));
}

#include "gtest/gtest.h"
#include "array/MedianTwoSortedArrays.hpp"

TEST(array, median_two_sorted_arrays) {
    // Test both solutions with identical cases
    auto test = [](vector<int> a, vector<int> b, double expected) {
        EXPECT_DOUBLE_EQ(MedianTwoSortedArrays::Solution1::findMedianSortedArrays(a, b), expected);
        EXPECT_DOUBLE_EQ(MedianTwoSortedArrays::Solution2::findMedianSortedArrays(a, b), expected);
    };

    test({1, 3}, {2}, 2.0);
    test({1, 2}, {3, 4}, 2.5);
    test({}, {1}, 1.0);
    test({2}, {}, 2.0);
    test({1}, {2}, 1.5);
    test({1, 2}, {3, 4, 5}, 3.0);
    test({-5, -3, -1}, {0, 2, 4}, -0.5);
}

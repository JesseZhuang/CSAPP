#include "gtest/gtest.h"
#include "array/ShortestSubarrayRemoved.hpp"
#include <vector>

using namespace std;

TEST(array, shortest_subarray_removed) {
    vector<int> v1{1, 2, 3, 10, 4, 2, 3, 5};
    EXPECT_EQ(ShortestSubarrayRemoved::findLengthOfShortestSubarray(v1), 3);

    vector<int> v2{5, 4, 3, 2, 1};
    EXPECT_EQ(ShortestSubarrayRemoved::findLengthOfShortestSubarray(v2), 4);

    vector<int> v3{1, 2, 3};
    EXPECT_EQ(ShortestSubarrayRemoved::findLengthOfShortestSubarray(v3), 0);

    vector<int> v4{1};
    EXPECT_EQ(ShortestSubarrayRemoved::findLengthOfShortestSubarray(v4), 0);

    vector<int> v5{2, 2, 2, 1, 1, 1};
    EXPECT_EQ(ShortestSubarrayRemoved::findLengthOfShortestSubarray(v5), 3);
}

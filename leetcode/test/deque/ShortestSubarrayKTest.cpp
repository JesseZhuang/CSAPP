#include "gtest/gtest.h"
#include "deque/ShortestSubarrayK.hpp"

TEST(deque, shortest_subarray_k) {
    ShortestSubarrayK sol;

    vector<int> nums1 = {1};
    ASSERT_EQ(1, sol.shortestSubarray(nums1, 1));

    vector<int> nums2 = {1, 2};
    ASSERT_EQ(-1, sol.shortestSubarray(nums2, 4));

    vector<int> nums3 = {2, -1, 2};
    ASSERT_EQ(3, sol.shortestSubarray(nums3, 3));
}

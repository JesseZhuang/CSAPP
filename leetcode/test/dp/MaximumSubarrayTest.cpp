#include "gtest/gtest.h"
#include "dp/MaximumSubarray.hpp"

#include <vector>

using namespace std;

namespace {
void verify(const vector<int>& nums, int expected) {
    SolutionMaximumSubarray sol;
    ASSERT_EQ(expected, sol.maxSubArrayDP(nums)) << "DP";
    ASSERT_EQ(expected, sol.maxSubArrayDnC(nums)) << "DnC";
}
}  // namespace

TEST(dp, maximum_subarray_example1) {
    verify({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
}

TEST(dp, maximum_subarray_single_positive) {
    verify({1}, 1);
}

TEST(dp, maximum_subarray_single_negative) {
    verify({-3}, -3);
}

TEST(dp, maximum_subarray_all_positive) {
    verify({5, 4, -1, 7, 8}, 23);
}

TEST(dp, maximum_subarray_all_negative) {
    verify({-3, -2, -5, -1, -4}, -1);
}

TEST(dp, maximum_subarray_zeros_and_negatives) {
    verify({0, -1, 0, -2, 0}, 0);
}

TEST(dp, maximum_subarray_two_elements_increasing) {
    verify({-1, 2}, 2);
}

TEST(dp, maximum_subarray_two_elements_decreasing) {
    verify({2, -1}, 2);
}

TEST(dp, maximum_subarray_alternating) {
    verify({1, -2, 3, -2, 5}, 6);  // {3,-2,5} = 6
}

TEST(dp, maximum_subarray_large_negative_at_ends) {
    verify({-100, 1, 2, 3, -100}, 6);
}

TEST(dp, maximum_subarray_extremes) {
    verify({-10000, 10000, -10000, 10000, -10000}, 10000);
}

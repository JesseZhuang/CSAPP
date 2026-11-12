#include "gtest/gtest.h"
#include "array/MaximumSumQueries.hpp"

using namespace std;

TEST(array, maximum_sum_queries) {
    Solution sol;

    // Official examples also exercise restoration of the original query order.
    vector<int> nums1{4, 3, 1, 2};
    vector<int> nums2{2, 4, 9, 5};
    vector<vector<int>> queries{{4, 1}, {1, 3}, {2, 5}};
    EXPECT_EQ((vector<int>{6, 10, 7}), sol.maximumSumQueries(nums1, nums2, queries));

    nums1 = {3, 2, 5};
    nums2 = {2, 3, 4};
    queries = {{4, 4}, {3, 2}, {1, 1}};
    EXPECT_EQ((vector<int>{9, 9, 9}), sol.maximumSumQueries(nums1, nums2, queries));

    nums1 = {2, 1};
    nums2 = {2, 3};
    queries = {{3, 3}};
    EXPECT_EQ((vector<int>{-1}), sol.maximumSumQueries(nums1, nums2, queries));

    // No qualifying x, no qualifying y, and both individually possible but no pair.
    nums1 = {8, 2};
    nums2 = {1, 7};
    queries = {{9, 1}, {1, 8}, {8, 7}, {1, 1}};
    EXPECT_EQ((vector<int>{-1, -1, -1, 9}), sol.maximumSumQueries(nums1, nums2, queries));

    // Equal b values must retain their maximum; both thresholds are inclusive.
    nums1 = {6, 4, 7, 2};
    nums2 = {3, 3, 2, 8};
    queries = {{4, 3}, {6, 3}, {7, 2}, {2, 8}, {3, 4}, {4, 2}};
    EXPECT_EQ((vector<int>{9, 9, 9, 10, -1, 9}), sol.maximumSumQueries(nums1, nums2, queries));

    // A y threshold between compressed coordinates must use the next larger b.
    nums1 = {10, 3};
    nums2 = {2, 8};
    queries = {{1, 3}, {1, 2}, {10, 3}};
    EXPECT_EQ((vector<int>{11, 12, -1}), sol.maximumSumQueries(nums1, nums2, queries));

    nums1 = {1'000'000'000};
    nums2 = {1'000'000'000};
    queries = {{1'000'000'000, 1'000'000'000}, {1, 1}};
    EXPECT_EQ((vector<int>{2'000'000'000, 2'000'000'000}),
              sol.maximumSumQueries(nums1, nums2, queries));
}

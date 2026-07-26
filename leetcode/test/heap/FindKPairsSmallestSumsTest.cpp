#include "gtest/gtest.h"
#include "heap/FindKPairsSmallestSums.hpp"

using namespace std;

// Helper: sort pairs by sum then by first element for deterministic comparison
static vector<vector<int>> sortBySum(vector<vector<int>> v) {
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        int sa = a[0] + a[1], sb = b[0] + b[1];
        return sa != sb ? sa < sb : a < b;
    });
    return v;
}

// Helper to run both solutions and compare results (order-independent for tied sums)
static void checkBoth(vector<int> nums1, vector<int> nums2, int k,
                      vector<vector<int>> expected) {
    auto res1 = SolutionFindKPairs::kSmallestPairsHeap(nums1, nums2, k);
    EXPECT_EQ(sortBySum(res1), sortBySum(expected));

    auto res2 = SolutionFindKPairs::kSmallestPairsBFS(nums1, nums2, k);
    EXPECT_EQ(sortBySum(res2), sortBySum(expected));
}

TEST(heap, find_k_pairs_basic) {
    checkBoth({1, 7, 11}, {2, 4, 6}, 3,
              {{1, 2}, {1, 4}, {1, 6}});
}

TEST(heap, find_k_pairs_duplicates) {
    checkBoth({1, 1, 2}, {1, 2, 3}, 2,
              {{1, 1}, {1, 1}});
}

TEST(heap, find_k_pairs_single_column) {
    checkBoth({1, 2}, {3}, 3,
              {{1, 3}, {2, 3}});
}

TEST(heap, find_k_pairs_k_larger_than_total) {
    // Total pairs = 2*2 = 4, k = 10
    checkBoth({1, 2}, {3, 4}, 10,
              {{1, 3}, {1, 4}, {2, 3}, {2, 4}});
}

TEST(heap, find_k_pairs_single_elements) {
    checkBoth({5}, {10}, 1,
              {{5, 10}});
}

TEST(heap, find_k_pairs_empty_arrays) {
    checkBoth({}, {1, 2, 3}, 3, {});
    checkBoth({1, 2, 3}, {}, 3, {});
    checkBoth({}, {}, 1, {});
}

TEST(heap, find_k_pairs_negative_numbers) {
    checkBoth({-5, -3, 0}, {-2, 0, 4}, 4,
              {{-5, -2}, {-5, 0}, {-3, -2}, {-3, 0}});
}

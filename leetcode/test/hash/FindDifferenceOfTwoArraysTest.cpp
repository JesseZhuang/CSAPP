#include "gtest/gtest.h"
#include "hash/FindDifferenceOfTwoArrays.hpp"

#include <unordered_set>
#include <vector>

using namespace std;

static void expectDifference(const vector<int>& nums1, const vector<int>& nums2,
                             const unordered_set<int>& expectedFirst,
                             const unordered_set<int>& expectedSecond) {
    Solution2215 solution;
    const auto result = solution.findDifference(nums1, nums2);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(expectedFirst.size(), result[0].size());
    EXPECT_EQ(expectedSecond.size(), result[1].size());
    EXPECT_EQ(expectedFirst, (unordered_set<int>(result[0].begin(), result[0].end())));
    EXPECT_EQ(expectedSecond, (unordered_set<int>(result[1].begin(), result[1].end())));
}

TEST(hash, find_difference_of_two_arrays_duplicates) {
    expectDifference({1, 2, 3, 3}, {1, 1, 2, 2, 4, 4}, {3}, {4});
}

TEST(hash, find_difference_of_two_arrays_identical) {
    expectDifference({-2, -2, 3}, {3, -2, 3}, {}, {});
}

TEST(hash, find_difference_of_two_arrays_disjoint) {
    expectDifference({1, 2}, {3, 4}, {1, 2}, {3, 4});
}

TEST(hash, find_difference_of_two_arrays_negatives) {
    expectDifference({-5, -2, 0}, {-2, -1, 0}, {-5}, {-1});
}

TEST(hash, find_difference_of_two_arrays_bounds) {
    expectDifference({-1000, 0, 0}, {0, 1000, 1000}, {-1000}, {1000});
}

TEST(hash, find_difference_of_two_arrays_asymmetric) {
    expectDifference({1, 2, 3, 4}, {2, 3}, {1, 4}, {});
    expectDifference({2, 3}, {1, 2, 3, 4}, {}, {1, 4});
}

TEST(hash, find_difference_of_two_arrays_singletons) {
    expectDifference({-1}, {1}, {-1}, {1});
    expectDifference({1}, {1}, {}, {});
}

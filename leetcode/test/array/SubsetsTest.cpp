#include "gtest/gtest.h"
#include "array/Subsets.hpp"
#include <vector>

using namespace std;

TEST(array, subsets) {
    Solution78 sol;

    // {1,2,3} -> 8 subsets
    vector<int> nums1{1, 2, 3};
    ASSERT_EQ(8u, sol.subsets(nums1).size());
    ASSERT_EQ(8u, sol.subsetsBitmask(nums1).size());

    // {0} -> 2 subsets
    vector<int> nums2{0};
    ASSERT_EQ(2u, sol.subsets(nums2).size());
    ASSERT_EQ(2u, sol.subsetsBitmask(nums2).size());

    // {} -> 1 subset (empty set)
    vector<int> nums3{};
    ASSERT_EQ(1u, sol.subsets(nums3).size());
    ASSERT_EQ(1u, sol.subsetsBitmask(nums3).size());

    // {1,2} -> 4 subsets
    vector<int> nums4{1, 2};
    ASSERT_EQ(4u, sol.subsets(nums4).size());
    ASSERT_EQ(4u, sol.subsetsBitmask(nums4).size());
}

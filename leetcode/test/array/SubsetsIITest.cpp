#include "gtest/gtest.h"
#include "array/SubsetsII.hpp"
#include <vector>

using namespace std;

TEST(array, subsets_ii_backtrack) {
    Solution90 sol;

    // [1,2,2] -> 6 subsets
    vector<int> nums1{1, 2, 2};
    ASSERT_EQ(6u, sol.subsetsWithDup(nums1).size());

    // [0] -> 2 subsets
    vector<int> nums2{0};
    ASSERT_EQ(2u, sol.subsetsWithDup(nums2).size());

    // [1,1,1] -> 4 subsets
    vector<int> nums3{1, 1, 1};
    ASSERT_EQ(4u, sol.subsetsWithDup(nums3).size());

    // [1,2,3] -> 8 subsets (no duplicates)
    vector<int> nums4{1, 2, 3};
    ASSERT_EQ(8u, sol.subsetsWithDup(nums4).size());

    // [-1,-1,2] -> 6 subsets
    vector<int> nums5{-1, -1, 2};
    ASSERT_EQ(6u, sol.subsetsWithDup(nums5).size());

    // [1,1,2,2,3,3,4,4,5,5] -> 243 subsets
    vector<int> nums6{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    ASSERT_EQ(243u, sol.subsetsWithDup(nums6).size());
}

TEST(array, subsets_ii_cascade) {
    Solution90 sol;

    // [1,2,2] -> 6 subsets
    vector<int> nums1{1, 2, 2};
    ASSERT_EQ(6u, sol.subsetsWithDupCascade(nums1).size());

    // [0] -> 2 subsets
    vector<int> nums2{0};
    ASSERT_EQ(2u, sol.subsetsWithDupCascade(nums2).size());

    // [1,1,1] -> 4 subsets
    vector<int> nums3{1, 1, 1};
    ASSERT_EQ(4u, sol.subsetsWithDupCascade(nums3).size());

    // [1,2,3] -> 8 subsets (no duplicates)
    vector<int> nums4{1, 2, 3};
    ASSERT_EQ(8u, sol.subsetsWithDupCascade(nums4).size());

    // [-1,-1,2] -> 6 subsets
    vector<int> nums5{-1, -1, 2};
    ASSERT_EQ(6u, sol.subsetsWithDupCascade(nums5).size());

    // [1,1,2,2,3,3,4,4,5,5] -> 243 subsets
    vector<int> nums6{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    ASSERT_EQ(243u, sol.subsetsWithDupCascade(nums6).size());
}

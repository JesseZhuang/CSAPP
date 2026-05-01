#include "gtest/gtest.h"
#include "array/TwoSum.hpp"

#include <vector>

using namespace std;

TEST(array, two_sum_example1) {
    Solution sol;
    vector<int> nums{2, 7, 11, 15};
    auto res = sol.twoSum(nums, 9);
    // Result order may differ; verify the pair sums to target.
    ASSERT_EQ(2u, res.size());
    ASSERT_EQ(9, nums[res[0]] + nums[res[1]]);
}

TEST(array, two_sum_example2) {
    Solution sol;
    vector<int> nums{3, 2, 4};
    auto res = sol.twoSum(nums, 6);
    ASSERT_EQ(2u, res.size());
    ASSERT_EQ(6, nums[res[0]] + nums[res[1]]);
    ASSERT_NE(res[0], res[1]);
}

TEST(array, two_sum_example3_duplicates) {
    Solution sol;
    vector<int> nums{3, 3};
    auto res = sol.twoSum(nums, 6);
    ASSERT_EQ(2u, res.size());
    ASSERT_NE(res[0], res[1]);
    ASSERT_EQ(6, nums[res[0]] + nums[res[1]]);
}

TEST(array, two_sum_negative_numbers) {
    Solution sol;
    vector<int> nums{-1, -2, -3, -4, -5};
    auto res = sol.twoSum(nums, -8);
    ASSERT_EQ(2u, res.size());
    ASSERT_EQ(-8, nums[res[0]] + nums[res[1]]);
}

TEST(array, two_sum_first_and_last) {
    Solution sol;
    vector<int> nums{1, 5, 7, 9, 4};
    auto res = sol.twoSum(nums, 5); // 1 + 4
    ASSERT_EQ(2u, res.size());
    ASSERT_EQ(5, nums[res[0]] + nums[res[1]]);
}

TEST(array, two_sum_zero_target) {
    Solution sol;
    vector<int> nums{-3, 4, 3, 90};
    auto res = sol.twoSum(nums, 0); // -3 + 3
    ASSERT_EQ(2u, res.size());
    ASSERT_EQ(0, nums[res[0]] + nums[res[1]]);
}

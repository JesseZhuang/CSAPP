#include "array/LeftAndRightSumDifferences.hpp"
#include "gtest/gtest.h"

TEST(array, left_and_right_sum_differences_example) {
    Solution solution;
    vector<int> nums{10, 4, 8, 3};
    EXPECT_EQ((vector<int>{15, 1, 11, 22}), solution.leftRightDifference(nums));
    EXPECT_EQ((vector<int>{10, 4, 8, 3}), nums);
}

TEST(array, left_and_right_sum_differences_single_element) {
    Solution solution;
    vector<int> nums{1};
    EXPECT_EQ((vector<int>{0}), solution.leftRightDifference(nums));
}

TEST(array, left_and_right_sum_differences_symmetric_totals) {
    Solution solution;
    vector<int> nums{1, 2, 3, 2, 1};
    EXPECT_EQ((vector<int>{8, 5, 0, 5, 8}), solution.leftRightDifference(nums));
}

TEST(array, left_and_right_sum_differences_max_bounds) {
    Solution solution;
    vector<int> nums(1000, 100'000);
    const vector<int> result = solution.leftRightDifference(nums);
    ASSERT_EQ(1000, result.size());
    EXPECT_EQ(99'900'000, result.front());
    EXPECT_EQ(100'000, result[499]);
    EXPECT_EQ(100'000, result[500]);
    EXPECT_EQ(99'900'000, result.back());
}

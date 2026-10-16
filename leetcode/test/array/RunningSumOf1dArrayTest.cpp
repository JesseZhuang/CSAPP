#include "array/RunningSumOf1dArray.hpp"
#include "gtest/gtest.h"

TEST(array, running_sum_singleton) {
    Solution solution;
    vector<int> nums{7};
    EXPECT_EQ((vector<int>{7}), solution.runningSum(nums));
    EXPECT_EQ((vector<int>{7}), nums);
}

TEST(array, running_sum_examples) {
    Solution solution;
    vector<int> nums{1, 2, 3, 4};
    EXPECT_EQ((vector<int>{1, 3, 6, 10}), solution.runningSum(nums));

    vector<int> repeated{1, 1, 1, 1, 1};
    EXPECT_EQ((vector<int>{1, 2, 3, 4, 5}), solution.runningSum(repeated));

    vector<int> other{3, 1, 2, 10, 1};
    EXPECT_EQ((vector<int>{3, 4, 6, 16, 17}), solution.runningSum(other));
}

TEST(array, running_sum_all_zero) {
    Solution solution;
    vector<int> nums{0, 0, 0, 0};
    EXPECT_EQ((vector<int>{0, 0, 0, 0}), solution.runningSum(nums));
    EXPECT_EQ((vector<int>{0, 0, 0, 0}), nums);
}

TEST(array, running_sum_negative_values) {
    Solution solution;
    vector<int> nums{-1, -2, -3, -4};
    EXPECT_EQ((vector<int>{-1, -3, -6, -10}), solution.runningSum(nums));
}

TEST(array, running_sum_mixed_values) {
    Solution solution;
    vector<int> nums{5, -8, 3, 0, 6, -2};
    EXPECT_EQ((vector<int>{5, -3, 0, 0, 6, 4}), solution.runningSum(nums));
}

TEST(array, running_sum_max_magnitude_and_length) {
    Solution solution;
    vector<int> nums(1000, 1'000'000);
    const vector<int> result = solution.runningSum(nums);
    EXPECT_EQ(1'000'000, result.front());
    EXPECT_EQ(500'000'000, result[499]);
    EXPECT_EQ(1'000'000'000, result.back());
    EXPECT_EQ(result, nums);

    vector<int> negative(1000, -1'000'000);
    EXPECT_EQ(-1'000'000'000, solution.runningSum(negative).back());
}

TEST(array, running_sum_modifies_input_in_place) {
    Solution solution;
    vector<int> nums{2, 4, -1};
    vector<int> result = solution.runningSum(nums);
    EXPECT_EQ((vector<int>{2, 6, 5}), result);
    EXPECT_EQ(result, nums);
}

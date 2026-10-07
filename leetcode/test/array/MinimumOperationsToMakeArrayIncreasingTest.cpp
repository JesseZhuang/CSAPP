#include "gtest/gtest.h"
#include "array/MinimumOperationsToMakeArrayIncreasing.hpp"

#include <numeric>
#include <vector>

TEST(array, minimum_operations_to_make_array_increasing) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(3, solution.minOperations({1, 1, 1}));
    EXPECT_EQ(14, solution.minOperations({1, 5, 2, 4, 1}));
    EXPECT_EQ(0, solution.minOperations({8}));
}

TEST(array, minimum_operations_to_make_array_increasing_strictly_increasing) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(0, solution.minOperations({1, 2, 3, 4, 5}));
    EXPECT_EQ(0, solution.minOperations({1, 100, 1000, 10000}));
}

TEST(array, minimum_operations_to_make_array_increasing_equal_values) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(1, solution.minOperations({1, 1}));
    EXPECT_EQ(6, solution.minOperations({5, 5, 5, 5}));
}

TEST(array, minimum_operations_to_make_array_increasing_descending_values) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(2, solution.minOperations({2, 1}));
    EXPECT_EQ(20, solution.minOperations({5, 4, 3, 2, 1}));
}

TEST(array, minimum_operations_to_make_array_increasing_adjustment_carries_forward) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(6, solution.minOperations({3, 1, 2}));
    EXPECT_EQ(9, solution.minOperations({1, 2, 1, 1, 1}));
}

TEST(array, minimum_operations_to_make_array_increasing_larger_later_value_resets_previous) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(11, solution.minOperations({1, 1, 10, 1}));
    EXPECT_EQ(15, solution.minOperations({5, 1, 10, 1}));
}

TEST(array, minimum_operations_to_make_array_increasing_value_bounds) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;

    EXPECT_EQ(0, solution.minOperations({1}));
    EXPECT_EQ(0, solution.minOperations({10000}));
    EXPECT_EQ(0, solution.minOperations({9999, 10000}));
    EXPECT_EQ(1, solution.minOperations({10000, 10000}));
    EXPECT_EQ(10000, solution.minOperations({10000, 1}));
    EXPECT_EQ(10000, solution.minOperations({1, 10000, 1}));
}

TEST(array, minimum_operations_to_make_array_increasing_maximum_length_increasing) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;
    std::vector<int> nums(5000);
    std::iota(nums.begin(), nums.end(), 1);

    EXPECT_EQ(0, solution.minOperations(nums));
}

TEST(array, minimum_operations_to_make_array_increasing_maximum_length_equal_values) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;
    const std::vector<int> minimumValues(5000, 1);
    const std::vector<int> maximumValues(5000, 10000);

    EXPECT_EQ(12497500, solution.minOperations(minimumValues));
    EXPECT_EQ(12497500, solution.minOperations(maximumValues));
}

TEST(array, minimum_operations_to_make_array_increasing_maximum_length_high_then_low) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;
    std::vector<int> nums(5000, 1);
    nums[0] = 10000;

    EXPECT_EQ(62482501, solution.minOperations(nums));
}

TEST(array, minimum_operations_to_make_array_increasing_preserves_input) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;
    std::vector<int> nums{1, 5, 2, 4, 1};
    const std::vector<int> original = nums;

    EXPECT_EQ(14, solution.minOperations(nums));
    EXPECT_EQ(original, nums);
}

TEST(array, minimum_operations_to_make_array_increasing_repeated_calls) {
    MinimumOperationsToMakeArrayIncreasing::Solution solution;
    const std::vector<int> nums{1, 5, 2, 4, 1};

    EXPECT_EQ(14, solution.minOperations(nums));
    EXPECT_EQ(0, solution.minOperations({8}));
    EXPECT_EQ(3, solution.minOperations({1, 1, 1}));
    EXPECT_EQ(14, solution.minOperations(nums));
}

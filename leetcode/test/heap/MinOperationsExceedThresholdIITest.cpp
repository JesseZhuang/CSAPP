#include "gtest/gtest.h"
#include "heap/MinOperationsExceedThresholdII.hpp"

#include <vector>

using namespace std;

TEST(heap, min_operations_exceed_threshold_ii_examples) {
    Solution solution;

    vector<int> first = {2, 11, 10, 1, 3};
    EXPECT_EQ(2, solution.minOperations(first, 10));

    vector<int> second = {1, 1, 2, 4, 9};
    EXPECT_EQ(4, solution.minOperations(second, 20));
}

TEST(heap, min_operations_exceed_threshold_ii_no_operation_needed) {
    Solution solution;
    vector<int> nums = {10, 12};

    EXPECT_EQ(0, solution.minOperations(nums, 10));
}

TEST(heap, min_operations_exceed_threshold_ii_reaches_exactly_k) {
    Solution solution;
    vector<int> nums = {1, 2};

    EXPECT_EQ(1, solution.minOperations(nums, 4));
}

TEST(heap, min_operations_exceed_threshold_ii_uses_64_bit_intermediate_values) {
    Solution solution;
    vector<int> nums = {500000000, 500000000, 500000000};

    EXPECT_EQ(2, solution.minOperations(nums, 1000000000));
}

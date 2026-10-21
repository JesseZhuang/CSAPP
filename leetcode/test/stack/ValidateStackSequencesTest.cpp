#include "stack/ValidateStackSequences.hpp"
#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>

TEST(stack, validate_stack_sequences_official_true) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    EXPECT_TRUE(sol.validateStackSequences(pushed, popped));
}

TEST(stack, validate_stack_sequences_official_false) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};
    EXPECT_FALSE(sol.validateStackSequences(pushed, popped));
}

TEST(stack, validate_stack_sequences_singleton) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed = {0};
    vector<int> popped = {0};
    EXPECT_TRUE(sol.validateStackSequences(pushed, popped));
}

TEST(stack, validate_stack_sequences_ascending) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed = {1, 2, 3, 4};
    vector<int> popped = {1, 2, 3, 4};
    EXPECT_TRUE(sol.validateStackSequences(pushed, popped));
}

TEST(stack, validate_stack_sequences_reversed) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed = {1, 2, 3, 4};
    vector<int> popped = {4, 3, 2, 1};
    EXPECT_TRUE(sol.validateStackSequences(pushed, popped));
}

TEST(stack, validate_stack_sequences_impossible_interleaving) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed = {1, 2, 3};
    vector<int> popped = {3, 1, 2};
    EXPECT_FALSE(sol.validateStackSequences(pushed, popped));
}

TEST(stack, validate_stack_sequences_max_length) {
    ValidateStackSequences::Solution sol;
    vector<int> pushed(1000);
    iota(pushed.begin(), pushed.end(), 0);
    vector<int> popped = pushed;
    reverse(popped.begin(), popped.end());
    EXPECT_TRUE(sol.validateStackSequences(pushed, popped));
}

#include "gtest/gtest.h"
#include "array/NextPermutation.hpp"

TEST(array, next_permutation_ascending) {
    NextPermutationSolution sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    EXPECT_EQ(nums, (vector<int>{1, 3, 2}));
}

TEST(array, next_permutation_descending) {
    NextPermutationSolution sol;
    vector<int> nums = {3, 2, 1};
    sol.nextPermutation(nums);
    EXPECT_EQ(nums, (vector<int>{1, 2, 3}));
}

TEST(array, next_permutation_duplicates) {
    NextPermutationSolution sol;
    vector<int> nums = {1, 1, 5};
    sol.nextPermutation(nums);
    EXPECT_EQ(nums, (vector<int>{1, 5, 1}));
}

TEST(array, next_permutation_single) {
    NextPermutationSolution sol;
    vector<int> nums = {1};
    sol.nextPermutation(nums);
    EXPECT_EQ(nums, (vector<int>{1}));
}

TEST(array, next_permutation_duplicates_complex) {
    NextPermutationSolution sol;
    vector<int> nums = {1, 2, 2};
    sol.nextPermutation(nums);
    EXPECT_EQ(nums, (vector<int>{2, 1, 2}));
}

TEST(array, next_permutation_middle_pivot) {
    NextPermutationSolution sol;
    vector<int> nums = {2, 3, 1, 3, 3};
    sol.nextPermutation(nums);
    EXPECT_EQ(nums, (vector<int>{2, 3, 3, 1, 3}));
}

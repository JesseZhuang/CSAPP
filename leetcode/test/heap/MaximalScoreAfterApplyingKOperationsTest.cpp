#include "gtest/gtest.h"
#include "heap/MaximalScoreAfterApplyingKOperations.hpp"

#include <utility>
#include <vector>

using namespace std;

TEST(heap, maximal_score_after_applying_k_operations_examples) {
    Solution solution;
    const vector<int> equalNumbers = {10, 10, 10, 10, 10};
    const vector<int> mixedNumbers = {1, 10, 3, 3, 3};

    EXPECT_EQ(50LL, solution.maxKelements(equalNumbers, 5));
    EXPECT_EQ(17LL, solution.maxKelements(mixedNumbers, 3));
}

TEST(heap, maximal_score_after_applying_k_operations_single_operation) {
    Solution solution;
    const vector<int> numbers = {4, 1000000000, 1};

    EXPECT_EQ(1000000000LL, solution.maxKelements(numbers, 1));
}

TEST(heap, maximal_score_after_applying_k_operations_ceiling_division) {
    Solution solution;
    const vector<pair<int, long long>> testCases = {
            {3, 5LL}, {4, 7LL}, {5, 8LL}, {6, 9LL}};

    for (const auto& [initialValue, expectedScore] : testCases) {
        const vector<int> numbers = {initialValue};
        EXPECT_EQ(expectedScore, solution.maxKelements(numbers, 3))
                << "initial value: " << initialValue;
    }
}

TEST(heap, maximal_score_after_applying_k_operations_exact_round_count) {
    Solution solution;
    const vector<int> numbers = {1};

    EXPECT_EQ(100000LL, solution.maxKelements(numbers, 100000));
}

TEST(heap, maximal_score_after_applying_k_operations_heap_reorders) {
    Solution solution;
    const vector<int> numbers = {9, 8};

    EXPECT_EQ(23LL, solution.maxKelements(numbers, 4));
}

TEST(heap, maximal_score_after_applying_k_operations_64_bit_score) {
    Solution solution;
    const vector<int> numbers(3, 1000000000);

    EXPECT_EQ(3000000000LL, solution.maxKelements(numbers, 3));
}

TEST(heap, maximal_score_after_applying_k_operations_maximum_constraints) {
    Solution solution;
    const vector<int> numbers(100000, 1000000000);

    EXPECT_EQ(100000000000000LL, solution.maxKelements(numbers, 100000));
}

TEST(heap, maximal_score_after_applying_k_operations_preserves_input) {
    Solution solution;
    const vector<int> numbers = {1, 10, 3, 3, 3};
    const vector<int> originalNumbers = numbers;

    EXPECT_EQ(17LL, solution.maxKelements(numbers, 3));
    EXPECT_EQ(originalNumbers, numbers);
}

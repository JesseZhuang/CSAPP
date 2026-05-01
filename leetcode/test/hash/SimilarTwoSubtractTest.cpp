#include "gtest/gtest.h"
#include "hash/SimilarTwoSubtract.hpp"

#include <vector>

using namespace std;

TEST(hash, similar_two_subtract_no_pair) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{1, 2};
    ASSERT_EQ(0, sol.twoSubtract(a, 3));
}

TEST(hash, similar_two_subtract_single_pair) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{1, 2};
    ASSERT_EQ(1, sol.twoSubtract(a, 1));
}

TEST(hash, similar_two_subtract_zero_adds) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{1, 2, 0};
    ASSERT_EQ(2, sol.twoSubtract(a, 1));
}

TEST(hash, similar_two_subtract_duplicates) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{1, 2, 1, 2, 0};
    ASSERT_EQ(6, sol.twoSubtract(a, 1));
}

TEST(hash, similar_two_subtract_empty) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{};
    ASSERT_EQ(0, sol.twoSubtract(a, 1));
}

TEST(hash, similar_two_subtract_single_element_target_zero) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{5};
    ASSERT_EQ(1, sol.twoSubtract(a, 0));
}

TEST(hash, similar_two_subtract_single_element_nonzero) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{5};
    ASSERT_EQ(0, sol.twoSubtract(a, 3));
}

TEST(hash, similar_two_subtract_negative_values) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{-1, -3, -2};
    ASSERT_EQ(2, sol.twoSubtract(a, 1));
}

TEST(hash, similar_two_subtract_negative_target) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{1, 2};
    ASSERT_EQ(1, sol.twoSubtract(a, -1));
}

TEST(hash, similar_two_subtract_all_same_target_zero) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{5, 5, 5, 5};
    ASSERT_EQ(16, sol.twoSubtract(a, 0));
}

TEST(hash, similar_two_subtract_multiple_distinct) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{10, 7, 3, 0, 13, 17};
    ASSERT_EQ(3, sol.twoSubtract(a, 3));
}

TEST(hash, similar_two_subtract_no_match) {
    SolutionSimilarTwoSubtract sol;
    vector<int> a{1, 2, 3, 4, 5};
    ASSERT_EQ(0, sol.twoSubtract(a, 100));
}

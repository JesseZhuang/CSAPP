#include "sliding/FreqMostFrequentElement.hpp"
#include <gtest/gtest.h>

TEST(sliding, freq_most_frequent_element) {
    SolutionFreqMostFrequentSW sol;

    // Example 1: [1,2,4] k=5 -> 3
    vector<int> v1 = {1, 2, 4};
    EXPECT_EQ(sol.maxFrequency(v1, 5), 3);

    // Example 2: [1,4,8,13] k=5 -> 2
    vector<int> v2 = {1, 4, 8, 13};
    EXPECT_EQ(sol.maxFrequency(v2, 5), 2);

    // Example 3: [3,9,6] k=2 -> 1
    vector<int> v3 = {3, 9, 6};
    EXPECT_EQ(sol.maxFrequency(v3, 2), 1);

    // Single element
    vector<int> v4 = {7};
    EXPECT_EQ(sol.maxFrequency(v4, 10), 1);

    // All same elements
    vector<int> v5 = {5, 5, 5, 5};
    EXPECT_EQ(sol.maxFrequency(v5, 0), 4);

    // k=0, no operations possible
    vector<int> v6 = {1, 2, 3, 4};
    EXPECT_EQ(sol.maxFrequency(v6, 0), 1);

    // Large k covers all elements
    vector<int> v7 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.maxFrequency(v7, 100000), 5);
}

TEST(sliding, freq_most_frequent_element_bs) {
    SolutionFreqMostFrequentBS sol;

    // Example 1: [1,2,4] k=5 -> 3
    vector<int> v1 = {1, 2, 4};
    EXPECT_EQ(sol.maxFrequency(v1, 5), 3);

    // Example 2: [1,4,8,13] k=5 -> 2
    vector<int> v2 = {1, 4, 8, 13};
    EXPECT_EQ(sol.maxFrequency(v2, 5), 2);

    // Example 3: [3,9,6] k=2 -> 1
    vector<int> v3 = {3, 9, 6};
    EXPECT_EQ(sol.maxFrequency(v3, 2), 1);

    // Single element
    vector<int> v4 = {7};
    EXPECT_EQ(sol.maxFrequency(v4, 10), 1);

    // All same elements
    vector<int> v5 = {5, 5, 5, 5};
    EXPECT_EQ(sol.maxFrequency(v5, 0), 4);

    // k=0, no operations possible
    vector<int> v6 = {1, 2, 3, 4};
    EXPECT_EQ(sol.maxFrequency(v6, 0), 1);

    // Large k covers all elements
    vector<int> v7 = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.maxFrequency(v7, 100000), 5);
}

#include "gtest/gtest.h"
#include "hash/UniqueNumberOfOccurrences.hpp"

#include <vector>

using namespace std;

TEST(hash, unique_number_of_occurrences_example1) {
    Solution sol;
    vector<int> nums{1, 2, 2, 1, 1, 3};

    EXPECT_TRUE(sol.uniqueOccurrences(nums));
    EXPECT_TRUE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_example2) {
    Solution sol;
    vector<int> nums{1, 2};

    EXPECT_FALSE(sol.uniqueOccurrences(nums));
    EXPECT_FALSE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_example3) {
    Solution sol;
    vector<int> nums{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    EXPECT_TRUE(sol.uniqueOccurrences(nums));
    EXPECT_TRUE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_singleton) {
    Solution sol;
    vector<int> nums{42};

    EXPECT_TRUE(sol.uniqueOccurrences(nums));
    EXPECT_TRUE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_all_equal) {
    Solution sol;
    vector<int> nums{7, 7, 7, 7};

    EXPECT_TRUE(sol.uniqueOccurrences(nums));
    EXPECT_TRUE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_repeated_frequency) {
    Solution sol;
    vector<int> nums{1, 1, 2, 2};

    EXPECT_FALSE(sol.uniqueOccurrences(nums));
    EXPECT_FALSE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_value_bounds_unique_frequencies) {
    Solution sol;
    vector<int> nums{-1000, -1000, 1000};

    EXPECT_TRUE(sol.uniqueOccurrences(nums));
    EXPECT_TRUE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

TEST(hash, unique_number_of_occurrences_value_bounds_colliding_frequencies) {
    Solution sol;
    vector<int> nums{-1000, -1000, 1000, 1000};

    EXPECT_FALSE(sol.uniqueOccurrences(nums));
    EXPECT_FALSE(sol.uniqueOccurrencesByFrequencyArray(nums));
}

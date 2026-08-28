#include <gtest/gtest.h>
#include "binary_search/FlowersInFullBloom.hpp"

TEST(binary_search, flowers_in_full_bloom_binary_search) {
    Solution s;

    // Example 1
    vector<vector<int>> flowers1 = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people1 = {2, 3, 7, 11};
    vector<int> expected1 = {1, 2, 2, 2};
    EXPECT_EQ(expected1, s.fullBloomFlowers(flowers1, people1));

    // Example 2
    vector<vector<int>> flowers2 = {{1, 10}, {3, 3}};
    vector<int> people2 = {3, 3, 2};
    vector<int> expected2 = {2, 2, 1};
    EXPECT_EQ(expected2, s.fullBloomFlowers(flowers2, people2));

    // Single flower, single person exactly at start
    vector<vector<int>> flowers3 = {{5, 10}};
    vector<int> people3 = {5};
    vector<int> expected3 = {1};
    EXPECT_EQ(expected3, s.fullBloomFlowers(flowers3, people3));

    // Person arrives before any flower blooms
    vector<vector<int>> flowers4 = {{2, 5}, {3, 7}};
    vector<int> people4 = {1};
    vector<int> expected4 = {0};
    EXPECT_EQ(expected4, s.fullBloomFlowers(flowers4, people4));

    // Person arrives after all flowers end
    vector<vector<int>> flowers5 = {{1, 3}, {2, 4}};
    vector<int> people5 = {5};
    vector<int> expected5 = {0};
    EXPECT_EQ(expected5, s.fullBloomFlowers(flowers5, people5));

    // All flowers bloom at the same time
    vector<vector<int>> flowers6 = {{1, 5}, {1, 5}, {1, 5}};
    vector<int> people6 = {1, 3, 5, 6};
    vector<int> expected6 = {3, 3, 3, 0};
    EXPECT_EQ(expected6, s.fullBloomFlowers(flowers6, people6));
}

TEST(binary_search, flowers_in_full_bloom_sweep_line) {
    SolutionSweepLine s;

    // Example 1
    vector<vector<int>> flowers1 = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people1 = {2, 3, 7, 11};
    vector<int> expected1 = {1, 2, 2, 2};
    EXPECT_EQ(expected1, s.fullBloomFlowers(flowers1, people1));

    // Example 2
    vector<vector<int>> flowers2 = {{1, 10}, {3, 3}};
    vector<int> people2 = {3, 3, 2};
    vector<int> expected2 = {2, 2, 1};
    EXPECT_EQ(expected2, s.fullBloomFlowers(flowers2, people2));

    // Single flower, single person exactly at start
    vector<vector<int>> flowers3 = {{5, 10}};
    vector<int> people3 = {5};
    vector<int> expected3 = {1};
    EXPECT_EQ(expected3, s.fullBloomFlowers(flowers3, people3));

    // Person arrives before any flower blooms
    vector<vector<int>> flowers4 = {{2, 5}, {3, 7}};
    vector<int> people4 = {1};
    vector<int> expected4 = {0};
    EXPECT_EQ(expected4, s.fullBloomFlowers(flowers4, people4));

    // Person arrives after all flowers end
    vector<vector<int>> flowers5 = {{1, 3}, {2, 4}};
    vector<int> people5 = {5};
    vector<int> expected5 = {0};
    EXPECT_EQ(expected5, s.fullBloomFlowers(flowers5, people5));

    // All flowers bloom at the same time
    vector<vector<int>> flowers6 = {{1, 5}, {1, 5}, {1, 5}};
    vector<int> people6 = {1, 3, 5, 6};
    vector<int> expected6 = {3, 3, 3, 0};
    EXPECT_EQ(expected6, s.fullBloomFlowers(flowers6, people6));
}

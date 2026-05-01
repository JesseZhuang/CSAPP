#include "heap/IPO.hpp"
#include <gtest/gtest.h>

TEST(heap, ipo) {
    SolutionIPO sol;

    // Example 1
    vector<int> profits1 = {1, 2, 3}, capital1 = {0, 1, 1};
    EXPECT_EQ(sol.findMaximizedCapital(2, 0, profits1, capital1), 4);

    // Example 2
    vector<int> profits2 = {1, 2, 3}, capital2 = {0, 1, 2};
    EXPECT_EQ(sol.findMaximizedCapital(3, 0, profits2, capital2), 6);

    // k larger than available projects
    vector<int> profits3 = {1, 2}, capital3 = {0, 0};
    EXPECT_EQ(sol.findMaximizedCapital(5, 0, profits3, capital3), 3);

    // No affordable projects initially
    vector<int> profits4 = {5, 10}, capital4 = {3, 5};
    EXPECT_EQ(sol.findMaximizedCapital(2, 0, profits4, capital4), 0);
}

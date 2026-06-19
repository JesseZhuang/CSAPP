#include "heap/MaximumSubsequenceScore.hpp"
#include <gtest/gtest.h>

TEST(heap, maximum_subsequence_score) {
    SolutionMaximumSubsequenceScore sol;

    vector<int> n1a = {1,3,3,2}, n2a = {2,1,3,4};
    EXPECT_EQ(sol.maxScore(n1a, n2a, 3), 12);

    vector<int> n1b = {4,2,3,1,1}, n2b = {7,5,10,9,6};
    EXPECT_EQ(sol.maxScore(n1b, n2b, 1), 30);

    vector<int> n1c = {1,1,1}, n2c = {1,1,1};
    EXPECT_EQ(sol.maxScore(n1c, n2c, 2), 2);

    vector<int> n1d = {2,3,5}, n2d = {4,2,1};
    EXPECT_EQ(sol.maxScore(n1d, n2d, 3), 10);

    vector<int> n1e = {5}, n2e = {6};
    EXPECT_EQ(sol.maxScore(n1e, n2e, 1), 30);

    vector<int> n1f = {10,20,30}, n2f = {1,2,3};
    EXPECT_EQ(sol.maxScore(n1f, n2f, 2), 100);
}

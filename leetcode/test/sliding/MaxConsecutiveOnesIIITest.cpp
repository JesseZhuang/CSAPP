#include "sliding/MaxConsecutiveOnesIII.hpp"
#include <gtest/gtest.h>

TEST(sliding, max_consecutive_ones_iii) {
    SolutionMaxConsecutiveOnesIII sol;

    vector<int> v1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    EXPECT_EQ(sol.longestOnes(v1, 2), 6);

    vector<int> v2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(v2, 3), 10);

    vector<int> v3 = {1, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(v3, 0), 5);

    vector<int> v4 = {0, 0, 0, 0};
    EXPECT_EQ(sol.longestOnes(v4, 4), 4);

    vector<int> v5 = {0, 0, 0, 0};
    EXPECT_EQ(sol.longestOnes(v5, 2), 2);

    vector<int> v6 = {1, 1, 1, 0, 1, 1};
    EXPECT_EQ(sol.longestOnes(v6, 0), 3);

    vector<int> v7 = {1};
    EXPECT_EQ(sol.longestOnes(v7, 0), 1);

    vector<int> v8 = {0};
    EXPECT_EQ(sol.longestOnes(v8, 1), 1);

    vector<int> v9 = {0};
    EXPECT_EQ(sol.longestOnes(v9, 0), 0);

    vector<int> v10 = {1, 0, 1, 0, 1};
    EXPECT_EQ(sol.longestOnes(v10, 3), 5);

    vector<int> v11 = {0, 1, 0, 1, 0, 1};
    EXPECT_EQ(sol.longestOnes(v11, 2), 5);
}

TEST(sliding, max_consecutive_ones_iii_bs) {
    SolutionMaxConsecutiveOnesIII2 sol;

    vector<int> v1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    EXPECT_EQ(sol.longestOnes(v1, 2), 6);

    vector<int> v2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(v2, 3), 10);

    vector<int> v3 = {1, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(v3, 0), 5);

    vector<int> v4 = {0, 0, 0, 0};
    EXPECT_EQ(sol.longestOnes(v4, 4), 4);

    vector<int> v5 = {0, 0, 0, 0};
    EXPECT_EQ(sol.longestOnes(v5, 2), 2);

    vector<int> v6 = {1, 1, 1, 0, 1, 1};
    EXPECT_EQ(sol.longestOnes(v6, 0), 3);

    vector<int> v7 = {1};
    EXPECT_EQ(sol.longestOnes(v7, 0), 1);

    vector<int> v8 = {0};
    EXPECT_EQ(sol.longestOnes(v8, 1), 1);

    vector<int> v9 = {0};
    EXPECT_EQ(sol.longestOnes(v9, 0), 0);

    vector<int> v10 = {1, 0, 1, 0, 1};
    EXPECT_EQ(sol.longestOnes(v10, 3), 5);

    vector<int> v11 = {0, 1, 0, 1, 0, 1};
    EXPECT_EQ(sol.longestOnes(v11, 2), 5);
}

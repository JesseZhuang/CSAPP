#include "sliding/MaxConsecutiveOnesII.hpp"
#include <gtest/gtest.h>

TEST(sliding, max_consecutive_ones_ii) {
    SolutionMaxConsecutiveOnesII sol;

    vector<int> v1 = {1, 0, 1, 1, 0};
    EXPECT_EQ(sol.findMaxConsecutiveOnes(v1), 4);

    vector<int> v2 = {1, 0, 1, 1, 0, 1};
    EXPECT_EQ(sol.findMaxConsecutiveOnes(v2), 4);

    vector<int> v3 = {1, 0, 1, 1, 0, 0, 0, 0};
    EXPECT_EQ(sol.findMaxConsecutiveOnes(v3), 4);

    vector<int> v4 = {1, 0, 1, 0, 1};
    EXPECT_EQ(sol.findMaxConsecutiveOnes(v4), 3);

    vector<int> v5 = {1, 1, 1};
    EXPECT_EQ(sol.findMaxConsecutiveOnes(v5), 3);
}

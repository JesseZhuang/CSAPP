#include "stack/OneThreeTwoPattern.hpp"
#include <gtest/gtest.h>

TEST(stack, one_three_two_pattern) {
    OneThreeTwoPattern::Solution sol;

    vector<int> t1 = {1, 2, 3, 4};
    EXPECT_FALSE(sol.find132pattern(t1));

    vector<int> t2 = {3, 1, 4, 2};
    EXPECT_TRUE(sol.find132pattern(t2));

    vector<int> t3 = {-1, 3, 2, 0};
    EXPECT_TRUE(sol.find132pattern(t3));

    vector<int> t4 = {1, 2};
    EXPECT_FALSE(sol.find132pattern(t4));

    vector<int> t5 = {5, 4, 3, 2, 1};
    EXPECT_FALSE(sol.find132pattern(t5));

    vector<int> t6 = {3, 3, 3, 3};
    EXPECT_FALSE(sol.find132pattern(t6));

    vector<int> t7 = {-2, 1, -1};
    EXPECT_TRUE(sol.find132pattern(t7));

    vector<int> t8 = {1, 3, 2};
    EXPECT_TRUE(sol.find132pattern(t8));

    vector<int> t9 = {3, 5, 0, 3, 4};
    EXPECT_TRUE(sol.find132pattern(t9));
}

TEST(stack, one_three_two_pattern_prefix_min) {
    OneThreeTwoPattern::Solution sol;

    vector<int> t1 = {1, 2, 3, 4};
    EXPECT_FALSE(sol.find132patternPrefixMin(t1));

    vector<int> t2 = {3, 1, 4, 2};
    EXPECT_TRUE(sol.find132patternPrefixMin(t2));

    vector<int> t3 = {-1, 3, 2, 0};
    EXPECT_TRUE(sol.find132patternPrefixMin(t3));

    vector<int> t4 = {1, 2};
    EXPECT_FALSE(sol.find132patternPrefixMin(t4));

    vector<int> t5 = {5, 4, 3, 2, 1};
    EXPECT_FALSE(sol.find132patternPrefixMin(t5));

    vector<int> t6 = {3, 3, 3, 3};
    EXPECT_FALSE(sol.find132patternPrefixMin(t6));

    vector<int> t7 = {-2, 1, -1};
    EXPECT_TRUE(sol.find132patternPrefixMin(t7));

    vector<int> t8 = {1, 3, 2};
    EXPECT_TRUE(sol.find132patternPrefixMin(t8));

    vector<int> t9 = {3, 5, 0, 3, 4};
    EXPECT_TRUE(sol.find132patternPrefixMin(t9));
}

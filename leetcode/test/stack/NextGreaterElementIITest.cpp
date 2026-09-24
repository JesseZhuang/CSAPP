#include "stack/NextGreaterElementII.hpp"
#include <gtest/gtest.h>

TEST(stack, next_greater_element_ii) {
    NextGreaterElementII::Solution sol;
    vector<int> t1 = {1, 2, 3, 4, 3};
    EXPECT_EQ(sol.nextGreaterElements(t1), vector<int>({2, 3, 4, -1, 4}));

    vector<int> t2 = {1, 2, 1};
    EXPECT_EQ(sol.nextGreaterElements(t2), vector<int>({2, -1, 2}));

    vector<int> t3 = {5};
    EXPECT_EQ(sol.nextGreaterElements(t3), vector<int>({-1}));

    vector<int> t4 = {3, 3, 3};
    EXPECT_EQ(sol.nextGreaterElements(t4), vector<int>({-1, -1, -1}));

    vector<int> t5 = {4, 3, 5};
    EXPECT_EQ(sol.nextGreaterElements(t5), vector<int>({5, 5, -1}));

    vector<int> t6 = {1, 2, 3, 4};
    EXPECT_EQ(sol.nextGreaterElements(t6), vector<int>({2, 3, 4, -1}));

    vector<int> t7 = {3, 1, 5, 2, 4};
    EXPECT_EQ(sol.nextGreaterElements(t7), vector<int>({5, 5, -1, 4, 5}));

    vector<int> t8 = {1, 2};
    EXPECT_EQ(sol.nextGreaterElements(t8), vector<int>({2, -1}));

    vector<int> t9 = {2, 2};
    EXPECT_EQ(sol.nextGreaterElements(t9), vector<int>({-1, -1}));

    vector<int> t10 = {-1, -3, 0};
    EXPECT_EQ(sol.nextGreaterElements(t10), vector<int>({0, 0, -1}));
}

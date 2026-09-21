#include "gtest/gtest.h"
#include "dp/CombinationSumIV.hpp"

TEST(dp, combination_sum_iv_dp) {
    CombinationSumIVDP sol;
    vector<int> n1 = {1, 2, 3};
    ASSERT_EQ(7, sol.combinationSum4(n1, 4));
    vector<int> n2 = {9};
    ASSERT_EQ(0, sol.combinationSum4(n2, 3));
    vector<int> n3 = {1};
    ASSERT_EQ(1, sol.combinationSum4(n3, 1));
    vector<int> n4 = {1, 2};
    ASSERT_EQ(5, sol.combinationSum4(n4, 4));
    vector<int> n5 = {3, 1, 2, 4};
    ASSERT_EQ(8, sol.combinationSum4(n5, 4));
    vector<int> n6 = {5, 1, 8};
    ASSERT_EQ(982, sol.combinationSum4(n6, 24));
}

TEST(dp, combination_sum_iv_memo) {
    CombinationSumIVMemo sol;
    vector<int> n1 = {1, 2, 3};
    ASSERT_EQ(7, sol.combinationSum4(n1, 4));
    vector<int> n2 = {9};
    ASSERT_EQ(0, sol.combinationSum4(n2, 3));
    vector<int> n3 = {1};
    ASSERT_EQ(1, sol.combinationSum4(n3, 1));
    vector<int> n4 = {1, 2};
    ASSERT_EQ(5, sol.combinationSum4(n4, 4));
    vector<int> n5 = {3, 1, 2, 4};
    ASSERT_EQ(8, sol.combinationSum4(n5, 4));
    vector<int> n6 = {5, 1, 8};
    ASSERT_EQ(982, sol.combinationSum4(n6, 24));
}

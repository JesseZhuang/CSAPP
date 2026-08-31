#include "gtest/gtest.h"
#include "array/CombinationSumII.hpp"
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> sorted_combos2(vector<vector<int>> v) {
    for (auto& c : v) sort(c.begin(), c.end());
    sort(v.begin(), v.end());
    return v;
}

TEST(array, combination_sum_ii) {
    Solution40 sol;
    vector<int> c1{10,1,2,7,6,1,5};
    ASSERT_EQ(sorted_combos2({{1,1,6},{1,2,5},{1,7},{2,6}}), sorted_combos2(sol.combinationSum2(c1, 8)));
    vector<int> c2{2,5,2,1,2};
    ASSERT_EQ(sorted_combos2({{1,2,2},{5}}), sorted_combos2(sol.combinationSum2(c2, 5)));
    vector<int> c3{2,4,6};
    ASSERT_EQ(sorted_combos2({}), sorted_combos2(sol.combinationSum2(c3, 1)));
    vector<int> c4{1};
    ASSERT_EQ(sorted_combos2({{1}}), sorted_combos2(sol.combinationSum2(c4, 1)));
    vector<int> c5{1,1,1,1,1};
    ASSERT_EQ(sorted_combos2({{1,1,1}}), sorted_combos2(sol.combinationSum2(c5, 3)));
    vector<int> c6{3,3,3};
    ASSERT_EQ(sorted_combos2({{3,3,3}}), sorted_combos2(sol.combinationSum2(c6, 9)));
    vector<int> c7{1,1,1,2,2};
    ASSERT_EQ(sorted_combos2({{1,1,2},{2,2}}), sorted_combos2(sol.combinationSum2(c7, 4)));
}

TEST(array, combination_sum_ii_counter) {
    Solution40Counter sol;
    vector<int> c1{10,1,2,7,6,1,5};
    ASSERT_EQ(sorted_combos2({{1,1,6},{1,2,5},{1,7},{2,6}}), sorted_combos2(sol.combinationSum2(c1, 8)));
    vector<int> c2{2,5,2,1,2};
    ASSERT_EQ(sorted_combos2({{1,2,2},{5}}), sorted_combos2(sol.combinationSum2(c2, 5)));
    vector<int> c3{2,4,6};
    ASSERT_EQ(sorted_combos2({}), sorted_combos2(sol.combinationSum2(c3, 1)));
    vector<int> c4{1};
    ASSERT_EQ(sorted_combos2({{1}}), sorted_combos2(sol.combinationSum2(c4, 1)));
    vector<int> c5{1,1,1,1,1};
    ASSERT_EQ(sorted_combos2({{1,1,1}}), sorted_combos2(sol.combinationSum2(c5, 3)));
    vector<int> c6{3,3,3};
    ASSERT_EQ(sorted_combos2({{3,3,3}}), sorted_combos2(sol.combinationSum2(c6, 9)));
    vector<int> c7{1,1,1,2,2};
    ASSERT_EQ(sorted_combos2({{1,1,2},{2,2}}), sorted_combos2(sol.combinationSum2(c7, 4)));
}

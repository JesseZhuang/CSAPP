#include "gtest/gtest.h"
#include "array/CombinationSum.hpp"
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> sorted_combos(vector<vector<int>> v) {
    for (auto& c : v) sort(c.begin(), c.end());
    sort(v.begin(), v.end());
    return v;
}

TEST(array, combination_sum_backtrack) {
    Solution sol;
    vector<int> c1{2,3,6,7};
    ASSERT_EQ(sorted_combos({{2,2,3},{7}}), sorted_combos(sol.combinationSum(c1, 7)));
    vector<int> c2{2,3,5};
    ASSERT_EQ(sorted_combos({{2,2,2,2},{2,3,3},{3,5}}), sorted_combos(sol.combinationSum(c2, 8)));
    vector<int> c3{2};
    ASSERT_EQ(sorted_combos({}), sorted_combos(sol.combinationSum(c3, 1)));
    vector<int> c4{1};
    ASSERT_EQ(sorted_combos({{1}}), sorted_combos(sol.combinationSum(c4, 1)));
    vector<int> c5{1};
    ASSERT_EQ(sorted_combos({{1,1}}), sorted_combos(sol.combinationSum(c5, 2)));
    vector<int> c6{1,2};
    ASSERT_EQ(sorted_combos({{1,1,1,1},{1,1,2},{2,2}}), sorted_combos(sol.combinationSum(c6, 4)));
}

TEST(array, combination_sum_dp) {
    SolutionDP sol;
    vector<int> c1{2,3,6,7};
    ASSERT_EQ(sorted_combos({{2,2,3},{7}}), sorted_combos(sol.combinationSum(c1, 7)));
    vector<int> c2{2,3,5};
    ASSERT_EQ(sorted_combos({{2,2,2,2},{2,3,3},{3,5}}), sorted_combos(sol.combinationSum(c2, 8)));
    vector<int> c3{2};
    ASSERT_EQ(sorted_combos({}), sorted_combos(sol.combinationSum(c3, 1)));
    vector<int> c4{1};
    ASSERT_EQ(sorted_combos({{1}}), sorted_combos(sol.combinationSum(c4, 1)));
    vector<int> c5{1};
    ASSERT_EQ(sorted_combos({{1,1}}), sorted_combos(sol.combinationSum(c5, 2)));
    vector<int> c6{1,2};
    ASSERT_EQ(sorted_combos({{1,1,1,1},{1,1,2},{2,2}}), sorted_combos(sol.combinationSum(c6, 4)));
}

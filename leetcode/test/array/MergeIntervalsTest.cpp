#include "gtest/gtest.h"
#include "array/MergeIntervals.hpp"

using namespace std;

TEST(array, merge_intervals) {
    Solution sol;

    vector<vector<int>> iv1{{1,3},{2,6},{8,10},{15,18}};
    ASSERT_EQ((vector<vector<int>>{{1,6},{8,10},{15,18}}), sol.merge(iv1));

    vector<vector<int>> iv2{{1,4},{4,5}};
    ASSERT_EQ((vector<vector<int>>{{1,5}}), sol.merge(iv2));

    vector<vector<int>> iv3{{1,1}};
    ASSERT_EQ((vector<vector<int>>{{1,1}}), sol.merge(iv3));

    vector<vector<int>> iv4{{1,2},{4,5},{7,8}};
    ASSERT_EQ((vector<vector<int>>{{1,2},{4,5},{7,8}}), sol.merge(iv4));

    vector<vector<int>> iv5{{1,10},{2,3},{4,5},{6,7}};
    ASSERT_EQ((vector<vector<int>>{{1,10}}), sol.merge(iv5));

    vector<vector<int>> iv6{{3,4},{1,2},{5,6},{2,3}};
    ASSERT_EQ((vector<vector<int>>{{1,4},{5,6}}), sol.merge(iv6));

    vector<vector<int>> iv7{{1,5},{2,3}};
    ASSERT_EQ((vector<vector<int>>{{1,5}}), sol.merge(iv7));

    vector<vector<int>> iv8{{1,2},{2,3},{3,4}};
    ASSERT_EQ((vector<vector<int>>{{1,4}}), sol.merge(iv8));
}
